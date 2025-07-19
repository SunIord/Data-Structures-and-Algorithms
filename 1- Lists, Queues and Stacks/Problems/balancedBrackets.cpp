// cd "1- Lists, Queues and Stacks\Problems"
// g++ -std=c++11 balancedBrackets.cpp -o balancedBrackets
// ./balancedBrackets
#include <iostream>
#include <string>

class Link {
private:
    int element;
    Link* next;

public:
    int getElement() const {return element;}
    void setElement(int value) {element = value;}
    Link* getNext() const {return next;}
    void setNext(Link* nextval) {next = nextval;}

};

class Stack {
private:
    Link* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;

    }

    ~Stack() {
        while (top != nullptr) {
            Link* temp = top;
            top = top->getNext();
            delete temp;

        }
    }

    void push(int it) {
        Link* n = new Link;
        n->setElement(it);
        n->setNext(top);
        top = n;
        size++;

    }

    int pop() {
        if (top == nullptr) return -1;

        Link* temp = top;
        int it = top->getElement();
        top = top->getNext();
        delete temp;
        size--;
        return it;

    }

    int topValue() {
        if(top == nullptr) return -1;

        int num = top->getElement();
        return num;
    }

    int length() {
        return size;

    }

    bool isEmpty() {
        return size == 0;

    }

    Link *getTop() {
        return top;

    }

};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    while (n--) {
        std::string s;
        getline(std::cin, s);
        Stack stack;
        bool balanced = true;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);

            } else {
                if (stack.isEmpty()) {
                    balanced = false;
                    break;
                }
                int top = stack.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    balanced = false;
                    break;
                }

            }

        }

        if (balanced && stack.isEmpty()) {
            std::cout << "YES" << std::endl;

        } else {
            std::cout << "NO" << std::endl;

        }
    }
    return 0;

}