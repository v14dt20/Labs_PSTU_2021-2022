#include <iostream>
#include "List.h"

using namespace std;

template<typename t>
List<t>::List() {
    this->Head = this->Tail = NULL;
}

template<typename t>
List<t>::~List() {
    while (Head != NULL) {
        pop_front();
    }
}

template<typename t>
Node<t>* List<t>::push_back(t elem) {
    Node<t>* ptr = new Node<t>(elem);
 
    ptr->pPrev = Tail;
    if (Tail != NULL)
        Tail->pNext = ptr;
    if (Head == NULL)
        Head = ptr;
    Tail = ptr;
 
    return ptr;
}

template<typename t>
Node<t>* List<t>::push_front(t elem) {
    Node<t>* ptr = new Node<t>(elem);

    ptr->pNext = Head;
    if (Head != NULL)
        Head->pPrev = ptr;
    if (Tail == NULL)
        Tail = ptr;
    Head = ptr;
    
    return ptr;
}

template<typename t>
Node<t>* List<t>::push(int index, t data) {
    Node<t>* right = getAt(index);
    if (right == NULL)
        return push_back(data);
    
    Node<t>* left = getAt(index);
    if (left == NULL)
        return push_front(data);
    
    Node<t>* ptr = new Node<t>(data);

    ptr->pPrev = left;
    ptr->pNext = right;
    left->pNext = ptr;
    right->pPrev = ptr;

    return ptr;
}


template<typename t>
Node<t>* List<t>::getAt(int index) {
    Node<t>* ptr = Head;
    int n = 0;

    while (n != index) {
        if (ptr == NULL)
            return ptr;
        ptr = ptr->pNext;
        n++;
    }

    return ptr;
}

template<typename t>
void List<t>::pop_back() {
    if (Tail == NULL)
        return;
    Node<t>* ptr = Tail->pPrev;
    if (ptr != NULL)
        ptr->pNext = NULL;
    else
        Head = NULL;
    delete Tail;
    Tail = ptr;
}

template<typename t>
void List<t>::pop_front() {
    if (Head == NULL)
        return;
    Node<t>* ptr = Head->pNext;
    if (ptr != NULL)
        ptr->pPrev = NULL;
    else
        Tail = NULL;
    delete Head;
    Head = ptr;
}

template<typename t>
void List<t>::erase(int index) {
    Node<t>* ptr = getAt(index);
    
    if (ptr == NULL)
        return;
    if (ptr->pPrev == NULL) {
        pop_front();
        return;
    }
    if (ptr->pNext == NULL) {
        pop_back();
        return;
    }
    
    Node<t>* left = ptr->pPrev;
    Node<t>* right = ptr->pNext;
    left->pNext = right;
    right->pPrev = left;

    delete ptr;
}

template<typename t>
Node<t>* List<t>::operator[] (int index) {
    return getAt(index);
}