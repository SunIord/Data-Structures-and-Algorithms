// cd algoritmos
// g++ quicksort.c -o quicksort
// ./quicksort

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left;
    int j = right + 1;
    while (1) {
        while (1) {
            i++;
            if (arr[i] >= pivot || i >= right) {
                break;
            }
        }
        while (1) {
            j--;
            if (arr[j] <= pivot) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[left], &arr[j]);
    return j;
}

void sort(int arr[], int left, int right) {
    if (left < right) {
        int split = partition(arr, left, right);
        sort(arr, left, split - 1);
        sort(arr, split + 1, right);
    }
}