#include <iostream>
#include "List.h"

using namespace std;

void add(List* l)//�������� ����� ������������� 0
{
    elem* current = l->Head;//������� ���� = ���������� �� ������
    int count = 1;//�������
    while (current != NULL)//���� ������� ���� �� ������
    {
        if (current->data < 0)//���� �������������� ���� ������ 0
            l->push(count + 1, 0);//�� ��������� ����� ����� ���� ���� � �������������� ����� 0
        current = current->pNext;//��������� � ���� ����
        count++;//������� �����������
    }
}

int main()
{
    List l;
    l.print();//"List is empty!"

    int n = 0;
    cout << "Enter n >> "; cin >> n;
    for (int i = 0; i < n; i++)//������ ������ � ������
    {
        double num = 0;
        cout << ">>"; cin >> num;
        l.push_back(num);
    }
    l.print();

    add(&l);//��������� 0 ����� �������������
    l.print();
    return 0;
}