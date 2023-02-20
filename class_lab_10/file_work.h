#pragma once
#include "Money.h"
#include <string>
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//������� ���� ��� ������
	if (!stream) return -1;//������ �������� �����

	int n;
	Money m;
	cout << "Enter num >> "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//���� ��������� ������� � ������� �����
		stream << m;//������ ��������� ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���-�� ���������� ��������
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//������� ���� ��� ������
	if (!stream) return -1;//������ �������� �����

	Money m; int i = 0;
	while (stream>>m)//���� � ������ ���-�� ����
	{
		cout << m;
		i++;
	}
	stream.close();//�������� ������
	return i;//���������� ���������
}

int del_objects(const char* f_name, long Rub, int Kop)
{
	fstream stream(f_name, ios::in);//������� ���� �� ������
	fstream temp("temp", ios::out | ios::trunc);//������� ���� temp �� ������
	if (!stream) return -1;//������ �������� �����

	Money m; int i = 0;
	while (stream >> m)//���� ��� ����� �����, �������� � �������
	{
		if (stream.eof()) break;//���� �������� ������� ����� �����, �� ������� �� �����
		i++;

		if (m.Get_Rub() != Rub && m.Get_Kop() != Kop)//���� �������� ������� �� ����� ��������� ���������, �� ������ ������������ � temp
			temp << m;
	}
	//������� ������
	stream.close();
	temp.close();

	remove(f_name);//������� ���� f_name
	rename("temp", f_name);//������������� ���� temp
	return i; //���������� ����������� ��������
}

int boost_all(const char* f_name, long Rub, int Kop)
{
	fstream stream(f_name, ios::in);//������� ���� �� ������
	fstream temp("temp", ios::out | ios::trunc);//������� ���� temp �� ������
	if (!stream) return -1;//������ �������� �����

	Money m; int i = 0;
	while (stream >> m)//���� ��� ����� �����, �������� � �������
	{
		if (stream.eof()) break;//���� �������� ������� ����� �����, �� ������� �� �����
		
		m.Set_Rub(m.Get_Rub() + Rub);
		m.Set_Kop(m.Get_Kop() + Kop);
		temp << m;
		i++;
	}
	//������� ������
	stream.close();
	temp.close();

	remove(f_name);//������� ���� f_name
	rename("temp", f_name);//������������� ���� temp
	return i; //���������� ����������� �������� 
}

int add_file(const char* f_name, int K, int N)
{
	fstream stream(f_name, ios::in);//������� ���� �� ������
	fstream temp("temp", ios::out | ios::trunc);//������� ���� temp �� ������
	if (!stream) return -1;//������ �������� �����

	Money m; int i = 0, l = 0;
	Money new_m;
	while (stream >> m)//���� ��� ����� �����, �������� � �������
	{
		if (stream.eof()) break;//���� �������� ������� ����� �����, �� ������� �� �����

		if (i == N)
			for (int i = 0; i < K; i++)
			{
				cin >> new_m;
				temp << new_m;
				l++;
			}
		temp << m;
		i++;
	}
	//������� ������
	stream.close();
	temp.close();

	remove(f_name);//������� ���� f_name
	rename("temp", f_name);//������������� ���� temp
	return l; //���������� ����������� ��������
}