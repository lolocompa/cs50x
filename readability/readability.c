#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int len_text = strlen(text);

    int words = 1;
    for(int i = 0; i < len_text; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }



    int sentences = 0;
    for(int j = 0; j < len_text; j++)
    {
        if(text[j] == 46 || text[j] == 33 || text[j] == 63)
        {
            sentences++;
        }
    }
    printf("%i\n", letters);
    printf("%i\n", words);
    printf("%i\n", sentences);
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