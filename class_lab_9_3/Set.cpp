#include "Set.h"
#include "Error.h"
#include <iostream>

using namespace std;

//������������
Set::Set(void)
{
	size = 0;
	beg = 0;
}
Set::Set(int s)
{
	if (s > MAX_SIZE) throw MaxSizeError();//���� ������ ��������� ������ �������������, ������������ ����������
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
Set::Set(int s, int* mas)
{
	if (s > MAX_SIZE) throw MaxSizeError();//���� ������ ��������� ������ �������������, ������������ ����������
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
Set::Set(const Set& s)
{
	size = s.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = s.beg[i];
}

//����������
Set::~Set(void)
{
	if (beg != 0) delete[] beg;
}

//�������� ������������
const Set& Set::operator= (const Set& s)
{
	if (this == &s) return *this;
	if (beg != 0) delete[] beg;

	size = s.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = s.beg[i];

	return *this;
}

//�������� ������� �� �������
int Set::operator[] (int index)
{
	if (index < 0) throw MinIndexError();//���� ���������� � ������� ������ 0, ������������ ����������
	if (index >= size) throw MaxIndexError();//���� ���������� � ������ ������ �������� ������� ���������, ������������ ����������
	return beg[index];
}

//�������� ��������� ������ ���������
int Set::operator() ()
{
	return size;
}

//����������� ��������
Set Set::operator+ (const Set& s)
{
	Set temp(size + s.size);//�������� ��������� � �������� ������ ����� �������� 2 ������������ ��������
	for (int i = 0; i < size; i++)//��������� temp � 0 �������� ���������� �� 1 ��-��
		temp.beg[i] = beg[i];
	for (int i = size; i < temp.size; i++)//��������� temp ����������� ���������� �� 2 ��-��
		temp.beg[i] = s.beg[i - size];
	return temp;
}

//���������� �������� � ��-��
Set Set::operator++()
{
	if (size + 1 == MAX_SIZE) throw MaxSizeError();//���� ��� ���������� ������� ������ ��������� ������ ����, ������������ ����������

	int num;
	cout << "Enter num >> "; cin >> num;

	Set temp(size + 1, beg);
	temp.beg[size] = num;
	return temp;
}

//�������� �����-������
ostream& operator<< (ostream& out, const Set& s)
{
	if (s.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < s.size; i++)
			out << s.beg[i] << " ";
		out << "\n";
	}
	return out;
}
istream& operator>> (istream& in, Set& s)
{
	for (int i = 0; i < s.size; i++)
		in >> s.beg[i];
	return in;
}