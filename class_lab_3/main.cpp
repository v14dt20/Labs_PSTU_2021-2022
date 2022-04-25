#include <iostream>
#include "money.cpp"

using namespace std;

int main()
{
    Money a;
    Money b;
    Money c(1, 234);
    cin >> a;
    cout << a << "\n\n";
    
    b = a;

    cout << (a == b) << "\n";
    cout << (a == c) << "\n\n";

    cout << (a != b) << "\n";
    cout << (a != c) << "\n\n";
    return 0;
}