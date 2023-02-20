#include "Money.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<Money> Vec;//определяем тип работы с вектором

//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)//заполняем вектор рандомными значениями
	{
		Money a;
		a.Set_Rub(rand() % 1000);
		a.Set_Kop(rand() % 100);
		v.push_back(a);//добавляем элемент в конец вектора
	}
	return v;//возвращаем вектор как результат
}

//функция для печати вектора
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//вычисление среднего
void add_srednee(Vec& v)
{
	int sum = 0;
	
	for (int i = 0; i < v.size(); i++)
		sum += v[i].Get_Rub() * 100 + v[i].Get_Kop();
	
	int n = v.size();
	sum /= n;

	for (int i = 0; i < v.size(); i++)
	{
		v[i].Set_Rub(v[i].Get_Rub() + sum / 100);
		v[i].Set_Kop(v[i].Get_Kop() + sum % 100);
	}
}

//поиск макс элемента
int max(Vec v)
{
	int max = v[0].Get_Rub() * 100 + v[0].Get_Kop();//макс элем
	int n = 0;//номер макс элем

	for (int i = 0; i < v.size(); i++)
		if ((v[i].Get_Rub() * 100 + v[i].Get_Kop()) > max)
		{
			max = (v[i].Get_Rub() * 100 + v[i].Get_Kop());
			n = i;
		}

	return n;
}

//поиск мин элемента
int min(Vec v)
{
	int m = v[0].Get_Rub() * 100 + v[0].Get_Kop();//мин элемент
	int n = 0;//индекс мин элемента

	for (int i = 0; i < v.size(); i++)
		if ((v[i].Get_Rub() * 100 + v[i].Get_Kop()) < m)
		{
			m = (v[i].Get_Rub() * 100 + v[i].Get_Kop());
			n = i;
		}
	return n;
}
//удаление элемента
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}

//основная функция
int main()
{
	try
	{
		vector<Money> v;//создаём вектор
		vector<Money>::iterator vi = v.begin();//создаём итератор и ставим его в начало вектора

		int n;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;

		v = make_vector(n);//формируем вектор размером n

		cout << "\n1. Vector: "; print_vector(v);//выводим вектор
		cout << "2. Type: Money\n";

		cout << "3. Add max elem in front: ";
		//добавление макс элемента в начало
		int max_el = max(v);
		v.insert(v.begin(), v[max_el]);
		print_vector(v);

		cout << "4. Delete min elem: ";
		//удалить мин элемент
		int min_el = min(v);
		del_vector(v, min_el);
		print_vector(v);

		cout << "5. Add srednee all elem: ";
		//добавить среднее ко всем елементам
		add_srednee(v);
		print_vector(v);
	}
	catch (int)//обработка ошибок
	{
		cout << "ERROR!\n";
	}

	return 0;
}