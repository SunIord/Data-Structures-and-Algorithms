// cd "2- Hash Tables/Problems"
// g++ -std=c++14 interestingSubstrings.cpp -o interestingSubstrings
// ./interestingSubstrings

#include <iostream>
#include <string>
#include <vector>

typedef long long ll; // Cansei de digitar long long toda vez 

class Link {
private:
    /**/  // Os atributos deveriam ser privados, mas ok
    
public:
    ll key;
    ll value; 
    Link* next;
    
    Link(ll k, ll v) : key(k), value(v), next(nullptr) {}
    
};

class LinkedList {
private:
    Link* head;
    int cnt;
    
public:
    LinkedList() {
        head = new Link(0, 0);
        cnt = 0;
        
    }
    
    ~LinkedList() {
        Link* temp = head;
        while (temp) {
            Link* next = temp->next;
            delete temp;
            temp = next;
            
        }
    }
    
    ll get(ll key) {
        Link* curr = head->next;
        while (curr) {
            if (curr->key == key) {
                return curr->value;
                
            }
            curr = curr->next;
            
        }
        return 0;
        
    }
    
    void increment(ll key) {
        Link* prev = head;
        Link* curr = head->next;
        
        while (curr) {
            if (curr->key == key) {
                curr->value++;
                return;
                
            }
            prev = curr;
            curr = curr->next;
            
        }
        
        prev->next = new Link(key, 1);
        cnt++;
        
    }
    
};

class OpenHash {
private:
    int m;
    std::vector<LinkedList> table;
    
public:
    OpenHash(int size) : m(size), table(size) {}
    
    int hash(ll key) {
        return abs(static_cast<int>(key % m));
        
    }
    
    ll get(ll key) {
        int pos = hash(key);
        return table[pos].get(key);
        
    }
    
    void increment(ll key) {
        int pos = hash(key);
        table[pos].increment(key);
        
    }
    
};

int main() {
    ll totalValue = 0;
    const int hashSize = 100003; // Funciona em nome do Grande
    std::vector<OpenHash> letterTables;
    
    for (int i = 0; i < 26; i++) {
        letterTables.emplace_back(hashSize);
        
    }

    std::vector<int> point(26);
    for (int i = 0; i < 26; i++) {
        std::cin >> point[i];
        
    }

    std::string s;
    std::cin >> s;
    ll sum = 0;
    
    for (int i = 0; i < s.size(); i++) {
        int c_index = s[i] - 'a';
        totalValue += letterTables[c_index].get(sum);
        sum += point[c_index];
        letterTables[c_index].increment(sum);
        
    }
    std::cout << totalValue << std::endl;
    return 0;
    
}