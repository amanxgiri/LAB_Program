#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insertNode(node *root, int val)
{

    if (root == NULL)
    {
        root = createNode(val);
    }
    else if (val <= root->data)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }

    return root;
}

int main()
{

    return 0;
}
