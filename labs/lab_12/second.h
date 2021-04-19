#pragma once
#include <iostream>
#include <set>
#include <algorithm>
#include "money.h"
using namespace std;


multiset<money> second_make() {
	int n;
	cout << "���������� ����? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	multiset<money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.insert(val);
	}
	cout << "�������" << endl;
	return temp;
}

void second_show(string text, multiset<money>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void second_insert(multiset<money>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	v.insert(*minIter);
	cout << "�������" << endl;
}

void second_delete(multiset<money>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	money key;
	cout << "Key? "; cin >> key;
	auto findIter = find(v.begin(), v.end(), key);
	if (findIter == v.end())
		cout << "��� ������� ��������" << endl;
	else {
		v.erase(findIter);
		cout << "�������" << endl;
	}
}

void second_update(multiset<money>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	cout << " ����������� = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " ������������ = " << *maxIter;
	money dif = *minIter + *maxIter;
	multiset<money> temp;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		temp.insert(*iter + dif);
	}
	v.clear();
	v = temp;
	cout << " �������" << endl;
}

void second_exec() {
	multiset < money> v = second_make();
	second_show("��������: ", v);
	cout << "�������� ����������� � �����: ";
	second_insert(v);
	second_show("����� ����������: ", v);
	cout << "������� � �������� ������: ";
	second_delete(v);
	second_show("����� ��������: ", v);
	cout << "�� ���� ��������� �������� ����� ������������ � �������������: ";
	second_update(v);
	second_show("����� ���������: ", v);
}
