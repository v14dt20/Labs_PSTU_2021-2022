#include "Money.h"
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef multimap<int, Money> Tmmap;//���������� ��� ������ � ���������
typedef multimap<int, Money>::iterator it;//��������
Money s;

//�������� �������
Tmmap make_multimap(int n)
{
	Tmmap m;
	Money a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

//������ �������
void print_multimap(Tmmap m)
{
	it i = m.begin();
	while (i != m.end())
	{
		cout << i->first << ":" << i->second << " ";
		i++;
	}
	cout << "\n";
}

//�������
Money srednee(Tmmap m)
{
	it i = m.begin();
	Money sum;//����� ���������
	int n = 1;//���������� ���������
	while (i != m.end())
	{
		sum = sum + (*i).second;
		n++;
		i++;
	}

	return sum / n;
}

//����������
void add(pair<const int, Money> &p)
{
	p.second = p.second + s;
}

//�������� ��� ��������� �������� � �������
bool min_pred(pair<int, Money> a, pair<int, Money> b)
{
	return (a.second < b.second);
}

//�������� ��� ��������� �������� � �������
bool max_pred(pair<int, Money> a, pair<int, Money> b)
{
	return (a.second < b.second);
}

int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	Tmmap m = make_multimap(n);
	print_multimap(m);

	cout << "Add max: ";
	it i = max_element(m.begin(), m.end(), max_pred);
	Money max = (*i).second;
	Tmmap buf;
	it i1 = m.begin();//������ �������� � ������
	int k = 0;//�������� ������� ���������
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1, (*i1).second));//��������� �������� � �������� ���������
		k++;
		i1++;
	}
	buf.insert(make_pair(0, max));//��������� � ������ ���� �������
	m = buf;
	print_multimap(m);

	cout << "Del min: ";
	i = min_element(m.begin(), m.end(), min_pred);
	m.erase(i);
	print_multimap(m);

	cout << "Add srednee: ";
	s = srednee(m);
	for_each(m.begin(), m.end(), add);
	print_multimap(m);
	return 0;
}
