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
	cout << "Количество элементов? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	T val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.push(val);
	}
	cout << "Успешно" << endl;
}

template<class T>
inline void VectorFifth<T>::show(string text)
{
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
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
		throw exception("пустой вектор");
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
	cout << "Успешно" << endl;
}

template<class T>
inline void VectorFifth<T>::del()
{
	if (v.size() == 0)
		throw exception("пустой вектор");
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
		cout << "Успешно" << endl;
	else
		cout << "Нет заданных значений" << endl;
}

template<class T>
inline void VectorFifth<T>::upd()
{
	if (v.size() == 0)
		throw exception("пустой вектор");
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
	cout << " Минимальный = " << min;
	cout << " Максимальный = " << max;
	while (!temp.empty()) {
		m = temp.front();
		m = m + min + max;
		v.push(m);
		temp.pop();
	}
	cout << " Успешно" << endl;
}

void fifth_exec() {
	VectorFifth<int> v;
	v.make();
	v.show("Исходный: ");
	cout << "Добавить минимальный в конец: ";
	v.insert();
	v.show("После добавления: ");
	cout << "Удалить с заданным ключом: ";
	v.del();
	v.show("После удаления: ");
	cout << "Ко всем элементам добавить сумму минимального и максимального: ";
	v.upd();
	v.show("После изменения: ");
}