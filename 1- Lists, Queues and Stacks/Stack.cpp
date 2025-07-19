#include <iostream>

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

int main() {return 0;}