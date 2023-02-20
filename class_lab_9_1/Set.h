#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;

class Set
{
	int size;//������
	int* beg;//��������� �� ������ ������� ������������� �������
public:
	//������������
	Set(void);//��� ����������
	Set(int);//� 1 ����������
	Set(int, int*);//� 2 �����������
	Set(const Set&);//�����������

	//����������
	~Set(void);

	const Set& operator= (const Set&);//�������� ������������
	int operator[] (int);//�������� ������� �� �������
	int operator() ();//�������� ��������� ������ ���������
	Set operator+ (const Set&);//����������� ��������
	Set operator++ ();//���������� ������� � ���������

	//������������� ������� �����-������
	friend ostream& operator<< (ostream&, const Set&);
	friend istream& operator>> (istream&, Set&);
};
