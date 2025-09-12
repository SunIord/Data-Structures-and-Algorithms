// cd cd algoritmos\c++
// g++ selectionSort.cpp -o selectionSort
// ./selectionSort

#include <iostream>

void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
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