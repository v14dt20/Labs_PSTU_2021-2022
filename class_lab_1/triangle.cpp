#include <iostream>
#include <cmath> 
#include "triangle.h"

using namespace std;

//конструкторы
Triangle::Triangle()
{
    first = 0;
    second = 0;
}
Triangle::Triangle(int a, int b)
{
    first = a;
    second = b;
}

//деструктор
Triangle::~Triangle()
{
}

//селекторы
void Triangle::get_first()
{
    cout << first << "\n";
}
void Triangle::get_second()
{
    cout << second << "\n";
}

//модификаторы
void Triangle::set_first(int num)
{
    first = num;
}
void Triangle::set_second(int num)
{
    second = num;
}

//вычисление гипотенузы
void Triangle::hipotenuse()
{
    cout << "Hipotenuse: " << sqrt(pow(first, 2) + pow(second, 2)) << "\n";
}