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
unsigned int getLeafCount(struct node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left) +
               getLeafCount(node->right);
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}
int findHeight(struct node *temp)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = 0, rightHeight = 0;

        if (temp->left != NULL)
            leftHeight = findHeight(temp->left);

        if (temp->right != NULL)
            rightHeight = findHeight(temp->right);

        int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;

        return (max + 1);
    }
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
    if( findHeight(root)!=0)
    printf("The Height of a tree is: %d", findHeight(root)-1);
    else
    printf("The Height of a tree is: %d", findHeight(root));
}