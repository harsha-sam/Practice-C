#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;

void push(int stack[], int size, int c)
{
    stack[++top] = c;
}

int pop(int stack[])
{
    return stack[top--];
}

int main(void)
{
    char *postfix = malloc(sizeof(char));
    printf("Enter the Postfix Expression?\n");
    scanf("%s",postfix);
    int len = strlen(postfix), res = 0 ,stack[len];
    for (int i = 0 ; i < len ; i++)
    {
        if(isdigit(postfix[i]) != 0)
        {
            char c[2] = {postfix[i],'\0'};
            push(stack, len, atoi(c));
        }
        else
        {
            int b = pop(stack), a = pop(stack);
            if (postfix[i] == '+')
            {
                res = a + b;
            }
            else if (postfix[i] == '-')
            {
                res = a - b;
            }
            else if (postfix[i] == '/')
            {
                res = a / b;
            }
            else if (postfix[i] == '*')
            {
                res = a * b;
            }
            push(stack, len, res);
        } 
    }
    printf("Result after Postfix Expression Evaluation: %d\n", pop(stack));
}
