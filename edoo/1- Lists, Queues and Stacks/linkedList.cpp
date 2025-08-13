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

Link* createLink(int it, Link* nextval) {
    Link* n = new Link;
    n->setElement(it);
    n->setNext(nextval);
    return n;

}

Link* createHeader(Link* nextval) {
    Link* header = new Link;
    header->setNext(nextval);
    return header;

}

class linkedList {
private:
    Link* head;
    Link* tail;
    Link* curr;
    int cnt = 0;

public:
    linkedList() {
        curr = tail = head = createHeader (nullptr);
        cnt = 0;
    }

    ~linkedList() {
        Link* temp;
        while (head != nullptr) {
            temp = head;
            head = head->getNext();
            delete temp;

        }
    }

    void insert(int it) {
        curr->setNext(createLink(it, curr->getNext()));
        if (tail == curr) {
            tail = curr->getNext();

        }
        curr = curr->getNext();
        cnt++;
    }

    void moveToStart() {
        curr = head;
    }

    void moveToEnd() {
        curr = tail;
    }
    
    void prev() {
        if (curr == head) {return;}
        Link* temp = head;
        while (temp->getNext() != curr) {
            temp = temp->getNext();

        }

        curr = temp;
    }

    void next() {
        if (curr != tail) {curr = curr->getNext();}
    }

    int remove() {
        if (curr->getNext() == NULL) {
            return -1;

        }

        int it = curr->getNext()->getElement();

        if (tail == curr->getNext()) {
            tail = curr;

        }

        curr->setNext(curr->getNext()->getNext());
        cnt--;

        return it;
    }

    int currPos(){
        int pos = 0;
        Link* current = head;
        while(current != nullptr){
            if(current == curr) {
                return pos;

            }
            current = current->getNext();
            pos++;

        }
        return -1;
    }

};

int main() {return 0;}