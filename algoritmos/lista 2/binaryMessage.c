#include <stdio.h>
#include <stdlib.h>

char* read(int *size) {
    char *message = NULL;
    int capacity = 0;
    int count = 0;
    int zeroCount = 0;
    char current;
    
    while (scanf("%c", &current) == 1) {
        if (count >= capacity) {
            capacity = (capacity == 0) ? 10 : capacity * 2;
            message = realloc(message, capacity * sizeof(char));
        }
        message[count++] = current;
        
        if (current == '0') {
            zeroCount++;
            if (zeroCount == 10) {
                count -= 10;
                break;
            }
        } else {
            zeroCount = 0;
        }
    }
    
    *size = count;
    return message;
}

int main() {
    int size;
    char *message = read(&size);
    
    for (int i = 0; i < size; i++) {
        printf("%c", message[i]);
    }
    
    free(message);
    return 0;
}