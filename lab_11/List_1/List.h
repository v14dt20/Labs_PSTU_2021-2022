#pragma once
struct elem
{
    double data;
    elem* pNext;
};

struct List
{

    elem* Head;
    int size_list;

    //конструктор
    List();

    //деструктор
    ~List();

    //добавить элемент в конец
    void push_back(double);

    //удалить элемент с конца
    void pop_back();

    //удалить весь список
    void delAll();

    //вывести список
    void print();

    //вывести размер
    void size();

    //добавить элемент на произвольное место
    void push(int, double);

};