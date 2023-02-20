#include "Set.h"
#include "Money.h"
#include <iostream>

using namespace std;

void main()
{
	try
	{
		int n = 0;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;

		Set<Money> mon(n);//создаём мн-во mon с контейнером vector

		cout << "\n1. Vector in Set mon: "; mon.Print();//выводим содержимое контейнера
		cout << "2. Money\n";

		cout << "3. Add max elem in front: ";//добавляем в начало макс элем
		mon.add_begin(mon.max());
		mon.Print();

		cout << "4. Del min elem: ";//удаляем мин элем
		mon.del(mon.min());
		mon.Print();

		cout << "5. Add srednee all elem: ";//добавить среднее ко всем элементам
		mon.add_srednee();
		mon.Print();
	}
	catch (int)
	{
		cout << "ERROR!\n";
	}

}