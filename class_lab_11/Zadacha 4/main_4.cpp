#include "Money.h"
#include <stack>
#include <vector>

using namespace std;

typedef stack<Money>St;//определили стек
typedef vector<Money>Vec;//определили вектор

//ф-ия для формирования стека
St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//ввод переменной
		s.push(m);//добавляем её в стек
	}
	return s;//вернули стек как результат ф-ии
}

//копируем стек в вектор
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершины стека
		v.push_back(s.top());
		s.pop();
	}
	return v;//возвращаем вектор как результат ф-ии
}

//копируем вектор в стек
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = v.size() - 1; i >= 0; i--)
		s.push(v[i]);//добавить в стек элемент вектора
	return s;
}

//вывод стека
void print_stack(St s)
{
	Vec temp;
	temp = copy_stack_to_vector(s);//копируем стек в вектор, т.к стек очиститься
	
	//вывод
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	s = copy_vector_to_stack(temp);//заполняем стек из вектора прошлыми его значениями
	cout << "\n";
}

void add_srednee(St s)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	int n = 1;

	Money sum = s.top();//добавляем в сумму 1 элемент
	s.pop();//удаляем его из стека

	//ищем среднее арифметическое
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		n++;
	}
	sum = sum / n;

	//добавляем среднее ко всем элементам и копируем вектор в стек
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + sum;
	s = copy_vector_to_stack(v);
}

//добавление элемента в стек
void add_to_stack(St& s, Money el, int pos)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	v.insert(v.begin() + pos, el);//добавляем в вектор элемент
	s = copy_vector_to_stack(v);//копируем вектор в стек
}

//найти максимальный элемент
Money Max(St s)
{
	Money m = s.top();//максимальный элемент
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор

	while (!s.empty())
	{
		if (s.top() > m) m = s.top();
		s.pop();
	}

	s = copy_vector_to_stack(v);
	return m;
}

//найти минимальный элемент
int Min(St s)
{
	Money m = s.top();//минимальный элемент
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	int i = 0, min_i = 0;

	while (!s.empty())
	{
		if (s.top() < m)
		{
			m = s.top();
			min_i = i;
		}
		s.pop();
		i++;
	}

	s = copy_vector_to_stack(v);
	return min_i;
}

//удалить min элемент
void delete_from_stack(St& s)
{
	int m = Min(s);//находим минимальный элемент
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	v.erase(v.begin() + m);//удаляем минимальный элемент
	s = copy_vector_to_stack(v);//копируем вектор в стек
}

int main()
{
	try
	{
		Money m;
		St s;

		//создаём мн-во s с n элементами
		int n = 0;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;
		s = make_stack(n);

		cout << "\n1. Stack: "; print_stack(s);//выводим содержимое стека
		cout << "2. Money\n";

		cout << "3. Add max elem in front: ";//добавляем в начало макс элем
		m = Max(s);
		add_to_stack(s, m, 0);
		print_stack(s);

		cout << "4. Del min elem: ";//удаляем мин элем
		delete_from_stack(s);
		print_stack(s);

		cout << "5. Add srednee all elem: ";//добавить среднее ко всем элементам
		add_srednee(s);
		print_stack(s);
	}
	catch (int)
	{
		cout << "ERROR!\n";
	}
	return 0;
}
