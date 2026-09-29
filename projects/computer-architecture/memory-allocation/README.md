# comparch-4 programming exercise

So for this I made a bit of a fancy script that compiles and runs each and reports the data

See summary for overview of the different methods compared to eachother

## How to run it

Use the combined runner:

- `./run_all_methods.bat`

Optional arguments:

- `StepBytes` as the first argument
- `MaxIterations` as the second argument (`0` means run until failure)
- `MaxRuntimeSec` as the third argument
- `NoBuild` as a PowerShell switch if you want to skip recompiling

Examples:

- `./run_all_methods.bat`
- `./run_all_methods.bat 8388608 0`
- `./run_all_methods.bat 8388608 0 120`
- `./run_all_methods.bat -NoBuild 8388608 0 120`

## discussion

for the purpose of my own sanity I had to limit the total runtime to 10 minutes still this is plenty of time for an insightful view.

Realloc and malloc ran about the same time and amount of itteration before termination, and the same for realloc and malloc + free memory. There is essentially two types:

Type I (malloc and calloc):

Memory: block 1 -> block 1 + block 2 -> block 1 + block 2 + block 3 -> block 1 + block 2 + block 3 + block 4

Type II (realloc and malloc + free)

Memory: block 1 -> block 2 -> block 3 -> block 4

The size of each block increases

In other words calloc and malloc have:
biggest block = full memory - sum of previous blocks - other unrelated processes

While realloc and malloc + free have:
biggest block = full memory - other unrelated processes

In the logs we can see the stark difference in the methods. Malloc and callog allocated there biggest block to be 920 and 840 MiB while retaining a whopping 52 GiB and 43 GiB and then failing because there was no more ram to allocate after just 61.43s and 50.98s. Meanwhile realloc and malloc + free allocated a way bigger 4.48 and 4.59 GiB block, only retaining an equivalent amount of memory. They are so efficient I would have to run the script for much longer to arrive at memory allocation failure, they both managed to timeout. So overall the methods that clean up memory as they go takes much much less memory and will arrive and way bigger blocks before failure. 
