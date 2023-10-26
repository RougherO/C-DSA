#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int getHeight(Node* head)
{
    if (head) {
        return head->height;
    }
    return 0;
}

int getBalance(Node* head)
{
    if (head) {
        return getHeight(head->left) - getHeight(head->right);
    }
    return 0;
}

Node* findMin(Node* head)
{
    while (head->left) {
        head = head->left;
    }
    return head;
}

Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rotateLeft(Node* head)
{
    Node* node = head->right;
    head->right = node->left;
    node->left = head;

    head->height = max(getHeight(head->left), getHeight(head->right)) + 1; /* Notice how we update head's height first */
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}

Node* rotateRight(Node* head)
{
    Node* node = head->left;
    head->left = node->right;
    node->right = head;

    head->height = max(getHeight(head->left), getHeight(head->right)) + 1;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}
/*
 * 1) Insert Value normally like you would in a binary tree
 *
 * 2) Update height of each node from bottom up, i.e., while coming back up
 *
 * 3) Get balance of each node from bottom up,
 *
 *    -> If balance is less than -1 or greater than 1 then the subtree is unbalanced
 *    -> Check balance :
 *          * left-left : Simply right rotate the current node
 *          * left-right : Left rotate the current node's left node, now its the left-left case
 *          * right-right : Simply left rotate the current node
 *          * right-left : Right rotate the current node's right node, now its right-right case
 *    -> If balance is between -1 and 1 then return the current node
 */
Node* insertNode(Node* head, int data)
{
    if (head) {
        if (data >= head->data) {
            head->right = insertNode(head->right, data);
        } else {
            head->left = insertNode(head->left, data);
        }
        head->height = max(getHeight(head->left), getHeight(head->right)) + 1;

        int balance = getBalance(head);
        if (balance > 1) { /* Left Heavy */
            if (getBalance(head->left) >= 0) { /* Left Left case */
                return rotateRight(head);
            } else { /* Left Right case */
                head->left = rotateLeft(head->left);
                return rotateRight(head);
            }
        } else if (balance < -1) { /* Right Heavy */
            if (getBalance(head->right) <= 0) { /* Right Right case */
                return rotateLeft(head);
            } else { /* Right Left case */
                head->right = rotateRight(head->right);
                return rotateLeft(head);
            }
        }
        /* Alternate implemetation
         *
         * if (balance > 1) {
         *    if (data >= head->left->data) { // Left Right case
         *        head->left = rotateLeft(head->left);
         *    }
         *    return rotateRight(head);
         * } else if (balance < -1) {
         *    if (data < head->left->data) { // Right Left case
         *        head->right = rotateRight(head->right);
         *    }
         *    return rotateLeft(head);
         * }
         *
         */
        return head;
    }
    return createNode(data);
}

/*
 * 1) Delete Value normally like you would in a binary tree
 *
 * 2) Update height of each node from bottom up, i.e., while coming back up
 *
 * 3) Get balance of each node from bottom up,
 *
 *    -> If balance is less than -1 or greater than 1 then the subtree is unbalanced
 *    -> Check balance :
 *          * left-left : Simply right rotate the current node
 *          * left-right : Left rotate the current node's left node, now its the left-left case
 *          * right-right : Simply left rotate the current node
 *          * right-left : Right rotate the current node's right node, now its right-right case
 *    -> If balance is between -1 and 1 then return the current node
 */
Node* deleteNode(Node* head, int data)
{
    if (head) {
        if (data < head->data) {
            head->left = deleteNode(head->left, data);
        } else if (data == head->data) {
            if (head->left == NULL && head->right == NULL) {
                free(head);
                return NULL;
            }
            if (head->left == NULL) {
                Node* node = head->right;
                free(head);
                return node;
            }
            if (head->right == NULL) {
                Node* node = head->left;
                free(head);
                return node;
            }

            Node* node = findMin(head->right);
            head->data = node->data;
            head->right = deleteNode(head->right, node->data);
        } else {
            head->right = deleteNode(head->right, data);
        }

        head->height = max(getHeight(head->left), getHeight(head->right)) + 1;

        int balance = getBalance(head);
        if (balance > 1) { /* Left Heavy */
            if (getBalance(head->left) >= 0) { /* Left Left case */
                return rotateRight(head);
            } else { /* Left Right case */
                head->left = rotateLeft(head->left);
                return rotateRight(head);
            }
        } else if (balance < -1) { /* Right Heavy */
            if (getBalance(head->right) <= 0) { /* Right Right case */
                return rotateLeft(head);
            } else { /* Right Left case */
                head->right = rotateRight(head->right);
                return rotateLeft(head);
            }
        }
        return head;
    }
    return NULL;
}

void prettyPrintTree(struct Node* root, int space)
{
    if (root == NULL)
        return;

    prettyPrintTree(root->right, space + 5);

    printf("\n");
    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    prettyPrintTree(root->left, space + 5);
}

void deleteTree(Node* head)
{
    if (!head)
        return;
    deleteTree(head->left);
    deleteTree(head->right);
    free(head);
}

int main()
{
    Node* head = NULL;
    int ch = 0;

    printf("========= Menu =========\n");
    printf("1. Enter Key\n");
    printf("2. Delete Key\n");
    printf("3. Print Tree\n");
    printf("4. Exit\n");

    int data;
    while (ch != 4) {
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter key value: ");
            scanf("%d", &data);
            head = insertNode(head, data);
            break;
        case 2:
            printf("Enter key value: ");
            scanf("%d", &data);
            head = deleteNode(head, data);
            break;
        case 3:
            prettyPrintTree(head, 0);
            break;
        }
    }
    deleteTree(head);
}