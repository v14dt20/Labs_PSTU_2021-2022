#include <iostream>
#include "Queue.h"

using namespace std;

template<typename t>
Queue<t>::Queue() {
    this->Head = NULL;
}

template<typename t>
Queue<t>::~Queue() {
    while (Head != NULL) {
        if (Head->pNext == NULL) {
            delete Head;
            return;
        }
        Node<t>* ptr = Head->pNext;
        delete Head;
        Head = ptr;
    }
}

template<typename t>
Node<t>* Queue<t>::push(t data) {
    Node<t>* ptr = new Node<t>(data);
    if (Head == NULL) {
        Head = ptr;
        return ptr;
    }
    Node<t>* current = Head;
    while (current->pNext != NULL) {
        current = current->pNext;
    }
    current->pNext = ptr;

    return ptr;
}

template<typename t>
Node<t> Queue<t>::get() {
    if (Head != NULL) {
        Node<t> ptr = *Head;
        Node<t>* next = Head->pNext;
        delete Head;
        Head = next;
        return ptr;
    }
    else {
        cout << "Queue is empty!\n";
        return NULL;
    }
}

template<typename t>
void Queue<t>::pop() {
    if (Head != NULL) {
        Node<t>* ptr = Head->pNext;
        delete Head;
        Head = ptr->pNext;
    }
}
