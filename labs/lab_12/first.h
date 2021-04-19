#pragma once
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


multiset<double> first_make() {
	int n;
	cout << "���������� ���������? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	cout << "������� ����� ������ " << n << " ���������: ";
	multiset<double> temp;
	double val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.insert(val);
	}
	cout << "�������" << endl;
	return temp;
}

void first_show(string text, multiset<double>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void first_insert(multiset<double>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	v.insert(*minIter);
	cout << "�������" << endl;
}

void first_delete(multiset<double>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	float key;
	cout << "Key? "; cin >> key;
	auto findIter = find(v.begin(), v.end(), key);
	if (findIter == v.end())
		cout << "��� ������� ��������" << endl;
	else {
		v.erase(findIter);
		cout << "�������" << endl;
	}
}

void first_update(multiset<double>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	cout << " ����������� = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " ������������ = " << *maxIter;
	double dif = *minIter + *maxIter;
	multiset<double> temp;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		temp.insert(*iter + dif);
	}
	v.clear();
	v = temp;
	cout << " �������" << endl;
}

void first_exec() {
	multiset<double> v = first_make();
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
}
