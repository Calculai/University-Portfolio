#ifndef MEMORY_COMMON_H
#define MEMORY_COMMON_H

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KIB ((size_t)1024)
#define MIB (KIB * KIB)
#define DEFAULT_STEP_BYTES (8 * MIB)
#define PAGE_STRIDE ((size_t)4096)

static double elapsed_seconds(clock_t start)
{
    return (double)(clock() - start) / (double)CLOCKS_PER_SEC;
}

static void format_bytes(size_t bytes, char *buffer, size_t buffer_size)
{
    static const char *units[] = {"B", "KiB", "MiB", "GiB", "TiB"};
    double value = (double)bytes;
    size_t unit_index = 0;

    while (value >= 1024.0 && unit_index < (sizeof(units) / sizeof(units[0])) - 1)
    {
        value /= 1024.0;
        unit_index++;
    }

    snprintf(buffer, buffer_size, "%.2f %s", value, units[unit_index]);
}

static size_t parse_step_bytes(int argc, char **argv)
{
    if (argc < 2)
    {
        return DEFAULT_STEP_BYTES;
    }

    char *end_ptr = NULL;
    errno = 0;
    unsigned long long value = strtoull(argv[1], &end_ptr, 0);

    if (errno != 0 || end_ptr == argv[1] || (end_ptr != NULL && *end_ptr != '\0') || value == 0)
    {
        fprintf(stderr, "Invalid step size '%s'. Falling back to %zu bytes.\n", argv[1], DEFAULT_STEP_BYTES);
        return DEFAULT_STEP_BYTES;
    }

    return (size_t)value;
}

static size_t parse_max_iterations(int argc, char **argv)
{
    if (argc < 3)
    {
        return 0;
    }

    char *end_ptr = NULL;
    errno = 0;
    unsigned long long value = strtoull(argv[2], &end_ptr, 0);

    if (errno != 0 || end_ptr == argv[2] || (end_ptr != NULL && *end_ptr != '\0'))
    {
        fprintf(stderr, "Invalid max iteration count '%s'. Running without an iteration limit.\n", argv[2]);
        return 0;
    }

    return (size_t)value;
}

static int reached_iteration_limit(size_t iteration, size_t max_iterations)
{
    return max_iterations != 0 && iteration >= max_iterations;
}

static void touch_range(unsigned char *memory, size_t start, size_t end)
{
    if (memory == NULL || end == 0 || end <= start)
    {
        return;
    }

    size_t offset = start;
    if (offset == 0)
    {
        memory[0] = (unsigned char)(memory[0] + 1U);
        offset = PAGE_STRIDE;
    }
    else
    {
        offset = ((offset + PAGE_STRIDE - 1) / PAGE_STRIDE) * PAGE_STRIDE;
    }

    for (; offset < end; offset += PAGE_STRIDE)
    {
        memory[offset] = (unsigned char)(memory[offset] + 1U);
    }

    memory[end - 1] = (unsigned char)(memory[end - 1] + 1U);
}

static int ensure_capacity(void ***blocks, size_t *capacity, size_t needed)
{
    if (needed <= *capacity)
    {
        return 1;
    }

    size_t new_capacity = (*capacity == 0) ? 16 : (*capacity * 2);
    while (new_capacity < needed)
    {
        new_capacity *= 2;
    }

    void **new_blocks = realloc(*blocks, new_capacity * sizeof(void *));
    if (new_blocks == NULL)
    {
        return 0;
    }

    *blocks = new_blocks;
    *capacity = new_capacity;
    return 1;
}

static void print_step_info(const char *label, size_t iteration, size_t current_size, size_t tracked_size, clock_t start)
{
    char current_buffer[32];
    char tracked_buffer[32];
    format_bytes(current_size, current_buffer, sizeof(current_buffer));
    format_bytes(tracked_size, tracked_buffer, sizeof(tracked_buffer));

    printf("[%s] iteration=%zu current=%s tracked=%s elapsed=%.2fs\n",
           label,
           iteration,
           current_buffer,
           tracked_buffer,
           elapsed_seconds(start));
}

static void print_usage(const char *program_name)
{
    printf("Usage: %s [step_bytes] [max_iterations]\n", program_name);
    printf("If omitted, step_bytes defaults to %zu bytes (%zu MiB).\n",
           DEFAULT_STEP_BYTES,
           DEFAULT_STEP_BYTES / MIB);
    printf("If max_iterations is omitted or 0, the program runs until allocation fails.\n");
}

#endif
