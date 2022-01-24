#include <stdio.h>
#include <stdlib.h>

typedef struct word
{
    char *word;
} word;

typedef struct sentence
{
    word *sen;
} sent;

typedef struct paragraph
{
    sent *para;
} para;

typedef struct document
{
    para *doc;
}doc;

int main()
{
    word *w;
    sent *s[2] = {{"Learning", "C", "is", "fun"},{"Learning", "pointers", "is", "more", "fun"}};
    printf("%s",s[1]->sen);
}