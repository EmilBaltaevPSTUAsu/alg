#pragma once
#include <iostream>
#include <set>
#include <algorithm>
#include "money.h"
using namespace std;


multiset<money> second_make() {
	int n;
	cout << "Количество сумм? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	multiset<money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.insert(val);
	}
	cout << "Успешно" << endl;
	return temp;
}

void second_show(string text, multiset<money>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void second_insert(multiset<money>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	v.insert(*minIter);
	cout << "Успешно" << endl;
}

void second_delete(multiset<money>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	money key;
	cout << "Key? "; cin >> key;
	auto findIter = find(v.begin(), v.end(), key);
	if (findIter == v.end())
		cout << "Нет данного значения" << endl;
	else {
		v.erase(findIter);
		cout << "Успешно" << endl;
	}
}

void second_update(multiset<money>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	cout << " Минимальный = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " Максимальный = " << *maxIter;
	money dif = *minIter + *maxIter;
	multiset<money> temp;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		temp.insert(*iter + dif);
	}
	v.clear();
	v = temp;
	cout << " Успешно" << endl;
}

void second_exec() {
	multiset < money> v = second_make();
	second_show("Исходный: ", v);
	cout << "Добавить минимальный в конец: ";
	second_insert(v);
	second_show("После добавления: ", v);
	cout << "Удалить с заданным ключом: ";
	second_delete(v);
	second_show("После удаления: ", v);
	cout << "Ко всем элементам добавить сумму минимального и максимального: ";
	second_update(v);
	second_show("После изменения: ", v);
}
