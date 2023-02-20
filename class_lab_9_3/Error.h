#pragma once
#include <string>
#include <iostream>

using namespace std;

//������� �����
class Error
{
public:
	virtual void what() {}
};

//������ � ������� ��-��
class IndexError :
	public Error
{
protected:
	string msg;
public:
	IndexError() { msg = "Index Error\n"; }//�����������
	virtual void what() { cout << msg; }
};

//������ � ������� ��-��
class SizeError :
	public Error
{
protected:
	string msg;
public:
	SizeError() { msg = "Size Error\n"; }//�����������
	virtual void what() { cout << msg; }
};

//���������� ������������� �������
class MaxSizeError :
	public SizeError
{
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg_ = "size > MAX_SIZE\n"; }
	virtual void what() { cout << msg << msg_; }
};

//������ ������ ����
class MinIndexError :
	public IndexError
{
protected:
	string msg_;
public:
	MinIndexError() { IndexError(); msg_ = "index < 0\n"; }
	virtual void what() { cout << msg << msg_; }
};

//������ ������ �������� �������
class MaxIndexError :
	public IndexError
{
protected:
	string msg_;
public:
	MaxIndexError() { IndexError(); msg_ = "index >= size\n"; }
	virtual void what() { cout << msg << msg_; }
};