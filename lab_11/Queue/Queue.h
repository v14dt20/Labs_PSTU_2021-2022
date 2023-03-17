#pragma once

template<typename t>
struct Node {
    Node<t>* pNext;
    t data;

    Node(t data) {
        this->pNext = NULL;
        this->data = data;
    }
};

template<typename t>
class Queue {
public:
    Node<t>* Head;
public:
    Queue();
    ~Queue();

    Node<t>* push(t);
    Node<t> get();
    void pop();
};