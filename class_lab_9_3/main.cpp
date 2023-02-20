#include "Set.h"
#include "Error.h"
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
	catch (Error& err)
	{
		err.what();
	}

	return 0;
}