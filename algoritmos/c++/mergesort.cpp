// cd cd algoritmos\c++
// g++ mergesort.cpp -o mergesort
// ./mergesort

#include <iostream>

class Mergesort {
private:
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
public:
    void sort(int arr[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            sort(arr, left, mid);
            sort(arr, mid + 1, right);
            merge(arr, left, right);
        }
    }
};

int main() {
    int arr[] = {8, 4, 7, 3, 10, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Mergesort ms;
    ms.sort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

