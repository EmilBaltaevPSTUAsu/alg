#pragma once
#include <iostream>
using namespace std;

class error
{
private:
	string str;

public:
	error(string s) { str = s; }
	void what() { cout << "Îøèáêà: " << str << endl; }
};
