#include <iostream>
#include "Object.cpp"
#include "triad.cpp"
#include "date.cpp"
#include "vector.cpp"

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