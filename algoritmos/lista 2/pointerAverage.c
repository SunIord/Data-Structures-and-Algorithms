#include <stdio.h>

void calcular_media(int* A, int *B) {
    int average = (*A + *B) / 2;
    int mod = (*A + *B) % 2;
    
    if (*A < *B) {
        *A = average;
        *B = mod;
    } else {
        *B = average;
        *A = mod;
    }
}

int main() {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
    
    calcular_media(&A, &B);
    
    printf("A = %d\n", A);
    printf("B = %d\n", B);
    
    return 0;
}