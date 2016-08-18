#include "decimal.h"

decimal::decimal()
{

}

decimal::decimal(string str)
{
	int i;
	int realdot = -1;

	for (i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '.')
		{
			realdot = i;
			break;
		}
	}

	if (realdot == -1)
	{
		this->m_Integer = stoll(str);
		this->m_Real = "";
	}
	else
	{
		this->m_Integer = stoll(str.substr(0, realdot));
		this->m_Real = str.substr(realdot + 1, str.size() - realdot - 1);
	}
}

decimal::decimal(const decimal& d)
{
	this->m_Integer = d.m_Integer;
	this->m_Real = d.m_Real;
}

decimal::~decimal()
{

}

inline byte decimal::toByte(char chr)
{
	switch (chr)
	{
	case '0':
		return 0;

	case '1':
		return 1;

	case '2':
		return 2;

	case '3':
		return 3;

	case '4':
		return 4;

	case '5':
		return 5;

	case '6':
		return 6;

	case '7':
		return 7;

	case '8':
		return 8;

	case '9':
		return 9;
	}
}

string decimal::toString()
{
	if (this->m_Real != "")
		return to_string(this->m_Integer) + "." + this->m_Real;
	else
		return to_string(this->m_Integer);
}

double decimal::toReal64()
{
	return stod(this->toString());
}

long long decimal::toInt64()
{
	return m_Integer;
}

decimal decimal::operator+(decimal & de)
{
	decimal d;

	d.m_Integer = this->m_Integer + de.m_Integer;

	if (this->m_Real != "" || de.m_Real != "")
	{
		string real = "";

		int iup = 0;

		if (this->m_Real.size() >= de.m_Real.size())
		{
			real = realPlus(this->m_Real, de.m_Real, iup);
		}
		else
		{
			real = realPlus(de.m_Real, this->m_Real, iup);
		}

		d.m_Real = real;
		d.m_Integer += iup;
	}

	return d;
}

inline string decimal::realPlus(string big, string small, int &iup)
{
	int plus_zero = big.size() - small.size();

	int i;

	for (i = 0; i < plus_zero; i++)
	{
		small += '0';
	}

	int size = big.size();

	byte up = 0;

	string real;

	for (i = size - 1; i >= 0; i--)
	{
		byte b;

		b = toByte(big.at(i)) + toByte(small.at(i)) + up;

		up = 0;

		if (b >= 10)
		{
			byte m = 9;
			byte by = b - m;
			up += by;
		}

		string str = to_string(b);
		real = str.size() == 1 ? str + real : str.substr(1) + real;

		if (i == 0)
		{
			if (up != 0)
			{
				iup = up;
			}
		}
	}

	return real;
}

decimal decimal::operator-(decimal &de)
{
	decimal d;

	d.m_Integer = this->m_Integer;

	string real = "";

	real = realMinus(d.m_Real, de.m_Real, d.m_Integer);

	d.m_Integer = this->m_Integer - de.m_Integer;
	d.m_Real = real;

	return d;
}

inline string decimal::realMinus(string a, string b, long long &integer)
{
	int plus_zero = a.size() >= b.size() ? a.size() - b.size() : b.size() - a.size();
	bool isBigA = a.size() >= b.size() ? true : false;

	int i;

	for (i = 0; i < plus_zero; i++)
	{
		if (isBigA)
		{
			b += '0';
		}
		else
		{
			a += '0';
		}
	}

	int size = a.size();

	string real;

	for (i = size - 1; i >= 0; i--)
	{

	}

	return real;
}