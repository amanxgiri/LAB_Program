#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;

} Node;

Node *head = NULL;

void insert_at_beginning(int data)
{

    Node *newNode = createNewNode(data);
}

int main()
{
    int choice, data, val, pos;

    while (1)
    {
        printf("\n ---------------------------------------\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Insert after value\n");
        printf("5. Insert before value\n");
        printf("6. Delete from end\n");
        printf("7. Delete from position\n");
        printf("8. Display forward\n");
        printf("9. Display reverse\n");
        printf("10. Count nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at Beginning: ");
            scanf("%d", &data);
            break;

        default:
            break;
        }
    }

    return 0;
}