#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// void push_front(Node** tail, int data)
// {
//     if (!*tail) {
//         *tail = malloc(sizeof(Node));
//         (*tail)->val = data;
//         (*tail)->next = *tail;
//         return;
//     }
//     Node* ptr = malloc(sizeof(Node));
//     ptr->val = data;
//     ptr->next = (*tail)->next;
//     (*tail)->next = ptr;
//     return;
// }

void push_back(Node** tail, int data)
{
    if (!*tail) {
        *tail = malloc(sizeof(Node));
        (*tail)->val = data;
        (*tail)->next = *tail;
        return;
    }
    Node* ptr = malloc(sizeof(Node));
    ptr->val = data;
    ptr->next = (*tail)->next;
    (*tail)->next = ptr;
    *tail = ptr;
    return;
}

void print(Node** tail)
{
    if (tail) {
        Node* ptr = (*tail)->next;

        while (ptr != *tail) {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->val);
        return;
    }
}

void deleteNode(Node** tail, int K)
{
    if (*tail) {
        Node *ptr1 = *tail, *ptr2 = (*tail)->next;
        for (int i = 1; i < K; ++i) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr2->next;
        *tail = ptr1;
        free(ptr2);
    }
}

void clear(Node** tail)
{
    if (*tail) {
        Node* ptr = (*tail)->next;
        Node* ptr1 = ptr->next;
        while (ptr != *tail) {
            free(ptr);
            ptr = ptr1;
            ptr1 = ptr1->next;
        }
        free(*tail);
        return;
    }
}

int main()
{
    Node* tail = NULL;

    int N, K;
    printf("Enter Value of N : ");
    scanf("%d", &N);

    printf("Enter value of K : ");
    scanf("%d", &K);

    for (int i = 0; i < N; ++i) {
        push_back(&tail, i + 1);
    }

    while (tail->next != tail) {
        deleteNode(&tail, K);
    }

    printf("Child %d is the winner!\n", tail->val);
    clear(&tail);
}