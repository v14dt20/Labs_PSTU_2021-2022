#include "Money.h"
#include "Container.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	try
	{
		int n = 0;
		cout << "Enter n >> ";//вводим размер мултимапа
		cin >> n;
		if (n <= 0) throw 1;//создаём исключение

		Container<int, Money> mmap(n);//создаём контейнер
		cout << "\n";
		mmap.Print();//выводим контейнер

		cout << "Add max elem: ";
		mmap.Add_max();//добавляем макс элемент
		mmap.Print();//выводим контейнер

		cout << "Del min: ";
		mmap.Del_min();//удаляем мин элемент
		mmap.Print();//выводим контейнер

		cout << "Add srednee: ";
		mmap.Add_srednee();//добавляем всем элементам среднее
		mmap.Print();//выводим контейнер
	}
	catch (int)
	{
		cout << "Error!\n";
	}
	return 0;
}