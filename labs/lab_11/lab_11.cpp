#include <iostream>
#include "first.h"
#include "second.h"
#include "third.h"
#include "four.h"
#include "fifth.h"

int main()
{
	system("chcp 1251");

	cout << "\n1 часть\n"; first_exec();
	cout << "\n2 часть\n"; second_exec();
	cout << "\n3 часть\n"; third_exec();
	cout << "\n4 часть\n"; four_exec();
	cout << "\n5 часть\n"; fifth_exec();
}