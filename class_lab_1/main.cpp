#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    Triangle t(1, 2);
    t.hipotenuse();

    t.set_first(3);
    t.set_second(4);
    t.hipotenuse();
    return 0;
}