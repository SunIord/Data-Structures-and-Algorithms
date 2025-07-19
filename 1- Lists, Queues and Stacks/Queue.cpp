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

class Queue {
private:
    Link* front;
    Link* rear;
    int size;

public:
    Queue() {
        front = rear = nullptr;
        size = 0;

    }

    ~Queue() {
        while (front != nullptr) {
            Link* temp = front;
            front = front->getNext();
            delete temp;

        }
        rear = nullptr;

    }

    void enqueue(int it) {
        Link* new_link = new Link;
        new_link->setElement(it);
        new_link->setNext(nullptr);

        if (rear == nullptr) {
            front = new_link;

        } else {
            rear->setNext(new_link);

        }
        rear = new_link;
        size++;

    }

    int dequeue() {
        if (size == 0) {
            return -1;

        }

        Link* temp = front;
        int it = temp->getElement();
        front = front->getNext();
        delete temp;

        if (front == nullptr) {
            rear = front;

        }

        size--;
        return it;

    }

    bool isEmpty() {
        return size == 0;

    }

    Link *getFront() {
        return front;

    }

};

int main() {return 0;}