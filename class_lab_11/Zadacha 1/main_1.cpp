#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<double> Vec;//���������� ��� ������ � ��������

//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)//��������� ������ ���������� ����������
	{
		double a = rand() % 100;
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
	double sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	int n = v.size();
	sum /= n;

	for (int i = 0; i < v.size(); i++)
		v[i] += sum;
}

//����� ���� ��������
int max(Vec v)
{
	int max = v[0];//���� ����
	int n = 0;//����� ���� ����

	for (int i = 0; i < v.size(); i++)
		if (v[i] > max)
		{
			max = v[i];
			n = i;
		}

	return n;
}

//����� ��� ��������
int min(Vec v)
{
	double m = v[0];//��� �������
	int n = 0;//������ ��� ��������

	for (int i = 0; i < v.size(); i++)
		if (v[i] < m)
		{
			m = v[i];
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
		vector<double> v;//������ ������
		vector<double>::iterator vi = v.begin();//������ �������� � ������ ��� � ������ �������

		int n;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;

		v = make_vector(n);//��������� ������ �������� n

		cout << "\n1. Vector: "; print_vector(v);//������� ������
		cout << "2. Type: double\n";

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