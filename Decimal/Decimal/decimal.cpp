#include "decimal.h"

decimal::decimal()
{

}

decimal::decimal(string str)
{
	int i;
	int realdot;

	for (i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '.')
		{
			realdot = i;
			break;
		}
	}

	this->m_Integer = stoll(str.substr(0, realdot));
	this->m_Real = str.substr(realdot + 1, str.size() - realdot - 1);
}

decimal::decimal(const decimal& de)
{
	this->m_Integer = de.m_Integer;
	this->m_Real = de.m_Real;
}

decimal::~decimal()
{

}

string decimal::toString()
{
	return to_string(this->m_Integer) + "." + this->m_Real;
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
	decimal d(*this);

	return d;
}
