// cd "algoritmos\lista 1"
// g++ kroneckerProduct.c -o kronecker
// ./kronecker

#include <stdio.h>

void readVector(float v[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%f", &v[i]);
    }
}

void printVector(float v[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f", v[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void kroneckerProduct(float v[], int dv, float w[], int dw, float result[]) {
    for (int i = 0; i < dv; i++) {
        for (int j = 0; j < dw; j++) {
            result[i*dw + j] = v[i] * w[j];
        }
    }
}

int main() {
    int dv, dw;
    scanf("%d %d", &dv, &dw);

    float v[dv], w[dw], result[dv*dw];
    readVector(v, dv);
    readVector(w, dw);

    kroneckerProduct(v, dv, w, dw, result);

    printVector(result, dv*dw);

    return 0;
}