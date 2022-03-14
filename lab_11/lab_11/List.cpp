#include <iostream>
#include "List.h"

using namespace std;

//�����������
List::List()
{
    Head = NULL;
    size_list = 0;
}

//����������
List::~List()
{
    delAll();
}

//�������� ������� � �����
void List::push_back(double mes)
{
    elem* el = new elem;//������ ����, �������������� ���� �������� ����� ��������� ������, � ��������� �� ���� ������� NULL
    el->data = mes;
    el->pNext = NULL;

    if (Head == NULL)//���� ������ ������, �� ��������� ���� ���������� ������
        Head = el;
    else//����� 
    {
        elem* current = Head;//������ ���������, ������� ��������� �� ���� � ������ ������
        while (current->pNext != NULL)//��� �� ����� ������ (���� ���������, ���� ������ �� ���� ���� ����� NULL)
            current = current->pNext;//����������� ��������� �� ���� �������
        current->pNext = el;//��������� � ����� ��������� ����
    }
    size_list++;//����������� ������� ���������
}

//������� ������� � �����
void List::pop_back()
{
    if (Head == NULL)//���� ������ ������, �� ������� ������
        cout << "List is empty!\n"; 
    else if (Head->pNext == NULL)//���� ������ �� ������ ��������, �� ������ ���������� NULL
    {
        Head = NULL;
        size_list--;//��������� �������
    }
    else//�����
    {
        elem* current = Head;//��������� �� �������� ����
        elem* prev = current;//��������� �� ������� ����
        while (current->pNext != NULL)//���� �� ����� ������
        {
            prev = current;//���������� = ���������
            current = current->pNext;//�������� = ����������
        }
        size_list--;//��������� ������� 
        current = NULL;//������� �������� ����
        prev->pNext = NULL;//������ �� ���� ���� ����� NULL
    }
}

//������� ���� ������
void List::delAll()
{
    elem* current = Head;//��������� �� �������� ����
    if (current == NULL) return;//���� ������ ������ ������ �� ������
    do
    {
        elem* prev = current;//��������� �� ������� ����
        current = current->pNext;//�������� ����������� �� ���������
        delete prev;//������� ����������
    } while (current != NULL);//��� ������, ���� �������� �� ����� NULL
    size_list = 0;//������� 0
    Head = NULL;//1 ���� NULL
}


//������ ������
void List::print()
{
    if (Head == NULL)//���� ������ ������
        cout << "List is empty!";
    else//�����
    {
        elem* current = Head;//������ �� �������� �������
        cout << "Your list: ";
        while (current != NULL)//���� ���� ���� �� ����� NULL
        {
            cout << current->data << " ";//������� ��� �������������� ����
            current = current->pNext;//��������� � ���� ����
        }
    }
    cout << "\n";
    size();
    cout << "\n";
}

//����� �������
void List::size()
{
    cout << "Size: " << size_list << "\n";
}

//�������� �������
void List::push(int n, double mes)
{
    elem* current = Head;//��������� �� �������� ����
    if (n > size_list + 1)//���� ��������� ������ ������ ������� + 1, �� ������� ��������� �� ������ � ������� �� �-��
    {
        cout << "Error!\n";
        return;
    }

    if (n == 1)//���� ������ ������ 1, �.� ������ ������
    {
        elem* new_el = new elem;//������ ����� ����
        new_el->data = mes;
        new_el->pNext = Head;//��������� �� ���� = Head
        Head = new_el;//������ ������ ������� ����� ���������
        size_list++;//����������� ������
    }
    else if (n == size_list + 1)//���� ������ ����� ������ ������ + 1, �� ������ ��������� ������� � �����
        push_back(mes);
    else//� ���� �������:
    {
        int count = 1;//������� 
        elem* current = Head;//�������� ����
        elem* prev = current;//����������
        while (count != n)//���� �� ����� �� ���� � �������� �������
        {
            prev = current;//���������� ����� ���������
            current = current->pNext;//�������� ����������� �����
            count++;//������� �����������
        }
        elem* new_el = new elem;//������ ����� ����
        new_el->data = mes;
        new_el->pNext = current;//����� ���� ��������� �� ��������
        prev->pNext = new_el;//���������� ��������� �� ����� ��������� �������
        size_list++;//����������� ������
    }
}