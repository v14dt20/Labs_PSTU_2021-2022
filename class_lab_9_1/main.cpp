#include "Set.h"
#include <iostream>

using namespace std;

int main()
{
	//�������������� ����
	try
	{
		Set a(3);//��������� �� 3 ���������
		Set b;//������ ���������

		b = ++a;
		cout << a << "\n========================\n";
		cout << b << "\n========================\n";

		int i;
		cout << "Enter index >> "; cin >> i;

		//����� �������� � ������� i, ���� �� ������ 0 ��� ������/����� 3, ������������ �������������� ��������
		cout << a[i] << "\n";

		cout << a + b << "\n";
	}
	catch (int er)
	{
		cout << "\n\nError " << er << "!\nList errors:\n";
		cout << "1 - Create error\n2 - Min index error\n3 - Max index error\n4 - Max size error\n";
	}

	return 0;
}