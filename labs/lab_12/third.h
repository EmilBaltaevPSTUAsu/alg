#pragma once
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

template <class T>
class VectorThird
{
private:
	multiset<T> v;

public:
	VectorThird();
	~VectorThird();

	void make();
	void show(string text);
	void insert();
	void del();
	void upd();
};

template<class T>
inline VectorThird<T>::VectorThird()
{

}

template<class T>
inline VectorThird<T>::~VectorThird()
{
	v.clear();
}

template<class T>
inline void VectorThird<T>::make()
{
	int n;
	cout << "���������� ���������? "; cin >> n;
	if (n < 1)
		throw exception("�������� ����������");
	cout << "������� ����� ������ " << n << " ���������: ";
	T val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.insert(val);
	}
	cout << "�������" << endl;
}

template<class T>
inline void VectorThird<T>::show(string text)
{
	cout << text;
	if (v.size() == 0)
		cout << "�����" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

template<class T>
inline void VectorThird<T>::insert()
{
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	v.insert(*minIter);
	cout << "�������" << endl;
}

template<class T>
inline void VectorThird<T>::del()
{
	if (v.size() == 0)
		throw exception("������ ������");
	T key;
	cout << "Key? "; cin >> key;
	auto findIter = find(v.begin(), v.end(), key);
	if (findIter == v.end())
		cout << "��� ������� ��������" << endl;
	else {
		v.erase(findIter);
		cout << "�������" << endl;
	}
}

template<class T>
inline void VectorThird<T>::upd()
{
	if (v.size() == 0)
		throw exception("������ ������");
	auto minIter = min_element(v.begin(), v.end());
	cout << " ����������� = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " ������������ = " << *maxIter;
	T dif = *minIter + *maxIter;
	multiset<T> temp;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		temp.insert((*iter) + dif);
	}
	v.clear();
	v = temp;
	cout << " �������" << endl;
}

void third_exec() {
	VectorThird<int> v;
	v.make();
	v.show("��������: ");
	cout << "�������� ����������� � �����: ";
	v.insert();
	v.show("����� ����������: ");
	cout << "������� � �������� ������: ";
	v.del();
	v.show("����� ��������: ");
	cout << "�� ���� ��������� �������� ����� ������������ � �������������: ";
	v.upd();
	v.show("����� ���������: ");
}
