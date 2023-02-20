#pragma once
#include <iostream>

using namespace std;

class Money
{
protected:
	long rub;
	int kop;
public:
	//������������
	Money(void);
	Money(long, int);
	Money(const Money&);

	//����������
	~Money(void);

	//���������
	long Get_Rub();
	int Get_Kop();

	//������������
	void Set_Rub(long);
	void Set_Kop(int);

	Money operator= (const Money&);//�������� ������������
	const Money& operator+ (const Money&);//��������
	const Money& operator- (const Money&);//���������

	//������������� ������� �����/������
	friend ostream& operator<< (ostream& out, const Money& m);
	friend istream& operator>> (istream& in, Money& m);
};