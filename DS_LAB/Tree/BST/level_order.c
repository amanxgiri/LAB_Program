
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insertNode(node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else if (data <= root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

int main()
{
    node *root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
}