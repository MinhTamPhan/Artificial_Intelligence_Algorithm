#include"Graph.h"


void Print2(map<int, string> gr, const vector<int> &result, int end,ostream &out = cout)
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
		out << gr[i*h1 + kq.top()*h2 + h3];
		i = kq.top();
		kq.pop();
		if (!kq.empty())
			out << "->";
	}
}

void main(int argc, char* argv[])
{
	fstream ft;
	ft.open(argv[1], fstream::in);
	fstream ft2;
	ft2.open(argv[2], fstream::out);

	int start, end;
	float t;
	CMyGraph mygp;
	mygp.readInput(start, end,ft);
	ft.close();
	vector<int>result;
	t = mygp.RunDFS(start, end, result);
	ft2 << t << endl;
	if(t!=-1)
		Print2(Street::nStreet, result, end,ft2);
	ft2.close();


	//runISC
	ft2.open("output2.txt", fstream::out);
	t = mygp.RunISC(start, end, result);
	ft2 << t << endl;
	if (t != -1)
		Print2(Street::nStreet, result, end, ft2);
	ft2.close();
}