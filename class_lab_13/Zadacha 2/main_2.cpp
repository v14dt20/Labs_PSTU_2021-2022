#include "Money.h"
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef stack<Money> St;//определили стек
typedef vector<Money> Vec;//определили вектор
Money a;

//ф-ия для формирования стека
St make_stack(int n)
{
	St s;
	Money m;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s.push(m);
	}
	return s;
}

//копируем стек в вектор
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

//копируем вектор в стек
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
		s.push(v[i]);
	return s;
}

//вывод стека
void print_stack(St s)
{
	Vec temp;
	temp = copy_stack_to_vector(s);//копируем стек в вектор

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	s = copy_vector_to_stack(temp);//копируем вектор в стек
	cout << "\n";
}

//добавление
void add(Money& m)
{
	m = m + a;
}

int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	St s = make_stack(n);
	print_stack(s);

	cout << "Add max: ";
	Vec temp = copy_stack_to_vector(s);
	Vec::iterator i = max_element(temp.begin(), temp.end());
	Money max = (*i);
	temp.push_back(max);
	s = copy_vector_to_stack(temp);
	print_stack(s);

	cout << "Del min: ";
	temp = copy_stack_to_vector(s);
	i = min_element(temp.begin(), temp.end());
	temp.erase(i);
	s = copy_vector_to_stack(temp);
	print_stack(s);

	cout << "Add srednee: ";
	temp = copy_stack_to_vector(s);
	Money sum = temp[0];
	for (int i = 1; i < temp.size(); i++)
		sum = sum + temp[i];
	a = sum / temp.size();
	for_each(temp.begin(), temp.end(), add);
	s = copy_vector_to_stack(temp);
	print_stack(s);


	return 0;
}