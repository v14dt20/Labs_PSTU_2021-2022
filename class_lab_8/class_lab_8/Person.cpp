#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() { 
	name = "";
	age = 0;
}
Person::Person(string n, int a) {
	name = n;
	age = a;
}
Person::Person(Person& p) {
	name = p.name;
	age = p.age;
}
Person::~Person() {}

Person& Person::operator= (const Person& p) {
	name = p.name;
	age = p.age;
	return *this;
}

void Person::show() {
	cout << "���: " << name;
	cout << "\n�������: " << age << "\n";
}
void Person::input() {
	cout << "������� ��� >> "; cin >> name;
	cout << "������� ������� >> "; cin >> age;
}

int Person::HandleEvent(TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command)
		{
		case cmAver:
			return age;
			break;
		}
	}
}