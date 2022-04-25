#pragma once
#include <iostream>
#include "triad.h"

using namespace std;

class Vector
{
protected:
    TRIAD** beg;
    int size;
    int cur;
public:
    Vector(void);
    Vector(int);

    ~Vector(void);

    void Add(TRIAD*);

    friend ostream& operator<<(ostream&, const Vector&);
};