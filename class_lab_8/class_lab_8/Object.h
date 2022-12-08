#pragma once
#include "Event.h"
class Object
{
public:
	Object(void);
	virtual void show() = 0;
	virtual void input() = 0;
	virtual int HandleEvent(TEvent& e) = 0;
	virtual ~Object(void);
};

