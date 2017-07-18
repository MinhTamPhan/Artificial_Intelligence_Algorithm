#include "CExpression.h"



void CExpression::eliminateEquivalent(CExpression *&root)
{
	if (ltl == "<=>")
	{
		CExpression *temp = new CExpression();
		temp->ltl = "&";
		temp->left = new CExpression("->", left, right);
		temp->right = new CExpression("->", left, right);
		*this = *temp;
	}
}

void CExpression::eliminateDrag(CExpression *&root)
{
	if (root != nullptr)
	{
		if (root->ltl == "=>")
		{
			CExpression *temp = new CExpression();
			temp->ltl = "|";
			temp->left = new CExpression("~", left, nullptr);
			temp->right = new CExpression(right->ltl, nullptr, right->right);
			*this = *temp;
		}
		eliminateDrag(root->left);
		eliminateDrag(root->right);
	}
}

void CExpression::eliminateNot(CExpression *&root)
{
	if (root != nullptr)
	{
		if (root->ltl == "~")
		{
			if (root->left != nullptr)
			{
				//if (isNotOperator(root->left->ltl))
				{
					root->ltl = "~" + root->left->ltl;
					root->left = root->left->left;
				}
			}
		}
		eliminateNot(root->left);
		eliminateNot(root->right);
	}
}

void CExpression::eliminate_And(CExpression *& root)
{
	if (root != nullptr)
	{
		if (root->ltl == "|")
		{
			if (root->left != nullptr && root->right != nullptr)
			{
				if (root->left->ltl == "&" && root->right->ltl == "&")
				{
					root->ltl = "&";
					CExpression *subLL = new CExpression(root->left->left->ltl, nullptr, nullptr);
					CExpression *subLR = new CExpression(root->left->right->ltl, nullptr, nullptr);
					CExpression *subRL = new CExpression(root->right->left->ltl, nullptr, nullptr);
					CExpression *subRR = new CExpression(root->right->right->ltl, nullptr, nullptr);
					root->left->left = new CExpression("|", subLL, subRL);
					root->left->right = new CExpression("|", subLL, subRR);
					root->right->left = new CExpression("|", subLR, subRL);
					root->right->right = new CExpression("|", subLR, subRR);

				}
			}
			if (root->left != nullptr && root->right->ltl != "&")
			{
				if (root->left->ltl == "&")
				{
					CExpression *subL = new CExpression(root->left->left->ltl, nullptr, nullptr);
					CExpression *subR = new CExpression(root->left->right->ltl, nullptr, nullptr);
					CExpression *r = new CExpression(root->left->ltl,nullptr,nullptr);
					root->ltl = "&";
					root->left = new CExpression("|", r, subL);
					root->right = new CExpression("|", r, subR);
				}
			}
			if (root->right != nullptr && root->left->ltl!="&")
			{
				if (root->right->ltl == "&")
				{
					CExpression *subL = new CExpression(root->right->left->ltl, nullptr, nullptr);
					CExpression *subR = new CExpression(root->right->right->ltl, nullptr, nullptr);
					CExpression *r = new CExpression(root->left->ltl, nullptr,nullptr);
					root->ltl = "&";
					root->left = new CExpression("|", r,subL);
					root->right = new CExpression("|",r,subR);
				}
			}
		}
		eliminate_And(root->left);
		eliminate_And(root->right);
	}
}

CExpression * CExpression::SubClone(CExpression * sub)const
{
	if (sub == nullptr)
		return nullptr;
	else
	{
		return new CExpression(sub->ltl, SubClone(sub->left), SubClone(sub->right));
	}
}

CExpression::CExpression()
{
	
	left = nullptr;
	right = nullptr;
}

CExpression::CExpression(const CExpression & rhs)
{
	ltl = rhs.ltl;
	left = SubClone(rhs.left);
	right = SubClone(rhs.right);
}

void CExpression::makeSubEmpty(CExpression *& sub)
{
	if (sub != nullptr)
	{
		makeSubEmpty(sub->left);
		makeSubEmpty(sub->right);
		delete sub;
	}
	sub = nullptr;
}

CExpression::~CExpression()
{
	makeSubEmpty(this->left);
	makeSubEmpty(this->right);
}
