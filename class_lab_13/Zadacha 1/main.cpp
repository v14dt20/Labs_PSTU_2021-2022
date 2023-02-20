#include "Money.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<Money> Tvec;
Money s;//добавим глобальную переменную Money для сравнения с заданным значением

//добавим предикат для сравнения заданного значения с объектом Money
struct Greater_s//больше чем s
{
	bool operator() (Money m)
	{
		if (m > s) return true;
		else return false;
	}
};

//формирование вектора
Tvec make_vector(int n)
{
	Money a;
	Tvec v;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

//печать вектора
void print_vector(Tvec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//поиск среднего
Money srednee(Tvec v)
{
	Money sum = v[0];
	for (int i = 1; i < v.size(); i++)
		sum = sum + v[i];
	return sum / v.size();
}

//функция добавления
void add(Money& m)
{
	m = m + s;
}


int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	Tvec v = make_vector(n);
	print_vector(v);

	Tvec::iterator i;//создали итератор
	cout << "Add max: ";
	i = max_element(v.begin(), v.end());
	Money max = (*i);//нашли макс элемент
	v.insert(v.begin(), max);//добавили макс элемент в вектор
	print_vector(v);

	cout << "Del min: ";
	i = min_element(v.begin(), v.end());
	Money min = (*i);//нашли мин элемент
	remove(v.begin(), v.end(), min);//удалили мин элемент
	print_vector(v);

	cout << "Add srednee: ";
	s = srednee(v);
	for_each(v.begin(), v.end(), add);
	print_vector(v);

	return 0;
}