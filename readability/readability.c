#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
    string text = get_string("Text: ");
    int letters = strlen(text);
    printf("%i", text[0]);

}