#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Global pointers for Circular Singly Linked List
Node *first = NULL;
Node *last = NULL;

// Function to create a new node
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of the circular list
void insertAtEnd(int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL)
        return;

    // If list is empty
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
        newNode->next = first; // Point to itself to make it circular
        printf("Element %d inserted as first element.\n", value);
    }
    else
    {
        // Insert at end
        last->next = newNode;
        newNode->next = first; // Make it circular
        last = newNode;        // Update last pointer
        printf("Element %d inserted at end.\n", value);
    }
}

// Function to delete from the beginning
void deleteFromBeginning()
{
    if (first == NULL)
    {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    // If only one node
    if (first == last)
    {
        printf("Element %d deleted from beginning.\n", first->data);
        free(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        Node *temp = first;
        printf("Element %d deleted from beginning.\n", first->data);

        // Update first pointer
        first = first->next;

        // Update last's next pointer to maintain circular nature
        last->next = first;

        free(temp);
    }
}

// Function to delete from the end
void deleteFromEnd()
{
    if (first == NULL)
    {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    // If only one node
    if (first == last)
    {
        printf("Element %d deleted from end.\n", last->data);
        free(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        Node *temp = first;

        // Find the second last node
        while (temp->next != last)
        {
            temp = temp->next;
        }

        printf("Element %d deleted from end.\n", last->data);

        // Update connections
        temp->next = first; // Maintain circular nature
        free(last);
        last = temp; // Update last pointer
    }
}

// Function to display the circular list
void displayList()
{
    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *temp = first;
    printf("Circular List: ");

    do
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != first)
            printf(" -> ");
    } while (temp != first);

    printf(" -> (back to %d)\n", first->data);
    printf("First: %d, Last: %d\n", first->data, last->data);
}

// Function to count nodes in the list
int countNodes()
{
    if (first == NULL)
        return 0;

    int count = 1;
    Node *temp = first->next;

    while (temp != first)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to free all memory (for cleanup)
void freeList()
{
    if (first == NULL)
        return;

    Node *current = first;
    Node *next;

    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != first);

    first = NULL;
    last = NULL;
}

// Main function with menu-driven interface
int main()
{
    int choice, value;

    printf("=== Circular Singly Linked List Implementation ===\n");
    printf("Using First and Last pointers\n\n");

    while (1)
    {
        printf("\n=== Menu ===\n");
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Display list\n");
        printf("5. Count nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at end: ");
            if (scanf("%d", &value) == 1)
            {
                insertAtEnd(value);
                displayList();
            }
            else
            {
                printf("Invalid input!\n");
                while (getchar() != '\n')
                    ;
            }
            break;

        case 2:
            deleteFromBeginning();
            displayList();
            break;

        case 3:
            deleteFromEnd();
            displayList();
            break;

        case 4:
            displayList();
            break;

        case 5:
            printf("Number of nodes: %d\n", countNodes());
            break;

        case 6:
            printf("Freeing memory and exiting...\n");
            freeList();
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
