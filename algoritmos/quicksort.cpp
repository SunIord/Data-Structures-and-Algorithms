// cd algoritmos
// g++ quicksort.cpp -o quicksort
// ./quicksort

#include <iostream>

class Quicksort {
private:
    int partition(int arr[], int left, int right) {
        int pivot = arr[left];
        int i = left;
        int j = right + 1;
        while (true) {
            while (true) {
                i++;
                if (arr[i] >= pivot || i >= right) {
                    break;
                }
            }
            while (true) {
                j--;
                if (arr[j] <= pivot) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            std::swap(arr[i], arr[j]);
        }
        std::swap(arr[left], arr[j]);
        return j;
    }
public:
    void sort(int arr[], int left, int right) {
        if (left < right) {
            int split = partition(arr, left, right);
            sort(arr, left, split - 1);
            sort(arr, split + 1, right);
        }
    }
};

int main() {
    int arr[] = {8, 4, 7, 3, 10, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Quicksort qs;
    qs.sort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}