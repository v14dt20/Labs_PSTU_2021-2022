#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Set
{
	int size;//размер
	int* beg;//указатель на первый элемент динамического массива
public:
	//конструкторы
	Set(void);//без параметров
	Set(int);//с 1 параметром
	Set(int, int*);//с 2 параметрами
	Set(const Set&);//копирования

	//деструктор
	~Set(void);

	const Set& operator= (const Set&);//операция присваивания
	int operator[] (int);//операция доступа по индексу
	int operator() ();//операция выводящая размер множества
	Set operator+ (const Set&);//объединение множеств
	Set operator++ ();//добавление элемнта в множество

	//дружественные функции ввода-вывода
	friend ostream& operator<< (ostream&, const Set&);
	friend istream& operator>> (istream&, Set&);
};
