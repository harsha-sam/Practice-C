#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s,*t;
    printf("String1:");
    scanf("%s",s);
    t = (char*)malloc(strlen(s)+1); 
    //t = (char*)malloc(1), t = (char*)malloc(sizeof(s)) - These two allocate only some bytes but the next characters are stored in string continuosly, so u don't see any difference
    int i = 0;
    while (*(s+i)!='\0')
    {
        *(t+i) = *(s+i);
        i++;
    } 
    *t -= 32; 
    *(t+i) = '\0'; 
    printf("%s\n",t); 
    free(t);
}