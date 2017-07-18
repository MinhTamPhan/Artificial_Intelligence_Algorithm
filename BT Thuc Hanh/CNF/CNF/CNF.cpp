#include "CNF.h"



void CCNF::readInput()
{
	int n;
	cin >> n;	
	cin.ignore();
	while (n--)
	{
		string temp;
		getline(cin,temp);
		input.push_back(temp);
	}
}
const string NOT = "~", AND = "&", OR = "|", IMPLIES = "=>", IFF = "<=>";
bool isNotOperator(string a)
{
	
	if (a != NOT && a != AND && a != OR && a != IMPLIES && a != IFF)
		return 1;
	return 0;
}

const int not = 100, and = 30, or = 40, implies = 20, iff = 10;
int Priority(string opr)
{
	if (opr == AND)
		return and;
	else if (opr == OR)
		return or ;
	else if (opr == NOT)
		return not;
	else if (opr == IMPLIES)
		return implies;
	return iff;
}

void CCNF::Convert_prefix_to_suffixes(vector<queue<string>> &output)
{
	stack<string>st;
	for (size_t i = 0; i < input.size(); i++)
	{
		queue<string>out;
		istringstream iss(input[i]);
		string temp;
		while (!iss.eof())
		{
			iss >> temp;
			if (temp == "(")
				st.push(temp);
			else if (temp == " ")
				continue;
			else if (isNotOperator(temp) && temp != ")")
				out.push(temp);
			else if (temp == ")")
			{
				while (st.top() != "(")
				{
					out.push(st.top());
					st.pop();
				}
				st.pop();
			}
			else if (!isNotOperator(temp))
			{
				if (!st.empty())
				{
					if (Priority(temp) < Priority(st.top()))
					{
						out.push(st.top());
						st.pop();
					}
				}
				st.push(temp);
			}
		}
		while (!st.empty())
		{
			out.push(st.top());
			st.pop();
		}
		output.push_back(out);
	}
}

void CCNF::createTree(vector<queue<string>> input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		stack<CExpression*>tree;
		queue<string>inpi = input[i];
		while (!inpi.empty())
		{
			string tmp = inpi.front();
			CExpression *temp2;
			if (isNotOperator(tmp))
			{
				temp2 = new CExpression(tmp, nullptr, nullptr);
				tree.push(temp2);
			}
			else
			{
				CExpression *subR = tree.top();
				tree.pop();
				CExpression *subL = tree.top();
				tree.pop();
				temp2 = new CExpression(tmp, subL, subR);
				tree.push(temp2);
			}
			inpi.pop();
		}
		//if (i == 2)
		{
			CExpression *tmp = tree.top();
			tree.top()->eliminateDrag(tmp);
			tree.top()->eliminateNot(tmp);
			tmp->eliminate_And(tmp);
			tree.top()->NLR(tmp);
			cout << endl << endl;
		}
	}
}




CCNF::CCNF()
{
}


CCNF::~CCNF()
{
}
