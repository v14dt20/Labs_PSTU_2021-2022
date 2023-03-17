#pragma once

template<typename t>
struct Node {
    Node<t>* pPrev;
    Node<t>* pNext;
    t data;

    Node(t data) {
        this->data = data;
        this->pPrev = this->pNext = NULL;
    }
};

template<typename t>
struct List {
    Node<t>* Head;
    Node<t>* Tail;

    List();//конструктор
    ~List();//деструктор

    Node<t>* push_back(t);//добавить в конец
    Node<t>* push_front(t);//добавить в начало
    Node<t>* push(int, t);//добавить в произвольное место по индексу
    
    void pop_back();//удалить с конца
    void pop_front();//удалить с начала
    void erase(int);//удалить элемент по индексу

    Node<t>* getAt(int);//доступ к произвольному элементу списка
    Node<t>* operator[] (int);//доступ к элементам по индексу
};