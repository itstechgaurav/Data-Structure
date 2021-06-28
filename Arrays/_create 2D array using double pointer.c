#include<stdio.h>
#include<stdlib.h>

int main() {
    int **A; // A[2][3];
    A = (int **) malloc(sizeof(int *) * 2);

    A[0] = (int *) malloc(sizeof(int) * 3);
    A[1] = (int *) malloc(sizeof(int) * 3);

    A[0][1] = 10;
    A[0][2] = 20;

    printf("%d %d", A[0][1], A[0][2]);
    return 0;
}