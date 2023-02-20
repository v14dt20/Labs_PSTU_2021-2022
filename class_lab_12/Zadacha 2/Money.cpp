#include "Money.h"
#include <iostream>

using namespace std;

//������������
Money::Money(void)
{
	rub = 0;
	kop = 0;
}
Money::Money(long R, int K)
{
	long buf;
	buf = R * 100 + K;
	rub = buf / 100;
	kop = buf % 100;
}
Money::Money(const Money& m)
{
	rub = m.rub;
	kop = m.kop;
}

//����������
Money::~Money(void)
{
}

//���������
long Money::Get_Rub()
{
	return rub;
}
int Money::Get_Kop()
{
	return kop;
}

//������������
void Money::Set_Rub(long Rub)
{
	rub = Rub;
}
void Money::Set_Kop(int Kop)
{
	long buf;
	buf = rub * 100 + Kop;
	rub = buf / 100;
	kop = buf % 100;
}

//���������� ��������� ������������
Money Money::operator= (const Money& m)
{
	if (&m == this) return *this;
	rub = m.rub;
	kop = m.kop;
	return *this;
}

//�������� ��������
const Money& Money::operator+ (const Money& m)
{
	Money temp;
	long buf;

	buf = rub * 100 + kop + m.rub * 100 + m.kop;
	temp.rub = buf / 100;
	temp.kop = buf % 100;

	return temp;
}

//�������� ���������
const Money& Money::operator- (const Money& m)
{
	Money temp;
	long buf;

	buf = rub * 100 + kop - m.rub * 100 - m.kop;
	temp.rub = buf / 100;
	temp.kop = buf % 100;

	return temp;
}

//�������� �������
const Money& Money::operator/ (int m)
{
	Money temp;
	long buf;

	buf = (rub * 100 + kop) / m;
	temp.rub = buf / 100;
	temp.kop = buf % 100;

	return temp;
}

//��������� �����/������
ostream& operator<< (ostream& out, const Money& m)
{
	out << m.rub << "," << m.kop;
	return out;
}
istream& operator>> (istream& in, Money& m)
{
	long buf, r;
	int k;
	cout << "Enter rub >> "; in >> r;
	cout << "Enter kop >> "; in >> k;
	cout << "\n";

	buf = r * 100 + k;
	m.rub = buf / 100;
	m.kop = buf % 100;

	return in;
}

//�������� >
bool Money::operator>(const Money& m)
{
	if (rub > m.rub) return true;
	if (rub == m.rub && kop > m.kop) return true;
	return false;
}

//�������� <
bool Money::operator<(const Money& m)
{
	if (rub < m.rub) return true;
	if (rub == m.rub && kop < m.kop) return true;
	return false;
}

//�������� !=
bool Money::operator!=(const Money& m)
{
	if (rub != m.rub && kop != m.kop) return true;
	return false;
}