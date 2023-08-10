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
        n++;
        for(int y = 0; y<n; y++)
        {
            for(int dot = height; dot>0;dot--)
            {
                printf(".");
            }
            printf("#");
        }
        printf("\n");

    }

}