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
	// ���� ������ �����
	int ind = -1;
	for(int i=0; i<size; i++)
		if (beg[i] == 0) {
			ind = i;
			break;
		}
	if (ind == -1) {
		cout << "������: ���������" << endl;
		return;
	}
	// �������� ���
	cout << "�������� �������� (1) ��� ��������� (��������� �����)? ";
	int x; cin >> x;
	Object* obj;
	if (x == 1)
		obj = new Person();
	else
		obj = new Employee();
	obj->input();
	// ���������
	beg[ind] = obj;
	cout << "�������\n";
}

void List::del()
{
	// ���� �����
	int ind;
	for (ind = 0; ind < size; ind++)
		if (beg[ind] == 0)
			break;
	if (ind == 0) {
		cout << "������: �����" << endl;
		return;
	}
	delete beg[ind - 1];
	beg[ind - 1] = 0;
	cout << "�������\n";
}

void List::show()
{
	if ((*this)() == 0)
		cout << "�����";
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
			// ���� �����
			if (beg[i] == 0)
				break;
			// ���� ����� ���������
			if (e.a == (i + 1)) {
				beg[i]->HandleEvent(e);
				ok = true;
			}
		}
		if (ok == false)
			cout << "�� ������ �����\n";
	}
}
