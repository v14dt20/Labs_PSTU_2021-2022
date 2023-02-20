#include "Money.h"
#include <iostream>
#include <map>

using namespace std;

typedef multimap<int, Money> Tmmap;//���������� ��� ������ � ���������
typedef multimap<int, Money>::iterator It;//��������

//�������� �������
Tmmap Make_multimap(int n)
{
	Tmmap m;//������ �������
	Money a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		//������ ���� � ���������
		m.insert(make_pair(i, a));
	}
	return m;//������� ������� ��� ��������� ������ �-��
}

//������ �������
void Print_multimap(Tmmap m)
{
	It i = m.begin();
	while (i != m.end())
	{
		cout << i->first << ":" << i->second << " ";
		i++;
	}
	cout << "\n";
}

//����� ������������� �������� � ���������� ��� � ������
Tmmap Add_max(Tmmap m)
{
	It i = m.begin();
	int k = 0;//������� ���������
	Money max = (*i).second;//������������ �������

	while (i != m.end())
	{
		if ((*i).second > max)
		{
			max = (*i).second;
		}
		i++;//����������� ��������
		k++;//����������� ������� ���������
	}

	Tmmap buf;
	It i1 = m.begin();//������ �������� � ������
	k = 0;//�������� ������� ���������
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1, (*i1).second));//��������� �������� � �������� ���������
		k++;
		i1++;
	}
	buf.insert(make_pair(0, max));//��������� � ������ ���� �������
	return buf;
}

//�������� ������������ ��������
Tmmap Del_min(Tmmap m)
{
	It i = m.begin();//������ �������� � ������
	int k = 0;//������� ���������
	int n = 0;//����� ������������ ��������
	Money min = (*i).second;//����������� �������

	while (i != m.end())
	{
		if ((*i).second < min)
		{
			min = (*i).second;
		}
		i++;
	}

	Tmmap buf;
	It i1 = m.begin();//������ �������� � ������
	while (i1 != m.end())
	{
		if ((*i1).second != min)
			buf.insert(make_pair((*i1).first, (*i1).second));//��������� �������� � �������� ���������
		i1++;
	}
	return buf;
}

//�������� ������� ��������������
Tmmap Add_srednee(Tmmap m)
{
	It i = m.begin();
	Money sum;//����� ���������
	int n = 1;//���������� ���������
	while (i != m.end())
	{
		sum = sum + (*i).second;
		n++;
		i++;
	}
	
	sum = sum / n;

	Tmmap buf;
	It i1 = m.begin();
	while (i1 != m.end())
	{
		buf.insert(make_pair((*i1).first, (*i1).second + sum));
		i1++;
	}
	return buf;
}

int main()
{
	try
	{
		int n = 0;
		cout << "Enter n >> ";//������ ������ ���������
		cin >> n;
		if (n <= 0) throw 1;//������ ����������

		Tmmap mmap;//������ ���������
		mmap = Make_multimap(n);
		cout << "\n";
		Print_multimap(mmap);//������� ���������

		cout << "Add max elem: ";
		mmap = Add_max(mmap);//��������� ���� �������
		Print_multimap(mmap);//������� ���������

		cout << "Del min: ";
		mmap = Del_min(mmap);//������� ��� �������
		Print_multimap(mmap);//������� ���������

		cout << "Add srednee: ";
		mmap = Add_srednee(mmap);//��������� ���� ��������� �������
		Print_multimap(mmap);//������� ���������
	}
	catch (int)
	{
		cout << "Error!\n";
	}
	return 0;
}