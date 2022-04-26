#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Vector
{
protected:
    Object** beg;
    int size;
    int cur;
public:
    Vector(void);
    Vector(int);

    ~Vector(void);

    void Add(Object*);

    friend ostream& operator<<(ostream&, const Vector&);
};