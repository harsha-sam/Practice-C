// Not completed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int top = -1;

bool isEmpty()
{
    return top == -1 ? true : false;
}

bool isFull(int size)
{
    return top == size - 1 ? true : false;
}

int precedence(char operator)
{
    if (operator == '+' || operator == '-')
    {
        return 1;
    }
    else if (operator == '*' || operator == '/')
    {
        return 2;
    }
    else if (operator == '^')
    {
        return 3;
    }
}

void push(char stack[], int size, char c)
{
    if(isFull(size))
    {
        printf("Stack is overflow\n");
        return ;
    }
    stack[++top] = c;
}

char peek(char stack[])
{
    if(isEmpty())
    {
        printf("Stack is underflow\n");
        return ;
    }
    return stack[top];
}

char pop(char stack[])
{
    if(isEmpty())
    {
        printf("Stack is underflow\n");
        return ;
    }
    return stack[top--];
}

int main(void)
{
    char *infix = malloc(sizeof(char));
    printf("Enter infix:");
    scanf("%s",infix);
    int len = strlen(infix);
    char postfix[len], stack[len];
    int i = 0;
    while (infix[i] != '\0')
    {
        if(isdigit(infix[i]) != 0 || isalpha(infix[i]) != 0)
        {
            strcat(postfix, infix[i]);
            i++;
        }
        else if (infix[i] == '(')
        {
            push(stack, len, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            char x = pop(stack);
            while (x != '(' && !isEmpty())
            {
                strcat(postfix, x);
                x = pop(stack);
            }
            i++;
        }
        else
        {
            char c = peek(stack);
            while (precedence(c) >= precendence(infix[i]) && !isEmpty())
            {
                c = pop(stack);
                strcat(postfix, c);

            }
            push(stack, len, infix[i]);
            i++;
        }  
    }
}
