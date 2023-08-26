#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

void insert(node** head, int data, int pos)
{
    if (!*head) {
        if (pos == 0) {
            *head = malloc(sizeof(node));
            (*head)->val = data;
            (*head)->next = NULL;
            return;
        }
        printf("Out of Bounds!\n");
        return;
    }
    if (pos == 0) {
        node* ptr = malloc(sizeof(node));
        ptr->val = data;
        ptr->next = *head;
        *head = ptr;
        return;
    }
    node* ptr = *head;
    for (int i = 0; i < pos - 1; ++i) {
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("Out of Bounds!\n");
            return;
        }
    }
    node* temp = malloc(sizeof(node));
    temp->val = data;
    temp->next = ptr->next;
    ptr->next = temp;
    return;
}

void pop(node** head, int pos)
{
    if (!*head) {
        printf("List Empty!\n");
        return;
    }
    if (pos == 0) {
        node* ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
    node* ptr = *head;
    for (int i = 0; i < pos - 1; ++i) {
        ptr = ptr->next;
        if (ptr == NULL || ptr->next == NULL) {
            printf("Out of Bounds!\n");
            return;
        }
    }
    node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return;
}

void print(node** head)
{
    node* ptr = *head;
    while (ptr) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void print_reverse(node** head)
{
    if (*head == NULL)
        return;
    print_reverse(&(*head)->next);
    printf("%d ", (*head)->val);
}

void reverse(node** head)
{
    if (head == NULL)
        return;
    if ((*head)->next == NULL)
        return;
    node *ptr1 = *head, *ptr2 = (*head)->next, *ptr3 = (*head)->next->next;
    ptr1->next = NULL;
    while (ptr2) {
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
        if (ptr3)
            ptr3 = ptr3->next;
    }
    *head = ptr1;
    return;
}

int count(node** head)
{
    int count = 0;
    node* ptr = *head;
    while (ptr) {
        count += 1;
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    node* head = NULL;

    printf("=======Menu=======\n");
    printf("[1] Insert\n");
    printf("[2] Delete\n");
    printf("[3] Check size\n");
    printf("[4] Print List\n");
    printf("[5] Print reversed\n");
    printf("[6] Reverse List\n");
    printf("[7] Exit\n");

    int ch = -1, value, pos;

    while (ch) {
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter index to insert: ");
            scanf("%d", &pos);
            insert(&head, value, pos);
            break;
        case 2:
            printf("Enter index to delete: ");
            scanf("%d", &pos);
            pop(&head, pos);
            break;
        case 3:
            printf("%d\n", count(&head));
            break;
        case 4:
            print(&head);
            break;
        case 5:
            print_reverse(&head);
            printf("\n");
            break;
        case 6:
            reverse(&head);
            break;
        case 7:
            ch = 0;
            break;
        }
    }
}