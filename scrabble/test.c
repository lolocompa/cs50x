#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int letters = 'a';
    for(int i = 0; i < 26; i++)
    {
        printf("%c\n", letters);
        letters++;
    }
}