// cd "2- Hash Tables/Problems"
// g++ -std=c++14 hashIt.cpp -o hashIt
// ./hashIt
// Código feito em períodos passados

#include <iostream>
#include <string>

using namespace std;

class ClosedHash {
private:
    int m;
    int cnt;
    string* keys; 
    int* occupied; 
    
public:
    ClosedHash(int size);
    ~ClosedHash();
    int hash(string key);
    int search(string key);
    void insert(string key);
    void erase(string key);
    void printDict();
    
};

ClosedHash::ClosedHash(int size) {
    m = size;
    cnt = 0;
    keys = new string[m]; 
    occupied = new int[m]; 
    for (int i = 0; i < m; i++) {
        occupied[i] = 0; 
        
    }
    
}

ClosedHash::~ClosedHash() {
    delete[] keys;
    delete[] occupied;
    
}

int ClosedHash::hash(string key) {
    int value = 0;
    int length = key.length();
    for (int i = 0; i < length; i++) {
        value += (key[i] * (i + 1));
        
    }
    value *= 19;
    return value % m;
    
}

int ClosedHash::search(string key) {
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

void ClosedHash::insert(string key) {
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

void ClosedHash::erase(string key) {
    int idx = search(key);
    if (idx != -1) {
        keys[idx] = "";
        occupied[idx] = -1; 
        cnt--;
        
    }
    
}

void ClosedHash::printDict() {
    cout << cnt << endl;
    for (int i = 0; i < m; i++) {
        if (occupied[i] == 1) {
            cout << i << ":" << keys[i] << endl;
            
        }
        
    }
    
}

int main() {
    int t; 
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n; 
        cin >> n;
        
        ClosedHash dict(101); 
        for (int j = 0; j < n; j++) {
            string op, key;
            cin >> op;
            size_t colonPos = op.find(':');
            key = op.substr(colonPos + 1);
            
            if (op.substr(0, colonPos) == "ADD") {
                dict.insert(key);
                
            } else if (op.substr(0, colonPos) == "DEL") {
                dict.erase(key);
                
            }
            
        }
        
        dict.printDict();
        
    }
    
    return 0;
    
}