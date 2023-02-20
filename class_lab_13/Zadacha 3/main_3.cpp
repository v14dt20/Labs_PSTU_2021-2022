#include "Money.h"
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef multimap<int, Money> Tmmap;//определяем тип работы с мультимап
typedef multimap<int, Money>::iterator it;//итератор
Money s;

//создание словаря
Tmmap make_multimap(int n)
{
	Tmmap m;
	Money a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

//печать словаря
void print_multimap(Tmmap m)
{
	it i = m.begin();
	while (i != m.end())
	{
		cout << i->first << ":" << i->second << " ";
		i++;
	}
	cout << "\n";
}

//среднее
Money srednee(Tmmap m)
{
	it i = m.begin();
	Money sum;//сумма элементов
	int n = 1;//количество элементов
	while (i != m.end())
	{
		sum = sum + (*i).second;
		n++;
		i++;
	}

	return sum / n;
}

//добавление
void add(pair<const int, Money> &p)
{
	p.second = p.second + s;
}

//предикат для сравнения значений в словаре
bool min_pred(pair<int, Money> a, pair<int, Money> b)
{
	return (a.second < b.second);
}

//предикат для сравнения значений в словаре
bool max_pred(pair<int, Money> a, pair<int, Money> b)
{
	return (a.second < b.second);
}

int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	Tmmap m = make_multimap(n);
	print_multimap(m);

	cout << "Add max: ";
	it i = max_element(m.begin(), m.end(), max_pred);
	Money max = (*i).second;
	Tmmap buf;
	it i1 = m.begin();//ставим итератор в начало
	int k = 0;//обнуляем счётчик элементов
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1, (*i1).second));//сохраняем значение в буферный мультимап
		k++;
		i1++;
	}
	buf.insert(make_pair(0, max));//добавляем в начало макс элемент
	m = buf;
	print_multimap(m);

	cout << "Del min: ";
	i = min_element(m.begin(), m.end(), min_pred);
	m.erase(i);
	print_multimap(m);

	cout << "Add srednee: ";
	s = srednee(m);
	for_each(m.begin(), m.end(), add);
	print_multimap(m);
	return 0;
}
