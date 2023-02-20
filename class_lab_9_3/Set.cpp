#include "Set.h"
#include "Error.h"
#include <iostream>

using namespace std;

//конструкторы
Set::Set(void)
{
	size = 0;
	beg = 0;
}
Set::Set(int s)
{
	if (s > MAX_SIZE) throw MaxSizeError();//если рзамер множества больше максимального, генерируетс€ исключение
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
Set::Set(int s, int* mas)
{
	if (s > MAX_SIZE) throw MaxSizeError();//если рзамер множества больше максимального, генерируетс€ исключение
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
Set::Set(const Set& s)
{
	size = s.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = s.beg[i];
}

//деструктор
Set::~Set(void)
{
	if (beg != 0) delete[] beg;
}

//операци€ присваивани€
const Set& Set::operator= (const Set& s)
{
	if (this == &s) return *this;
	if (beg != 0) delete[] beg;

	size = s.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = s.beg[i];

	return *this;
}

//операци€ доступа по индексу
int Set::operator[] (int index)
{
	if (index < 0) throw MinIndexError();//если обращаемс€ к индексу меньше 0, генерируетс€ исключение
	if (index >= size) throw MaxIndexError();//если обращаемс€ к индесу больше текущего размера множества, генерируетс€ исключение
	return beg[index];
}

//операци€ вывод€ща€ размер множества
int Set::operator() ()
{
	return size;
}

//объединение множеств
Set Set::operator+ (const Set& s)
{
	Set temp(size + s.size);//создадим множество с размером равным сумме размеров 2 складываемых множеств
	for (int i = 0; i < size; i++)//заполн€ем temp с 0 элемента элементами из 1 мн-ва
		temp.beg[i] = beg[i];
	for (int i = size; i < temp.size; i++)//заполн€ем temp оставшимис€ элементами из 2 мн-ва
		temp.beg[i] = s.beg[i - size];
	return temp;
}

//добавление элемента в мн-во
Set Set::operator++()
{
	if (size + 1 == MAX_SIZE) throw MaxSizeError();//если при добавлении элемнта размер множества больше макс, генерируетс€ исключение

	int num;
	cout << "Enter num >> "; cin >> num;

	Set temp(size + 1, beg);
	temp.beg[size] = num;
	return temp;
}

//операции ввода-вывода
ostream& operator<< (ostream& out, const Set& s)
{
	if (s.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < s.size; i++)
			out << s.beg[i] << " ";
		out << "\n";
	}
	return out;
}
istream& operator>> (istream& in, Set& s)
{
	for (int i = 0; i < s.size; i++)
		in >> s.beg[i];
	return in;
}