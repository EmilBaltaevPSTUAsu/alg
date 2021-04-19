#pragma once
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include "money.h"
using namespace std;


void second_exec() {
	cout << "Стандартные алгоритмы не работают с адаптерами контейнеров, так как они";
	cout << " не имеют итераторов, значит их нельзя просто перебрать\n";
	cout << "Один из вариантов решения: сформировать контейнеры из элементов адаптера";
	cout << "и уже там выполнять алгоритмы, что аналогично 1 части\n";
}