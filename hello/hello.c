#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("enter your name: \n ");
    printf("hello, %s", name);
}