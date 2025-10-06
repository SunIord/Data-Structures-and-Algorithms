#include <stdio.h>

int *sort(int *ptr) { // InsertionSort
    for (int i = 1; i < 5; i++) {
        int value = ptr[i];
        int j = i - 1;
        while (j >= 0 && ptr[j] > value) {
            ptr[j + 1] = ptr[j];
            j--;
        }
        ptr[j + 1] = value;
    }
    return ptr;
}

int main() {
    int numbers[5];
    
    scanf("%d,%d,%d,%d,%d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);
    int *sorted = sort(numbers);
    
    for (int i = 0; i < 5; i++) {
        if (i == 4)
            printf("%d", sorted[i]); 
        else
            printf("%d,", sorted[i]);
    }
    
    return 0;
}