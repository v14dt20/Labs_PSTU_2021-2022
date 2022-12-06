#include "Money.h"
#include <iostream>

using namespace std;

Money::Money() {
	rub = 0;
	kop = 0;
}
Money::Money(long int r, int k) {
	kop = k % 100;
	rub = r + (k / 100);
}
Money::Money(Money& m) {
	rub = m.rub;
	kop = m.kop;
}
Money::~Money() {
	rub = 0;
	kop = 0;
}

void Money::set_rub(long int r) {
	rub = r;
}
void Money::set_kop(int k) {
	kop = k % 100;
	rub += k / 100;
}

long int Money::get_rub() {
	return rub;
}
int Money::get_kop() {
	return kop;
}

Money Money::operator+(Money& m) {
	Money temp;
	temp.set_kop((kop + m.kop) % 100);
	temp.set_rub((rub + m.rub) + (kop + m.kop) / 100);
	return temp;
}
Money Money::operator+(long int k) {
	Money temp;
	temp.kop = (kop + k) % 100;
	temp.rub = rub + (kop + k) / 100;
	return temp;
}
Money& Money::operator=(const Money& m) {
	rub = m.rub;
	kop = m.kop;
	return *this;
}
bool Money::operator==(Money& m) {
	if (rub == m.rub and kop == m.kop) return true;
	return false;
}

ostream& operator<<(ostream& out, Money& m) {
	out << m.get_rub() << ',' << m.get_kop();
	return out;
}
istream& operator>>(istream& in, Money& m) {
	long int buf_kop;
	long int buf_rub;
	cout << "Введите рубли, затем копейки >> ";
	in >> buf_rub >> buf_kop;
	m.set_kop(buf_kop % 100);
	m.set_rub(buf_rub + buf_kop / 100);
	return in;
}