#pragma once
#include "Object.h"
class List
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	List();
	List(int);
	~List();
	void add();
	void del();
	void show();
	int operator() ();

	virtual void HandleEvent(TEvent&);
};

