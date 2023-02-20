#pragma once
#include "Money.h"
#include <string>
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть файл для записи
	if (!stream) return -1;//ошибка открытии файла

	int n;
	Money m;
	cout << "Enter num >> "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//ввод атрибутов объекта в главный поток
		stream << m;//запись атрибутов объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть кол-во записанных объектов
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть файл для чтения
	if (!stream) return -1;//ошибка открытия файла

	Money m; int i = 0;
	while (stream>>m)//пока в потоке что-то есть
	{
		cout << m;
		i++;
	}
	stream.close();//закрытие потока
	return i;//количество элементов
}

int del_objects(const char* f_name, long Rub, int Kop)
{
	fstream stream(f_name, ios::in);//открыть файл на чтение
	fstream temp("temp", ios::out | ios::trunc);//открыть файл temp на запись
	if (!stream) return -1;//ошибка открытия файла

	Money m; int i = 0;
	while (stream >> m)//пока нет конца файла, работаем с файлами
	{
		if (stream.eof()) break;//если прочитан признак конца файла, то выходим из цикла
		i++;

		if (m.Get_Rub() != Rub && m.Get_Kop() != Kop)//если атрибуты объекта не равны пришедшим значениям, то объект записывается в temp
			temp << m;
	}
	//закрыть потоки
	stream.close();
	temp.close();

	remove(f_name);//удалить файл f_name
	rename("temp", f_name);//переименовать файл temp
	return i; //количество прочитанных объектов
}

int boost_all(const char* f_name, long Rub, int Kop)
{
	fstream stream(f_name, ios::in);//открыть файл на чтение
	fstream temp("temp", ios::out | ios::trunc);//открыть файл temp на запись
	if (!stream) return -1;//ошибка открытия файла

	Money m; int i = 0;
	while (stream >> m)//пока нет конца файла, работаем с файлами
	{
		if (stream.eof()) break;//если прочитан признак конца файла, то выходим из цикла
		
		m.Set_Rub(m.Get_Rub() + Rub);
		m.Set_Kop(m.Get_Kop() + Kop);
		temp << m;
		i++;
	}
	//закрыть потоки
	stream.close();
	temp.close();

	remove(f_name);//удалить файл f_name
	rename("temp", f_name);//переименовать файл temp
	return i; //количество прочитанных объектов 
}

int add_file(const char* f_name, int K, int N)
{
	fstream stream(f_name, ios::in);//открыть файл на чтение
	fstream temp("temp", ios::out | ios::trunc);//открыть файл temp на запись
	if (!stream) return -1;//ошибка открытия файла

	Money m; int i = 0, l = 0;
	Money new_m;
	while (stream >> m)//пока нет конца файла, работаем с файлами
	{
		if (stream.eof()) break;//если прочитан признак конца файла, то выходим из цикла

		if (i == N)
			for (int i = 0; i < K; i++)
			{
				cin >> new_m;
				temp << new_m;
				l++;
			}
		temp << m;
		i++;
	}
	//закрыть потоки
	stream.close();
	temp.close();

	remove(f_name);//удалить файл f_name
	rename("temp", f_name);//переименовать файл temp
	return l; //количество добавленных объектов
}