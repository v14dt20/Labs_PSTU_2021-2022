#pragma once
#include <string>
#include <iostream>

using namespace std;

//базовый класс
class Error
{
public:
	virtual void what() {}
};

//ошибка в индексе мн-ва
class IndexError :
	public Error
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }//конструктор
	virtual void what() { cout << msg; }
};

//ошибка в размере мн-ва
class SizeError :
	public Error
{
protected:
	string msg;
public:
	SizeError() { msg = "Size Error\n"; }//конструктор
	virtual void what() { cout << msg; }
};

//превышение максимального размера
class MaxSizeError :
	public SizeError
{
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg_ = "size > MAX_SIZE\n"; }
	virtual void what() { cout << msg << msg_; }
};

//индекс меньше нуля
class MinIndexError :
	public IndexError
{
protected:
	string msg_;
public:
	MinIndexError() { IndexError(); msg_ = "index < 0\n"; }
	virtual void what() { cout << msg << msg_; }
};

//индекс больше текущего размера
class MaxIndexError :
	public IndexError
{
protected:
	string msg_;
public:
	MaxIndexError() { IndexError(); msg_ = "index >= size\n"; }
	virtual void what() { cout << msg << msg_; }
};