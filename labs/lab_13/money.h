#pragma once
#include <iostream>
using namespace std;

class money
{
private:
	long rub;
	int cop;

public:
	money();
	money(long r, int c);
	money(const money& m);
	~money() {}

	long get_rub() { return rub; }
	long get_cop() { return cop; }

	void set_rub(long r);
	void set_cop(int c);

	money& operator= (const money& m);
	money operator+ (const money& m);
	bool operator== (const money& m) const;
	bool operator!= (const money& m);
	bool operator< (const money& m) const;

	friend istream& operator>> (istream& in, money& m);
	friend ostream& operator<< (ostream& out, const money& m);
};

