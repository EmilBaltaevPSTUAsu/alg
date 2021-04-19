#pragma once
#include <iostream>
#include <queue>
#include "money.h"
#include <algorithm>
using namespace std;

template <class T>
class VectorFifth
{
private:
	queue<T> v;

public:
	VectorFifth();
	~VectorFifth();

	void make();
	void show(string text);
	void insert();
	void del();
	void upd();
};

template<class T>
inline VectorFifth<T>::VectorFifth()
{

}

template<class T>
inline VectorFifth<T>::~VectorFifth()
{
	while(!v.empty())
		v.pop();
}

template<class T>
inline void VectorFifth<T>::make()
{
	int n;
	cout << "���������� ���������? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	T val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.push(val);
	}
	cout << "�������" << endl;
}

template<class T>
inline void VectorFifth<T>::show(string text)
{
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	queue<T> temp;
	T m;
	while (!v.empty()) {
		m = v.front();
		cout << m << " ";
		temp.push(m);
		v.pop();
	}
	while (!temp.empty()) {
		m = temp.front();
		v.push(m);
		temp.pop();
	}
	cout << endl;
}

template<class T>
inline void VectorFifth<T>::insert()
{
	if (v.size() == 0)
		throw exception("������ ������");
	queue<T> temp;
	T m = v.front(), min = m;
	while (!v.empty()) {
		m = v.front();
		if (m < min)
			min = m;
		temp.push(m);
		v.pop();
	}
	while (!temp.empty()) {
		m = temp.front();
		v.push(m);
		temp.pop();
	}
	v.push(min);
	cout << "�������" << endl;
}

template<class T>
inline void VectorFifth<T>::del()
{
	if (v.size() == 0)
		throw exception("������ ������");
	T m, key;
	cout << "Key? "; cin >> key;
	queue<T> temp;
	bool ok = false;
	while (!v.empty()) {
		m = v.front();
		if (m != key)
			temp.push(m);
		else
			ok = true;
		v.pop();
	}
	while (!temp.empty()) {
		m = temp.front();
		v.push(m);
		temp.pop();
	}
	if (ok == true)
		cout << "�������" << endl;
	else
		cout << "��� �������� ��������" << endl;
}

template<class T>
inline void VectorFifth<T>::upd()
{
	if (v.size() == 0)
		throw exception("������ ������");
	queue<T> temp;
	T m = v.front(), min = m, max = m;
	while (!v.empty()) {
		m = v.front();
		if (m < min)
			min = m;
		if (max < m)
			max = m;
		temp.push(m);
		v.pop();
	}
	cout << " ����������� = " << min;
	cout << " ������������ = " << max;
	while (!temp.empty()) {
		m = temp.front();
		m = m + min + max;
		v.push(m);
		temp.pop();
	}
	cout << " �������" << endl;
}

void fifth_exec() {
	VectorFifth<int> v;
	v.make();
	v.show("��������: ");
	cout << "�������� ����������� � �����: ";
	v.insert();
	v.show("����� ����������: ");
	cout << "������� � �������� ������: ";
	v.del();
	v.show("����� ��������: ");
	cout << "�� ���� ��������� �������� ����� ������������ � �������������: ";
	v.upd();
	v.show("����� ���������: ");
}