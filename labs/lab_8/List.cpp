#include "List.h"

List::List()
{
	size = 10;
	beg = new Object * [size];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}

List::List(int n)
{
	size = n;
	beg = new Object * [size];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}

List::~List()
{
	for (int i = 0; i < size; i++) {
		if (beg[i] == 0)
			break;
		delete beg[i];
	}
	delete[] beg;
	beg = 0;
}

void List::add()
{
	// ищем пустое место
	int ind = -1;
	for(int i=0; i<size; i++)
		if (beg[i] == 0) {
			ind = i;
			break;
		}
	if (ind == -1) {
		cout << "Ошибка: заполнено" << endl;
		return;
	}
	// выбираем тип
	cout << "Добавить человека (1) или работника (остальные числа)? ";
	int x; cin >> x;
	Object* obj;
	if (x == 1)
		obj = new Person();
	else
		obj = new Employee();
	obj->input();
	// добавляем
	beg[ind] = obj;
	cout << "Успешно\n";
}

void List::del()
{
	// ищем конец
	int ind;
	for (ind = 0; ind < size; ind++)
		if (beg[ind] == 0)
			break;
	if (ind == 0) {
		cout << "Ошибка: пусто" << endl;
		return;
	}
	delete beg[ind - 1];
	beg[ind - 1] = 0;
	cout << "Успешно\n";
}

void List::show()
{
	if ((*this)() == 0)
		cout << "Пусто";
	for (int i = 0; i < size; i++) {
		if (beg[i] == 0)
			break;
		beg[i]->show();
	}
	cout << endl;
}

int List::operator()()
{
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (beg[i] == 0)
			break;
		count++;
	}
	return count;
}

void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		bool ok = false;
		for (int i = 0; i < size; i++) {
			// если конец
			if (beg[i] == 0)
				break;
			// если номер совпадает
			if (e.a == (i + 1)) {
				beg[i]->HandleEvent(e);
				ok = true;
			}
		}
		if (ok == false)
			cout << "Не верный номер\n";
	}
}
