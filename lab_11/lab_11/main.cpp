#include <iostream>
#include "List.h"

using namespace std;

void add(List* l)//добавить после отрицательных 0
{
    elem* current = l->Head;//текущий узел = начальному из списка
    int count = 1;//счётчик
    while (current != NULL)//пока текущий узел не пустой
    {
        if (current->data < 0)//если информационное поле меньше 0
            l->push(count + 1, 0);//то добавляем после этого узла узел с информационным полем 0
        current = current->pNext;//переходим к след узлу
        count++;//счётчик увеличиваем
    }
}

int main()
{
    List l;
    l.print();//"List is empty!"

    int n = 0;
    cout << "Enter n >> "; cin >> n;
    for (int i = 0; i < n; i++)//вводим данные в список
    {
        double num = 0;
        cout << ">>"; cin >> num;
        l.push_back(num);
    }
    l.print();

    add(&l);//добавляем 0 после отрицательных
    l.print();
    return 0;
}