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




    for(int x = 0; x<height; x++)
    {
        for(height = 0; height>0; height--)
        {

            printf("#");
        }
        printf("\n");

    }
}