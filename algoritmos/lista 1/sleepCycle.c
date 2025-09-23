// cd "algoritmos\lista 1"
// g++ sleepCycle.c -o sleep
// ./sleep

#include <stdio.h>

float SleepAverage(float hours[7]) {
    float sum = 0;
    for (int i = 0;i < 7; i++) {
        sum += hours[i];
    }
    return sum / 7;
}

void sleepAlert(float hours[7], float average) {
    const char *days[7] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
    int alert = 0;

    for (int i = 0; i < 7; i++) {
        if (hours[i] < average) {
            if (!alert) {
                printf("Atencao! Judite dormiu abaixo da media semanal nos dias:\n");
                alert = 1;
            }
            printf("%s\n", days[i]);
        }
    }
} 

int main() {
    float hours[7], average;

    for (int i = 0; i < 7; i++) {
        scanf("%f", &hours[i]);
    }

    average = SleepAverage(hours); 
    printf("Media semanal de sono: %.2f horas\n", average);

    if (average < 8) {
        printf("A media esta fora do esperado de pelo menos 8 horas!\n");
    } else {
        printf("A media esta dentro do esperado de pelo menos 8 horas!\n");
    }

    sleepAlert(hours, average);

    return 0;
}