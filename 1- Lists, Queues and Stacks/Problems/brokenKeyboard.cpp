// cd "1- Lists, Queues and Stacks\Problems"
// g++ -std=c++11 brokenKeyboard.cpp -o brokenKeyboard
// ./brokenKeyboard

#include <iostream>
#include <string>
#include <vector>

class ArrayList {
private:
    int maxSize;
    int listSize;
    int curr;
    char* listArray;

public:
    ArrayList(int size) {
        maxSize = size;
        listSize = 0;
        curr = 0;
        listArray = new char[maxSize];
    }

    ~ArrayList() {
        delete[] listArray;
    }

    void insert(const char& it) {
        for (int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = it;
        listSize++;
    }

    void append(const char& it) {
        listArray[listSize++] = it;
    }

    char remove() {
        char it = listArray[curr];
        for (int i = curr; i < listSize; i++) {
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
    void moveToPos(int pos) { curr = pos; }
    const char& getValue() const { return listArray[curr]; }
    
    // Verifica se uma linha inteira pode ser digitada
    bool canTypeLine(const std::string& line, const std::vector<bool>& broken) {
        for (char c : line) {
            if (isalpha(c)) {
                char l = tolower(c);
                if (broken[l - 'a']) return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<std::vector<std::string>> allTexts;
    std::vector<std::vector<bool>> allBroken;

    std::string lines;
    while (std::getline(std::cin, lines)) {
        if (lines == "finish") break;

        std::vector<bool> broken(26, false);
        for (char c : lines) {
            if (std::isalpha(c)) broken[std::tolower(c) - 'a'] = true;
        }

        std::vector<std::string> textLines;
        while (std::getline(std::cin, lines)) {
            textLines.push_back(lines);
            if (lines == "END") break;
        }

        allBroken.push_back(broken);
        allTexts.push_back(textLines);
    }

    std::cout << "+----------+----------------+-----------------------------+" << std::endl;
    std::cout << "| Keyboard | # of printable | Additionally, the following |" << std::endl;
    std::cout << "|          |      lines     |  letter keys can be broken  |" << std::endl;
    std::cout << "+----------+----------------+-----------------------------+" << std::endl;

    for (int k = 0; k < static_cast<int>(allTexts.size()); ++k) {
        const std::vector<std::string>& text = allTexts[k];
        const std::vector<bool>& broken = allBroken[k];

        int printableCount = 0;
        std::vector<bool> used(26, false);

        for (const std::string& line : text) {
            ArrayList list(100);
            for (char c : line) {
                list.append(c);
            }

            if (list.canTypeLine(line, broken)) {
                printableCount++;
                list.moveToStart();
                for (int i = 0; i < list.lenght(); ++i) {
                    char c = list.getValue();
                    if (std::isalpha(c)) {
                        used[std::tolower(c) - 'a'] = true;
                    }
                    list.next();
                }
            }
        }

        std::string additional;
        for (int i = 0; i < 26; ++i) {
            if (!broken[i] && !used[i]) {
                additional += static_cast<char>('a' + i);
            }
        }

        std::cout << '|';

        int keyboard = k + 1;
        std::string keyStr = std::to_string(keyboard);
        int leftSpaces1 = (11 - keyStr.length()) / 2;
        int rightSpaces1 = 10 - keyStr.length() - leftSpaces1;
        for (int i = 0; i < leftSpaces1; i++) std::cout << ' ';
        std::cout << keyStr;
        for (int i = 0; i < rightSpaces1; i++) std::cout << ' ';

        std::cout << '|';

        std::string countStr = std::to_string(printableCount);
        int leftSpaces2 = (17 - countStr.length()) / 2;
        int rightSpaces2 = 16 - countStr.length() - leftSpaces2;
        for (int i = 0; i < leftSpaces2; i++) std::cout << ' ';
        std::cout << countStr;
        for (int i = 0; i < rightSpaces2; i++) std::cout << ' ';

        std::cout << '|';
        
        std::cout << ' ' << additional;
        int extraSpaces = 28 - additional.length(); 
        while (extraSpaces-- > 0) std::cout << ' ';
        std::cout << "|" << std::endl;
        
        std::cout << "+----------+----------------+-----------------------------+" << std::endl;
    }

    return 0;
}