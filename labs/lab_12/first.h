#pragma once
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


multiset<double> first_make() {
	int n;
	cout << "Количество элементов? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	cout << "Введите через пробел " << n << " элементов: ";
	multiset<double> temp;
	double val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.insert(val);
	}
	cout << "Успешно" << endl;
	return temp;
}

void first_show(string text, multiset<double>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void first_insert(multiset<double>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	v.insert(*minIter);
	cout << "Успешно" << endl;
}

void first_delete(multiset<double>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	float key;
	cout << "Key? "; cin >> key;
	auto findIter = find(v.begin(), v.end(), key);
	if (findIter == v.end())
		cout << "Нет данного значения" << endl;
	else {
		v.erase(findIter);
		cout << "Успешно" << endl;
	}
}

void first_update(multiset<double>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	cout << " Минимальный = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " Максимальный = " << *maxIter;
	double dif = *minIter + *maxIter;
	multiset<double> temp;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		temp.insert(*iter + dif);
	}
	v.clear();
	v = temp;
	cout << " Успешно" << endl;
}

void first_exec() {
	multiset<double> v = first_make();
	first_show("Исходный: ", v);
	cout << "Добавить минимальный в конец: ";
	first_insert(v);
	first_show("После добавления: ", v);
	cout << "Удалить с заданным ключом: ";
	first_delete(v);
	first_show("После удаления: ", v);
	cout << "Ко всем элементам добавить сумму минимального и максимального: ";
	first_update(v);
	first_show("После изменения: ", v);
}
