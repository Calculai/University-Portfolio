@echo off
setlocal

cd /d "%~dp0"

powershell -ExecutionPolicy Bypass -File "%~dp0run_all_methods.ps1" %*
exit /b %ERRORLEVEL%
