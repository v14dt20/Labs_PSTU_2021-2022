#include "Money.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<Money> Tvec;
Money s;//������� ���������� ���������� Money ��� ��������� � �������� ���������

//������� �������� ��� ��������� ��������� �������� � �������� Money
struct Greater_s//������ ��� s
{
	bool operator() (Money m)
	{
		if (m > s) return true;
		else return false;
	}
};

//������������ �������
Tvec make_vector(int n)
{
	Money a;
	Tvec v;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

//������ �������
void print_vector(Tvec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//����� ��������
Money srednee(Tvec v)
{
	Money sum = v[0];
	for (int i = 1; i < v.size(); i++)
		sum = sum + v[i];
	return sum / v.size();
}

//������� ����������
void add(Money& m)
{
	m = m + s;
}


int main()
{
	int n;
	cout << "Enter n >> ";
	cin >> n;

	Tvec v = make_vector(n);
	print_vector(v);

	Tvec::iterator i;//������� ��������
	cout << "Add max: ";
	i = max_element(v.begin(), v.end());
	Money max = (*i);//����� ���� �������
	v.insert(v.begin(), max);//�������� ���� ������� � ������
	print_vector(v);

	cout << "Del min: ";
	i = min_element(v.begin(), v.end());
	Money min = (*i);//����� ��� �������
	remove(v.begin(), v.end(), min);//������� ��� �������
	print_vector(v);

	cout << "Add srednee: ";
	s = srednee(v);
	for_each(v.begin(), v.end(), add);
	print_vector(v);

	return 0;
}