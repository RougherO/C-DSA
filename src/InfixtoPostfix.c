#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top, char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top)
{
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(1);
    }
    Node* temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*')
        return 2;
    if (op == '/')
        return 3;
    return 0;
}

void infixToPostfix(char* infix)
{
    Node* stack = NULL;
    char postfix[100];
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isspace(infix[i])) {
            i++;
        } else if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (isOperator(infix[i])) {
            while (stack != NULL && precedence(stack->data) > precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (stack->data != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
            i++;
        }
    }
    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%[^\n]s", infix);
    infixToPostfix(infix);
    return 0;
}