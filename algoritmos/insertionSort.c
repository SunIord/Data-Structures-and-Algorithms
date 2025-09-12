// cd algoritmos
// g++ insertionSort.c -o insertionSort
// ./insertionSort

#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}