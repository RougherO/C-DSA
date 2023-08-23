#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} Node;

void push(Node** head, Node** tail, int data)
{
    if (*head) {
        (*tail)->next = malloc(sizeof(Node));
        (*tail)->next->prev = *tail;
        *tail = (*tail)->next;
        (*tail)->next = NULL;
        (*tail)->val = data;
    } else {
        *head = malloc(sizeof(Node));
        (*head)->val = data;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        *tail = *head;
    }
}

void pop(Node** head, Node** tail)
{
    if (*head) {
        if (*head == *tail) {
            free(*head);
            *head = NULL;
            *tail = NULL;
            return;
        }
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = NULL;
        return;
    }
    printf("Stack empty!");
}

void print(Node** head, Node** tail)
{
    Node* ptr = *head;
    while (ptr) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

int top(Node** head, Node** tail)
{
    if (*head) {
        return (*tail)->val;
    }
    printf("Stack empty!");
    return INT_MIN;
}

int empty(Node** head, Node** tail)
{
    if (*head == NULL) {
        return 1;
    }
    return 0;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int ch = 0, data;
    while (ch != 6) {
        printf("Enter your choice : \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. View top\n");
        printf("4. Check empty\n");
        printf("5. Print\n");
        printf("6. Exit\n");
        scanf(" %d", &ch);

        switch (ch) {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d", &data);
            push(&head, &tail, data);
            break;
        case 2:
            pop(&head, &tail);
            break;
        case 3:
            printf("Top value : %d\n", top(&head, &tail));
            break;
        case 4:
            printf("%s", empty(&head, &tail) ? "Empty\n" : "Not Empty\n");
            break;
        case 5:
            print(&head, &tail);
            break;
        }
    }
}