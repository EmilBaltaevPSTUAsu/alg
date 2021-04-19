#pragma once
#include <iostream>
#include <queue>
#include "money.h"
#include <algorithm>
using namespace std;

queue<money> four_make() {
	int n;
	cout << "���������� ����? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	queue<money> temp;
	money val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		temp.push(val);
	}
	cout << "�������" << endl;
	return temp;
}

void four_show(string text, queue<money>& v) {
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
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
		throw exception("������ ������");
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
	cout << "�������" << endl;
}

void four_delete(queue<money>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
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
		cout << "�������" << endl;
	else
		cout << "��� �������� ��������" << endl;
}

void four_update(queue<money>& v) {
	if (v.size() == 0)
		throw exception("������ ������");
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
	cout << " ����������� = " << min;
	cout << " ������������ = " << max;
	while (!temp.empty()) {
		m = temp.front();
		m = m + min + max;
		v.push(m);
		temp.pop();
	}
	cout << " �������" << endl;
}

void four_exec() {
	queue<money> v = four_make();
	four_show("��������: ", v);
	cout << "�������� ����������� � �����: ";
	four_insert(v);
	four_show("����� ����������: ", v);
	cout << "������� � �������� ������: ";
	four_delete(v);
	four_show("����� ��������: ", v);
	cout << "�� ���� ��������� �������� ����� ������������ � �������������: ";
	four_update(v);
	four_show("����� ���������: ", v);
}
