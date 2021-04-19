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

	int& operator[] (int index);	// ������ �� �������
	int operator() ();				// ����������� �������
	Set operator* (const Set& s);	// ����������� ��������

	Set& operator-- ();		// �������
	Set operator-- (int);	// ��������

private:
	void reset();					// ������ ����������
};

