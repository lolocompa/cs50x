#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int main(void)
{
    string text = get_string("Text: ");

    int count_letters(string text);
    printf("%i", letters);
}




int count_letters(string text)
{
    int lenght = strlen(text);
    int spaces = 0;
    for(int i = 0; i < lenght; i++)
    {
        if (text[i] == 32)
        spaces++;
    }
    int letters = lenght - spaces;
    return letters;

}