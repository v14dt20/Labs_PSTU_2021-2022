#include <iostream>
#include "triad.h"

using namespace std;

//конструкторы
TRIAD::TRIAD()
{
    first = 0;
    second = 0;
    third = 0;
}
TRIAD::TRIAD(int a, int b, int c)
{
    first = a;
    second = b;
    third = c;
}
TRIAD::TRIAD(const TRIAD& T)
{
    first = T.first;
    second = T.second;
    third = T.third;
}

//деструктор
TRIAD::~TRIAD() = default;

//модификаторы
void TRIAD::set_first(int num)
{
    first = num;
}
void TRIAD::set_second(int num)
{
    second = num;
}
void TRIAD::set_third(int num)
{
    third = num;
}

//селекторы
int TRIAD::get_first()
{
    return first;
}
int TRIAD::get_second()
{
    return second;
}
int TRIAD::get_third()
{
    return third;
}

void TRIAD::Show() {
    cout << first << "." << second << "." << third;
}

//оператор присваивания
TRIAD& TRIAD::operator=(const TRIAD& T)
{
    if (&T == this)//если присваиваем этот же объект, то возвращаем этот объект
        return *this;
    first = T.first;
    second = T.second;
    third = T.third;
    return *this;
}

istream& operator>>(istream& in, TRIAD& T)//оператор ввода
{
    cout << "First >> "; in >> T.first;
    cout << "Second >> "; in >> T.second;
    cout << "Third >> "; in >> T.third;
    return in;
}
ostream& operator<<(ostream& out, const TRIAD& T)//оператор вывода
{
    return (out << T.first << "." << T.second << "." << T.third);
}