#include <map>
#include <iostream>

using namespace std;

typedef multimap<int, double> Tmultimap;//определяем тип для работы с multimap
typedef Tmultimap::iterator it;//итератор

//создание словаря
Tmultimap make_multimap(int n)
{
	Tmultimap m;//пустой словарь
	double a;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter a >> ";
		cin >> a;
		//создаём пару и добавляем в multimap
		m.insert(make_pair(i, a));
	}
	return m;//вернули m как результат ф-ии
}

//печать словаря
void Print_multimap(Tmultimap m)
{
	it i = m.begin();
	while (i != m.end())
	{
		cout << i->first << ":" << i->second << " ";
		i++;
	}
	cout << "\n";
}

//поиск максималтного элемента и добавление его в начало
Tmultimap Add_max(Tmultimap m)
{
	it i = m.begin();
	int k = 0;//счётчик элементов
	double max = (*i).second;//максимальный элемент

	while (i != m.end())
	{
		if ((*i).second > max)
		{
			max = (*i).second;
		}
		i++;//увеличиваем итератор
		k++;//увеличиваем счетчик элементов
	}

	Tmultimap buf;
	it i1 = m.begin();//ставим итератор в начало
	k = 0;//обнуляем счётчик элементов
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1,(*i1).second));//сохраняем значение в буферный мультимап
		k++;
		i1++;
	}	
	buf.insert(make_pair(0, max));//добавляем в начало макс элемент
	return buf;
}

//удаление минимального элемента
Tmultimap Del_min(Tmultimap m)
{
	it i = m.begin();//ставим итератор в начало
	int k = 0;//счётчик элементов
	int n = 0;//номер минимального элемента
	double min = (*i).second;//минимальный элемент

	while (i != m.end())
	{
		if ((*i).second < min)
		{
			min = (*i).second;
		}
		i++;
	}
	
	Tmultimap buf;
	it i1 = m.begin();//ставим итератор в начало
	while (i1 != m.end())
	{
		if ((*i1).second != min)
			buf.insert(make_pair((*i1).first, (*i1).second));//сохраняем значение в буферный мультимап
		i1++;
	}
	return buf;
}

//добавить среднее арифметическое
Tmultimap Add_srednee(Tmultimap m)
{
	it i = m.begin();
	double sum = 0;//сумма элементов
	int n = 1;//количество элементов
	while (i != m.end())
	{
		sum += (*i).second;
		n++;
		i++;
	}
	sum /= n;

	Tmultimap buf;
	it i1 = m.begin();
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

		Tmultimap mmap;//создаём контейнер
		mmap = make_multimap(n);
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