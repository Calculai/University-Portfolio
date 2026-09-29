#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50
#define FILENAME "queue_data.txt"

typedef struct {
    char name[50];
} person;

typedef struct {
    /* pointer to active storage (points to `fixed` for non-dynamic queues,
       or to a malloc'd buffer for dynamic queues) */
    person *people;
    /* small fixed buffer used when queue is non-dynamic */
    person fixed[CAPACITY];
    int size;
    int capacity; /* current capacity of `people` buffer */
    int dynamic;  /* 0 = use fixed buffer (no automatic growth), 1 = dynamic/resizable */
} queue;

/* API: initialize queue with preset fixed capacity (non-dynamic) */
void queue_init(queue *q);
/* API: initialize queue with an initial capacity and enable dynamic resizing */
int queue_init_with_capacity(queue *q, int initial_capacity);
/* free any resources used by queue (only needed for dynamic queues) */
void queue_free(queue *q);

// Function declarations
void enqueue(queue *q, char name[]);
void dequeue(queue *q);
void save_queue(queue *q);
void load_queue(queue *q);
void print_queue(queue *q);

void queue_init(queue *q);
int queue_init_with_capacity(queue *q, int initial_capacity);
void queue_free(queue *q);

int main(void) {
    queue q;
    /* Default initialization: preset fixed capacity (non-dynamic) */
    queue_init(&q);

    /* Load queue from file if it exists */
    load_queue(&q);

    while (1) {
        printf("\nQueue size: %d\n", q.size);
        print_queue(&q);

        printf("\nChoose an option:\n");
        printf("1: Enqueue (add name)\n");
        printf("2: Dequeue (remove name)\n");
        printf("3: Exit\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            if (q.size >= q.capacity && !q.dynamic) {
                printf("Queue is full! Cannot add more names.\n");
                continue;
            }
            char name[50];
            printf("Enter name to enqueue: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            enqueue(&q, name);
            save_queue(&q);  // Save after enqueue
        }
        else if (choice == 2) {
            dequeue(&q);
            save_queue(&q);  // Save after dequeue
        }
        else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    queue_free(&q);
    return 0;
}

void enqueue(queue *q, char name[]) {
    if (q->size >= q->capacity) {
        if (q->dynamic) {
            /* resize: double capacity */
            int new_cap = (q->capacity > 0) ? q->capacity * 2 : 1;
            person *tmp = realloc(q->people, sizeof(person) * new_cap);
            if (!tmp) {
                printf("Failed to expand queue memory.\n");
                return;
            }
            q->people = tmp;
            q->capacity = new_cap;
        } else {
            printf("Queue is full!\n");
            return;
        }
    }
    strcpy(q->people[q->size].name, name);
    q->size++;
}

void dequeue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Removed: %s\n", q->people[0].name);
    for (int i = 1; i < q->size; i++) {
        q->people[i - 1] = q->people[i];
    }
    q->size--;
}

void save_queue(queue *q) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    /* Save size and capacity so we can restore dynamic queues */
    fprintf(file, "%d %d\n", q->size, q->dynamic ? q->capacity : 0);
    for (int i = 0; i < q->size; i++) {
        fprintf(file, "%s\n", q->people[i].name);
    }
    fclose(file);
}

void load_queue(queue *q) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        // No file to load from, start empty
        return;
    }
    int size, saved_capacity;
    if (fscanf(file, "%d %d\n", &size, &saved_capacity) != 2 || size < 0) {
        printf("File corrupted or invalid size, starting with empty queue.\n");
        fclose(file);
        return;
    }

    /* If the saved file indicated a dynamic capacity (>0) we restore into a dynamic queue
       sized to at least the saved_capacity, otherwise use the fixed buffer. */
    if (saved_capacity > 0) {
        /* initialize as dynamic with capacity at least saved_capacity */
        if (queue_init_with_capacity(q, saved_capacity) != 0) {
            printf("Failed to allocate memory while loading queue.\n");
            fclose(file);
            return;
        }
    } else {
        /* keep whatever init already provided (likely fixed buffer) but ensure capacity is CAPACITY */
        if (q->people == NULL) {
            queue_init(q);
        }
    }

    q->size = 0; /* we'll increment as we read */
    for (int i = 0; i < size; i++) {
        char buf[sizeof(q->people[0].name)];
        if (fgets(buf, sizeof(buf), file) == NULL) {
            printf("File corrupted or incomplete, stopping load.\n");
            break;
        }
        buf[strcspn(buf, "\n")] = 0;
        enqueue(q, buf);
    }
    fclose(file);
}

void print_queue(queue *q) {
    if (q->size == 0) {
        printf("[empty]\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        printf("%d: %s\n", i + 1, q->people[i].name);
    }
}

/* Implementation of initialization/free helpers */
void queue_init(queue *q) {
    q->people = q->fixed;
    q->size = 0;
    q->capacity = CAPACITY;
    q->dynamic = 0;
}

int queue_init_with_capacity(queue *q, int initial_capacity) {
    if (initial_capacity <= 0) return -1;
    person *buf = malloc(sizeof(person) * initial_capacity);
    if (!buf) return -1;
    q->people = buf;
    q->size = 0;
    q->capacity = initial_capacity;
    q->dynamic = 1;
    return 0;
}

void queue_free(queue *q) {
    if (q->dynamic && q->people) {
        free(q->people);
        q->people = NULL;
    }
    /* If non-dynamic nothing to free; fixed buffer is on stack */
}