#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#define LENGTH 45
#define HASH_TABLE_SIZE 26

typedef struct node
{
    char name[LENGTH + 1];
    long phno;
    struct node *next;
} Node;

Node *table[HASH_TABLE_SIZE];
int contacts_inserted = 0;

bool hash_init(Node *t[])
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        t[i] = NULL;
    }
    return true;
}

unsigned int hash(char *word)
{
    if (!isalpha(word[0]))
    {
        return HASH_TABLE_SIZE;
    }
    else
    {
        int ascii_value = (int)toupper(word[0]);
        return ascii_value = abs(65 - ascii_value);
    }
}

bool load(char *name, long num)
{
    Node *nptr = malloc(sizeof(Node));
    if (nptr == NULL)
    {
        printf("Insufficient Memory : Can't allocate memory for new node\n");
        return false;
    }
    else
    {
        int index = hash(name);
        if (index >= HASH_TABLE_SIZE)
        {
            printf("\nInvalid Name: Entered name doesn't start with an alphabet\n");
            return false;
        }
        strcpy(nptr->name, name);
        nptr->phno = num;
        nptr->next = table[index];
        table[index] = nptr;
        contacts_inserted++;
        return true;
    }
}

unsigned int count(void)
{
    return contacts_inserted;
}

bool unload(Node *t[])
{
    printf("\nUnloading Hash Table : \n.....\n.....\n\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        printf("Bucket %i: ", i);
        Node *temp = table[i];
        while (temp != NULL)
        {
            Node *prev = temp;
            temp = temp->next;
            printf("Node(%s, %lu) Freed\t", prev->name, prev->phno);
            free(prev);
        }
        printf("\n\n------------------------\n");
        printf("Bucket %i: FREED\n", i);
        printf("------------------------\n\n");
    }
    return true;
}

void display()
{
    printf("\nHash Table :\n....\n.....\n\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        printf("Bucket %i: ", i);
        if (table[i] == NULL)
        {
            printf("Empty");
        }
        else
        {
            for (Node *temp = table[i]; temp != NULL; temp = temp->next)
            {
                printf("(%s , %lu)", temp->name, temp->phno);
            }
        }
        printf("\n\n");
    }
}

int main()
{
    char choice;
    hash_init(table);
    do
    {
        char name[LENGTH + 1];
        long ph;
        printf("Name : ");
        scanf("%s", name);
        printf("Phno : ");
        scanf("%lu", &ph);
        if (!load(name, ph))
        {
            printf("\nError: Could not load the contact into the table\n");
            return 1;
        }
        printf("Enter y to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y');
    printf("\nNumber of contacts inserted : %d\n", count());
    display();
    unload(table);
    return 0;
}