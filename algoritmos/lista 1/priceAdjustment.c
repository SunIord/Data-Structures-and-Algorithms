// cd "algoritmos\lista 1"
// g++ priceAdjustment.c -o price
// ./price

#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

void readProduct(struct Product *product) {
    fgets(product->name, sizeof(product->name), stdin);
    product->name[strcspn(product->name, "\n")] = 0;
    scanf("%f", &product->price);
    scanf("%d", &product->quantity);
    getchar(); 
}

void adjustPrice(struct Product *product, float percent) {
    product->price = product->price * (1 + percent / 100);
}

void printProduct(struct Product *product) {
    printf("%s: %.2f\n", product->name, product->price);
}

int main() {
    struct Product product1, product2, product3;

    readProduct(&product1);
    readProduct(&product2);
    readProduct(&product3);

    adjustPrice(&product1, 10.0);
    adjustPrice(&product2, 10.0);
    adjustPrice(&product3, 10.0);

    printProduct(&product1);
    printProduct(&product2);
    printProduct(&product3);

    return 0;
}