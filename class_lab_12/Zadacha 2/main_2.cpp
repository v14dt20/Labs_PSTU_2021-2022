#include "Money.h"
#include <iostream>
#include <map>

using namespace std;

typedef multimap<int, Money> Tmmap;//определяем тип работы с мультимап
typedef multimap<int, Money>::iterator It;//итератор

//создание словаря
Tmmap Make_multimap(int n)
{
	Tmmap m;//пустой словарь
	Money a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//создаёс пару и добавляем
		m.insert(make_pair(i, a));
	}
	return m;//вернули словарь как результат работы ф-ии
}

//печать словаря
void Print_multimap(Tmmap m)
{
	It i = m.begin();
	while (i != m.end())
	{
		cout << i->first << ":" << i->second << " ";
		i++;
	}
	cout << "\n";
}

//поиск максималтного элемента и добавление его в начало
Tmmap Add_max(Tmmap m)
{
	It i = m.begin();
	int k = 0;//счётчик элементов
	Money max = (*i).second;//максимальный элемент

	while (i != m.end())
	{
		if ((*i).second > max)
		{
			max = (*i).second;
		}
		i++;//увеличиваем итератор
		k++;//увеличиваем счетчик элементов
	}

	Tmmap buf;
	It i1 = m.begin();//ставим итератор в начало
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

//удаление минимального элемента
Tmmap Del_min(Tmmap m)
{
	It i = m.begin();//ставим итератор в начало
	int k = 0;//счётчик элементов
	int n = 0;//номер минимального элемента
	Money min = (*i).second;//минимальный элемент

	while (i != m.end())
	{
		if ((*i).second < min)
		{
			min = (*i).second;
		}
		i++;
	}

	Tmmap buf;
	It i1 = m.begin();//ставим итератор в начало
	while (i1 != m.end())
	{
		if ((*i1).second != min)
			buf.insert(make_pair((*i1).first, (*i1).second));//сохраняем значение в буферный мультимап
		i1++;
	}
	return buf;
}

//добавить среднее арифметическое
Tmmap Add_srednee(Tmmap m)
{
	It i = m.begin();
	Money sum;//сумма элементов
	int n = 1;//количество элементов
	while (i != m.end())
	{
		sum = sum + (*i).second;
		n++;
		i++;
	}
	
	sum = sum / n;

	Tmmap buf;
	It i1 = m.begin();
	while (i1 != m.end())
	{
		buf.insert(make_pair((*i1).first, (*i1).second + sum));
		i1++;
	}
	return buf;
}

int main()
{
	try
	{
		int n = 0;
		cout << "Enter n >> ";//вводим размер мултимапа
		cin >> n;
		if (n <= 0) throw 1;//создаём исключение

		Tmmap mmap;//создаём контейнер
		mmap = Make_multimap(n);
		cout << "\n";
		Print_multimap(mmap);//выводим контейнер

		cout << "Add max elem: ";
		mmap = Add_max(mmap);//добавляем макс элемент
		Print_multimap(mmap);//выводим контейнер

		cout << "Del min: ";
		mmap = Del_min(mmap);//удаляем мин элемент
		Print_multimap(mmap);//выводим контейнер

		cout << "Add srednee: ";
		mmap = Add_srednee(mmap);//добавляем всем элементам среднее
		Print_multimap(mmap);//выводим контейнер
	}
	catch (int)
	{
		cout << "Error!\n";
	}
	return 0;
}