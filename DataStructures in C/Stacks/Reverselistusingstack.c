#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *top = NULL;

Node *create(Node *hptr)
{
    int x = 0;
    Node *nptr = NULL, *tail = NULL;
    printf("Enter data and -1 to exit\n");
    scanf("%d",&x);
    while (x != -1)
    {
        nptr = malloc(sizeof(Node));
        nptr->data = x;
        nptr->next = NULL;
        if (hptr == NULL)
        {
            hptr = nptr;
            tail = nptr;
        }
        else
        {
            tail->next = nptr;
            tail = nptr;
        }
        scanf("%d", &x);
    }
    return hptr;
}

void free_list(Node *hptr)
{
    Node *temp = hptr, *prev = NULL;
    int c = 0;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
        c++;
    }
    printf("Nodes Freed: %d\n", c);
}

void display(Node *hptr)
{
    for (Node *temp = hptr; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}

void push(Node *ptr)
{
    if (top == NULL)
    {
        top = malloc(sizeof(Node));
        *top = *ptr;
        top->next = NULL;
    }
    else
    {
        Node *nptr = malloc(sizeof(Node));
        *nptr = *ptr;
        nptr->next = top;
        top = nptr;
        
    }
}

int main(void)
{
    Node *hptr = NULL;
    hptr = create(hptr);
    if (hptr == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    Node *temp = hptr;
    while (temp != NULL)
    {
       push(temp);
       temp = temp->next;
    } 
    free_list(hptr);
    hptr = top;
    printf("Linked List After reverse\n");
    display(hptr);
    // free_list(top);
    return 0;
}