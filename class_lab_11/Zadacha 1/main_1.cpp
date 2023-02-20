#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<double> Vec;//определяем тип работы с вектором

//функция для формирования вектора
Vec make_vector(int n)
{
	Vec v;//пустой вектор
	for (int i = 0; i < n; i++)//заполняем вектор рандомными значениями
	{
		double a = rand() % 100;
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
	double sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	int n = v.size();
	sum /= n;

	for (int i = 0; i < v.size(); i++)
		v[i] += sum;
}

//поиск макс элемента
int max(Vec v)
{
	int max = v[0];//макс элем
	int n = 0;//номер макс элем

	for (int i = 0; i < v.size(); i++)
		if (v[i] > max)
		{
			max = v[i];
			n = i;
		}

	return n;
}

//поиск мин элемента
int min(Vec v)
{
	double m = v[0];//мин элемент
	int n = 0;//индекс мин элемента

	for (int i = 0; i < v.size(); i++)
		if (v[i] < m)
		{
			m = v[i];
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
		vector<double> v;//создаём вектор
		vector<double>::iterator vi = v.begin();//создаём итератор и ставим его в начало вектора

		int n;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;

		v = make_vector(n);//формируем вектор размером n

		cout << "\n1. Vector: "; print_vector(v);//выводим вектор
		cout << "2. Type: double\n";

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