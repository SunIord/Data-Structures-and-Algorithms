// cd algoritmos\c++
// g++ binarySearch.cpp -o binarySearch
// ./binarySearch

#include <iostream>

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

int main() {
    int arr[] = {2, 3, 4, 6, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int key;
    std::cin >> key;

    int result = search(arr, 0, n - 1, key);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in array" << std::endl;
    }

    return 0;
}