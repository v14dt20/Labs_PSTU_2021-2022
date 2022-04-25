#pragma once
#include <iostream>

using namespace std;

class TRIAD
{
//атрибуты
protected:
    int first;
    int second;
    int third;
public:
    //конструкторы
    TRIAD(void);
    TRIAD(int, int, int);
    TRIAD(const TRIAD&);

    //деструктор
    virtual ~TRIAD(void);

    //модификаторы
    virtual void set_first(int);
    virtual void set_second(int);
    virtual void set_third(int);

    //селекторы
    virtual int get_first();
    virtual int get_second();
    virtual int get_third();

    virtual TRIAD& operator=(const TRIAD&);//оператор присваивания

    friend istream& operator>>(istream&, TRIAD&);//оператор ввода
    friend ostream& operator<<(ostream&, const TRIAD&);//оператор вывода
};