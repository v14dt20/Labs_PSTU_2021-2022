#include <iostream>
#include "date.cpp"

using namespace std;

int main()
{
    DATE a;
    cin >> a;

    cout << a << "\n";

    a = a + 2;
    cout << a << "\n\n";

    a.add_first();
    a.add_second();
    a.add_third();
    cout << a << "\n";
    return 0;
}