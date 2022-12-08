#include "Abiturient.h"
#include <iostream>

using namespace std;

Abiturient::Abiturient() {
	name = "";
	age = 0;
	points = 0;
	speciality = "";
}
Abiturient::Abiturient(string n, int a, int p, string s) {
	name = n;
	age = a;
	points = p;
	speciality = s;
}
Abiturient::Abiturient(Abiturient& a) {
	name = a.name;
	age = a.age;
	points = a.points;
	speciality = a.speciality;
}
Abiturient::~Abiturient() {}

Abiturient& Abiturient::operator=(const Abiturient& a) {
	name = a.name;
	age = a.age;
	points = a.points;
	speciality = a.speciality;
	return *this;
}

void Abiturient::show() {
	cout << "Имя: " << name;
	cout << "\nВозраст: " << age;
	cout << "\nБаллы: " << points;
	cout << "\nСпециальность: " << speciality << "\n";
}
void Abiturient::input() {
	cout << "Введите имя >> "; cin >> name;
	cout << "Введите возраст >> "; cin >> age;
	cout << "Введите количество баллов >> "; cin >> points;
	cout << "Введите специальность >> "; cin >> speciality;
}