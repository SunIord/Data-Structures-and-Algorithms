#include <stdio.h>
#include <stdlib.h>

double* getUniqueValues(double* sequence, int size, int* uniqueSize) {
    int* isUnique = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++) {
        isUnique[i] = 1;
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sequence[i] == sequence[j]) {
                isUnique[i] = 0;
                isUnique[j] = 0;
            }
        }
    }
    
    *uniqueSize = 0;
    for (int i = 0; i < size; i++) {
        if (isUnique[i]) {
            (*uniqueSize)++;
        }
    }
    
    double* uniqueValues = (double*)malloc((*uniqueSize) * sizeof(double));
    int index = 0;
    
    for (int i = 0; i < size; i++) {
        if (isUnique[i]) {
            uniqueValues[index++] = sequence[i];
        }
    }
    
    free(isUnique);
    return uniqueValues;
}

int main() {
    int n;
    scanf("%d", &n);
    
    double* sequence = (double*)malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        scanf("%lf", &sequence[i]);
    }
    
    int uniqueSize;
    double* uniqueValues = getUniqueValues(sequence, n, &uniqueSize);
    
    printf("[");
    for (int i = 0; i < uniqueSize; i++) {
        printf("%.4f", uniqueValues[i]);
        if (i < uniqueSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    free(sequence);
    free(uniqueValues);
    
    return 0;
}