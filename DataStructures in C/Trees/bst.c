#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left, *right;
}Node;

Node *newnode(int data)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node *insert(Node *n, int data)
{
    if(n == NULL)
    {
        return newnode(data);
    }
    else if(data < n->data)
    {
        n->left = insert(n->left,data);
    }
    else
    {
        n->right = insert(n->right, data);
    }
    return n;
}

Node *create(Node *root)
{
    int x = 0;
    printf("Enter data and -1 to exit\n");
    scanf("%d",&x);
    while (x != -1)
    {
        Node *n = newnode(x);
        root = insert(root, x);
        scanf("%d",&x);
    }
    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int count(Node *root)
{
    int c = 1;
    if (root->left != NULL )
    {   
        c += count(root->left);
    }
    if (root->right != NULL )
    {   
        c += count(root->right);
    }
    return c;
}

int leaf(Node *root)
{
    int count = 0;
    if (root->left == NULL && root->right == NULL) {
        count = 1;
    }
    else {
        if (root->left != NULL) {
            count += leaf(root->left);
        }
        if (root->right != NULL) {
            count += leaf(root->right);
        }
    }
    return count;
}

int main()
{
    Node *root =  NULL;
    root = create(root);
    // printf("Inorder: ");
    // inorder(root);
    // printf("\nPostorder: ");
    // postorder(root);
    // printf("\nPreorder: ");
    // preorder(root);
    if (root != NULL)
    {
        printf("Total Nodes :%d",count(root));
        printf("\nTotal Leaf Nodes :%d",leaf(root));
    }
    else
    {
        printf("Total Nodes :%d",0);
        printf("\nTotal Leaf Nodes :%d",0);
    }
    return 0;
}