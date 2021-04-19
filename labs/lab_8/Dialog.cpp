#include "Dialog.h"

Dialog::Dialog(void)
{
	EndState = 0;
}

Dialog::Dialog(int n) : List(n)
{

}

Dialog::~Dialog(void)
{
}

Dialog& Dialog::operator=(const Dialog& d)
{
	if (this == &d)
		return *this;
	if ((*this)() != 0)
		for (int i = 0; i < size; i++) {
			if (beg[i] == 0)
				break;
			delete beg[i];
		}
	delete[] beg;
	size = d.size;
	for (int i = 0; i < size; i++)
		beg[i] = d.beg[i];
	return *this;
}

void Dialog::GetEvent(TEvent& event)
{
	string s, param, OpInt = "m+-szqc"; // строка с символами операций
	char code;
	cout << '>'; cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)	// является ли символ кодом операции
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break;
		case 'c': event.command = cmClear; break;
		}
		if (s.length() > 1)	// выделяем параметры команды, если они есть
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());	// преобразуем параметр в число
			event.a = A;	// записываем в сообщение
		}
	}
	else
		event.what = evNothing;	// пустое событие
}

int Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			*this = Dialog(event.a);
			cout << "Успешно\n";
			ClearEvent(event);
			break;
		case cmAdd:
			add();
			ClearEvent(event);
			break;
		case cmDel:
			del();
			ClearEvent(event);
			break;
		case cmShow:
			show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		case cmClear:
			system("cls");
			ClearEvent(event);
			break;
		default:
			List::HandleEvent(event);
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

int Dialog::Valid()
{
	if (EndState == 0)
		return 0;
	else
		return 1;
}

void Dialog::EndExec()
{
	EndState = 1;
}
