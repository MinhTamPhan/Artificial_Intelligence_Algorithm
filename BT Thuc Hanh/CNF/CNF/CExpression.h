#include<string>
#include<iostream>
using namespace std;
#pragma once

class CExpression
{
	string ltl;
	CExpression *left;
	CExpression *right;
public:
	void eliminateEquivalent(CExpression *&roo);
	void eliminateDrag(CExpression *&root);
	void eliminateNot(CExpression *&root);
	void eliminate_And(CExpression *&root);
	CExpression(string t, CExpression* l, CExpression *r) :ltl(t), left(l), right(r)
	{}
	CExpression *SubClone(CExpression *sub)const;
	CExpression();
	void NLR(CExpression * root)
	{
		if (root != nullptr)
		{
			NLR(root->left);
			cout << root->ltl;
			NLR(root->right);
		}
	}
	CExpression(const CExpression & rsl);
	void makeSubEmpty(CExpression *&sub);
	~CExpression();
};
