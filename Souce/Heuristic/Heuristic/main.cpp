#include"MyGraph.h"

void Print(const CMyGraph &gr, const vector<int> &result, int end)
{
	stack<int>kq;
	int i = end;
	kq.push(i);
	while (result[i] != -1)
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

void main(int argc,char*argv[])
{
	freopen(argv[1], "rt", stdin);
	int start, end;
	vector<int>result;
	CMyGraph G;
	G.readInput(start, end, argv[2]);
	float cost = G.runGreedy(start, end, result);
	cout << cost << endl;
	Print(G, result, end);
}