#pragma once
#include "Employee.h"

class List
{
protected:
	Object** beg;
	int size;

public:
	List();
	List(int n);
	~List();

	void add();
	void del();
	void show();

	int operator() ();
	virtual void HandleEvent(const TEvent& e);
};

