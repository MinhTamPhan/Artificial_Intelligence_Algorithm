#include"Clause.h"

bool RoBinSon(vector<CClause> KB)
{
	size_t i = 0,j = i+1;
	while (true)
	{
		vector<CClause>_New;
		for (; i < KB.size() - 1; i++)
		{
			for (j = i + 1; j < KB.size(); j++)
			{
				CClause Ck;
				bool rsl = KB[i].HopGiai(KB[j], Ck);
				if (!rsl)
					continue;
				else
				{
					if (!Ck.Check())
						return true;
					else
					{
						_New.push_back(Ck);
						//cout << Ck << endl;
					}
				}
			}
		}
		i = 0;
		if (_New.size() == 0)
			return false;
		for (size_t i = 0; i < _New.size(); i++)
		{
			KB.push_back(_New[i]);
		}
	}
}

void main(int argc,char* argv[])
{
	freopen(argv[1], "rt", stdin);
	freopen(argv[2], "wt", stdout);
	int n;
	cin >> n;
	vector<CClause>KB;
	while (n--)
	{
		string temp;
		cin >> temp;
		CClause tmp;
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (temp[i] != '|' && temp[i] != '\0')
			{
				if (temp[i] == '~')
				{
					CListeral tm(temp[++i],true);
					tmp.Add(tm);
					continue;
				}
				else
				{
					CListeral tm(temp[i], false);
					tmp.Add(tm);
				}
			}
		}
		KB.push_back(tmp);
	}
	~KB[KB.size() - 1];
	cout<<(RoBinSon(KB) == 1)?"true":"false";
}