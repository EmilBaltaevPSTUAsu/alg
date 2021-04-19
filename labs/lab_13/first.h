#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "money.h"
using namespace std;

vector<money> first_make() {
	int n;
	cout << "���������� ����? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	vector<money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.push_back(val);
	}
	cout << "�������" << endl;
	return temp;
}

void first_show(string text, vector<money>& v) {
	// for_each
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	for_each(v.begin(), v.end(), [] (const money&m) { cout << m << " "; });
	cout << endl;
}

void first_insert(vector<money>& v) {
	// min_element
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	v.push_back(*minIter);
	cout << "�������" << endl;
}

void first_delete(vector<money>& v) {
	// remove
	if (v.size() == 0)
		throw exception("������ ������");
	money key;
	cout << "Key? "; cin >> key;
	auto resIter = remove(v.begin(), v.end(), key);
	if (resIter == v.end())
		cout << "��� ������ ��������" << endl;
	else
		cout << "�������" << endl;
}

void first_update(vector<money>& v) {
	// min_element, max_element, transform
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	cout << " ����������� = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " ������������ = " << *maxIter;
	money dif = *minIter + *maxIter;
	transform(v.begin(), v.end(), v.begin(), [dif](money& m) { return m + dif; });
	cout << " �������" << endl;
}

void first_sort(vector<money>& v) {
	// sort
	if (v.size() == 0)
		throw exception("������ ������");
	sort(v.begin(), v.end());
	cout << "�������" << endl;
}

void first_exec() {
	vector<money> v = first_make();
	first_show("��������: ", v);
	cout << "�������� ����������� � �����: ";
	first_insert(v);
	first_show("����� ����������: ", v);
	cout << "������� � �������� ������: ";
	first_delete(v);
	first_show("����� ��������: ", v);
	cout << "�� ���� ��������� �������� ����� ������������ � �������������: ";
	first_update(v);
	first_show("����� ���������: ", v);
	cout << "���������� �� �����������: ";
	first_sort(v);
	first_show("����� ����������: ", v);
}