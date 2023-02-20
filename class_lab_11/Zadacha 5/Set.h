#pragma once
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <class T>
class Set
{
protected:
	stack <T> s;//���������
	int len;//������ ����������
public:
	//������������
	Set(void);
	Set(int);
	Set(const Set&);

	//����������
	~Set(void);

	//������
	void Print();

	//�������� �������
	T Srednee();
	void Add_srednee();

	//�������� ������������ ������� � ������
	void Add_max();

	//������� ��� �������
	void Del_min();

};

//����������� ����� � ������
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;//��������� ������

	while (!s.empty())//���� ���� �� ������ ��������� ������� � ������ � ������� ��� �� �����
	{
		v.insert(v.begin(), s.top());
		s.pop();
	}
	return v;//������� ������
}

//����������� ������� � ����
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;//����
	for (int i = 0; i < v.size(); i++)//��������� ���� �� �������
		s.push(v[i]);
	return s;//������� ����
}

//������������
template <class T>
Set<T>::Set(void)
{
	len = 0;
}
template <class T>
Set<T>::Set(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//�������� � ���� ������� �
	}
	len = s.size();
}
template <class T>
Set<T>::Set(const Set& s)
{
	len = s.len;
	//�������� �������� ����� Set.s � ������ v
	vector<T> v = copy_stack_to_vector(s);
	//�������� ������ v � ���� s
	s = copy_vector_to_stack(v);
}

//����������
template <class T>
Set<T>::~Set(void)
{
}

//������
template <class T>
void Set<T>::Print()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		cout << s.top() << " ";//����� �������� ��� �������
		s.pop();
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
	cout << "\n";
}

//�������� �������
template <class T>
T Set<T>::Srednee()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	T sum = s.top();//����� ���� ���������
	int n = 1;
	s.pop();

	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
		++n;
	}
	s = copy_vector_to_stack(v);
	return sum / n;//�������
}
template <class T>
void Set<T>::Add_srednee()
{
	vector<T> v;
	T sred = Srednee();
	while (!s.empty())
	{
		v.push_back(sred + s.top());
		s.pop();
	}
	s = copy_vector_to_stack(v);
}


//���������� ���� �������� � ������ �����
template <class T>
void Set<T>::Add_max()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	T max = s.top();//������������ �������

	while (!s.empty())//���� ���� �� ������
	{
		if (s.top() > max)
			max = s.top();
		s.pop();
	}

	v.push_back(max);
	s = copy_vector_to_stack(v);//�������� ������ � ����
}

//�������� ������������ �������� �� �����
template <class T>
void Set<T>::Del_min()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	T min = v[0];//����������� �������
	int n = 0;//����� ��� ��������

	for (int i = 0; i < v.size(); i++)
		if (v[i] < min)
		{
			min = v[i];
			n = i;
		}

	v.erase(v.begin() + n);
	s = copy_vector_to_stack(v);//�������� ������ � ����
}