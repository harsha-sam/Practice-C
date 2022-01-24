#include <stdio.h>
#include <string.h>
#include <math.h>
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

void reverse(node *ptr)
{

    if (ptr == NULL)
    {
        printf("");
    }
    else
    {
        reverse(ptr->next);
        printf("%d ", ptr->data);
    }
}

int main()
{

    node *hptr = NULL;
    hptr = create(hptr);
    printf("Linked list in reverse order:\n");
    reverse(hptr);
    free_list(hptr);
    return 0;
}