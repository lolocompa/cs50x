#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


bool only_digits(string key);
int rotate(char letter, int number);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("error\n");
        return 1;
    }
    else if (argc > 2)
    {
         printf("error\n");
         return 1;
    }
    bool key = only_digits(argv[1]);
    if(key == 0)
    {
        printf("Usage: ./caesar key\n");
    }


    int key_num = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    int plain_lenght = strlen(plaintext);

    for(int i = 0; i < plain_lenght; i++)
    {
        int rotated_letter = rotate(plaintext[i], key_num);
    }

}




bool only_digits(string key)
{
    int lenght = strlen(key);
    int check = 0;
    int compare = 0;
    for(int i = 0; i < lenght; i++, compare++)
    {
        if (key[i] > 48 && key[i] < 57)
        {
            check++;
        }

    }
    if (check == compare)
    {
        return true;
    }
    else
    {
        return false;
    }






    int rotate(char letter, int number);
    {

    }
}