#pragma once
#include <iostream>

using namespace std;

template <class T>
class Set
{
public: 
	Set(int s);
	Set(int s, T k);
	Set(const Set<T>& a);
	~Set();

	Set& operator= (const Set<T>& a);
	T& operator[] (int index);
	Set operator+ (T k);
	int operator() ();
	bool operator> (T k);

	friend ostream& operator<< <>(ostream& out, Set<T>& a);
	friend istream& operator>> <>(istream& in, Set<T>& a);
private:
	int size;
	T* data;
};

template <class T>
Set<T>::Set(int s) {
	size = s;
	data = new T[size];
}
template <class T>//конструктор с параметрами
Set<T>::Set(int s, T k) {
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
template <class T>//конструктор копирования
Set<T>::Set(const Set<T>& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
template <class T>//деструктор
Set<T>::~Set() {
	delete[] data;
	data = 0;
	size = 0;
}

//операции
template <class T>
Set<T>& Set<T>::operator=(const Set<T>& a) {
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return*this;
}

template <class T>
T& Set<T>::operator[](int index) {
	if (index < size) return data[index];
	else cout << "Error! Index >= Size !!!\n";
}

template <class T>
Set<T> Set<T>::operator+ (T k) {
	Set<T> temp(size, k);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] + k;
	return temp;
}

template <class T>
int Set<T>::operator() () {
	return size;
}

template <class T>
bool Set<T>::operator> (T k) {
	for (int i = 0; i < size; i++)
		if (data[i] == k) return true;
	return false;
}

//ввод-вывод
template <class T>
ostream& operator<< (ostream& out, Set<T>& a) {
	for (int i = 0; i < a.size; i++)
		out << a.data[i] << " ";
	return out;
}

template <class T>
istream& operator>> (istream& in, Set<T>& a) {
	for (int i = 0; i < a.size; i++)
		in >> a.data[i];
	return in;
}
