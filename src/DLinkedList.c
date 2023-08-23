#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} Node;

void insert(Node** head, int data, int pos)
{
    if (!*head) {
        *head = malloc(sizeof(Node));
        (*head)->val = data;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return;
    }

    Node *ptr2 = *head, *ptr1 = NULL;

    for (int i = 0; i < pos - 1; ++i) {
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }

    Node* temp = malloc(sizeof(Node));
    temp->val = data;
    temp->next = ptr2;
    temp->prev = ptr1;

    if (ptr2)
        ptr2->prev = temp;
    if (ptr1) {
        ptr1->next = temp;
    } else {
        *head = temp;
    }
    return;
}

void deleteNode(Node** head, int pos)
{
    if (*head) {
        Node* ptr = *head;
        for (int i = 0; i < pos - 1; ++i) {
            ptr = ptr->next;
        }
        if (ptr->next) {
            ptr->next->prev = ptr->prev;
        } else {
            ptr->prev->next = NULL;
        }
        if (ptr->prev) {
            ptr->prev->next = ptr->next;
        } else {
            ptr->next->prev = NULL;
            *head = ptr->next;
        }
        free(ptr);
    }
}

void reverse(Node** head)
{
    if (*head) {
        Node *ptr1 = *head, *ptr2 = (*head)->next;
        while (ptr2) {
            ptr1->next = ptr1->prev;
            ptr1->prev = ptr2;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr1->prev;
        ptr1->prev = ptr2;
        *head = ptr1;
        return;
    }
}

void print(Node** head)
{
    if (*head) {
        Node* ptr = *head;
        while (ptr) {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void print_reverse(Node** head)
{
    if (*head) {
        Node* ptr = *head;
        while (ptr->next) {
            ptr = ptr->next;
        }
        while (ptr) {
            printf("%d ", ptr->val);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}

void clear(Node** head)
{
    if (*head) {
        Node* ptr = *head;
        while (ptr) {
            *head = ptr->next;
            free(ptr);
            ptr = *head;
        }
    }
}

int main()
{
    Node* head = NULL;
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);
    insert(&head, 4, 4);
    print(&head);
    deleteNode(&head, 1);
    print(&head);
    reverse(&head);
    print(&head);
    print_reverse(&head);
    clear(&head);
}