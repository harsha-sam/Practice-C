#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int top = -1;
bool isEmpty()
{
   return top == -1 ? true : false;
}

bool isFull(int size)
{
    return top == size - 1 ? true : false;
}

void push(char c, char stack[], int len)
{
    if(!isFull(len))
    {
        stack[++top] = c;
        return ;
    }
    printf("Stack Overflow\n");
    return ;
}

char pop(char stack[])
{
    if(!isEmpty())
    {
        return stack[top--];
    }
    printf("Stack Underflow\n");
    return '1';
}

void display(char stack[])
{
    for (int i = top ; i >= 0; i--)
    {
        printf("%c\t",stack[i]);
    }
    printf("\n");
}

int main() 
{
    char *s = malloc(sizeof(char));
    printf("Enter an exp: \n");
    scanf("%s",s);
    // printf("%s",s);
    int len = strlen(s);
    // printf("%d",len);
    char *stack = malloc(len*sizeof(char));
    for (int i = 0 ; i < len; i++)
    {
        // printf("Element : %c\n",s[i]);
        // printf("topvalue : %d\n",top);
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            // printf("Pushing : %c\n",s[i]);
            push(s[i], stack, len);
        }
        else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            char res_char;
            if (s[i] == ']')
            {
                res_char = '[';   
            }
            else if (s[i] == '}')
            {
                res_char = '{';   
            }
            else if (s[i] == ')')
            {
                res_char = '(';   
            }
            // printf("res: %c",res_char);
            char pop_char;
            do
            {
                pop_char = pop(stack);
                if (pop_char == '1')
                {
                    printf("NO\n");
                    return 0;
                }
                // printf("Pop: %c\t",pop_char);
            }while(pop_char != res_char );
        }     
        // printf("\nStack\n");
        // display(stack);
        // sleep(2);
    }
    printf("YES\n");
    free(s);
    free(stack);
    return 0;
}