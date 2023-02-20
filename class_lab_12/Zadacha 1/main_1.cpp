#include <map>
#include <iostream>

using namespace std;

typedef multimap<int, double> Tmultimap;//���������� ��� ��� ������ � multimap
typedef Tmultimap::iterator it;//��������

//�������� �������
Tmultimap make_multimap(int n)
{
	Tmultimap m;//������ �������
	double a;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter a >> ";
		cin >> a;
		//������ ���� � ��������� � multimap
		m.insert(make_pair(i, a));
	}
	return m;//������� m ��� ��������� �-��
}

//������ �������
void Print_multimap(Tmultimap m)
{
	it i = m.begin();
	while (i != m.end())
	{
		cout << i->first << ":" << i->second << " ";
		i++;
	}
	cout << "\n";
}

//����� ������������� �������� � ���������� ��� � ������
Tmultimap Add_max(Tmultimap m)
{
	it i = m.begin();
	int k = 0;//������� ���������
	double max = (*i).second;//������������ �������

	while (i != m.end())
	{
		if ((*i).second > max)
		{
			max = (*i).second;
		}
		i++;//����������� ��������
		k++;//����������� ������� ���������
	}

	Tmultimap buf;
	it i1 = m.begin();//������ �������� � ������
	k = 0;//�������� ������� ���������
	while (i1 != m.end())
	{
		buf.insert(make_pair(k + 1,(*i1).second));//��������� �������� � �������� ���������
		k++;
		i1++;
	}	
	buf.insert(make_pair(0, max));//��������� � ������ ���� �������
	return buf;
}

//�������� ������������ ��������
Tmultimap Del_min(Tmultimap m)
{
	it i = m.begin();//������ �������� � ������
	int k = 0;//������� ���������
	int n = 0;//����� ������������ ��������
	double min = (*i).second;//����������� �������

	while (i != m.end())
	{
		if ((*i).second < min)
		{
			min = (*i).second;
		}
		i++;
	}
	
	Tmultimap buf;
	it i1 = m.begin();//������ �������� � ������
	while (i1 != m.end())
	{
		if ((*i1).second != min)
			buf.insert(make_pair((*i1).first, (*i1).second));//��������� �������� � �������� ���������
		i1++;
	}
	return buf;
}

//�������� ������� ��������������
Tmultimap Add_srednee(Tmultimap m)
{
	it i = m.begin();
	double sum = 0;//����� ���������
	int n = 1;//���������� ���������
	while (i != m.end())
	{
		sum += (*i).second;
		n++;
		i++;
	}
	sum /= n;

	Tmultimap buf;
	it i1 = m.begin();
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

		Tmultimap mmap;//������ ���������
		mmap = make_multimap(n);
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