#pragma once
#include <iostream>
#include <queue>
#include "money.h"
#include <algorithm>
using namespace std;

queue<money> four_make() {
	int n;
	cout << "Количество сумм? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	queue<money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.push(val);
	}
	cout << "Успешно" << endl;
	return temp;
}

void four_show(string text, queue<money>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
	queue<money> temp;
	money m;
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

void four_insert(queue<money>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	queue<money> temp;
	money m = v.front(), min = m;
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

void four_delete(queue<money>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	money m, key;
	cout << "Key? "; cin >> key;
	queue<money> temp;
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

void four_update(queue<money>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	queue<money> temp;
	money m = v.front(), min = m, max = m;
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

void four_exec() {
	queue<money> v = four_make();
	four_show("Исходный: ", v);
	cout << "Добавить минимальный в конец: ";
	four_insert(v);
	four_show("После добавления: ", v);
	cout << "Удалить с заданным ключом: ";
	four_delete(v);
	four_show("После удаления: ", v);
	cout << "Ко всем элементам добавить сумму минимального и максимального: ";
	four_update(v);
	four_show("После изменения: ", v);
}
