#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} Node;

Node* buildTree(Node* node)
{
    int data;
    printf("Enter left value of %d: ", node->val);
    scanf("%d", data);
    if (data == 'N') {
        node->left = NULL;
    } else {
        node->left = malloc(sizeof(Node));
        node->left->val = data;
    }
    printf("Enter right value of %d: ", node->val);
    scanf("%d", data);
    if (data == 'N') {
        node->right = NULL;
    } else {
        node->right = malloc(sizeof(Node));
        node->right->val = data;
    }
    if (node->left)
        buildTree(node->left);
    if (node->right)
        buildTree(node->right);
}

void InOrder(Node* node)
{
    if (node) {
        if (node->left)
            InOrder(node->left);
        printf("%d ", node->val);
        if (node->right)
            InOrder(node->right);
        return;
    }
    printf("Tree is empty\n");
}

void PreOrder(Node* node)
{
    if (node) {
        printf("%d ", node->val);
        if (node->left)
            PreOrder(node->left);
        if (node->right)
            PreOrder(node->right);
        return;
    }
    printf("Tree is empty\n");
}

void PostOrder(Node* node)
{
    if (node) {
        if (node->left)
            PostOrder(node->left);
        if (node->right)
            PostOrder(node->right);
        printf("%d ", node->val);
        return;
    }
    printf("Tree is empty\n");
}

void deleteTree(Node** node)
{
    if (*node) {
        if ((*node)->left) {
            deleteTree(&(*node)->left);
            (*node)->left = NULL;
        }
        if ((*node)->right) {
            deleteTree(&(*node)->right);
            (*node)->right = NULL;
        }
        free(*node);
        *node = NULL;
        return;
    }
    printf("Tree is empty\n");
}

int main()
{
    Node* head = malloc(sizeof(Node));
    printf("Enter value of root Node");
    scanf("%d", &head->val);
    buildTree(head);

    printf("======== Menu ========\n");
    printf("1. InOrder Traversal\n");
    printf("2. PreOrder Traversal\n");
    printf("3. PostOrder Traversal\n");
    printf("4. Exit");

    char ch = 0;
    while (ch != '4') {
        printf("Enter choice\n");
        scanf("%c", &ch);
        switch (ch) {
        case '1':
            InOrder(head);
            break;
        case '2':
            PreOrder(head);
            break;
        case '3':
            PostOrder(head);
            break;
        }
        if (ch == '4')
            break;
    }
    deleteTree(&head);
}