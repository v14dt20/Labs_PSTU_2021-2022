#include <iostream>
#include "Queue.cpp"

using namespace std;

int main() {
    Queue<int> q;
    for (int i = 0; i < 10; i++)
        q.push(i);
    for (int i = 0; i < 10; i++)
        cout << q.get().data << " ";
    
    for (int i = 10; i < 20; i++)
        q.push(i);
    for (int i = 0; i < 10; i++)
        cout << q.get().data << " ";

    q.get();
    return 0;
}