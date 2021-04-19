#include "stream.h"

#pragma once
#include "money.h"

void save() {
	ofstream out;
	out.open("file1.txt");
	if (!out.is_open())
		throw exception("���� �� ��������");
	int n;
	cout << "���������� ����? "; cin >> n;
	if (n < 1)
		throw exception("������� �������� ������ 0");
	money m;
	for (int i = 0; i < n; i++) {
		cin >> m;		// ������ ������
		out << m << endl; // ���������� � ����
	}
	out.close();
	cout << "�������!" << endl;
}

void read() {
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("���� �� ��������");
	money m;
	int c = 0;
	do {
		in >> m;	// ������ ������
		if (in.eof())
			break;
		c++;
		cout << m << endl;	// ������� �� �����
	} while (true);
	in.close();
	if (c == 0)
		cout << "�����" << endl;
}

void del() {
	money key;
	cin >> key;
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("���� ��� ������ �� ��������");
	ofstream out;
	out.open("file1_temp.txt");
	if (!out.is_open())
		throw exception("����� �� ������ �� ��������");
	money m;
	do {
		in >> m;
		if (in.eof())
			break;
		// ���� ����� ��������
		if (m == key)
			out << m << endl;
	} while (true);
	in.close();
	out.close();
	remove("file1.txt");
	rename("file1_temp.txt", "file1.txt");
	cout << "�������!" << endl;
}

void update() {
	money key;
	cin >> key;
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("���� ��� ������ �� ��������");
	ofstream out;
	out.open("file1_temp.txt");
	if (!out.is_open())
		throw exception("����� �� ������ �� ��������");
	money m;
	do {
		in >> m;
		if (in.eof())
			break;
		// ���� ����� ��������
		if (m == key)
			m = m / 2;
		out << m << endl;
	} while (true);
	in.close();
	out.close();
	remove("file1.txt");
	rename("file1_temp.txt", "file1.txt");
	cout << "�������!" << endl;
}

void insert() {
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("���� ��� ������ �� ��������");
	ofstream out;
	out.open("file1_temp.txt");
	if (!out.is_open())
		throw exception("����� �� ������ �� ��������");
	money m;
	int K;
	cout << "���������� ����? "; cin >> K;
	if (K < 1)
		throw exception("������� �������� ������ 0");
	for (int i = 0; i < K; i++) {
		cin >> m;
		out << m << endl;
	}
	do {
		in >> m;
		if (in.eof())
			break;
		out << m << endl;
	} while (true);
	in.close();
	out.close();
	remove("file1.txt");
	rename("file1_temp.txt", "file1.txt");
	cout << "�������!" << endl;
}
