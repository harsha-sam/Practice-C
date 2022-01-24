#include <stdio.h>

#define SIZE 3

int que[SIZE];
int front = -1, rear = -1;

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enqueueue()
{
    if (isFull())
        printf("Circular Queue Is Full\n");

    else
    {
        int g;
        printf("Enter a number to Insert :\n");
        scanf("%d", &g);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        que[rear] = g;
    }
}

void dequeueue()
{
    int x;
    if (isEmpty())
    {
        printf("The Circular Queue is Empty\n");
        return;
    }
    else
    {
        x = que[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
                    printf("%d was deleted\n", x);

    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("The Circular Queue is Empty\n");
        return;
    }
    else
    {
        printf("Elements are:\n");

        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", que[i]);
        }
        printf("%d ", que[i]);
    }
    printf("\n");
}
int main()
{
    int f;
    printf("1.Insert\n2.Delete\n3.Display\n4.EXIT\n");
    do
    {
        printf("Enter choice\n");
        scanf("%d", &f);
        switch (f)
        {
        case 1:
            enqueueue();
            break;
        case 2:
        dequeueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");

        default:
            break;
        }

    } while (f != 4);

    return 0;
}