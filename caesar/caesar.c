#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


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

}




bool only_digits(string key)
{
    int lenght = strlen(key);
    int check = 0
    for(int i = 0; i < lenght; i++)
    {
        if (key[i] < 0)
        {
            check++
        }
        if ( key[i] > 9)
        {
            check++
        }
        else
        {
            return false;
        }
    }

}