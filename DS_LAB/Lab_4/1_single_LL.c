#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

node *insertBefore(node *head, int target, int value)
{
    node *newNode = createNode(value);
    if (newNode == NULL)
        return head;

    if (head == NULL)
    {
        printf("List is empty! Inserting %d as the first element.\n", value);
        return newNode;
    }

    if (head->val == target)
    {
        newNode->next = head;
        return newNode;
    }

    node *current = head;
    while (current->next != NULL && current->next->val != target)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Target element %d not found!\n", target);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

node *insertAfter(node *head, int target, int value)
{
    if (head == NULL)
    {
        printf("List is empty! Inserting %d as the first element.\n", value);
        node *newNode = createNode(value);
        return newNode;
    }

    node *current = head;
    while (current != NULL && current->val != target)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Target element %d not found!\n", target);
        return head;
    }

    node *newNode = createNode(value);
    if (newNode == NULL)
        return head;

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

node *deleteElement(node *head, int value)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return head;
    }

    if (head->val == value)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted successfully!\n", value);
        return head;
    }

    node *current = head;
    while (current->next != NULL && current->next->val != value)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Element %d not found!\n", value);
        return head;
    }

    node *temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Element %d deleted successfully!\n", value);
    return head;
}

void displayList(node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("\n");
}

node *reverseList(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

node *sortList(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int swapped;
    node *current;
    node *last = NULL;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != last)
        {
            if (current->val > current->next->val)
            {
                int temp = current->val;
                current->val = current->next->val;
                current->next->val = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    return head;
}

node *deleteAlternate(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *current = head;
    while (current != NULL && current->next != NULL)
    {
        node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        free(nodeToDelete);
        current = current->next;
    }

    return head;
}

node *insertSorted(node *head, int value)
{
    node *newNode = createNode(value);
    if (newNode == NULL)
        return head;

    if (head == NULL || head->val >= value)
    {
        newNode->next = head;
        return newNode;
    }

    node *current = head;
    while (current->next != NULL && current->next->val < value)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void freeList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    node *head = NULL;
    int choice, value, target;

    while (1)
    {
        printf("\n=== Linked List Operations Menu ===\n");
        printf("1. Insert before specified element\n");
        printf("2. Insert after specified element\n");
        printf("3. Delete specified element\n");
        printf("4. Display list\n");
        printf("5. Reverse list\n");
        printf("6. Sort list (ascending)\n");
        printf("7. Delete alternate nodes\n");
        printf("8. Insert into sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter target element to insert before: ");
            scanf("%d", &target);
            head = insertBefore(head, target, value);
            displayList(head);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter target element to insert after: ");
            scanf("%d", &target);
            head = insertAfter(head, target, value);
            printf("List after Insertion: \n");
            displayList(head);
            break;

        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &value);
            head = deleteElement(head, value);
            printf("List after Deletion: \n");
            displayList(head);
            break;

        case 4:
            displayList(head);
            break;

        case 5:
            head = reverseList(head);
            printf("List reversed successfully!\n");
            printf("Reversed List: \n");
            displayList(head);
            break;

        case 6:
            head = sortList(head);
            printf("List sorted successfully!\n");
            printf("Sorted List: \n");
            displayList(head);
            break;

        case 7:
            head = deleteAlternate(head);
            printf("Alternate nodes deleted successfully!\n");
            printf("List after Deletion of Alternate List  \n");
            displayList(head);
            break;

        case 8:
            printf("Enter value to insert into sorted list: ");
            scanf("%d", &value);
            head = insertSorted(head, value);
            printf("Element inserted into sorted position!\n");
            break;

        case 9:
            freeList(head);
            printf("Exiting program. Memory freed.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}