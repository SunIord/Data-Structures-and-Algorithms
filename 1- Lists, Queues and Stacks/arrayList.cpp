#include <iostream>

class ArrayList {
private:
    int maxSize;
    int listSize;
    int curr;
    int* listArray;

public:
    ArrayList(int size) {
        maxSize = size;
        listSize = 0;
        curr = 0;
        listArray = new int[maxSize];
    }

    ~ArrayList() {
        delete[] listArray;
    }

    void insert(const int& it) {
        for (int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1];

        }
        listArray[curr] = it;
        listSize++;

    }

    void append(const int& it) {
        listArray[listSize++] = it;

    }

    int remove() {
        int it = listArray[curr];
        for (int i=curr; i < listSize; i++) {
            listArray[i] = listArray[i + 1];
            
        }
        listSize--;
        return it;

    }

    void moveToStart() { curr = 0; }
    void moveToEnd() { curr = listSize; }
    void prev() { if (curr != 0) curr--; }
    void next() { if (curr < listSize) curr++; }

    int lenght() const { return listSize; }
    int currPos() const { return curr; }
    void moveToPos (int pos) { curr = pos; }
    const int& getValue() const { return listArray[curr]; }

};

int main() {return 0;}