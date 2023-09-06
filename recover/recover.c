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
    BYTE buffer[block];
    int file_count = 000;
    BYTE j = 0xff;
    

    while (fread(buffer, 1, block, forensic) == block)
    {
        BYTE first = buffer[0];
        BYTE second = buffer[1];
        BYTE third = buffer[2];
        BYTE fourth = buffer[3];

        if (first == 0xff && second == 0xd8 && third == 0xff && fourth/2 == 0xe)
        {

        }
    }

}