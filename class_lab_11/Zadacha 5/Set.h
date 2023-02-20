#pragma once
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <class T>
class Set
{
protected:
	stack <T> s;//контейнер
	int len;//размер контейнера
public:
	//конструкторы
	Set(void);
	Set(int);
	Set(const Set&);

	//деструктор
	~Set(void);

	//печать
	void Print();

	//добавить среднее
	T Srednee();
	void Add_srednee();

	//добавить максимальный элемент в начало
	void Add_max();

	//удалить мин элемент
	void Del_min();

};

//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;//контейнер вектор

	while (!s.empty())//пока стек не пустой добавляем элемент в вектор и удаляем его из стека
	{
		v.insert(v.begin(), s.top());
		s.pop();
	}
	return v;//вернули вектор
}

//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;//стек
	for (int i = 0; i < v.size(); i++)//заполняем стек из вектора
		s.push(v[i]);
	return s;//вернули стек
}

//конструкторы
template <class T>
Set<T>::Set(void)
{
	len = 0;
}
template <class T>
Set<T>::Set(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}
template <class T>
Set<T>::Set(const Set& s)
{
	len = s.len;
	//копируем значения стека Set.s в вектор v
	vector<T> v = copy_stack_to_vector(s);
	//копируем вектор v в стек s
	s = copy_vector_to_stack(v);
}

//деструктор
template <class T>
Set<T>::~Set(void)
{
}

//печать
template <class T>
void Set<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << " ";//вывод элемента при вершине
		s.pop();
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
	cout << "\n";
}

//добавить среднее
template <class T>
T Set<T>::Srednee()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	T sum = s.top();//сумма всех элементов
	int n = 1;
	s.pop();

	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		++n;
	}
	s = copy_vector_to_stack(v);
	return sum / n;//среднее
}
template <class T>
void Set<T>::Add_srednee()
{
	vector<T> v;
	T sred = Srednee();
	while (!s.empty())
	{
		v.push_back(sred + s.top());
		s.pop();
	}
	s = copy_vector_to_stack(v);
}


//добавление макс элемента в начало стека
template <class T>
void Set<T>::Add_max()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	T max = s.top();//максимальный элемент

	while (!s.empty())//пока стек не пустой
	{
		if (s.top() > max)
			max = s.top();
		s.pop();
	}

	v.push_back(max);
	s = copy_vector_to_stack(v);//копируем вектор в стек
}

//удаление минимального элемента из стека
template <class T>
void Set<T>::Del_min()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	T min = v[0];//минимальный элемент
	int n = 0;//номер мин элемента

	for (int i = 0; i < v.size(); i++)
		if (v[i] < min)
		{
			min = v[i];
			n = i;
		}

	v.erase(v.begin() + n);
	s = copy_vector_to_stack(v);//копируем вектор в стек
}