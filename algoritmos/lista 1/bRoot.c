// cd "algoritmos\lista 1"
// g++ bRoot.c -o bRoot
// ./bRoot

#include <stdio.h>
#include <math.h>

float bRoot(float a, float b) {
    return pow(a, 1 / b);
}

int main() {
    float a, b;
    scanf("%f %f", &a, &b);

    float result = bRoot(a, b);
    printf("%.2f\n", result);

    return 0;
}