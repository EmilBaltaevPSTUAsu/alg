#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include "money.h"
using namespace std;

map<int, money> third_make() {
	int n;
	cout << "���������� ����? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	map<int, money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.insert(pair<int, money>(i + 1, val));
	}
	cout << "�������" << endl;
	return temp;
}

void third_show(string text, map<int, money>& v) {
	// for_each
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	for_each(v.begin(), v.end(), [](const pair<int, money>& m) { cout << m.second << " "; });
	cout << endl;
}


void third_insert(map<int, money>& v) {
	// min_element
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end(), [](const pair<int, money>& m1, const pair<int, money>& m2) {return m1.second < m2.second; });
	v.insert(pair<int, money>(100, (*minIter).second));
	cout << "�������" << endl;
}


void third_delete(map<int, money>& v) {
	// remove
	if (v.size() == 0)
		throw exception("������ ������");
	money key;
	cout << "Key? "; cin >> key;
	auto resIter = find_if(v.begin(), v.end(), [&key] (const pair<int, money>& m) { return m.second == key; });
	if (resIter == v.end())
		cout << "��� ������ ��������" << endl;
	else {
		v.erase(resIter);
		cout << "�������" << endl;
	}
}


void third_update(map<int, money>& v) {
	// min_element, max_element, transform
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end(), [](const pair<int, money>& m1, const pair<int, money>& m2) {return m1.second < m2.second; });
	cout << " ����������� = " << (*minIter).second;
	auto maxIter = max_element(v.begin(), v.end(), [](const pair<int, money>& m1, const pair<int, money>& m2) {return m1.second < m2.second; });
	cout << " ������������ = " << (*maxIter).second;
	money dif = (*minIter).second + (*maxIter).second;
	for_each(v.begin(), v.end(), [&v, &dif](pair<int, money> m) { v[m.first] = m.second + dif; });
	cout << " �������" << endl;
}

void third_exec() {
	map<int, money> v = third_make();
	third_show("��������: ", v);
	cout << "�������� ����������� � �����: ";
	third_insert(v);
	third_show("����� ����������: ", v);
	cout << "������� � �������� ������: ";
	third_delete(v);
	third_show("����� ��������: ", v);
	cout << "�� ���� ��������� �������� ����� ������������ � �������������: ";
	third_update(v);
	third_show("����� ���������: ", v);
	cout << "���������� �� �����������: ";
	cout << "������ ������� ����������� �� ��������, ���������� ����������� �� �����\n";
}