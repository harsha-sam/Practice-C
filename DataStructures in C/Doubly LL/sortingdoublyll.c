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
Node *swap(Node *hptr);
void display(Node *hptr);

int main(void)
{
    Node *hptr = NULL;
    hptr = create(hptr);
    if (hptr == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    hptr = swap(hptr);
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

Node *swap(Node *hptr)
{
    for(Node *i = hptr ; i -> next != NULL; i = i->next)
    {
        Node *min = i;
        for(Node *j = i->next ; j != NULL; j = j->next)
        {
            if(j->data < min->data)
            {
              min = j;
            }
        }
        int temp = i->data;
        i->data = min->data;
        min->data = temp;

    }
    return hptr;
}
