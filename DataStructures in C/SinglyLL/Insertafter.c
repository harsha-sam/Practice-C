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

void display(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}

node *insertafter(node *hptr)
{
    int e;
    printf("Enter the Element\n");
    scanf("%d", &e);
    int af;
    printf("Enter the value after which the data has to be inserted\n");
    scanf("%d", &af);
    node *nptr = malloc(sizeof(node));
    nptr->data = e;
    nptr->next = NULL;
    node *temp = hptr;
    while (temp->data != af)
    {
        temp = temp->next;
    }
    nptr->next = temp->next;
    temp->next = nptr;
    return hptr;
}

int main()
{

    node *hptr = NULL;
    hptr = create(hptr);
    hptr = insertafter(hptr);
    display(hptr);
    free_list(hptr);
    return 0;
}