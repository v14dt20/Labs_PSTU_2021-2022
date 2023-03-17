#include <iostream>
#include "Stack.h"

using namespace std;

template<typename t>
Stack<t>::Stack() {
    this->Head = NULL;
}

template<typename t>
Stack<t>::~Stack() {
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
Node<t>* Stack<t>::push(t data) {
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
Node<t> Stack<t>::get() {
    if (Head == NULL) {
        cout << "Stack is empty!\n";
        return NULL;
    }
    if (Head->pNext == NULL) {
        Node<t> res = *Head;
        delete Head;
        Head = NULL;
        return res;
    }
    Node<t>* ptr = Head->pNext;
    Node<t>* prev = Head;
    while (ptr->pNext != NULL) {
        prev = prev->pNext;
        ptr = ptr->pNext;
    }

    Node<t> res = *ptr;
    delete ptr;
    prev->pNext = NULL;
    return res;

}

template<typename t>
void Stack<t>::pop() {
    if (Head != NULL) {
        Node<t>* ptr = Head->pNext;
        delete Head;
        Head = ptr->pNext;
    }
}
