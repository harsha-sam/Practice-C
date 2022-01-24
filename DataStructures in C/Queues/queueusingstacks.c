#include <stdio.h>
#include <stdlib.h>
 
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data)
{
    st1[++top1] = data;
}
 

int pop1()
{
    return(st1[top1--]);
}
 

void push2(int data)
{
    st2[++top2] = data;
}
 

 
int pop2()
{
    return(st2[top2--]);
}
 

void enqueue()
{
    int data;
    printf("Enter data into queue\n");
    scanf("%d", &data);
    push1(data);
    count++;
}
 
void dequeue()
{
    if(top1 == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (int i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}
 
 
void display()
{
    if(top1 == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Elements are\n");
    for (int i = 0;i <= top1;i++)
    {
        printf("%d ", st1[i]);
    }
    printf("\n");
}
int main()
{
    int ch;
    printf("1.Enqueue element into queue\n");
    printf("2.Dequeu element from queue\n");
    printf("3.Display from queue\n");
    printf("4.Exit\n");
    while (1)
    {
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            exit(0);
        }
    }
}