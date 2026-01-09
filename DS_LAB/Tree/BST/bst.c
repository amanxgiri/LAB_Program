

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// write insert function with iterative approach
node *insertNode(node *root, int data)
{
    // if tree is empty
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    // if tree is not empty
    else if (root->data >= data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int search(node *root, int data)
{
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int findMinRecursive(node *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty!");
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

int findMaxRecursive(node *root)
{

    if (root == NULL)
    {
        printf("Error: Tree is empty!");
        return -1;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

int findHeight(node *root)
{

    if (root == NULL)
        return -1;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void printTree(node *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d  ", root->data);
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int val, choice;

    node *root = NULL; // creating an empty tree
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 8);
    root = insertNode(root, 12);

    int num;
    printf("Enter A Number to search : ");
    scanf("%d", &num);
    if (search(root, num))
        printf("Number Found. \n\n");
    else
        printf("Number not found. \n\n");

    printTree(root);

    printf("\nMax Number : %d \n", findMaxRecursive(root));

    printf("Height Of Tree: %d \n", findHeight(root));

    return 0;
}