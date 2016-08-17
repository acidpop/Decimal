#ifndef DECIMAL
#define DECIMAL

#include <string>
using namespace std;

typedef unsigned char byte;
typedef signed char sbyte;

class decimal
{
public:
	explicit decimal();
	explicit decimal(string str);
	decimal(const decimal& d);
	virtual ~decimal();

	string toString();
	double toReal64();
	long long toInt64();

	decimal operator+(decimal &de);

private:
	long long m_Integer;
	string m_Real;

private:
	inline byte toByte(char chr);

private:
	inline string realPlus(string big, string small, int &iup);
};

#endif