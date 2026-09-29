param(
    [long]$StepBytes = 8388608,
    [long]$MaxIterations = 0,
    [long]$MaxRuntimeSec = 0,
    [switch]$NoBuild
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

Set-Location -LiteralPath $PSScriptRoot

if (-not (Get-Command gcc -ErrorAction SilentlyContinue)) {
    Write-Error "gcc not found on PATH. Install GCC (e.g. MinGW-w64) or run this from a shell where gcc is available."
    exit 1
}

$methods = @(
    @{ Label = "malloc";      Source = "main.c";             Exe = "memory_malloc.exe" },
    @{ Label = "calloc";      Source = "main_calloc.c";      Exe = "memory_calloc.exe" },
    @{ Label = "realloc";     Source = "main_realloc.c";     Exe = "memory_realloc.exe" },
    @{ Label = "malloc+free"; Source = "main_malloc_free.c"; Exe = "memory_malloc_free.exe" }
)

$logDir = Join-Path $PSScriptRoot "logs"
if (-not (Test-Path -LiteralPath $logDir)) {
    New-Item -Path $logDir -ItemType Directory | Out-Null
}

if (-not $NoBuild) {
    Write-Host "[build] Compiling all methods..."
    foreach ($method in $methods) {
        Write-Host "  - $($method.Label): $($method.Source) -> $($method.Exe)"
        gcc -std=c11 -O2 $method.Source -o $method.Exe
        if ($LASTEXITCODE -ne 0) {
            Write-Error "Build failed for $($method.Label)."
            exit $LASTEXITCODE
        }
    }
}
else {
    Write-Host "[build] Skipped (--NoBuild). Using existing executables."
}

$results = @()

Write-Host ""
Write-Host "[run] StepBytes=$StepBytes MaxIterations=$MaxIterations MaxRuntimeSec=$MaxRuntimeSec"
if ($MaxIterations -eq 0) {
    Write-Host "      MaxIterations=0 means each method runs until allocation failure."
}
if ($MaxRuntimeSec -eq 0) {
    Write-Host "      MaxRuntimeSec=0 means no time limit per method."
}

foreach ($method in $methods) {
    $label = $method.Label
    $exePath = Join-Path $PSScriptRoot $method.Exe
    $logPath = Join-Path $logDir ("{0}.log" -f ($label -replace '\+', '_plus_'))

    Write-Host ""
    Write-Host "[run] $label"

    $start = Get-Date
    $timedOut = $false
    $stderrPath = "$logPath.stderr"
    if (Test-Path -LiteralPath $logPath) {
        Remove-Item -Force $logPath
    }
    if (Test-Path -LiteralPath $stderrPath) {
        Remove-Item -Force $stderrPath
    }

    $process = Start-Process -FilePath $exePath -ArgumentList @($StepBytes, $MaxIterations) -PassThru -NoNewWindow -RedirectStandardOutput $logPath -RedirectStandardError $stderrPath
    if ($MaxRuntimeSec -gt 0) {
        $exited = $process.WaitForExit($MaxRuntimeSec * 1000)
        if (-not $exited) {
            $timedOut = $true
            Stop-Process -Id $process.Id -Force
            $process.WaitForExit()
            Add-Content -LiteralPath $logPath -Value "[$label] terminated by runner after ${MaxRuntimeSec}s timeout"
        }
    }
    else {
        $process.WaitForExit()
    }

    if (Test-Path -LiteralPath $stderrPath) {
        Get-Content -LiteralPath $stderrPath | Add-Content -LiteralPath $logPath
        Remove-Item -Force $stderrPath
    }

    Get-Content -LiteralPath $logPath | Out-Host
    $process.Refresh()
    $exitCode = $process.ExitCode
    $duration = (Get-Date) - $start
    $outputLines = Get-Content -LiteralPath $logPath

    $labelEsc = [regex]::Escape($label)

    $iterations = "n/a"
    $largest = "n/a"
    $retained = "n/a"
    $cpu = "n/a"
    $lastIter = $null
    $lastCurrent = $null
    $lastTracked = $null
    $lastElapsed = $null

    foreach ($line in $outputLines) {
        if ($line -match "^\[$labelEsc\] iteration=(?<iter>\d+) current=(?<current>.+?) tracked=(?<tracked>.+?) elapsed=(?<elapsed>[0-9.]+)s$") {
            $lastIter = $Matches['iter']
            $lastCurrent = $Matches['current'].Trim()
            $lastTracked = $Matches['tracked'].Trim()
            $lastElapsed = $Matches['elapsed']
        }
        if ($line -match "^\[$labelEsc\] finished after (?<count>\d+) successful") {
            $iterations = $Matches['count']
        }
        if ($line -match "^\[$labelEsc\] (largest single allocation|largest resized block):\s+(?<value>.+)$") {
            $largest = $Matches['value'].Trim()
        }
        if ($line -match "^\[$labelEsc\] (total retained memory|final retained memory):\s+(?<value>.+)$") {
            $retained = $Matches['value'].Trim()
        }
        if ($line -match "^\[$labelEsc\] elapsed CPU time:\s+(?<value>[0-9.]+s)$") {
            $cpu = $Matches['value']
        }
    }

    if ($iterations -eq "n/a" -and $null -ne $lastIter) {
        $iterations = $lastIter
    }
    if ($largest -eq "n/a" -and $null -ne $lastCurrent) {
        $largest = $lastCurrent
    }
    if ($retained -eq "n/a" -and $null -ne $lastTracked) {
        $retained = $lastTracked
    }
    if ($cpu -eq "n/a" -and $null -ne $lastElapsed) {
        $cpu = ("~{0}s (from last iter)" -f $lastElapsed)
    }

    $hasFinishedMarker = $false
    foreach ($line in $outputLines) {
        if ($line -match "^\[$labelEsc\] finished after (?<count>\d+) successful") {
            $hasFinishedMarker = $true
            break
        }
    }

    $normalizedExitCode = if ($null -eq $exitCode) {
        if ($hasFinishedMarker) { 0 } else { -1 }
    }
    else {
        [int]$exitCode
    }

    $status = if ($timedOut) { "timeout" } elseif ($normalizedExitCode -eq 0) { "ok" } else { "exit $normalizedExitCode" }

    $results += [pscustomobject]@{
        Method         = $label
        Iterations     = $iterations
        LargestBlock   = $largest
        RetainedMemory = $retained
        CpuTime        = $cpu
        WallTime       = ("{0:n2}s" -f $duration.TotalSeconds)
        Status         = $status
        Log            = $logPath
    }
}

Write-Host ""
Write-Host "=== Final Stats (all methods) ==="
$results | Format-Table -AutoSize Method, Iterations, LargestBlock, RetainedMemory, CpuTime, WallTime, Status

Write-Host ""
Write-Host "=== Logs ==="
$results | ForEach-Object { Write-Host ("- {0}: {1}" -f $_.Method, $_.Log) }

$summaryLogPath = Join-Path $logDir "summary.log"
$summaryHeader = @(
    "comparch-4 run summary",
    "StepBytes: $StepBytes",
    "MaxIterations: $MaxIterations",
    "MaxRuntimeSec: $MaxRuntimeSec",
    ""
) -join [Environment]::NewLine

$tableText = ($results | Format-Table -AutoSize Method, Iterations, LargestBlock, RetainedMemory, CpuTime, WallTime, Status | Out-String)
$logsText = (("=== Per-method logs ===" + [Environment]::NewLine) + (($results | ForEach-Object { "- {0}: {1}" -f $_.Method, $_.Log }) -join [Environment]::NewLine) + [Environment]::NewLine)

Set-Content -LiteralPath $summaryLogPath -Value $summaryHeader
Add-Content -LiteralPath $summaryLogPath -Value "=== Final Stats (all methods) ==="
Add-Content -LiteralPath $summaryLogPath -Value $tableText
Add-Content -LiteralPath $summaryLogPath -Value $logsText

Write-Host "- summary: $summaryLogPath"

$failures = @($results | Where-Object { $_.Status -ne "ok" })
if ($failures.Count -gt 0) {
    Write-Error "One or more methods failed. See logs above."
    exit 1
}

Write-Host ""
Write-Host "Done. One run completed for all methods."
