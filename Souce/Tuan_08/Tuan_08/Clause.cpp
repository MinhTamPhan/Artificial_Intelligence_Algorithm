#include "Clause.h"



bool CClause::HopGiai(const CClause & cl, CClause &rsl)const
{
	if (CL.size() != cl.CL.size())
		return false;
	CClause clA(*this);
	CClause clB(cl);
	for (size_t i = 0; i < clA.CL.size(); i++)
	{
		for (size_t j = 0; j < clB.CL.size(); j++)
		{
			if (clA.CL[i] == ~clB.CL[j])
			{
				clA.CL.erase(clA.CL.begin() + i);
				clB.CL.erase(clB.CL.begin() + j);
				continue;
			}
			if (clA.CL[i] == clB.CL[j])
			{
				clB.CL.erase(clB.CL.begin() + j);
			}
		}
	}
	rsl = clA;
	for (size_t i = 0; i < clB.CL.size(); i++)
	{
		rsl.CL.push_back(clB.CL[i]);
	}
	if (rsl.CL.size() == cl.CL.size() + CL.size())
		return false;
	if (rsl.CL.size() == 0)
		rsl.CL.push_back(CListeral('*', false));
	return true;
}

void CClause::Add(const CListeral & ltr)
{
	CL.push_back(ltr);
}

void CClause::operator~()
{
	int n = CL.size();
	for (size_t i = 0; i < n; i++)
	{
		CL[i]=~CL[i];
	}
}

CClause::CClause(const CClause & rhs)
{
	CL.resize(rhs.CL.size());
	for (size_t i = 0; i < rhs.CL.size(); i++)
	{
		CL[i] = rhs.CL[i];
	}
}

CClause::CClause()
{
}


CClause::~CClause()
{
}
