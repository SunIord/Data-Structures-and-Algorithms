#include <stdio.h>
#include <stdlib.h>

int* readVector(int *size) {
    int* vector = NULL;
    *size = 0;
    int number;
    
    while (scanf("%d", &number) == 1) {
        vector = (int*)realloc(vector, (*size + 1) * sizeof(int));
        vector[*size] = number;
        (*size)++;
     
        char nextChar = getchar();
        if (nextChar == '\n') break;
    }
    
    return vector;
}

int* sumVectors(int* a, int* b, int size_a, int size_b) {
    if (size_a != size_b) {
        return NULL;
    }
    
    int* c = (int*)malloc(size_a * sizeof(int));
    
    for (int i = 0; i < size_a; i++) {
        c[i] = a[i] + b[i];
    }
    
    return c;
}

void printVector(int* vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", vector[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
}

int main() {
    int size_a, size_b;
    
    int* a = readVector(&size_a);
    int* b = readVector(&size_b);
    
    int* result = sumVectors(a, b, size_a, size_b);
    
    if (result == NULL) {
        printf("Vetores de tamanhos diferentes!");
    } else {
        printVector(result, size_a);
        free(result);
    }
    
    free(a);
    free(b);
    
    return 0;
}