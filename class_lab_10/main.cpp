#include "Money.h"
#include "file_work.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Money a;
	int k, c;
	char file_name[30];
	do
	{
		//Menu
		cout << "\n1. Create file";//������� ����
		cout << "\n2. Print file";//������� ����
		cout << "\n3. Delete objects";//������� ������� � ������������ ����������
		cout << "\n4. Boost all elem on 1,50";//��������� ��� �������� �� 1 ��� 50 ���
		cout << "\n5. Add objects on file";//�������� k ���� ����� n-��
		cout << "\n0. Exit\n";//�����
		cout << ">"; cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter file name >> "; cin >> file_name;//������ ��� �����
			k = make_file(file_name);//�������� ������� ��� �������� �����
			if (k < 0)
				cout << "Can't create file\n";//��������� �� ������
			break;
		case 2:
			cout << "Enter file name >> "; cin >> file_name;
			k = print_file(file_name);//�������� ������� ��� ������ �����
			if (k < 0)
				cout << "Can't open file\n";//���� ����� �� ����������
			if (k == 0)
				cout << "Empty file\n";//���� ���� ������
			break;
		case 3:
			cout << "Enter file name >> "; cin >> file_name;
			int Rub, Kop;
			cout << "Enter Rub and Kop >> "; cin >> Rub >> Kop;
			
			k = del_objects(file_name, Rub, Kop);//�������� ������� ��� �������� ��������
			if (k < 0)
				cout << "Can't open file\n";//���� ����� �� ����������
			if (k == 0)
				cout << "Empty file\n";//���� ���� ������
			break;
		case 4:
			cout << "Enter file name >> "; cin >> file_name;
			
			k = boost_all(file_name, 1, 50);//�������� ������� ��� �������� ��������
			if (k < 0)
				cout << "Can't open file\n";//���� ����� �� ����������
			if (k == 0)
				cout << "Empty file\n";//���� ���� ������
			break;
		case 5:
			cout << "Enter file name >> "; cin >> file_name;
			
			int K, N;
			cout << "Enter K and N >> "; cin >> K >> N;
			k = add_file(file_name, K, N);//�������� ������� ��� ���������� ��������
			if (k < 0)
				cout << "Can't open file\n";//���� ����� �� ����������
			if (k == 0)
				cout << "Nothing add\n";//���� ������ �� ��������
			break;
		}
	} while (c != 0);

	return 0;
}