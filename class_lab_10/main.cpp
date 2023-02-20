#include "Money.h"
#include "file_work.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Money a;
	int k, c;
	char file_name[30];
	do
	{
		//Menu
		cout << "\n1. Create file";//создать файл
		cout << "\n2. Print file";//вывести файл
		cout << "\n3. Delete objects";//удалить объекты с определёнными значениями
		cout << "\n4. Boost all elem on 1,50";//увеличить все элементы на 1 руб 50 коп
		cout << "\n5. Add objects on file";//добавить k элем после n-го
		cout << "\n0. Exit\n";//выход
		cout << ">"; cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter file name >> "; cin >> file_name;//задаем имя файла
			k = make_file(file_name);//вызываем функцию для создания файла
			if (k < 0)
				cout << "Can't create file\n";//сообщение об ошибке
			break;
		case 2:
			cout << "Enter file name >> "; cin >> file_name;
			k = print_file(file_name);//вызываем функцию для печати файла
			if (k < 0)
				cout << "Can't open file\n";//если файла не существует
			if (k == 0)
				cout << "Empty file\n";//если файл пустой
			break;
		case 3:
			cout << "Enter file name >> "; cin >> file_name;
			int Rub, Kop;
			cout << "Enter Rub and Kop >> "; cin >> Rub >> Kop;
			
			k = del_objects(file_name, Rub, Kop);//вызываем функцию для удаления объектов
			if (k < 0)
				cout << "Can't open file\n";//если файла не существует
			if (k == 0)
				cout << "Empty file\n";//если файл пустой
			break;
		case 4:
			cout << "Enter file name >> "; cin >> file_name;
			
			k = boost_all(file_name, 1, 50);//вызываем функцию для удаления объектов
			if (k < 0)
				cout << "Can't open file\n";//если файла не существует
			if (k == 0)
				cout << "Empty file\n";//если файл пустой
			break;
		case 5:
			cout << "Enter file name >> "; cin >> file_name;
			
			int K, N;
			cout << "Enter K and N >> "; cin >> K >> N;
			k = add_file(file_name, K, N);//вызываем функцию для добавления объектов
			if (k < 0)
				cout << "Can't open file\n";//если файла не существует
			if (k == 0)
				cout << "Nothing add\n";//если ничего не добавили
			break;
		}
	} while (c != 0);

	return 0;
}