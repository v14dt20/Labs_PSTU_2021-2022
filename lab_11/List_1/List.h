#pragma once
struct elem
{
    double data;
    elem* pNext;
};

struct List
{

    elem* Head;
    int size_list;

    //�����������
    List();

    //����������
    ~List();

    //�������� ������� � �����
    void push_back(double);

    //������� ������� � �����
    void pop_back();

    //������� ���� ������
    void delAll();

    //������� ������
    void print();

    //������� ������
    void size();

    //�������� ������� �� ������������ �����
    void push(int, double);

};