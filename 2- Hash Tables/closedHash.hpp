#ifndef CLOSED_HASH_HPP
#define CLOSED_HASH_HPP

#include <iostream>

class ClosedHash {
private:
    int m; 
    int cnt; 
    int* keys; 
    int* occupied; 

public:
    ClosedHash(int size) {
        m = size;
        cnt = 0;
        keys = new int[m]; 
        occupied = new int[m]; 
        for (int i = 0; i < m; i++) {
            keys[i] = -1;
            occupied[i] = 0; 
            
        }
        
    }

    ~ClosedHash() {
        delete[] keys;
        delete[] occupied;
        
    }
    
    int hash(int key) { 
        if (key < 0) {
            key = -key; 
            
        }
        
        int value = 0;
        value = key % m;
        return value;

    }
    
    int search(int key) {
        int value = hash(key);
        for (int i = 0; i < 20; i++) {
            int pos = (value + i * i + 23 * i) % m;
            if (occupied[pos] == 0) {
                return -1;
                
            } else if (occupied[pos] == 1 && keys[pos] == key) {
                return pos;
                
            }
            
        }
        
        return -1;
        
    }

    void insert(int key) {
        if (cnt < m && search(key) == -1) {
            int value = hash(key);
            for (int i = 0; i < 20; i++) {
                int pos = (value + i * i + 23 * i) % m;
                if (occupied[pos] != 1) {
                    keys[pos] = key;
                    occupied[pos] = 1;
                    cnt++;
                    return;
                    
                }
                
            }
            
        }
        
    }

    void erase(int key) {
        int idx = search(key);
        if (idx != -1) {
            keys[idx] = -1;
            occupied[idx] = -1; 
            cnt--;
            
        }
        
    }

};

#endif 