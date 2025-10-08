// cd algoritmos\c++
// g++ sequentialSearch.cpp -o sequentialSearch
// ./sequentialSearch

#include <iostream>

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

int main() {
    int arr[] = {2, 3, 4, 6, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    int key;
    std::cin >> key;
   
    int result = search(arr, n, key);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in array" << std::endl;
    }
   
    return 0;
}