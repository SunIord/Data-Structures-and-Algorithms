// cd algoritmos\c++
// g++ heap.cpp -o heap
// ./heap

#include <iostream>

void heapBottomUp(int arr[], int n) {
    for (int i = (n - (n % 2)) / 2; i >= 1; i--) {
        int key = i;
        int value = arr[i];
        bool heap = false;
        while (!heap && 2 * key <= n) {
            int j = 2 * key;
            if (j < n && arr[j] < arr[j + 1]) {j++;}
            if (value >= arr[j]) {heap = true;}
            else {
                arr[key] = arr[j];
                key = j;
            }
        }
        arr[key] = value;
    }
}

void heapTopDown(int arr[], int n) {
    for (int i = 2; i <= n; i++) {
        int key = i;
        int value = arr[i];
        bool heap = false;
        while (!heap && key > 1) {
            int j = key / 2;
            if (arr[j] >= value) {heap = true;}
            else {
                arr[key] = arr[j];
                key = j;
            }
        }
        arr[key] = value;
    }
}

int main() {
    int H[8] = {0, 2, 9, 7, 6, 5, 8, 10};
    int n = 7;

    heapBottomUp(H, n);

    std::cout << "Heap resultante: ";
    for (int i = 1; i <= n; i++)
        std::cout << H[i] << " ";
    std::cout << std::endl;

    heapTopDown(H, n);
    std::cout << "Heap resultante: ";
    for (int i = 1; i <= n; i++)
        std::cout << H[i] << " ";
    std::cout << std::endl;    

    return 0;
}