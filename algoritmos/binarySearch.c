// cd algoritmos
// g++ binarySearch.c -o binarySearch
// ./binarySearch

#include <stdio.h>

int search(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = (left + right) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            return search(arr, left, mid - 1, key);
        } else {
            return search(arr, mid + 1, right, key);
        }
    } else {
        return -1;
    }
}