#include <iostream>
#include "List.cpp"

using namespace std;

int main() {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);
    l.push(6, 4);
    for (Node<int>* ptr = l.Head; ptr != NULL; ptr = ptr->pNext)
        cout << ptr->data << " ";
    cout << "\n";
    l.pop_back();
    l.pop_front();
    for (Node<int>* ptr = l.Head; ptr != NULL; ptr = ptr->pNext)
        cout << ptr->data << " ";

    return 0;
}