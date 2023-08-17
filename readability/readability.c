#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int main(void)
{
    string text = get_string("Text: ");

    float letters = count_letters(text);
    int len_text = strlen(text);

    float words = 1;
    for(int i = 0; i < len_text; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }



    float sentences = 0;
    for(int j = 0; j < len_text; j++)
    {
        if(text[j] == 46 || text[j] == 33 || text[j] == 63)
        {
            sentences++;
        }
    }
    float wor = sentences / words;
    float L = letters/words * 100;
    float S = wor * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) index;
    if (grade>16)
    {
        printf("Grade 16+");
    }
    else if (grade<1)
    {
        printf("Before grade 1");
    }
    else
    {
    printf("Grade %i\n", grade);;
    }



}




int count_letters(string text)
{
    int lenght = strlen(text);
    int puntuation = 0;
    for(int i = 0; i < lenght; i++)
    {
        if (isupper(text[i]))
        {
            text[i] = tolower(text[i]);
        }
        if ( text[i] < 97)
        {
            puntuation++;
        }
    }
    int letters = lenght - puntuation;
    return letters;

}