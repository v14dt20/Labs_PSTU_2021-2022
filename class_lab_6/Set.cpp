#include <iostream>
#include "Set.h"

using namespace std;

Iterator& Iterator::operator++ (int n)//передвинуть итератор на один вправо
{
    elem++;
    return *this;
}
Iterator& Iterator::operator- (int n)//передвинуть итератор на n влево
{
    elem -= n;
    return *this;
}

//конструкторы
Set::Set()
{
    size = 0;
    data = 0;

    begin.elem = &data[0];
    end.elem = &data[size];
}
Set::Set(int n)
{
    size = n;
    data = new int[n];
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }

    begin.elem = &data[0];
    end.elem = &data[size];
}
Set::Set(const Set& set1)
{
    size = set1.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = set1.data[i];
    }

    begin.elem = &data[0];
    end.elem = &data[size];
}

//деструктор
Set::~Set()
{
    delete[] data;
    size = 0;
}

Set Set::operator= (const Set& set1)//оператор присваивания
{
    if (this == &set1)
		return *this; //проверка на самоприсваивание
	if (size != 0)
		delete[] data;
	size = set1.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = set1.data[i];
	//установление указателей на первый и последний элементы
	begin.elem = &data[0];
	end.elem = &data[size];
	return *this;
}
int Set::operator[] (int n)//оператор доступа к элементу по индексу
{
    if (n < 0 || n > size) cout << "Index out of range!\n";
    else return data[n];
}
bool Set::operator== (Set& set1)//оператор равенства
{
    bool flag = true;
    if (size == set1.size)
        for (int i = 0; i < size; i++)
            if (data[i] != set1.data[i]) { flag = false; break; }
            else flag = true;
    else flag = false;

    return flag;
}
bool Set::operator> (int num)//оператор на проверку вхождения элемента в Set
{
    bool flag = false;
    for (int i = 0; i < size; i++)
        if (data[i] == num) { flag = true; break; }
    return flag;
}

//операторы для работы с входным/выходным потоками
istream& operator>> (istream& in, Set& set1)
{
    int n;
    cout << "Enter size >> "; in >> n;
    Set buf(n);

    cout << "Input data >> ";
    int* new_data = new int[n];
    for (int i = 0; i < n; i++)
        in >> new_data[i];

    buf.size = n;
    buf.data = new_data;

    set1 = buf;

    delete[] new_data;
    return in;
}
ostream& operator<< (ostream& out, const Set& set1)
{
    for (int i = 0; i < set1.size; i++)
    {
        out << set1.data[i] << " ";
    }
    cout << "\n";
    return out;
}