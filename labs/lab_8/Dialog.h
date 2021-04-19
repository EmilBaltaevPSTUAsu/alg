#pragma once
#include "List.h"
class Dialog :
    public List
{
protected:
	int EndState;

public:
	Dialog(void);
	Dialog(int n);
	~Dialog(void);

	Dialog& operator= (const Dialog& d);

	virtual void GetEvent(TEvent& event);		// получить событие
	virtual int Execute();						// бесконечное выполнение
	virtual void HandleEvent(TEvent& event);	// обработка события
	virtual void ClearEvent(TEvent& event);		// очистка события после обработки
	int Valid();								// проверка EndState
	void EndExec();								// обарботка события "конец работы"
};

