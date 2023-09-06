#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("only 2 command line arguments\n");
        return 1;
    }

    FILE *forensic = fopen(argv[1], "r");

    if (forensic == NULL)
    {
        printf("cant open file\n");
        return 1;
    }

    int block = 512;
    uint8_t buffer[block];

}