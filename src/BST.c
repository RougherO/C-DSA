#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} Node;

void printTree(Node* head)
{
    if (head) {
        if (head->left)
            printTree(head->left);
        printf("%d ", head->val);
        if (head->right)
            printTree(head->right);
        return;
    }
    printf("Empty Tree\n");
}

Node* createKey(int data)
{
    Node* node = malloc(sizeof(Node));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* pushKey(Node* head, int data)
{
    if (head) {
        if (data < head->val) {
            head->left = pushKey(head->left, data);
            return head;
        }
        head->right = pushKey(head->right, data);
        return head;
    }
    return createKey(data);
}

Node* findMax(Node* head)
{
    if (!head)
        return NULL;
    while (head->right) {
        head = head->right;
    }
    return head;
}

Node* findMin(Node* head)
{
    if (!head)
        return NULL;
    while (head->left) {
        head = head->left;
    }
    return head;
}

Node* searchKey(Node* head, int data)
{
    while (head && head->val != data) {
        if (data < head->val) {
            head = head->left;
        }
        if (data > head->val) {
            head = head->right;
        }
    }
    return head;
}

Node* findInorderPredecessor(Node* head, int data)
{
    Node* pred = NULL;
    while (head && head->val != data) {
        if (data < head->val) {
            pred = head;
            head = head->left;
        } else if (data > head->val) {
            head = head->right;
        }
    }
    if (head) {
        Node* temp = findMax(head->left);
        pred = temp ? temp : pred;
    }
    return pred;
}

Node* findInorderSuccessor(Node* head, int data)
{
    Node* succ = NULL;
    while (head && head->val != data) {
        if (data < head->val) {
            head = head->left;
        } else if (data > head->val) {
            succ = head;
            head = head->right;
        }
    }
    if (head) {
        Node* temp = findMin(head->right);
        succ = temp ? temp : succ;
    }
    return succ;
}

Node* popKey(Node* head, int data, int* key_found)
{
    if (head) {
        if (data < head->val) {
            head->left = popKey(head->left, data, key_found);
            return head;
        }
        if (data > head->val) {
            head->right = popKey(head->right, data, key_found);
            return head;
        }
        if (!head->left && !head->right) {
            free(head);
            return NULL;
        }
        if (!head->left) {
            Node* temp = head->right;
            free(head);
            return temp;
        }
        if (!head->right) {
            Node* temp = head->left;
            free(head);
            return temp;
        }
        head->val = findMax(head->left)->val;
        head->left = popKey(head->left, head->val, key_found);
        return head;
    }
    *key_found = 0;
    return NULL;
}

Node* deleteTree(Node* head)
{
    if (head) {
        head->left = deleteTree(head->left);
        head->right = deleteTree(head->right);
        free(head);
    }
    return NULL;
}

int main()
{
    Node* head = NULL;

    char ch = 0;
    printf("======= Menu =======\n");
    printf("1. Insert a Key\n");
    printf("2. Search a Key\n");
    printf("3. Delete a Key\n");
    printf("4. Find InOrder Successor of a Key\n");
    printf("5. Find InOrder Predecessor of a Key\n");
    printf("6. Print Tree\n");
    printf("7. Exit\n");
    while (ch != 7) {
        printf("Enter your choice: ");
        scanf("%hi", &ch);

        int data, key_found;
        Node* temp;
        switch (ch) {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &data);
            head = pushKey(head, data);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &data);
            searchKey(head, data) ? printf("Key Found!\n") : printf("Key Not Found\n");
            break;
        case 3:
            printf("Enter key to delete : ");
            scanf("%d", &data);
            popKey(head, data, &key_found);
            key_found ? printf("Key deleted\n") : printf("Key Not Found\n");
            break;
        case 4:
            printf("Enter key to search predecessor: ");
            scanf("%d", &data);
            temp = findInorderPredecessor(head, data);
            temp ? printf("%d is the inorder predecessor\n", temp->val) : printf("Predecessor Not Found\n");
            break;
        case 5:
            printf("Enter key to search successor: ");
            scanf("%d", &data);
            temp = findInorderSuccessor(head, data);
            temp ? printf("%d is the Inorder successor\n", temp->val) : printf("Successor Not Found\n");
            break;
        case 6:
            printTree(head);
            printf("\n");
            break;
        default:
            break;
        }
    }
    deleteTree(head);
}