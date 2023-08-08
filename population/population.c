#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    do
    {
        start = get_int("starting population: ");
    }
    while (start < 9);


    int end;
    do
    {
        end = get_int("ending population: ");
    }
    while (end < start);


    int years = 0;

    while(start < end)
    {

     start = start + start/12;
     years ++;

    }

    printf("%i\n", years);
}