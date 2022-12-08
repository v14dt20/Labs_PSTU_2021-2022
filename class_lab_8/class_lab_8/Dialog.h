#pragma once
#include "List.h"
#include "Event.h" 

class Dialog : public List
{
protected:
	int EndState;
public:
	Dialog(void);
	virtual ~Dialog(void);//деструктор
	virtual void GetEvent(TEvent&);//получить событие
	virtual int Execute();//главный цикл обработки событий
	virtual void HandleEvent(TEvent&);//обработчик
	virtual void ClearEvent(TEvent&);//очистить событие
	int Valid();//проверка атрибута EndState
	void EndExec();//обработка события "конец работы"
};

