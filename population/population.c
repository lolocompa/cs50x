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


    

    while(e < n)
    {

        int years = 0;
        int x = e/3;
        int y = e/4;
        e = e + x - y;
        years++;
    }

    printf("%i\n", years);
}