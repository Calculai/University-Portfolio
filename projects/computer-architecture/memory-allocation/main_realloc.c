#include "memory_common.h"

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    size_t step_bytes = parse_step_bytes(argc, argv);
    size_t max_iterations = parse_max_iterations(argc, argv);
    unsigned char *block = NULL;
    size_t current_size = 0;
    size_t last_success = 0;
    size_t iteration = 0;
    clock_t start = clock();

    print_usage(argv[0]);

    for (size_t request_size = step_bytes;; request_size += step_bytes)
    {
        unsigned char *resized = realloc(block, request_size);
        if (resized == NULL)
        {
            break;
        }

        block = resized;
        touch_range(block, current_size, request_size);
        current_size = request_size;
        last_success = request_size;
        iteration++;
        print_step_info("realloc", iteration, current_size, current_size, start);

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

    printf("\n[realloc] finished after %zu successful resizes\n", iteration);
    printf("[realloc] largest resized block: %s\n", last_buffer);
    printf("[realloc] final retained memory: %s\n", last_buffer);
    printf("[realloc] elapsed CPU time:      %.2fs\n", elapsed_seconds(start));

    free(block);
    return 0;
}
