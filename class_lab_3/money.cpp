#include <iostream>
#include "money.h"

using namespace std;

//конструкторы
Money::Money()
{
    rub = 0;
    kop = 0;
}
Money::Money(long first, int second)
{
    rub = (first + second) / 100;
    kop = (first + second) % 100;
}
Money::Money(const Money& m)
{
    rub = m.rub;
    kop = m.kop;
}

//деструктор
Money::~Money()
{

}

//модификаторы
void Money::set_rub(long num)
{
    rub = num;
}
void Money::set_kop(int num)
{
    rub = num / 100;
    kop = num % 100;
}

//селекторы
void Money::get_rub()
{
    cout << "Rub: " << rub << "\n";
}
void Money::get_kop()
{
    cout << "Kop: " << kop << "\n";
}

//перегрузка оператора присваивания
Money& Money::operator=(const Money& m)
{
    if (&m == this) return *this;
    rub = m.rub;
    kop = m.kop;
    return *this;    
}

//перегрузка операторов ввода-вывода
istream& operator>>(istream& in, Money& m)
{
    int buf;
    cout << "Rub >> "; in >> m.rub;
    cout << "Kop >> "; in >> buf;
    m.rub += buf / 100;
    m.kop = buf % 100;
    return in;
}
ostream& operator<<(ostream& out, const Money& m)
{
    return (out << m.rub << "," << m.kop);
}

//перегрузка операторов сравнения
bool Money::operator==(const Money& m)
{
    if (rub == m.rub && kop == m.kop)
        return true;
    return false;
}
bool Money::operator!=(const Money& m)
{
    if (rub != m.rub || kop != m.kop)
        return true;
    return false;
}