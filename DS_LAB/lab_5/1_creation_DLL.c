#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

// Function to create a new node
Node *createNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert an element at the rear end of the list (Append)
void insert_at_end(int data)
{
    Node *newNode = createNewNode(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // Fixed: was temp->next = newNode
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// 2. Delete an element from the rear end of the list
void delete_from_end()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) // Only one node
    {
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// 3. Insert an element at a given position (position starts from 1)
void insert_at_position(int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position! Position should start from 1.\n");
        return;
    }

    Node *newNode = createNewNode(data);

    if (position == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// 4. Delete an element from a given position
void delete_from_position(int position)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position! Position should start from 1.\n");
        return;
    }

    Node *temp = head;

    if (position == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// 5. Insert an element after a node containing a specific value
void insert_after_value(int data, int value)
{
    Node *temp = head;

    while (temp != NULL && temp->val != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list!\n", value);
        return;
    }

    Node *newNode = createNewNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// 6. Insert an element before a node containing a specific value
void insert_before_value(int data, int value)
{
    Node *temp = head;

    while (temp != NULL && temp->val != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list!\n", value);
        return;
    }

    Node *newNode = createNewNode(data);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode; // New node becomes head

    temp->prev = newNode;
}

// 7. Traverse the list in forward direction
void display_DLL_FWD()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    printf("Forward Traversal: ");

    while (temp != NULL)
    {
        printf("%d", temp->val);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next; // Fixed: was missing this line
    }

    printf(" -> NULL\n");
}

// 8. Traverse the list in reverse direction
void display_DLL_BWD()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;

    // Go to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Reverse Traversal: ");

    // Traverse backwards
    while (temp != NULL)
    {
        printf("%d", temp->val);
        if (temp->prev != NULL)
            printf(" -> ");
        temp = temp->prev;
    }

    printf(" -> NULL\n");
}

// Insert at beginning (fixing your incomplete function)
void insert_at_beginning(int data)
{
    Node *newNode = createNewNode(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Helper function to count nodes
int count_nodes()
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

int main()
{
    int choice, data, position, value;

    while (1)
    {
        printf("\n=== Doubly Linked List Operations ===\n");
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
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insert_at_beginning(data);
            break;

        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position (starting from 1): ");
            scanf("%d", &position);
            insert_at_position(data, position);
            break;

        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter value after which to insert: ");
            scanf("%d", &value);
            insert_after_value(data, value);
            break;

        case 5:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter value before which to insert: ");
            scanf("%d", &value);
            insert_before_value(data, value);
            break;

        case 6:
            delete_from_end();
            printf("Deleted from end\n");
            break;

        case 7:
            printf("Enter position to delete (starting from 1): ");
            scanf("%d", &position);
            delete_from_position(position);
            break;

        case 8:
            display_DLL_FWD();
            break;

        case 9:
            display_DLL_BWD();
            break;

        case 10:
            printf("Number of nodes: %d\n", count_nodes());
            break;

        case 0:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}