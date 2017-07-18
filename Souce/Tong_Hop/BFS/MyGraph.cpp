#include "MyGraph.h"


void MyGraph::readInput(int &start, int &end)
{
	cin >> soDinh;
	cin >> start >> end;
	///start; end;
	dinh.resize(soDinh);
	for (int i = 0; i < soDinh; i++)
	{
		dinh[i].resize(soDinh);
		for (int j = 0; j < soDinh; j++)
			cin >> dinh[i][j];
	}
}

int  MyGraph::runBFS( int start,int end,vector<int> &previous)
{
	queue<int> q;
	vector<bool> label(soDinh);
	previous.resize(soDinh, -1);
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
				if (dinh[v-1][i] == 1)
				{
					if (label[i] == false)
					{
						previous[i] = v;
						label[i] = true;
						q.push(i+1);
					}
				}
		}
	}
	return 0;
}

MyGraph::MyGraph()
{
	soDinh = 0;
	dinh.resize(0);
}

MyGraph::MyGraph(const MyGraph & rhs)
{
	soDinh = rhs.soDinh;
	for (int i = 0; i < rhs.dinh.size(); i++)
		dinh[i] = rhs.dinh[i];
}


MyGraph::~MyGraph()
{
}
