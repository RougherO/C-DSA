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

int evaluate(char a, char b, char ch)
{
    switch (ch) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        break;
    }
}

void evalPostfix(char* postfix)
{
    Node* stack = NULL;
    char eval;
    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {
            i++;
        } else if (isdigit(postfix[i]) || isalpha(postfix[i])) {
            push(&stack, postfix[i++] - '0');
        } else if (isOperator(postfix[i])) {
            char b = pop(&stack);
            char a = pop(&stack);
            char c = evaluate(a, b, postfix[i++]);
            push(&stack, c);
        }
    }
    eval = pop(&stack);
    printf("Postfix evaluation: %d\n", eval);
}

int main()
{
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%[^\n]s", postfix);
    evalPostfix(postfix);
    return 0;
}