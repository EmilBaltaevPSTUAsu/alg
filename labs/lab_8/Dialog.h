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

	virtual void GetEvent(TEvent& event);		// �������� �������
	virtual int Execute();						// ����������� ����������
	virtual void HandleEvent(TEvent& event);	// ��������� �������
	virtual void ClearEvent(TEvent& event);		// ������� ������� ����� ���������
	int Valid();								// �������� EndState
	void EndExec();								// ��������� ������� "����� ������"
};

