#pragma once
#include <iostream>

using namespace std;

class Money
{
private:
    long rub;
    int kop;
public:
    //конструкторы
    Money();//без параметров
    Money(long, int);//с параметрами
    Money(const Money&);//копирования

    //деструктор
    ~Money();

    //модификаторы
    void set_rub(long);
    void set_kop(int);
    
    //селекторы
    void get_rub();
    void get_kop();

    Money& operator=(const Money&);//перегрузка оператора присваивания

    //перегрузка ввода-вывода
    friend istream& operator>>(istream&, Money&);
    friend ostream& operator<<(ostream&, const Money&);

    //перегрузка операторов сравнения
    bool operator==(const Money&);
    bool operator!=(const Money&);
};