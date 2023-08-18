#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    printf("%i", key);
}




bool only_digits(string key)
{
    int lenght = strlen(key);
    int check = 0;
    int compare = 0;
    for(int i = 0; i < lenght; i++)
    {
        if (key[i] < 0)
        {
            check++;
        }
        if ( key[i] > 9)
        {
            check++;
        }
        compare++;

    }
    if (check == compare)
    {
        return true;
    }
    else
    {
        return false;
    }

}