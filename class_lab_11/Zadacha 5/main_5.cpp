#include "Set.h"
#include "Money.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	try
	{	
		//создаём set с n элементами
		int n = 0;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;
		Set<Money> m(n);

		cout << "\n1. Stack in Set: "; m.Print();//выводим содержимое стека
		cout << "2. Money\n";

		cout << "3. Add max elem in front: ";//добавляем в начало макс элемент
		m.Add_max();
		m.Print();

		cout << "4. Del min elem: ";//удаляем мин элемент
		m.Del_min();
		m.Print();

		cout << "5. Add srednee all elem: ";//добавляем среднее всем элементам
		m.Add_srednee();
		m.Print();
	}
	catch (int)
	{
		cout << "ERROR!\n";
	}
	return 0;
}