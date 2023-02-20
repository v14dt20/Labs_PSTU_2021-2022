#pragma once
#include "Money.h"
#include <iostream>
#include <map>

using namespace std;


template <class D, class T>
class Container
{
protected:
	multimap<int, T> m;//�������
	int len = 0;//����� �������
public:
	//������������
	Container(void);
	Container(int);

	//����������
	~Container(void);

	void Print();//������
	multimap<int, T> Add_max();//�������� ���� �������
	multimap<int, T> Del_min();//������� ��� �������
	multimap<int, T> Add_srednee();//�������� ������� � ������� ��������
};

//=========================================
//������������
template <class D, class T>
Container<D, T>::Container(void)
{
	len = 0;
}
template <class D, class T>
Container<D, T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
}

//����������
template <class D, class T>
Container<D, T>::~Container(void)
{
}

//������
template <class D, class T>
void Container<D, T>::Print()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();

	while (i != m.end())
	{
		cout << (*i).first << ":" << (*i).second << " ";
		i++;
	}
	cout << "\n";
}

//���������� ���� ��������
template <class D, class T>
multimap<int, T> Container<D, T>::Add_max()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();
	int k = 0;//������� ���������
	T max = (*i).second;//������������ �������

	while (i != m.end())
	{
		if ((*i).second > max)
		{
			max = (*i).second;
		}
		i++;//����������� ��������
		k++;//����������� ������� ���������
	}

	multimap<int, T> buf;
	it i1 = m.begin();//������ �������� � ������
	k = 0;//�������� ������� ���������
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1, (*i1).second));//��������� �������� � �������� ���������
		k++;
		i1++;
	}
	buf.insert(make_pair(0, max));//��������� � ������ ���� �������
	return buf;
}

//�������� ��� ��������
template <class D, class T>
multimap<int, T> Container<D, T>::Del_min()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();//������ �������� � ������
	int k = 0;//������� ���������
	int n = 0;//����� ������������ ��������
	T min = (*i).second;//����������� �������

	while (i != m.end())
	{
		if ((*i).second < min)
		{
			min = (*i).second;
		}
		i++;
	}

	multimap<int, T> buf;
	it i1 = m.begin();//������ �������� � ������
	while (i1 != m.end())
	{
		if ((*i1).second != min)
			buf.insert(make_pair((*i1).first, (*i1).second));//��������� �������� � �������� ���������
		i1++;
	}
	return buf;
}

//���������� �������� �� ���� ���������
template <class D, class T>
multimap<int, T> Container<D, T>::Add_srednee()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();
	T sum;//����� ���������
	int n = 1;//���������� ���������
	while (i != m.end())
	{
		sum = sum + (*i).second;
		n++;
		i++;
	}

	sum = sum / n;

	multimap<int, T> buf;
	it i1 = m.begin();
	while (i1 != m.end())
	{
		buf.insert(make_pair((*i1).first, (*i1).second + sum));
		i1++;
	}
	return buf;
}