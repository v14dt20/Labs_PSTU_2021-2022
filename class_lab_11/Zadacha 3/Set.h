#pragma once
#include "Money.h"
#include <vector>
#include <iostream>

using namespace std;

//������ ������
template <class T>
class Set
{
protected:
	vector <T> v;//���������������� ��������� ��� �������� ��������� ��-��
	int len;
public:
	//������������
	Set(void);
	Set(int);

	//����������
	~Set(void);

	//������
	void Print();

	//����� ���� �������
	T& max();
	//�������� ������� � ������
	void add_begin(T elem);

	//����� ����������� �������
	int min();
	//������� �������
	void del(int);

	//�������� ������� ��������������
	void add_srednee();
};


//===================================

//������������
template <class T>
Set<T>::Set()
{
	len = 0;
}
template <class T>
Set<T>::Set(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

//����������
template <class T>
Set<T>::~Set()
{
}

//������
template <class T>
void Set<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//����� ������������� ��������
template <class T>
T& Set<T>::max()
{
	T Max = v[0];//���� �������
	int n = 0;//����� ���� ��������

	for (int i = 0; i < v.size(); i++)
		if (v[i] > Max)
		{
			Max = v[i];
			n = i;
		}
	return v[n];
}
//���������� �������� � ������
template <class T>
void Set<T>::add_begin(T elem)
{
	v.insert(v.begin(), elem);
}

//����� ��� ��������
template <class T>
int Set<T>::min()
{
	T Min = v[0];//��� �������
	int n = 0;//����� ��� ��������

	for (int i = 0; i < v.size(); i++)
		if (v[i] < Min)
		{
			Min = v[i];
			n = i;
		}
	return n;
}
//�������� ��������
template <class T>
void Set<T>::del(int pos)
{
	v.erase(v.begin() + pos);
}

//���������� ��������
template <class T>
void Set<T>::add_srednee()
{
	int sum = 0;

	for (int i = 0; i < v.size(); i++)
		sum += v[i].Get_Rub() * 100 + v[i].Get_Kop();

	int n = v.size();
	sum /= n;

	for (int i = 0; i < v.size(); i++)
	{
		v[i].Set_Rub(v[i].Get_Rub() + sum / 100);
		v[i].Set_Kop(v[i].Get_Kop() + sum % 100);
	}
}