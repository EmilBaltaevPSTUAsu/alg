#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<float> first_make() {
	int n;
	cout << "Количество элементов? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	cout << "Введите через пробел " << n << " элементов: ";
	vector<float> temp;
	float val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.push_back(val);
	}
	cout << "Успешно" << endl;
	return temp;
}

void first_show(string text, vector<float>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void first_insert(vector<float>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	v.push_back(*minIter);
	cout << "Успешно" << endl;
}

void first_delete(vector<float>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	float key;
	cout << "Key? "; cin >> key;
	auto findIter =	find(v.begin(), v.end(), key);
	if(findIter == v.end())
		cout << "Нет данного значения" << endl;
	else {
		v.erase(findIter);
		cout << "Успешно" << endl;
	}
}

void first_update(vector<float>& v) {
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	cout << " Минимальный = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " Максимальный = " << *maxIter;
	float dif = *minIter + *maxIter;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		*iter = (*iter) + dif;
	cout << " Успешно" << endl;
}

void first_exec() {
	vector<float> v = first_make();
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