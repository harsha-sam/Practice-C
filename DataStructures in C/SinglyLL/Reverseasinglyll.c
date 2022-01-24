#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create(Node *hptr)
{
    int x = 0;
    Node *nptr = NULL, *tail = NULL;
    printf("Enter data and -1 to exit\n");
    while (1)
    {
        scanf("%d", &x);
        if (x > 0)
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
        }
        else
        {
            break;
        }
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
        printf("Nodes Freed: %d\n", c);
    }
}

void display(Node *hptr)
{
    printf("Elements are\n");
    if (hptr == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        for (Node *temp = hptr; temp != NULL; temp = temp->next)
        {
            printf("%d  ", temp->data);
        }
    }
    printf("\n");
}

Node *reverse(Node *hptr)
{
    Node *prev = NULL, *curr = hptr, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(void)
{
    Node *hptr = NULL;
    hptr = create(hptr);
    if (hptr == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    display(hptr);
    hptr = reverse(hptr);
    display(hptr);
    free_list(hptr);
    return 0;
}