#include "memory_common.h"

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    size_t step_bytes = parse_step_bytes(argc, argv);
    size_t max_iterations = parse_max_iterations(argc, argv);
    size_t last_success = 0;
    size_t iteration = 0;
    clock_t start = clock();

    print_usage(argv[0]);

    for (size_t request_size = step_bytes;; request_size += step_bytes)
    {
        unsigned char *block = malloc(request_size);
        if (block == NULL)
        {
            break;
        }

        touch_range(block, 0, request_size);
        free(block);

        last_success = request_size;
        iteration++;
        print_step_info("malloc+free", iteration, request_size, request_size, start);

        if (reached_iteration_limit(iteration, max_iterations))
        {
            break;
        }

        if (SIZE_MAX - request_size < step_bytes)
        {
            break;
        }
    }

    char last_buffer[32];
    format_bytes(last_success, last_buffer, sizeof(last_buffer));

    printf("\n[malloc+free] finished after %zu successful allocations\n", iteration);
    printf("[malloc+free] largest single allocation: %s\n", last_buffer);
    printf("[malloc+free] elapsed CPU time:          %.2fs\n", elapsed_seconds(start));

    return 0;
}
