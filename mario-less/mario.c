#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("height: ");
    }
    while(height<0 || height>=8);




    int n = 0;

    for(int x = 0; x<height; x++)
    {
        dot--;
        n++;
        for(int y = 0; y<n; y++)
        {
            for(dot = height-1;dot>0; dot--)
            {
                print(".")
            }
            printf("#");
        }
        printf("\n");

    }

}