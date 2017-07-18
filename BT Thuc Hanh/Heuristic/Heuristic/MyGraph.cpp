#include "MyGraph.h"


map<int, string> CMyGraph::nStreet;

vector<ToaDo> CMyGraph::H;

void CMyGraph::readInput(int & start, int & end, char *filename2)
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

	fstream ft;
	ft.open(filename2, fstream::in);

	ft >> n;
	H.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		ft >> H[i];
	}
}

float CMyGraph::runGreedy(int start, int end, vector<int>& previous)
{
	if (start == end)
		return 0;
	priority_queue<priority_vetex, vector<priority_vetex>, greater<priority_vetex> >pri_q;
	vector<bool>lables(soDinh, false);
	vector<float>cost(soDinh, 0);
	previous.resize(soDinh, -1);

	pri_q.push(*new priority_vetex(start,tinhKC(H[start], H[end])));
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
						previous[i] = v;
						cost[i] += cost[v] + Dinh[v][i];
						pri_q.push(*new priority_vetex(i,tinhKC(H[i], H[end])));
						lables[i] = true;
					}
				}
			}
		}
	}
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
