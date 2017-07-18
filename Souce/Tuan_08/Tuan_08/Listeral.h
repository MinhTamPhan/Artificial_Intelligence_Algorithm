#include<string>
#include<vector>
#include<iostream>
using namespace std;
#pragma once
class CListeral
{
	bool isNot;
	char Name;
public:
	bool GetN()const
	{
		return isNot;
	}
	char GetName()const
	{
		return Name;
	}
	bool operator == (const CListeral rhs)const;
	CListeral operator ~()const;
	CListeral& operator = (CListeral &&rhs);
	CListeral& operator = (const CListeral &rhs);
	CListeral(CListeral &&rhs);
	CListeral(const CListeral &rhs);
	CListeral(char n,bool i);
	CListeral();
	~CListeral();
};

