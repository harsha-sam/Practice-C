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
        if (x > 0)
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
}

void del(node *head)
{
    if (head == NULL)
        return;
    node *prev = head, *curr = head->next;

    while (prev != NULL && curr != NULL)
    {
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        if (prev != NULL)
            curr = prev->next;
    }
}

int main()
{

    node *hptr = NULL;
    hptr = create(hptr);
    if (hptr == NULL)
    {
        printf("List is Empty");
        return 0;
    }
    del(hptr);
    printf("Elements are\n");
    display(hptr);
    free_list(hptr);
    return 0;
}