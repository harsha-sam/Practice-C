#include <stdio.h>

#define SIZE 100
int top = -1;
int stack[100];

void push(int data)
{
    stack[++top] = data;
}

int pop()
{
    return stack[top--];
}

void display()
{
    for (int i = top ; i >= 0; i--)
    {
        printf("%d",stack[i]);
    }
    printf("\n");
}

int main(void)
{
    int num;
    printf("Enter decimal number: \n");
    scanf("%d",&num);
    int temp = num;
    while (temp > 0)
    {
        int x = temp % 2;
        temp /= 2;
        push(x);
    }
    printf("Binary Equivalent of %d is: ",num);
    display();
}
