#include "memory_common.h"

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    size_t step_bytes = parse_step_bytes(argc, argv);
    size_t max_iterations = parse_max_iterations(argc, argv);
    void **blocks = NULL;
    size_t capacity = 0;
    size_t count = 0;
    size_t total_retained = 0;
    size_t last_success = 0;
    clock_t start = clock();

    print_usage(argv[0]);

    for (size_t request_size = step_bytes;; request_size += step_bytes)
    {
        void *block = calloc(1, request_size);
        if (block == NULL)
        {
            break;
        }

        if (!ensure_capacity(&blocks, &capacity, count + 1))
        {
            fprintf(stderr, "Failed to grow block tracking array.\n");
            free(block);
            break;
        }

        blocks[count++] = block;
        touch_range((unsigned char *)block, 0, request_size);

        last_success = request_size;
        total_retained += request_size;
        print_step_info("calloc", count, request_size, total_retained, start);

        if (reached_iteration_limit(count, max_iterations))
        {
            break;
        }

        if (SIZE_MAX - request_size < step_bytes)
        {
            break;
        }
    }

    char last_buffer[32];
    char total_buffer[32];
    format_bytes(last_success, last_buffer, sizeof(last_buffer));
    format_bytes(total_retained, total_buffer, sizeof(total_buffer));

    printf("\n[calloc] finished after %zu successful allocations\n", count);
    printf("[calloc] largest single allocation: %s\n", last_buffer);
    printf("[calloc] total retained memory:     %s\n", total_buffer);
    printf("[calloc] elapsed CPU time:          %.2fs\n", elapsed_seconds(start));

    for (size_t index = 0; index < count; ++index)
    {
        free(blocks[index]);
    }
    free(blocks);

    return 0;
}
