#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(node *head)
{
    node *newptr, *tail;
    int x = 0;
    printf("Enter data and -1 to exit\n");
    while (1)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            newptr = (node *)malloc(sizeof(node));
            newptr->data = x;
            newptr->next = NULL;
            if (head == NULL)
            {
                head = newptr;
                tail = newptr;
            }
            else
            {
                tail->next = newptr;
                tail = newptr;
            }
        }
        else
        {
            break;
        }
    }
    return head;
}

void free_list(node *hptr)
{
    node *temp = hptr, *prev = NULL;
    int c = 0;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
        c++;
        printf("Nodes Freed: %d\n", c);
    }
}

void display(node *hptr)
{
    for (node *temp = hptr; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}

node *sorted_insert(node *head, int e)
{
    node *temp = head, *prev = NULL;
    node *nptr = malloc(sizeof(node));
    nptr->data = e;
    nptr->next = NULL;
    if (head == NULL || e <= temp->data)
    {
        nptr->next = head;
        head = nptr;
        return head;
    }
    else
    {
        while (temp->data <= e)
        {
            prev = temp;
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }
    }
    nptr->next = prev->next;
    prev->next = nptr;
    return head;
}

int main()
{

    node *hptr = NULL;
    hptr = create(hptr);
    int e;
    printf("Enter an element to insert at proper position:\n");
    scanf("%d", &e);
    hptr = sorted_insert(hptr, e);
    printf("Elements in linked list After insert:\n");
    display(hptr);
    free_list(hptr);
    return 0;
}