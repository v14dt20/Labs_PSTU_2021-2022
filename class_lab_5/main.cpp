#include <iostream>
#include "Object.h"
#include "triad.h"
#include "date.h"
#include "vector.h"

using namespace std;

int main()
{
    Vector v(5);
    TRIAD a;
    cin >> a;
    DATE b;
    cin >> b;
    Object* p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);
    cout << v << "\n";
    return 0;
}