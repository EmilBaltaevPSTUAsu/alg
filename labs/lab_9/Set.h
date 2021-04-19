#pragma once
#include <iostream>
#include "error.h"
using namespace std;

class Set
{
private:
	int size;
	int* data;

public:
	Set(int s);
	Set(const Set& s);
	~Set();

	Set& operator= (const Set& v);
	friend ostream& operator<< (ostream& out, const Set& v);
	friend istream& operator>> (istream& in, Set& v);

	int& operator[] (int index);	// доступ по индексу
	int operator() ();				// определение размера
	Set operator* (const Set& s);	// пересечение множеств

	Set& operator-- ();		// префикс
	Set operator-- (int);	// постфикс

private:
	void reset();					// убрать одинаковые
};

