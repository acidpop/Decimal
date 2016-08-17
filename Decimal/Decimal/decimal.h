#ifndef DECIMAL
#define DECIMAL

#include <string>
using namespace std;

class decimal
{
public:
	explicit decimal();
	explicit decimal(string str);
	explicit decimal(const decimal& de);
	virtual ~decimal();

	string toString();
	double toReal64();
	long long toInt64();

	decimal operator+(decimal &de);

private:
	long long m_Integer;
	string m_Real;
};

#endif