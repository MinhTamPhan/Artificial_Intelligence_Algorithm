#include "Listeral.h"



bool CListeral::operator==(const CListeral rhs) const
{
	return isNot == rhs.isNot && Name == rhs.Name;
}

CListeral CListeral::operator~()const
{
	CListeral rsl(*this);
	rsl.isNot = !rsl.isNot;
	return rsl;
}

CListeral & CListeral::operator=(CListeral && rhs)
{
	Name = std::move(rhs.Name);
	isNot = std::move(rhs.isNot);
	return *this;
}

CListeral & CListeral::operator=(const CListeral & rhs)
{
	Name = rhs.Name;
	isNot = rhs.isNot;
	return *this;
}

CListeral::CListeral(CListeral && rhs)
{
	*this = std::move(rhs);
}

CListeral::CListeral(const CListeral & rhs)
{
	Name = rhs.Name;
	isNot = rhs.isNot;
}

CListeral::CListeral(char n, bool i):Name(n),isNot(i)
{
}

CListeral::CListeral()
{
}


CListeral::~CListeral()
{
}
