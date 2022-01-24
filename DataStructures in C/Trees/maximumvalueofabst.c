#include <stdio.h>
#include <stdlib.h>
struct node *root = NULL;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
int maximum(struct node *node)
{
   struct node *temp = node, *prev = NULL;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp->right;
    }
    return prev->data;
}
int main()
{
    int x, cnt = 0;
    printf("Enter data and -1 to exit\n");
    scanf("%d", &x);
    if (x != -1)
    {
        do
        {
            if (root == NULL)
                root = insert(root, x);
            else
                insert(root, x);
            scanf("%d", &x);
            cnt += 1;
        } while (x != -1);
    }
    else
    {
        printf("List is Empty");
        return 0;
    }
    printf("The maximum value in a Binary Search Tree: %d",maximum(root));
} 