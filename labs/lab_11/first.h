#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<float> first_make() {
	int n;
	cout << "���������� ���������? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	cout << "������� ����� ������ " << n << " ���������: ";
	vector<float> temp;
	float val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.push_back(val);
	}
	cout << "�������" << endl;
	return temp;
}

void first_show(string text, vector<float>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void first_insert(vector<float>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	v.push_back(*minIter);
	cout << "�������" << endl;
}

void first_delete(vector<float>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	float key;
	cout << "Key? "; cin >> key;
	auto findIter =	find(v.begin(), v.end(), key);
	if(findIter == v.end())
		cout << "��� ������� ��������" << endl;
	else {
		v.erase(findIter);
		cout << "�������" << endl;
	}
}

void first_update(vector<float>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	cout << " ����������� = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " ������������ = " << *maxIter;
	float dif = *minIter + *maxIter;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		*iter = (*iter) + dif;
	cout << " �������" << endl;
}

void first_exec() {
	vector<float> v = first_make();
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