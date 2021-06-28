#include<stdio.h>
#include<stdlib.h>

int main() {
    int *P = NULL;
    P = (int *) calloc(5, sizeof(int));
    P[0] = 5;
    P[1] = 6;
    P[2] = 7;
    P[3] = 8;
    P[4] = 9; 
    P[8] = 20;         

    printf("%u\n", &P);

    P = realloc(P, sizeof(int) * 10);
    printf("P{8} = %d\n", P[8]);
    printf("%u\n", &P);
    
}