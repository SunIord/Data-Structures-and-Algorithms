// cd "algoritmos\lista 1"
// g++ inheritance.c -o inheritance
// ./inheritance

#include <stdio.h>

int main() {
    int children, totalAcres, luizShare;
    float acresPerChild;

    scanf("%d", &children);
    scanf("%d", &totalAcres);

    acresPerChild = (float) totalAcres / children;

    luizShare = totalAcres % children;

    printf("Filhos: %.2f\n", acresPerChild);
    printf("Luiz: %d\n", luizShare);

    return 0;
}