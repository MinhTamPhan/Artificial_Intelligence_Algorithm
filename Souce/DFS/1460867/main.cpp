#include"MyGraph.h"
void print(const vector<int> &result, int end)
{
	if (result[end] != -1)
	{
		print(result, result[end]);
		cout << result[end] << " ";
	}
}
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
/*
	do đề bài yêu cầu dường đi ngắn nhất nên sẽ chạy thuật toán USC
	Cài đặt thuật toán DFS nhưng không chạy
*/

void main(int argc,char* argv[])
{
	freopen(argv[1], "rt", stdin);
	///freopen(argv[2], "wt", stdout);
	int start, end;
	float t;
	CMyGraph mygp;
	mygp.readInput(start,end);
	vector<int>result;

	/*DFS*/
	//float t = mygp.RunDFS(start, end, result);
	///print(result, end);
	//Print2(mygp,result, end);

	/*USC*/
	/// t= mygp.RunUSC(start, end, result);
	//cout << t << endl;
	//Print2(mygp,result, end);
	
	/*ISC*/
	t = mygp.RunISC(start, end, result);
	cout << t << endl;
	Print2(mygp, result, end);
}