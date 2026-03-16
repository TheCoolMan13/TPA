#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_SIZE 1001

int main()
{

    uint8_t numar_bytes = MAX_ENTRY_SIZE / 8 + 1;
    unsigned char *vect = malloc(numar_bytes * sizeof(unsigned char));
    if (vect == NULL)
    {
        perror(NULL);
        exit(1);
    }
    memset(vect, 0, numar_bytes);

    char *inputname = "problema1Input.txt";
    FILE *input = fopen(inputname, "r");
    if(input == NULL)
    {
        fprintf(stderr, "EROARE INPUT");
        perror(NULL);
        free(vect);
        exit(1);
    }

    uint16_t ReadNumber;
    uint16_t Byte_poz;
    uint16_t In_Byte_poz;
    while(fscanf(input , "%hu" , &ReadNumber) == 1)
    {
        Byte_poz = ReadNumber / 8;
        In_Byte_poz = ReadNumber % 8;
        *(vect + Byte_poz) |= 1<<In_Byte_poz;
        printf("%d %d %d \n" , ReadNumber , Byte_poz , In_Byte_poz);
    }
    printf("\n");

    uint16_t Number;
    for(Number = 0 ; Number < 1001 ; Number++)
    {
        Byte_poz = Number / 8;
        In_Byte_poz = Number % 8;
        if((*(vect+Byte_poz) & (1<<In_Byte_poz)) == (1 << In_Byte_poz))
        {
            printf("%d " , Number);
        }
    }

    free(vect);
    fclose(input);
    return 0;
}