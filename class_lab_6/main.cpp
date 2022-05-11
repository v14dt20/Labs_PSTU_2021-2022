#include <iostream>
#include "Set.cpp"

using namespace std;

int main()
{
    Set set;
    cin >> set;

    cout << set << "\n";

    cout << "First elem: ";
    cout << set[0] << "\n";

    Set set2;
    cin >> set2;
    cout << set2;
    cout << "set == set2: " << (set == set2) << "\n";

    cout << "5 in set: " << (set > 5) << "\n";

    Iterator it1 = set.end;
    it1 = it1 - 3;
    cout << *it1 << "\n";
    return 0;
}