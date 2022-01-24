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
    printf("Elements are\n");
    if (hptr == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        for (node *temp = hptr; temp != NULL; temp = temp->next)
        {
            printf("%d ", temp->data);
        }
    }
}

node *del(node *head, int e)
{
    node *temp = head, *prev = NULL;
    if (head->data == e)
    {
        head = head->next;
        free(temp);
        return head;
    }
    else
    {
        while (temp->data != e)
        {
            prev = temp;
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }
    }
    if (temp->data == e)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Not Found\n");
    }
    return head;
}

int main()
{

    node *hptr = NULL;
    hptr = create(hptr);
    if (hptr == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    int e;
    printf("Enter the value of the node which has to be deleted:\n");
    scanf("%d", &e);
    hptr = del(hptr, e);
    display(hptr);
    free_list(hptr);
    return 0;
}