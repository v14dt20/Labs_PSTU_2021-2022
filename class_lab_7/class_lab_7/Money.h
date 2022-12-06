#pragma once
#include <iostream>

using namespace std;

class Money
{
private:
	long int rub;
	int kop;
public:
	Money(long int, int);
	Money(Money&);
	Money();
	~Money();

	void set_rub(long int);
	void set_kop(int);

	long int get_rub();
	int get_kop();

	Money operator+(Money&);
	Money operator+(long int);
	Money& operator=(const Money&);
	bool operator==(Money&);
	
	friend ostream& operator<<(ostream&, Money&);
	friend istream& operator>>(istream&, Money&);
};

