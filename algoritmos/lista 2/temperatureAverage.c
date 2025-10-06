#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    float *temperatures = (float*)malloc(n * sizeof(float));
    float sum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%f", &temperatures[i]);
        sum += temperatures[i];
    }
    
    float average = sum / n;
    printf("%.2f\n", average);
    
    free(temperatures);
    return 0;
}