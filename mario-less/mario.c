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
        for(int y = 0; y<height; y++)
        {
            printf("#");
        }
    }
}