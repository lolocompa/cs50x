#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    printf("%i", letters);
}




int count_letters(string text)
{
    int lenght = strlen(text);
    int puntuation = 0;
    for(int i = 0; i < lenght; i++)
    {

        if ( text[i] < 97)
        {
            puntuation++;
        }
    }
    int letters = lenght - puntuation;
    return letters;

}