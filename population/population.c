#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int e;
    do
    {
        n = get_int("starting population: ");
        e = get_int("ending population: ");
    }
    while (n < 9 || e < n);


    int years = 0;

    while(e < n)
    {

     e = e + e/12;
     years ++;

    }

    printf("%i\n", years);
}