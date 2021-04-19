#include "stream.h"

#pragma once
#include "money.h"

void save() {
	ofstream out;
	out.open("file1.txt");
	if (!out.is_open())
		throw exception("Файл не открылся");
	int n;
	cout << "Количество сумм? "; cin >> n;
	if (n < 1)
		throw exception("Введите значенме больше 0");
	money m;
	for (int i = 0; i < n; i++) {
		cin >> m;		// вводим объект
		out << m << endl; // записываем в файл
	}
	out.close();
	cout << "Успешно!" << endl;
}

void read() {
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("Файл не открылся");
	money m;
	int c = 0;
	do {
		in >> m;	// читаем строку
		if (in.eof())
			break;
		c++;
		cout << m << endl;	// выводим на экран
	} while (true);
	in.close();
	if (c == 0)
		cout << "Пусто" << endl;
}

void del() {
	money key;
	cin >> key;
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("Файл для чтения не открылся");
	ofstream out;
	out.open("file1_temp.txt");
	if (!out.is_open())
		throw exception("Файла на запись не открылся");
	money m;
	do {
		in >> m;
		if (in.eof())
			break;
		// если равны копируем
		if (m == key)
			out << m << endl;
	} while (true);
	in.close();
	out.close();
	remove("file1.txt");
	rename("file1_temp.txt", "file1.txt");
	cout << "Успешно!" << endl;
}

void update() {
	money key;
	cin >> key;
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("Файл для чтения не открылся");
	ofstream out;
	out.open("file1_temp.txt");
	if (!out.is_open())
		throw exception("Файла на запись не открылся");
	money m;
	do {
		in >> m;
		if (in.eof())
			break;
		// если равны копируем
		if (m == key)
			m = m / 2;
		out << m << endl;
	} while (true);
	in.close();
	out.close();
	remove("file1.txt");
	rename("file1_temp.txt", "file1.txt");
	cout << "Успешно!" << endl;
}

void insert() {
	ifstream in;
	in.open("file1.txt");
	if (!in.is_open())
		throw exception("Файл для чтения не открылся");
	ofstream out;
	out.open("file1_temp.txt");
	if (!out.is_open())
		throw exception("Файла на запись не открылся");
	money m;
	int K;
	cout << "Количество сумм? "; cin >> K;
	if (K < 1)
		throw exception("Введите значенме больше 0");
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
	cout << "Успешно!" << endl;
}
