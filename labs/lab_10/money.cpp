#include "money.h"

money::money()
{
	rub = 0;
	cop = 0;
}

money::money(long r, int c)
{
	set_rub(r);
	set_cop(c);
}

money::money(const money& m)
{
	rub = m.rub;
	cop = m.cop;
}

void money::set_rub(long r)
{
	if (r < 0)
		rub = 0;
	else
		rub = r;
}

void money::set_cop(int c)
{
	if (c < 0)
		cop = 0;
	else {
		rub += c / 100;
		cop = c % 100;
	}
}

money& money::operator=(const money& m)
{
	if (&m == this)
		return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}

money money::operator/(int val)
{
	money m(rub / val, cop / 2);
	return m;
}

bool money::operator==(const money& m)
{
	if (rub == m.rub && cop == m.cop)
		return true;
	return false;
}

istream& operator>>(istream& in, money& m)
{
	long r;
	int c;
	cout << "¬ведите сумму через пробел: ";
	in >> r; m.set_rub(r);
	in >> c; m.set_cop(c);
	return in;
}

ostream& operator<<(ostream& out, const money& m)
{
	out << m.rub << "," << m.cop;
	return out;
}

ofstream& operator<<(ofstream& fout, const money& m)
{
	fout << m.rub << " " << m.cop;
	return fout;
}

ifstream& operator>>(ifstream& fin, money& m)
{
	fin >> m.rub >> m.cop;
	return fin;
}
