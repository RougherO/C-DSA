#include <stdio.h>
#include <stdlib.h>

typedef struct q {
    int* arr;
    int size;
    int max_size;
} Queue;

void push(Queue* q, int data)
{
    if (q->size == q->max_size) {
        printf("Queue Overflow\n");
        return;
    }
    q->arr[q->size++] = data;
}

int pop(Queue* q)
{
    if (q->size > 0) {
        int temp = q->arr[0];
        for (int i = 0; i < q->size - 1; ++i) {
            q->arr[i] = q->arr[i + 1];
        }
        q->size -= 1;
        return temp;
    }
    printf("Queue Underflow\n");
    return -1;
}

void print(Queue* q)
{
    for (int i = 0; i < q->size; ++i) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue q = { 0, 0, 0 };
    printf("Enter size of queue: ");
    scanf("%d", &q.max_size);

    q.arr = calloc(q.max_size, sizeof(int));
    printf("========Menu========\n");
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

    free(q.arr);
}