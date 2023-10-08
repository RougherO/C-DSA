#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int val)
{
    Node* temp = malloc(sizeof(Node));
    temp->val = val;
    temp->left = NULL;
    temp->left = NULL;
    return temp;
}

Node* buildTree(int* InOrder, int* PreOrder, int inStart, int inEnd, int preStart, int preEnd)
{
    if (inStart == inEnd) {
        return NULL;
    }
    int index = inStart;
    while (InOrder[index] != PreOrder[preStart])
        ++index;
    int l_size = index - inStart;
    int r_size = inEnd - (index + 1);
    Node* root = createNode(PreOrder[preStart]);
    root->left = buildTree(InOrder, PreOrder, inStart, index, preStart + 1, preEnd - r_size);
    root->right = buildTree(InOrder, PreOrder, index + 1, inEnd, preEnd - r_size, preEnd);
    return root;
}

void PostOrder(Node* head)
{
    if (head) {
        PostOrder(head->left);
        PostOrder(head->right);
        printf("%d ", head->val);
    }
}

int main()
{
    int InOrder[100], PreOrder[100];
    int size;

    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter all %d elements for inorder: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", InOrder + i);
    }

    printf("Enter all %d elements for preorder: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", PreOrder + i);
    }

    Node* head = buildTree(InOrder, PreOrder, 0, size, 0, size);
    PostOrder(head);
}