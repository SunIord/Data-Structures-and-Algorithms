// cd "1- Lists, Queues and Stacks\Problems"
// g++ -std=c++11 parenthesesBalance.cpp -o parenthesesBalance
// ./parenthesesBalance
// Código feito em períodos passados

#include <iostream>
#include <string>

using namespace std;

class Link {
private:
    //arara

public:
    int element;
    Link* next;

};

class Stack {
private:
    Link* top;
    int size;

public:
    Stack ();
    void push (int it);
    int pop ();
    int topValue ();
    int length ();
    bool isEmpty ();
    Link* getTop ();

};

Stack::Stack () {
    top = nullptr;
    size = 0;

}

void Stack::push (int it) {
    Link* n = new Link;
    n->element = it;
    n->next = top;
    top = n;
    size++;

}

int Stack::pop () {
    if (top == nullptr) return -1;

    Link* temp = top;
    int it = top->element;
    top = top->next;
    delete temp;
    size--;
    return it;

}

int Stack::topValue () {
    if(top == nullptr) return -1;

    int num = top->element;
    return num;
}

int Stack::length () {
    return size;

}

bool Stack::isEmpty () {
    return size == 0;

}

Link *Stack::getTop () {
    return top;

}

int main () {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        Stack stack;
        bool valid = true;

        for (char c : s) {
            if (c == '(' || c == '[') {
                stack.push(c);

            } else if (c == ')' || c == ']') {
                if (stack.isEmpty()) {
                    valid = false;

                } else {
                    Link* topLink = stack.getTop ();
                    char topChar = topLink->element;
                    stack.pop ();
                    if ((c == ')' && topChar != '(') || (c == ']' && topChar != '[')) {
                        valid = false;

                    }

                }

            }

        }

        if (!stack.isEmpty()) {
            valid = false;

        }

        cout << (valid ? "Yes" : "No") << endl;

    }

    return 0;

}