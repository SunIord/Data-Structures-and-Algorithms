// cd "algoritmos\lista 1"
// g++ swapValues.c -o swap
// ./swap

#include <stdio.h>

int main() {
    int a, b, temp;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("Inicial: %d %d\n", a, b);

    temp = a;
    a = b;
    b = temp;
    printf("Final: %d %d\n", a, b);

    return 0;
}