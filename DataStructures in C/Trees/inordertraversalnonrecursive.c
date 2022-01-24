#include <stdio.h>
#include <stdlib.h>
struct node *root = NULL;
int max = 0, top = -1;
struct node *stack[20];
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void push(struct node *x)
{
    stack[++top] = x;
}
struct node * pop()
{
    return stack[top--];
}
struct node *peek()
{
    return (stack[top]);
}
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
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
void Max(struct node *root)
{
    if (root == NULL)
        return;
    if (max < root->data)
        max = root->data;
    Max(root->left);
    Max(root->right);
}
void non_inorder(struct node *root)
{
    do
    {
        while (root != NULL)
        {
            push(root);
            root = root->left;
        }
        if (!isempty())
        {
            root = peek();
            printf("%d ", root->data);
            pop();
            root = root->right;
        }
    } while (root != NULL || !isempty());
}

void non_perorder(struct node *root)
{
    do
    {

        while (root != NULL)
        {
            printf("%d ", root->data);

            push(root);
            root = root->left;
        }
        if (!isempty())
        {
            root = peek();
            pop();
            root = root->right;
        }
    } while (root != NULL || !isempty());
}
void non_postorder(struct node *root)
{
    do
    { 
        while (root) 
        { 
            if (root->right) 
                push( root->right); 
            push( root); 
  
            root = root->left; 
        } 
  
        root = pop(); 
  
        if (root->right && peek() == root->right) 
        { 
            pop();  
            push( root);  
            root = root->right; 
                                
        } 
        else  
        { 
            printf("%d ", root->data); 
            root = NULL; 
        } 
    } while (!isempty()); 
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
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
    if (cnt == 0)
    {
        printf("List is Empty");
    }
    else
    {
        printf("Inorder Traversal (Non-Recursive): ");
        non_inorder(root);
    }
}