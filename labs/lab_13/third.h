#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include "money.h"
using namespace std;

map<int, money> third_make() {
	int n;
	cout << "Количество сумм? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	map<int, money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.insert(pair<int, money>(i + 1, val));
	}
	cout << "Успешно" << endl;
	return temp;
}

void third_show(string text, map<int, money>& v) {
	// for_each
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
	for_each(v.begin(), v.end(), [](const pair<int, money>& m) { cout << m.second << " "; });
	cout << endl;
}


void third_insert(map<int, money>& v) {
	// min_element
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end(), [](const pair<int, money>& m1, const pair<int, money>& m2) {return m1.second < m2.second; });
	v.insert(pair<int, money>(100, (*minIter).second));
	cout << "Успешно" << endl;
}


void third_delete(map<int, money>& v) {
	// remove
	if (v.size() == 0)
		throw exception("пустой вектор");
	money key;
	cout << "Key? "; cin >> key;
	auto resIter = find_if(v.begin(), v.end(), [&key] (const pair<int, money>& m) { return m.second == key; });
	if (resIter == v.end())
		cout << "Нет данных значений" << endl;
	else {
		v.erase(resIter);
		cout << "Успешно" << endl;
	}
}


void third_update(map<int, money>& v) {
	// min_element, max_element, transform
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end(), [](const pair<int, money>& m1, const pair<int, money>& m2) {return m1.second < m2.second; });
	cout << " Минимальный = " << (*minIter).second;
	auto maxIter = max_element(v.begin(), v.end(), [](const pair<int, money>& m1, const pair<int, money>& m2) {return m1.second < m2.second; });
	cout << " Максимальный = " << (*maxIter).second;
	money dif = (*minIter).second + (*maxIter).second;
	for_each(v.begin(), v.end(), [&v, &dif](pair<int, money> m) { v[m.first] = m.second + dif; });
	cout << " Успешно" << endl;
}

void third_exec() {
	map<int, money> v = third_make();
	third_show("Исходный: ", v);
	cout << "Добавить минимальный в конец: ";
	third_insert(v);
	third_show("После добавления: ", v);
	cout << "Удалить с заданным ключом: ";
	third_delete(v);
	third_show("После удаления: ", v);
	cout << "Ко всем элементам добавить сумму минимального и максимального: ";
	third_update(v);
	third_show("После изменения: ", v);
	cout << "Сортировка по возрастанию: ";
	cout << "Нельзя словарь сортировать по значению, изначально сортируется по ключу\n";
}