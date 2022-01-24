#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 50
int top = -1;

bool isEmpty()
{
    return top == -1 ? true : false;
}

bool isFull()
{
    return top == SIZE - 1 ? true : false;
}

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *stck[SIZE];

Node *create(Node *hptr)
{
    int x = 0;
    Node *nptr = NULL, *tail = NULL;
    printf("Enter data and -1 to exit\n");
    scanf("%d", &x);
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

void push(struct node *tmp)
{
    if (!isFull())
    {
        stck[++top] = tmp;
        return;
    }
    printf("Stack Overflow\n");
    return;
}

Node *pop()
{
    return stck[top--];
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
    // display(hptr);
    Node *temp = hptr, *prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        push(temp);
        temp = temp->next;
    }
    // printf("%d\n",prev->data);
    prev = pop();
    hptr = prev;
    // printf("%d\n",prev->data);
    while (!isEmpty())
    {
        prev->next = pop();
        prev = prev->next;
    }
    prev->next = NULL;
    printf("Linked List After reverse\n");
    display(hptr);
    free_list(hptr);
    return 0;
}