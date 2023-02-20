#include "Set.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()
{
	//контролируемый блок
	try
	{
		Set a(3);//множество из 3 элементов
		Set b;//пустое множество

		b = ++a;
		cout << a << "\n========================\n";
		cout << b << "\n========================\n";

		int i;
		cout << "Enter index >> "; cin >> i;

		//вывод элемента с номером i, если он меньше 0 или больше/равен 3, генерируется исключительная ситуация
		cout << a[i] << "\n";

		cout << a + b << "\n";
	}
	catch (Error& err)
	{
		err.what();
	}

	return 0;
}