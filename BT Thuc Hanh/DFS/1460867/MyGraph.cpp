#include "MyGraph.h"


map<int, string> CMyGraph::nStreet;

void CMyGraph::readInput(int & start, int & end)
{
	int n;
	cin >> start;
	cin >> end;
	cin >> soDinh;
	cin >> n;
	Dinh.resize(soDinh);
	for (int i = 0; i < soDinh; ++i)
	{
		Dinh[i].resize(soDinh, 0);
	}
	arrStreet.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arrStreet[i];
		Dinh[arrStreet[i].getvt2()][arrStreet[i].getvt1()] = arrStreet[i].getLeng();
		Dinh[arrStreet[i].getvt1()][arrStreet[i].getvt2()] = arrStreet[i].getLeng();
		nStreet.insert(nStreet.begin(),pair<int,string>(arrStreet[i].getvt1()*h1 + 
			arrStreet[i].getvt2()*h2 + h3,arrStreet[i].Getmane()));
		nStreet.insert(nStreet.begin(), pair<int, string>(arrStreet[i].getvt2()*h1 +
			arrStreet[i].getvt1()*h2 + h3, arrStreet[i].Getmane()));
	}
}

float CMyGraph::RunDFS(const int & start, const int & end, vector<int>& Previous)
{
	stack<int>st;
	vector<bool>labels(soDinh, false);
	Previous.resize(soDinh, -1);
	vector<float>cost(soDinh, -1);
	cost[start] = 0;

	if (start == end)
		return 0;
	
	st.push(start);
	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		if (v == end)
		{
			return cost[v];
		}
		else if (labels[v] == true)
			continue;
		else
		{
			labels[v] = true;
			for (int i = 0; i < soDinh; i++)
			{
				if (labels[i] == false && Dinh[v][i]!=0)
				{
					Previous[i] = v;
					st.push(i);
					cost[i] = cost[v] + Dinh[v][i];
				}
			}
		}
	}
	return -1;
}



float CMyGraph::RunUSC(const int & start, const int & end, vector<int>& Previous)
{
	if (start == end)
		return 0;
	priority_queue<priority_vetex, vector<priority_vetex>, greater<priority_vetex> >pri_q;
	vector<bool>lables(soDinh, false);
	vector<float>cost(soDinh, 0);
	Previous.resize(soDinh,-1);

	pri_q.push(*new priority_vetex(start,cost[start]));
	lables[start] = true;
	while (!pri_q.empty())
	{
		int v = pri_q.top().vertex;
		pri_q.pop();
		if (v == end)
			return cost[v];
		else
		{
			for (int i = 0; i < soDinh; ++i)
			{
				if (lables[i] == false)
				{
					if (Dinh[v][i] != 0)
					{
						Previous[i] = v;
						cost[i] += cost[v] + Dinh[v][i];
						pri_q.push(*new priority_vetex(i, cost[i]));
						lables[i] = true;
					}
				}
			}
		}

	}

	return -1;
}


float CMyGraph::RunISC(const int & start, const int & end, vector<int>& Previous)
{
	int h = 1;
	float cost = -1;
	while (cost == -1)
	{
		cost = IDS(*this, start, end, Previous, h);
		++h;
		if (h > 100)
			break;
	}
	return cost;
}



float IDS(const CMyGraph& G, const int & start, const int & end, vector<int>& Previous, int h)
{
	stack<int>st;
	vector<bool>labels(G.soDinh, false);
	Previous.resize(G.soDinh, -1);
	vector<float>cost(G.soDinh, -1);
	cost[start] = 0;

	if (start == end)
		return 0;

	st.push(start);
	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		if (v == end)
		{
			return cost[v];
		}
		else if (labels[v] == true)
			continue;
		else
		{
			labels[v] = true;
			if (h > 0)
			{
				for (int i = 0; i < G.soDinh; i++)
				{
					if (labels[i] == false && G.Dinh[v][i] != 0)
					{
						Previous[i] = v;
						st.push(i);
						cost[i] = cost[v] + G.Dinh[v][i];
					}
				}
				--h;
			}
		}
	}
	return -1;
}


CMyGraph CMyGraph::operator=(const CMyGraph & rhs)
{
	return CMyGraph(rhs);
}

CMyGraph CMyGraph::operator=(CMyGraph && rhs)
{
	return CMyGraph(rhs);
}

CMyGraph::CMyGraph(const CMyGraph & rhs)
{
	soDinh = rhs.soDinh;
	Dinh.resize(soDinh);
	for (int i = 0; i < soDinh; ++i)
	{
		Dinh[i].resize(soDinh);
		for (int j = 0; j < soDinh; ++j)
		{
			Dinh[i][j] = rhs.Dinh[i][j];
		}
	}
	arrStreet = rhs.arrStreet;
}

CMyGraph::CMyGraph(CMyGraph && rhs)
{
	soDinh = rhs.soDinh;
	Dinh.resize(soDinh);
	for (int i = 0; i < soDinh; ++i)
	{
		Dinh[i].resize(soDinh);
		for (int j = 0; j < soDinh; ++j)
		{
			Dinh[i][j] = rhs.Dinh[i][j];
		}
	}
	arrStreet = rhs.arrStreet;
}

CMyGraph::CMyGraph()
{
	soDinh = 0;
	Dinh.resize(0);
	arrStreet.resize(0);
}


CMyGraph::~CMyGraph()
{
}
