// cd algoritmos
// g++ insertionSort.cpp -o insertionSort
// ./insertionSort

#include <iostream>

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

int main() {
    int arr[] = {8, 4, 7, 3, 10, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}