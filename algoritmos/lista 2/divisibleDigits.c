#include <stdio.h>

void contaDivisiveis(int m, int n, int *c) {
    *c = 0;
    int num = m;
    
    if (n == 0) {
        return;
    }
    
    while (num != 0) {
        int digit = num % 10;
        if (digit % n == 0) {
            (*c)++;
        }
        num = num / 10;
    }
}

int main() {
    int m, n, count;
    
    scanf("%d %d", &m, &n);
    contaDivisiveis(m, n, &count);
    printf("%d", count);
    
    return 0;
}