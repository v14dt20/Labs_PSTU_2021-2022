#pragma once
#include "Money.h"
#include <iostream>
#include <map>

using namespace std;


template <class D, class T>
class Container
{
protected:
	multimap<int, T> m;//словарь
	int len = 0;//длина словаря
public:
	//конструкторы
	Container(void);
	Container(int);

	//деструктор
	~Container(void);

	void Print();//печать
	multimap<int, T> Add_max();//добавить макс элемент
	multimap<int, T> Del_min();//удалить мин элемент
	multimap<int, T> Add_srednee();//добавить среднее к каждому элементу
};

//=========================================
//конструкторы
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

//деструктор
template <class D, class T>
Container<D, T>::~Container(void)
{
}

//печать
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

//добавление макс элемента
template <class D, class T>
multimap<int, T> Container<D, T>::Add_max()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();
	int k = 0;//счётчик элементов
	T max = (*i).second;//максимальный элемент

	while (i != m.end())
	{
		if ((*i).second > max)
		{
			max = (*i).second;
		}
		i++;//увеличиваем итератор
		k++;//увеличиваем счетчик элементов
	}

	multimap<int, T> buf;
	it i1 = m.begin();//ставим итератор в начало
	k = 0;//обнуляем счётчик элементов
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1, (*i1).second));//сохраняем значение в буферный мультимап
		k++;
		i1++;
	}
	buf.insert(make_pair(0, max));//добавляем в начало макс элемент
	return buf;
}

//удаление мин элемента
template <class D, class T>
multimap<int, T> Container<D, T>::Del_min()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();//ставим итератор в начало
	int k = 0;//счётчик элементов
	int n = 0;//номер минимального элемента
	T min = (*i).second;//минимальный элемент

	while (i != m.end())
	{
		if ((*i).second < min)
		{
			min = (*i).second;
		}
		i++;
	}

	multimap<int, T> buf;
	it i1 = m.begin();//ставим итератор в начало
	while (i1 != m.end())
	{
		if ((*i1).second != min)
			buf.insert(make_pair((*i1).first, (*i1).second));//сохраняем значение в буферный мультимап
		i1++;
	}
	return buf;
}

//добавление среднего ко всем элементам
template <class D, class T>
multimap<int, T> Container<D, T>::Add_srednee()
{
	typedef multimap<int, T>::iterator it;
	it i = m.begin();
	T sum;//сумма элементов
	int n = 1;//количество элементов
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