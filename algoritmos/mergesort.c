// cd algoritmos
// g++ mergesort.c -o mergesort
// ./mergesort

#include <stdio.h>

void merge(int arr[], int left, int right) {
    int temp[right - left + 1];
    for (int i = left; i <= right; i++) {
        temp[i] = arr[i];
    }
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    for (int curr = left; curr <= right; curr++) {
        if (i > mid) {
            arr[curr] = temp[j++];
        } else if (j > right) {
            arr[curr] = temp[i++];
        } else if (temp[i] <= temp[j]) {
            arr[curr] = temp[i++];
        } else {
            arr[curr] = temp[j++];
        }
    }
}

void sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}