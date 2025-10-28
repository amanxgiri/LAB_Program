#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2B_evalPost.c"

typedef struct node
{
    char c;
    struct node *next;
} node;

node *stack = NULL;

void push(char c)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->c = c;
    newNode->next = NULL;
    if (stack == NULL)
    {
        stack = newNode;
    }
    else
    {
        newNode->next = stack;
        stack = newNode;
    }
}

int isEmpty()
{
    if (stack == NULL)
    {
        return 1;
    }
    return 0;
}

char pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack is Empty.");
        exit(0);
    }
    node *temp = stack;
    char top = temp->c;
    stack = stack->next;
    free(temp);
    return top;
}

int isOperator(char c)
{
    if (c == '+' || c == '/' || c == '*' || c == '-' || c == '^')
    {
        return 1;
    }
    return 0;
}

char peek()
{
    if (isEmpty() == 1)
    {
        printf("Stack is Empty.");
        exit(0);
    }
    return stack->c;
}

int checkPriority(char c)
{
    if (c == '^')
    {
        return 2;
    }
    if (c == '*' || c == '/')
    {
        return 1;
    }
    if (c == '+' || c == '-')
    {
        return 0;
    }
    exit(1);
}

void infixToPostfix(char *str)
{
    for (char *c = str; *c != '\0'; c++)
    {
        if (*c == '(')
        {
            push(*c);
        }
        else if (isOperator(*c) == 1)
        {
            while (isEmpty() != 1 && peek() != '(' && checkPriority(*c) < checkPriority(peek()))
            {
                printf("%c", pop());
            }
            if (checkPriority(*c) != 2)
            {
                while (isEmpty() != 1 && peek() != '(' && checkPriority(*c) == checkPriority(peek()))
                {
                    printf("%c", pop());
                }
            }
            push(*c);
        }
        else if (*c == ')')
        {
            while (peek() != '(')
            {
                printf("%c", pop());
            }
            pop();
        }
        else
        {
            printf("%c", *c);
        }
    }
    while (isEmpty() != 1)
    {
        printf("%c", pop());
    }
}

int main()
{
    char str[100];
    gets(str);
    evaluatePostfix(str);
}
