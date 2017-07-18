#include"MyGraph.h"
#include<stack>
void in(int *pr,int en,ostream &out=cout)
{
	stack<int>st;
	int i = en;
	st.push(i);
	while (pr[i] != -1)
	{
		st.push(pr[i]);
		i = pr[i];
	}
	while (!st.empty())
	{
		out << st.top() << " ";
		st.pop();
	}
}
void main(int agrc,char* argv[])
{
	fstream ft;
	ft.open(argv[1], fstream::in);
	if (ft.fail())
	{
		cout << "Khong mo duoc tap tin intput" << endl;
		return;
	}
	int st, en,*pr;
	MyGraph BFS;
	BFS.readInput(st,en,ft);
	ft.close();
	int lb = BFS.runBFS(pr, st, en);
	/*ft.open(argv[2], fstream::out);
	if (ft.fail())
	{
		cout << "Khong mo duoc tap tin output" << endl;
		return;
	}*/
	in(pr, en);
}