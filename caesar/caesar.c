#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int rotate(char letter, int number);
bool only_digits(string key);

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

    int j = rotate(plaintext[3], 2);

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
        int number = 6;
        int let = letter + 1;
        return let;
    }
}