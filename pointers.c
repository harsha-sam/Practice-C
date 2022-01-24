#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *ptr;
    printf("Integer Pointer after declaration:");
    printf("\nAddress where ptr is located:%p\nAddress held by ptr:%p \nValue at address held by ptr:%d", &ptr, ptr, *ptr);
    printf("\n------------------------------------\n");
    ptr = (int *)malloc(sizeof(int));
    *ptr = 50;
    printf("Pointer after dynamically allocating it space for an integer:");
    printf("\nAddress where ptr is located:%p\nAddress held by ptr:%p \nValue at address held by ptr:%d\n", &ptr, ptr, *ptr);
    printf("\n------------------------------------\n");
    char *s,*c; //two char ptrs 
    printf("Char Pointer after declaration:");
    printf("\nAddress where ptr is located:%p\nAddress held by ptr:%p \nValue at address held by ptr:%s", &s, s, s);
    *s = 'a';
    printf("\n------------------------------------\n");
    s = "harsha";
    printf("char pointer after initilization");
    printf("\nAddress where ptr is located:%p\nAddress held by ptr:%p \nValue at address held by ptr:%s\n", &s, s, s);
    printf("address where s is located:%p\n",&s); // Gives address where s is located;
    printf("string s: %s\n",s); //Gives string s
    printf("Gives first char of s:%c\n",*s); // Gives first char of s
    printf("address of s:%p\n",s); // Gives address of s
    printf("address of first char of s:%p\n",&s[0]); // Gives address of first char of s
    printf("address of first char of s%p\n",(s+0)); // Gives address of first char of s
    c = "xyz";
    printf("%s",c);

    printf("\n");
}