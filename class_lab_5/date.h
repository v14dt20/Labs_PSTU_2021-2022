#pragma once
#include "triad.h"

class DATE : public TRIAD
{
public:
    //конструкторы
    DATE(void);
    DATE(int, int, int);
    DATE(const DATE&);

    //деструктор
    ~DATE(void);

    //модификаторы
    void set_first(int);
    void set_second(int);
    void set_third(int);

    //селекторы
    int get_first();
    int get_second();
    int get_third();

    //добавить 1 к каждому атрибуту
    void add_first();
    void add_second();
    void add_third();

    //бинарный оператор сложения (прибавить n дней к дате)
    friend DATE& operator+(DATE&, int);

    friend istream& operator>>(istream&, DATE&);//оператор ввода
};