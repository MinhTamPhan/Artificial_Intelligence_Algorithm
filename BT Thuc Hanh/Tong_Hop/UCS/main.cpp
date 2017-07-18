#include"MyGraph.h"

void Print2(const CMyGraph &gr,const vector<int> &result, int end)
{
	stack<int>kq;
	int i = end;
	kq.push(i);
	while (result[i]!=-1)
	{
		kq.push(result[i]);
		i = result[i];
	}
	i = kq.top();
	kq.pop();
	while (!kq.empty())
	{
		cout << gr.nStreet[i*h1 + kq.top()*h2 + h3];
		i = kq.top();
		kq.pop();
		if (!kq.empty())
			cout << "->";
	}
}

void main(int argc,char* argv[])
{
	freopen(argv[1], "rt", stdin);
	freopen(argv[2], "wt", stdout);
	int start, end;
	float t;
	CMyGraph mygp;
	mygp.readInput(start,end);
	vector<int>result;

	/*UCS*/
	t= mygp.RunUSC(start, end, result);
	cout << t << endl;
	if(t!=-1)
		Print2(mygp,result, end);
}