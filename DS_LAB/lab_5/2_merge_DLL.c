#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

// Function to create a new node
Node *createNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->val = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end of a specific list
void insert_at_end(Node **head, int data)
{
    Node *newNode = createNewNode(data);
    if (newNode == NULL)
        return;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Display list in forward direction
void display_DLL_FWD(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    printf("List: ");

    while (temp != NULL)
    {
        printf("%d", temp->val);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Function to concatenate two doubly linked lists
// X1 will point to the first node of the resulting list
void concatenate_DLL(Node **X1, Node **X2)
{
    // If X1 is empty, X1 becomes X2
    if (*X1 == NULL)
    {
        *X1 = *X2;
        *X2 = NULL; // X2 becomes empty
        return;
    }

    // If X2 is empty, nothing to concatenate
    if (*X2 == NULL)
    {
        return;
    }

    // Find the last node of X1
    Node *temp = *X1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect the last node of X1 to the first node of X2
    temp->next = *X2;
    (*X2)->prev = temp;

    // X2 becomes NULL as all its nodes are now part of X1
    *X2 = NULL;

    printf("Lists concatenated successfully!\n");
}

// Function to count nodes in a list
int count_nodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to create a list by taking input from user
void create_list(Node **head, int list_num)
{
    int n, data;
    printf("Enter number of elements for List %d: ", list_num);
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of elements!\n");
        return;
    }

    printf("Enter %d elements for List %d:\n", n, list_num);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &data);
        insert_at_end(head, data);
    }
}

// Function to free memory of entire list
void free_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    Node *X1 = NULL; // First doubly linked list
    Node *X2 = NULL; // Second doubly linked list
    int choice, data;

    while (1)
    {
        printf("\n=== Doubly Linked List Concatenation ===\n");
        printf("1. Create List X1\n");
        printf("2. Create List X2\n");
        printf("3. Add element to X1\n");
        printf("4. Add element to X2\n");
        printf("5. Display List X1\n");
        printf("6. Display List X2\n");
        printf("7. Concatenate X2 to X1\n");
        printf("8. Count nodes in X1\n");
        printf("9. Count nodes in X2\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (X1 != NULL)
            {
                free_list(X1);
                X1 = NULL;
            }
            create_list(&X1, 1);
            break;

        case 2:
            if (X2 != NULL)
            {
                free_list(X2);
                X2 = NULL;
            }
            create_list(&X2, 2);
            break;

        case 3:
            printf("Enter data to add to X1: ");
            scanf("%d", &data);
            insert_at_end(&X1, data);
            break;

        case 4:
            printf("Enter data to add to X2: ");
            scanf("%d", &data);
            insert_at_end(&X2, data);
            break;

        case 5:
            printf("List X1: ");
            display_DLL_FWD(X1);
            break;

        case 6:
            printf("List X2: ");
            display_DLL_FWD(X2);
            break;

        case 7:
            printf("Before concatenation:\n");
            printf("X1: ");
            display_DLL_FWD(X1);
            printf("X2: ");
            display_DLL_FWD(X2);

            concatenate_DLL(&X1, &X2);

            printf("\nAfter concatenation:\n");
            printf("X1 (concatenated list): ");
            display_DLL_FWD(X1);
            printf("X2: ");
            display_DLL_FWD(X2);
            break;

        case 8:
            printf("Number of nodes in X1: %d\n", count_nodes(X1));
            break;

        case 9:
            printf("Number of nodes in X2: %d\n", count_nodes(X2));
            break;

        case 0:
            printf("Freeing memory and exiting...\n");
            free_list(X1);
            free_list(X2);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}