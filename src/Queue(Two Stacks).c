#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue {
    int* arr1;
    int* arr2;
    int size;
    int size1;
    int size2;
    int max_size;
} Queue;

void initialise(Queue* q)
{
    q->arr1 = calloc(q->max_size, sizeof(int));
    q->arr2 = calloc(q->max_size, sizeof(int));
    q->size = 0;
    q->size1 = 0;
    q->size2 = 0;
}

void push(Queue* q, int val)
{
    if (q->size < q->max_size) {
        q->arr1[q->size1++] = val;
        q->size += 1;
    } else {
        printf("Queue Overflow\n");
    }
}

int pop(Queue* q)
{
    if (q->size > 0) {
        if (q->size2 > 0) {
            q->size -= 1;
            return q->arr2[--q->size2];
        }
        while (q->size1 > 0) {
            q->arr2[q->size2++] = q->arr1[--q->size1];
        }
        q->size -= 1;
        return q->arr2[--q->size2];
    }
    printf("Queue Underflow\n");
    return INT_MIN;
}

void print(Queue* q)
{
    for (int i = q->size2 - 1; i >= 0; --i) {
        printf("%d ", q->arr2[i]);
    }
    for (int i = 0; i < q->size1; ++i) {
        printf("%d ", q->arr1[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    printf("Enter size of Queue : ");
    scanf("%d", &q.max_size);

    initialise(&q);

    printf("=======Menu=======\n");
    printf("[1] Enqueue\n");
    printf("[2] Dequeue\n");
    printf("[3] Check size\n");
    printf("[4] Print Queue\n");
    printf("[5] Exit\n");

    int ch = -1, value;

    while (ch) {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            push(&q, value);
            break;
        case 2:
            printf("%d\n", pop(&q));
            break;
        case 3:
            printf("%d\n", q.size);
            break;
        case 4:
            print(&q);
            break;
        case 5:
            ch = 0;
            break;
        }
    }

    free(q.arr1);
    free(q.arr2);
}