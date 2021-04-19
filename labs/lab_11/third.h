#pragma once

template <class T>
class VectorThird
{
private:
	vector<T> v;

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
	cout << "Количество элементов? "; cin >> n;
	if (n < 1)
		throw exception("неверное количество");
	T val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}
	cout << "Успешно" << endl;
}

template<class T>
inline void VectorThird<T>::show(string text)
{
	cout << text;
	if (v.size() == 0)
		cout << "Пусто" << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

template<class T>
inline void VectorThird<T>::insert()
{
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	v.push_back(*minIter);
	cout << "Успешно" << endl;
}

template<class T>
inline void VectorThird<T>::del()
{
	if (v.size() == 0)
		throw exception("пустой вектор");
	T key;
	cout << "Key? "; cin >> key;
	auto findIter = find(v.begin(), v.end(), key);
	if (findIter == v.end())
		cout << "Нет данного значения" << endl;
	else {
		v.erase(findIter);
		cout << "Успешно" << endl;
	}
}

template<class T>
inline void VectorThird<T>::upd()
{
	if (v.size() == 0)
		throw exception("пустой вектор");
	auto minIter = min_element(v.begin(), v.end());
	cout << " Минимальный = " << *minIter;
	auto maxIter = max_element(v.begin(), v.end());
	cout << " Максимальный = " << *maxIter;
	T dif = *minIter + *maxIter;
	for (auto iter = v.begin(); iter != v.end(); iter++)
		*iter = (*iter) + dif;
	cout << " Успешно" << endl;
}

void third_exec() {
	VectorThird<int> v;
	v.make();
	v.show("Исходный: ");
	cout << "Добавить минимальный в конец: ";
	v.insert();
	v.show("После добавления: ");
	cout << "Удалить с заданным ключом: ";
	v.del();
	v.show("После удаления: ");
	cout << "Ко всем элементам добавить сумму минимального и максимального: ";
	v.upd();
	v.show("После изменения: ");
}
