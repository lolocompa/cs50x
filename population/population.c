#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("starting population: ");
    }
    while (n < 9);


    int e;
    do
    {
        e = get_int("ending population: ");
    }
    while (e < n);


    int years = 0;

    while(e < n)
    {

     e = e + e/12;
     years ++;

    }

    printf("%i\n", years);
}