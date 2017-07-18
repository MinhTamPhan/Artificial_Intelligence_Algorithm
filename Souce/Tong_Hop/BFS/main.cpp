#include"MyGraph.h"
void print(const vector<int> &result, int end)
{
	if (result[end-1] != -1)
	{
		print(result,result[end-1]);
		cout << result[end-1] << " ";
	}
}


void main(int agrc, char* argv[])
{
	int start, end;
	vector<int> result;
	MyGraph BFS;
	freopen(argv[1], "rt", stdin);
	BFS.readInput(start,end);
	int lb = BFS.runBFS(start,end-1,result);
	freopen(argv[2], "wt", stdout);
	if (lb == 1)
	{
		print(result, end);
		cout << end;
	}
	else
	{
		cout << "Null";
	}
}