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


    int years = 3;

    int r = 5;

    printf("%i/n", years + r);
}