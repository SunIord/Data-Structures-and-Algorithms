// cd "algoritmos\lista 1"
// g++ circuits.c -o circuits
// ./circuits

#include <stdio.h>
#include <string.h>

struct Circuit {
    char name[31];
    float voltage;
    float current;
    float power;
};

void readCircuit(struct Circuit *c) {
    getchar(); 
    fgets(c->name, sizeof(c->name), stdin);
    c->name[strcspn(c->name, "\n")] = 0; 
    scanf("%f", &c->voltage);
    scanf("%f", &c->current);
}

void calculatePower(struct Circuit *c) {
    c->power = c->voltage * c->current;
}

void printCircuit(struct Circuit *c) {
    printf("%s - Potencia: %.2f W\n", c->name, c->power);
}

void sortCircuits(struct Circuit circuits[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(circuits[j].power < circuits[j+1].power) {

                struct Circuit temp = circuits[j];
                circuits[j] = circuits[j+1];
                circuits[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Circuit circuits[n];

    for(int i = 0; i < n; i++) {
        readCircuit(&circuits[i]);
        calculatePower(&circuits[i]);
    }

    sortCircuits(circuits, n);

    printf("Circuitos em ordem decrescente de potencia:\n");
    for(int i = 0; i < n; i++) {
        printCircuit(&circuits[i]);
    }

    return 0;
}