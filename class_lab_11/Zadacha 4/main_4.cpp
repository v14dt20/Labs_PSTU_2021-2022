#include "Money.h"
#include <stack>
#include <vector>

using namespace std;

typedef stack<Money>St;//���������� ����
typedef vector<Money>Vec;//���������� ������

//�-�� ��� ������������ �����
St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//���� ����������
		s.push(m);//��������� � � ����
	}
	return s;//������� ���� ��� ��������� �-��
}

//�������� ���� � ������
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//���� ���� �� ������
	{
		//�������� � ������ ������� �� ������� �����
		v.push_back(s.top());
		s.pop();
	}
	return v;//���������� ������ ��� ��������� �-��
}

//�������� ������ � ����
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = v.size() - 1; i >= 0; i--)
		s.push(v[i]);//�������� � ���� ������� �������
	return s;
}

//����� �����
void print_stack(St s)
{
	Vec temp;
	temp = copy_stack_to_vector(s);//�������� ���� � ������, �.� ���� ����������
	
	//�����
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	s = copy_vector_to_stack(temp);//��������� ���� �� ������� �������� ��� ����������
	cout << "\n";
}

void add_srednee(St s)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	int n = 1;

	Money sum = s.top();//��������� � ����� 1 �������
	s.pop();//������� ��� �� �����

	//���� ������� ��������������
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		n++;
	}
	sum = sum / n;

	//��������� ������� �� ���� ��������� � �������� ������ � ����
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + sum;
	s = copy_vector_to_stack(v);
}

//���������� �������� � ����
void add_to_stack(St& s, Money el, int pos)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	v.insert(v.begin() + pos, el);//��������� � ������ �������
	s = copy_vector_to_stack(v);//�������� ������ � ����
}

//����� ������������ �������
Money Max(St s)
{
	Money m = s.top();//������������ �������
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������

	while (!s.empty())
	{
		if (s.top() > m) m = s.top();
		s.pop();
	}

	s = copy_vector_to_stack(v);
	return m;
}

//����� ����������� �������
int Min(St s)
{
	Money m = s.top();//����������� �������
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	int i = 0, min_i = 0;

	while (!s.empty())
	{
		if (s.top() < m)
		{
			m = s.top();
			min_i = i;
		}
		s.pop();
		i++;
	}

	s = copy_vector_to_stack(v);
	return min_i;
}

//������� min �������
void delete_from_stack(St& s)
{
	int m = Min(s);//������� ����������� �������
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	v.erase(v.begin() + m);//������� ����������� �������
	s = copy_vector_to_stack(v);//�������� ������ � ����
}

int main()
{
	try
	{
		Money m;
		St s;

		//������ ��-�� s � n ����������
		int n = 0;
		cout << "Enter n >> "; cin >> n;
		if (n <= 0) throw 1;
		s = make_stack(n);

		cout << "\n1. Stack: "; print_stack(s);//������� ���������� �����
		cout << "2. Money\n";

		cout << "3. Add max elem in front: ";//��������� � ������ ���� ����
		m = Max(s);
		add_to_stack(s, m, 0);
		print_stack(s);

		cout << "4. Del min elem: ";//������� ��� ����
		delete_from_stack(s);
		print_stack(s);

		cout << "5. Add srednee all elem: ";//�������� ������� �� ���� ���������
		add_srednee(s);
		print_stack(s);
	}
	catch (int)
	{
		cout << "ERROR!\n";
	}
	return 0;
}
