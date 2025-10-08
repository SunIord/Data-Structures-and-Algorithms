// cd algoritmos
// g++ sequentialSearch.c -o sequentialSearch
// ./sequentialSearch

#include <stdio.h>

int search(int arr[], int n, int key) {
    int i = 0;
   
    while (i < n && arr[i] != key) {
        i += 1;
    }
   
    if (i < n) {
        return i;
    } else {
        return -1;
    }
}