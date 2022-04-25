#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector(void)
{
    beg = 0;
    size = 0;
    cur = 0;
}
Vector::Vector(int n)
{
    beg = new TRIAD* [n];
    cur = 0;
    size = n;
}

Vector::~Vector(void)
{
    if (beg != 0) delete[] beg;
    beg = 0;
}

void Vector::Add(TRIAD* p)
{
    if (cur > size)
    {
        beg[cur] = p;
        cur++;
    }
}

ostream& operator<<(ostream& out, const Vector& v)
{
    if (v.size == 0) out << "Empty!";
    TRIAD** p = v.beg;
    for (int i = 0; i < v.cur; i++)
    {
        out << *p << "/";
        p++;
    }

    return out;
}