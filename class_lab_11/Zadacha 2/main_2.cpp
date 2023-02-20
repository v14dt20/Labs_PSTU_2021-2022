#include "Money.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<Money> Vec;//���������� ��� ������ � ��������

//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)//��������� ������ ���������� ����������
	{
		Money a;
		a.Set_Rub(rand() % 1000);
		a.Set_Kop(rand() % 100);
		v.push_back(a);//��������� ������� � ����� �������
	}
	return v;//���������� ������ ��� ���������
}

//������� ��� ������ �������
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//���������� ��������
void add_srednee(Vec& v)
{
	int sum = 0;
	
	for (int i = 0; i < v.size(); i++)
		sum += v[i].Get_Rub() * 100 + v[i].Get_Kop();
	
	int n = v.size();
	sum /= n;

	for (int i = 0; i < v.size(); i++)
	{
		v[i].Set_Rub(v[i].Get_Rub() + sum / 100);
		v[i].Set_Kop(v[i].Get_Kop() + sum % 100);
	}
}

//����� ���� ��������
int max(Vec v)
{
	int max = v[0].Get_Rub() * 100 + v[0].Get_Kop();//���� ����
	int n = 0;//����� ���� ����

	for (int i = 0; i < v.size(); i++)
		if ((v[i].Get_Rub() * 100 + v[i].Get_Kop()) > max)
		{
			max = (v[i].Get_Rub() * 100 + v[i].Get_Kop());
			n = i;
		}

	return n;
}

//����� ��� ��������
int min(Vec v)
{
	int m = v[0].Get_Rub() * 100 + v[0].Get_Kop();//��� �������
	int n = 0;//������ ��� ��������

	for (int i = 0; i < v.size(); i++)
		if ((v[i].Get_Rub() * 100 + v[i].Get_Kop()) < m)
		{
			m = (v[i].Get_Rub() * 100 + v[i].Get_Kop());
			n = i;
		}
	return n;
}
//�������� ��������
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}

//�������� �������
int main()
{
	try
	{
		vector<Money> v;//������ ������
		vector<Money>::iterator vi = v.begin();//������ �������� � ������ ��� � ������ �������

		int n;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;

		v = make_vector(n);//��������� ������ �������� n

		cout << "\n1. Vector: "; print_vector(v);//������� ������
		cout << "2. Type: Money\n";

		cout << "3. Add max elem in front: ";
		//���������� ���� �������� � ������
		int max_el = max(v);
		v.insert(v.begin(), v[max_el]);
		print_vector(v);

		cout << "4. Delete min elem: ";
		//������� ��� �������
		int min_el = min(v);
		del_vector(v, min_el);
		print_vector(v);

		cout << "5. Add srednee all elem: ";
		//�������� ������� �� ���� ���������
		add_srednee(v);
		print_vector(v);
	}
	catch (int)//��������� ������
	{
		cout << "ERROR!\n";
	}

	return 0;
}