#pragma once
#include "Money.h"
#include <vector>
#include <iostream>

using namespace std;

//шаблон класса
template <class T>
class Set
{
protected:
	vector <T> v;//последовательный контейнер для хранения элементов мн-ва
	int len;
public:
	//конструкторы
	Set(void);
	Set(int);

	//деструктор
	~Set(void);

	//печать
	void Print();

	//найти макс элемент
	T& max();
	//добавить элемент в начало
	void add_begin(T elem);

	//найти минимальный элемент
	int min();
	//удалить элемент
	void del(int);

	//добавить среднее арифметическое
	void add_srednee();
};


//===================================

//конструкторы
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

//деструктор
template <class T>
Set<T>::~Set()
{
}

//печать
template <class T>
void Set<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//поиск максимального элемента
template <class T>
T& Set<T>::max()
{
	T Max = v[0];//макс элемент
	int n = 0;//номер макс элемента

	for (int i = 0; i < v.size(); i++)
		if (v[i] > Max)
		{
			Max = v[i];
			n = i;
		}
	return v[n];
}
//добавление элемента в начало
template <class T>
void Set<T>::add_begin(T elem)
{
	v.insert(v.begin(), elem);
}

//поиск мин элемента
template <class T>
int Set<T>::min()
{
	T Min = v[0];//мин элемент
	int n = 0;//номер мин элемента

	for (int i = 0; i < v.size(); i++)
		if (v[i] < Min)
		{
			Min = v[i];
			n = i;
		}
	return n;
}
//удаление элемента
template <class T>
void Set<T>::del(int pos)
{
	v.erase(v.begin() + pos);
}

//добавление среднего
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