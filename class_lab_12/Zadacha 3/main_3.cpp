#include "Money.h"
#include "Container.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	try
	{
		int n = 0;
		cout << "Enter n >> ";//������ ������ ���������
		cin >> n;
		if (n <= 0) throw 1;//������ ����������

		Container<int, Money> mmap(n);//������ ���������
		cout << "\n";
		mmap.Print();//������� ���������

		cout << "Add max elem: ";
		mmap.Add_max();//��������� ���� �������
		mmap.Print();//������� ���������

		cout << "Del min: ";
		mmap.Del_min();//������� ��� �������
		mmap.Print();//������� ���������

		cout << "Add srednee: ";
		mmap.Add_srednee();//��������� ���� ��������� �������
		mmap.Print();//������� ���������
	}
	catch (int)
	{
		cout << "Error!\n";
	}
	return 0;
}