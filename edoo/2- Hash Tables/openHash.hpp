#ifndef OPEN_HASH_HPP
#define OPEN_HASH_HPP

#include <iostream>

class Link {
private:
    int key;
    int value;
    Link* next;

public:
    Link(int k = 0, int v = 0, Link* n = nullptr) : key(k), value(v), next(n) {}

    int getKey() const { return key; }
    int getValue() const { return value; }
    Link* getNext() const { return next; }

    void setNext(Link* n) { next = n; }
};

class linkedList {
private:
    Link* head;
    Link* tail;
    int cnt;

public:
    linkedList() {
        head = tail = new Link();
        tail->setNext(nullptr);
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

    void insert(int key, int value) {
        Link* novo = new Link(key, value, nullptr);
        tail->setNext(novo);
        tail = novo;
        cnt++;

    }

    bool search(int key) {
        Link* temp = head->getNext();
        while (temp != nullptr) {
            if (temp->getKey() == key) return true;
            temp = temp->getNext();
        }
        return false;
    }

    void remove(int key) {
        Link* temp = head;
        while (temp->getNext() != nullptr) {
            if (temp->getNext()->getKey() == key) {
                Link* toDelete = temp->getNext();
                temp->setNext(toDelete->getNext());
                if (toDelete == tail) tail = temp;
                delete toDelete;
                cnt--;
                return;
            }
            temp = temp->getNext();
        }
    }

    int getSize() {
        return cnt;
    }
};

class OpenHash {
private:
    int m;
    linkedList* table;

public:
    OpenHash(int size) {
        m = size;
        table = new linkedList[m];

    }

    ~OpenHash() {
        delete[] table;

    }

    int hash(int key) {
        return key % m;

    }

    void insert(int key, int value) {
        int pos = hash(key);
        table[pos].insert(key, value);

    }

    void removeKey(int key) {
        int pos = hash(key);
        table[pos].remove(key);

    }

    bool search(int key) {
        int pos = hash(key);
        return table[pos].search(key);

    }

};

#endif 