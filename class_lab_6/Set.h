#pragma once
#include <iostream>

using namespace std;

class Iterator//класс итератор
{
protected:
    int* elem;//указатель на текущий элемент
    friend class Set;//лбъявление класса Set как дружественого
public:
    Iterator() { elem = 0; }//конструктор без параметров
    Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования

    int& operator* () { return *elem; }//перегрузка оператора разыменовывания
    Iterator& operator++ (int);//сдвинуть итератор на 1 вправо
    Iterator& operator- (int);//сдвинуть итератор на n элементов влево
};

class Set//класс множество
{
public:
    int size;
    int* data;
    Iterator begin;
    Iterator end;
public:
    //конструкторы
    Set(void);
    Set(int);
    Set(const Set&);

    //деструктор
    ~Set(void);

    //перегрузка операторов
    Set operator= (const Set&);
    int operator[] (int);
    bool operator== (Set&);
    bool operator> (int);

    //перегрузка операторов для работы с потоками
    friend istream& operator>> (istream&, Set&);
    friend ostream& operator<< (ostream&, const Set&);
};