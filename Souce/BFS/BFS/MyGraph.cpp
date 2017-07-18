#include "MyGraph.h"


void MyGraph::readInput(int &start, int &end,istream &in)
{
	in >> soDinh;
	in >> start >> end;
	dinh = new int*[soDinh];
	for (int i = 0; i < soDinh; i++)
	{
		dinh[i] = new int[soDinh];
		for (int j = 0; j < soDinh; j++)
			in >> dinh[i][j];
	}
}

int  MyGraph::runBFS(int *&pre,int start,int end)
{
	//khởi tạo queue và các tp #
	queue<int> q;
	bool* label;
	pre = new int[soDinh];
	label = new bool[soDinh];
	for (int i = 0; i < soDinh; i++)
	{
		label[i] = 0;
		pre[i] = -1;
	}
	//gán nhãn
	label[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (v == end)
			return 1;
		else
		{
			for (int i = 0; i < soDinh; i++)				
				if (dinh[v][i] == 1)
				{
					if (label[i] == false)
					{
						pre[i] = v;
						label[i] = true;
						q.push(i);
					}
				}
		}
	}
	return 0;
}

MyGraph::MyGraph()
{
	soDinh = 0;
	dinh = nullptr;
}

MyGraph::MyGraph(const MyGraph & rhs)
{
	soDinh = rhs.soDinh;
	for (int i = 0; i < soDinh; i++)
		for (int j = 0; j < soDinh; j++)
			dinh[i][j] = rhs.dinh[i][j];
}


MyGraph::~MyGraph()

{
	delete[]dinh;
}
