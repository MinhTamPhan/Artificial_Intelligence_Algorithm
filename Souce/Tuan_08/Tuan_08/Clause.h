#include"Listeral.h"
#pragma once
class CClause
{
private:
	vector<CListeral>CL;
public:
	friend ostream& operator << (ostream & out, const CClause &a)
	{
		for (size_t i = 0; i < a.CL.size(); i++)
		{
			if (a.CL[i].GetN() == true)
				out << "~";
			out << a.CL[i].GetName() << "   ";
		}
		return out;
	}
	bool Check()
	{
		if (CL.size() == 1 && CL[0].GetName() == '*')
			return false;
		true;
	}
	bool HopGiai(CClause &cl,CClause &rsl)const;
	void Add(const CListeral &cl);
	void operator ~();
	CClause(const CClause & rhs);
	CClause();
	~CClause();
};

