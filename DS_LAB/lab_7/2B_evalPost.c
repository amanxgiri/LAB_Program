#include <stdio.h>

void evaluatePostfix(char *str)
{
    for (char *c = str; *c != '\0'; c++)
    {
        if (isOperator(*c) != 1)
        {
            push(*c);
        }
        else
        {
            int b = pop() - '0';
            int a = pop() - '0';
            if (*c == '+')
            {
                push(a + b + '0');
            }
            else if (*c == '/')
            {
                push(a / b + '0');
            }
            else if (*c == '*')
            {
                push(a * b + '0');
            }
            else
            {
                push(a - b + '0');
            }
        }
    }
    printf("The result is: %d", pop() - '0');
}
