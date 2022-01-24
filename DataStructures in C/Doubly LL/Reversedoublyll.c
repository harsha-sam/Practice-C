#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} Node;

Node *create(Node *hptr);
bool unload(Node *hptr);
Node *reverse(Node *hptr);
void display(Node *hptr);

int main(void)
{
    Node *hptr = NULL;
    hptr = create(hptr);
    // display(hptr);
    if (hptr == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    hptr = reverse(hptr);
    display(hptr);
    // unload(hptr);
}
Node *create(Node *hptr)
{
    int x = 0 ;
    Node *nptr = NULL, *tail = NULL;
    printf("Enter data and -1 to exit\n");
    scanf("%d",&x);
    while (x != -1)
    {
        nptr = malloc(sizeof(Node));
        nptr->prev = NULL;
        nptr->next = NULL;
        nptr->data = x;
        if (hptr == NULL)
        {
            hptr = nptr;
            tail = nptr;
        }
        else
        {
            nptr->prev = tail;
            tail->next = nptr;
            tail = nptr;
        }
        scanf("%d",&x);
    }
    return hptr;
}

bool unload(Node *hptr)
{
    Node *temp = hptr->next;
    int c = 0;
    while (temp->next != NULL)
    {
        free(temp->prev);
        c++;
        temp = temp->next;
    }
    free(temp->prev);
    c++;
    free(temp);
    c++;
    printf("NODES FREED: %d\n",c);
    return true;
}

void display(Node *hptr)
{
    if (hptr == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        for(Node *temp = hptr ; temp!= NULL ;temp = temp->next)
        {
            printf("%d ",temp->data);
        }
    }
    printf("\n");
    
}

Node *reverse(Node *hptr)
{
    Node *temp = hptr, *prev = NULL;
    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = temp->prev;
        temp->prev = next; 
        prev = temp;
        temp = next;
    }    
    return prev;
}
