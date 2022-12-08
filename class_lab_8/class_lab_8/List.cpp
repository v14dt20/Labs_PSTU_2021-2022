#include "List.h"
#include "Person.h"
#include "Abiturient.h"
#include <iostream>

using namespace std;

List::List() {
	size = 0;
	cur = 0;
	beg = 0;
}
List::List(int s) {
	size = s;
	cur = 0;
	beg = new Object*[size];
}
List::~List() {
	if (beg != 0) delete[] beg;
	beg = 0;
}

void List::add() {
	if (cur >= size) {
		cout << "List is full\n";
		return;
	}
	int y;
	cout << "1. Person\n2. Abiturient\nEnter number >> ";
	cin >> y;
	if (y == 1) {
		Person* a = new (Person);
		a->input();
		beg[cur] = a;
	}
	else if (y == 2) {
		Abiturient* a = new (Abiturient);
		a->input();
		beg[cur] = a;
	}
	else {
		cout << "Error! Try again\n";
	}
	if (cur < size) {
		cur++;
	}
}
void List::show() {
	if (cur == 0) cout << "List is empty\n";
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->show();
		cout << "----------------------------------------\n";
		p++;
	}
}
int List::operator() () {
	return cur;
}
void List::del() {
	if (cur == 0) return;
	cur--;
}

void List::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		Object** p = beg;
		float aver = 0;
		for (int i = 0; i < cur; i++) {
			aver += (*p)->HandleEvent(event);
			p++;
		}
		aver /= cur;
		cout << aver << "\n";
	}
}