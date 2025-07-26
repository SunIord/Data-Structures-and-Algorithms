// cd "2- Hash Tables/Problems"
// g++ -std=c++14 interestingSubstrings.cpp -o interestingSubstrings
// ./interestingSubstrings

#include <iostream>
#include <string>
#include <vector>

class ClosedHash {
private:
    int m;
    std::vector<long long> keys;
    std::vector<int> freqs; // Frequências de cada chave
    std::vector<int> occupied; // Estado de ocupação de cada posição

public:
    ClosedHash(int size) {
        m = size;
        keys.resize(m, -1);
        freqs.resize(m, 0);
        occupied.resize(m, 0);
    }
    
    ~ClosedHash() {} // Não é necessário liberar memória já que usei vector

    int hash(long long key) {
        if (key < 0) key = -key;
        return static_cast<int>(key % m);

    }

    void insert(long long key) {
        int value = hash(key);
        for (int i = 0; i < 20; i++) {
            int pos = (value + i * i + 23 * i) % m;
            if (occupied[pos] == 0 || occupied[pos] == -1) {
                keys[pos] = key;
                freqs[pos] = 1;
                occupied[pos] = 1;
                return;

            } else if (occupied[pos] == 1 && keys[pos] == key) {
                freqs[pos]++;
                return;

            }

        }

    }

    int getFreq(long long key) {
        int value = hash(key);
        for (int i = 0; i < 20; i++) {
            int pos = (value + i * i + 23 * i) % m;
            if (occupied[pos] == 0) {
                return 0;

            } else if (occupied[pos] == 1 && keys[pos] == key) {
                return freqs[pos];
                
            }

        }
        return 0;

    }

};

int main() {
    std::vector<int> letterValues(26);
    for (int i = 0; i < 26; i++) {
        std::cin >> letterValues[i];

    }
    std::string s;
    std::cin >> s;

    int hashSize = 10007; // Diminuir o tamanho do hash
    std::vector<ClosedHash> letterTables;
    for (int i = 0; i < 26; i++) {
        letterTables.push_back(ClosedHash(hashSize));

    }

    long long totalValue = 0;
    long long prefixSum = 0;

    for (size_t i = 0; i < s.size(); i++) {
        int letterIndex = s[i] - 'a';
        totalValue += letterTables[letterIndex].getFreq(prefixSum);
        prefixSum += letterValues[letterIndex];
        letterTables[letterIndex].insert(prefixSum);

    }
    std::cout << totalValue << std::endl;

    return 0;

}