/* Question 1:

Array-Based Stack
i. Check whether a given string is a palindrome using stack.
➤ Use character stack to compare original and reversed string.
ii. Check for matching parentheses in each expression.
➤ Push opening brackets, pop for matching closing brackets.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define pf printf
#define sf scanf
#define MAX_VAL 100
#define false 0
#define true 1

typedef int i;

char stack[MAX_VAL];
int top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAX_VAL - 1);
}

void push(char data)
{
    if (isFull())
    {
        pf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
}

char pop()
{
    if (isEmpty())
    {
        pf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

void peek()
{
    if (isEmpty())
    {
        pf("Stack is Empty!\n");
        return;
    }
    pf("Top element: %c\n", stack[top]);
}

void display()
{
    if (isEmpty())
    {
        pf("Stack is Empty!\n");
        return;
    }

    pf("Stack contents (bottom to top): ");
    for (int i = 0; i <= top; i++)
    {
        pf("%c ", stack[i]);
    }
    pf("\n");
}

void palindromeCheck()
{
    char str[MAX_VAL];
    char cleaned[MAX_VAL];
    int j = 0;

    pf("\nEnter a string to check palindrome: ");
    getchar(); // Clear newline from previous input
    fgets(str, MAX_VAL, stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    // Clean string - remove spaces and convert to lowercase
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            cleaned[j++] = tolower(str[i]);
        }
    }
    cleaned[j] = '\0';

    int len = strlen(cleaned);

    if (len == 0)
    {
        pf("Empty string!\n");
        return;
    }

    // Reset stack
    top = -1;

    // Push first half onto stack
    for (int i = 0; i < len / 2; i++)
    {
        push(cleaned[i]);
    }

    // Start comparing from second half
    int start = (len % 2 == 0) ? len / 2 : (len / 2) + 1;

    for (int i = start; i < len; i++)
    {
        if (isEmpty() || pop() != cleaned[i])
        {
            pf("'%s' is NOT a palindrome.\n", str);
            return;
        }
    }

    pf("'%s' is a palindrome!\n", str);
}

void checkParenthesis()
{
    char expr[MAX_VAL];

    pf("\nEnter an expression to check parentheses: ");
    getchar(); // Clear newline from previous input
    fgets(expr, MAX_VAL, stdin);

    // Remove newline character
    expr[strcspn(expr, "\n")] = '\0';

    int len = strlen(expr);

    if (len == 0)
    {
        pf("Empty expression!\n");
        return;
    }

    // Reset stack
    top = -1;

    for (int i = 0; i < len; i++)
    {
        char ch = expr[i];

        // Push opening brackets
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (isEmpty())
            {
                pf("Error: Unmatched closing bracket '%c' at position %d\n", ch, i + 1);
                return;
            }

            char topChar = pop();

            // Check if brackets match
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{'))
            {
                pf("Error: Mismatched brackets - found '%c' but expected matching bracket for '%c'\n", ch, topChar);
                return;
            }
        }
    }

    // Check if any opening brackets are left
    if (!isEmpty())
    {
        pf("Error: Unmatched opening bracket(s) found\n");
        return;
    }

    pf("All parentheses are properly matched!\n");
}

int main()
{
    int choice;
    char value;

    pf("----------- Stack Operations ------------- \n");

    while (1)
    {
        pf("\n=== MENU ===\n");
        pf("1. Push Element to Stack\n");
        pf("2. Pop Element from Stack\n");
        pf("3. Peek Element of Stack\n");
        pf("4. Display Stack\n");
        pf("5. Check Palindrome\n");
        pf("6. Check Matching Parentheses\n");
        pf("0. Exit Program\n");
        pf("Enter Your Choice: ");

        if (sf("%d", &choice) != 1)
        {
            pf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            pf("Enter character to push: ");
            getchar(); // Clear newline
            sf("%c", &value);
            push(value);
            pf("'%c' pushed to stack\n", value);
            break;

        case 2:
            if (!isEmpty())
            {
                char popped = pop();
                if (popped != '\0')
                {
                    pf("Popped element: %c\n", popped);
                }
            }
            else
            {
                pf("Stack is empty! Cannot pop.\n");
            }
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            palindromeCheck();
            break;

        case 6:
            checkParenthesis();
            break;

        case 0:
            pf("Exiting program...\n");
            exit(0);

        default:
            pf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}