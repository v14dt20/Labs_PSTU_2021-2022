#include <iostream>
#include "Stack.cpp"

using namespace std;

int main() {
    Stack<int> s;
    for (int i = 0; i < 10; i++)
        s.push(i);
    for (int i = 0; i < 10; i++)
        cout << s.get().data << " ";
    
    for (int i = 10; i < 20; i++)
        s.push(i);
    for (int i = 0; i < 10; i++)
        cout << s.get().data << " ";

    s.get();
    return 0;
}