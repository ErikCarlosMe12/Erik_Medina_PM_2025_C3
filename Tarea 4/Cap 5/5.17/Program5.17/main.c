#include <stdio.h>

/* Apuntadores y arreglos */

int main(void)
{
    int V1[4] = {1, 3, 5, 7};
    int V2[4] = {2, 4, 0, 0};
    int *AX, *AY;

    AX = &V1[2];
    AY = &V2[2];

    V2[2] = *(AX + 1);
    V2[3] = *AX;

    AX = AX + 1;
    V1[0] = *AX;

    printf("\n[Primera salida]");
    printf("\nV1:{%d, %d, %d, %d}\tV2: {%d, %d, %d, %d}",
           V1[0], V1[1], V1[2], V1[3],
           V2[0], V2[1], V2[2], V2[3]);

           V1[2]= *AY;
           V1[1]= --*AY;

           AX = &V1[3];
           V1[3] = *AX;

     printf("\n[Segunda salida]");
    printf("\nV1:{%d, %d, %d, %d} \tV2: {%d, %d, %d, %d}\n",
           V1[0], V1[1], V1[2], V1[3],
           V2[0], V2[1], V2[2], V2[3]);

           return 0;
}




