// cd "algoritmos\lista 1"
// g++ fibonacciSequence.c -o fibonacci
// ./fibonacci

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, result;
    scanf("%d", &n);

    result = fibonacci(n);
    printf("O %d termo da sequencia de Fibonacci e %d.", n, result);

    return 0;
}