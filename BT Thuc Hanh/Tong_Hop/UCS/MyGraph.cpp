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


float CMyGraph::RunUSC(const int & start, const int & end, vector<int>& Previous)
{
	if (start == end)
		return 0;
	priority_queue<priority_vetex, vector<priority_vetex>, greater<priority_vetex> >pri_q;
	vector<bool>lables(soDinh, false);
	vector<float>cost(soDinh, 0);
	vector<float>pri_v(soDinh, -1);///lưu độ ưu tiên của mỗi đinh
	Previous.resize(soDinh,-1);

	pri_q.push(*new priority_vetex(start,cost[start]));
	pri_v[start] = 0;
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
				//nếu có chạnh nối và chưa đc viếng thăm
				cost[i] += cost[v] + Dinh[v][i];
				if (Dinh[v][i] != 0 && lables[i] == false)
				{
					if (pri_v[i] == -1)//chưa có trong hàng đợi
					{
						Previous[i] = v;
						pri_q.push(*new priority_vetex(i, cost[i]));
						lables[i] = true;
					}
				}
				else if (cost[i] < pri_v[i])//có trong hàng đợi và có chi phí nhỏ hơn
						//thì thêm vào hàng đợi,chi phí chính là độ ưu tiên
					{
						Previous[i] = v;
						pri_q.push(*new priority_vetex(i, cost[i]));
						pri_v[i] = cost[i];//cập nhật lại độ ưu tiên của đỉnh i
						lables[i] = true;
					}
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
