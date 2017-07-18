#include "Graph.h"


map<int, string> Street::nStreet; //khởi tạo thành phần statics

void CMyGraph::readInput(int & start, int & end, istream &in)
{
	int n;
	in >> start;
	in >> end;
	in >> soDinh;
	in >> n;
	Dinh.resize(soDinh);
	for (int i = 0; i < soDinh; ++i)
	{
		Dinh[i].resize(soDinh, 0);
	}
	arrStreet.resize(n);
	for (int i = 0; i < n; i++)
	{
		in >> arrStreet[i];
		Dinh[arrStreet[i].getvt2()][arrStreet[i].getvt1()] = arrStreet[i].getLeng();
		Dinh[arrStreet[i].getvt1()][arrStreet[i].getvt2()] = arrStreet[i].getLeng();


		Street::nStreet.insert(Street::nStreet.begin(), pair<int, string>(arrStreet[i].getvt1()*h1 +
			arrStreet[i].getvt2()*h2 + h3, arrStreet[i].Getmane()));
		Street::nStreet.insert(Street::nStreet.begin(), pair<int, string>(arrStreet[i].getvt2()*h1 +
			arrStreet[i].getvt1()*h2 + h3, arrStreet[i].Getmane()));
	}
}

float CMyGraph::RunDFS(const int & start, const int & end, vector<int>& Previous)
{
	stack<int>st; //khởi tạo stack
	vector<bool>labels(soDinh, false); // khởi tạo nhãn
	Previous.resize(soDinh, -1);//khởi tạo đỉnh trước
	vector<float>cost(soDinh, -1);//vector lưu chi phí mỗi đỉnh tính từ start
	cost[start] = 0;

	if (start == end)
		return 0;

	st.push(start);
	while (!st.empty())
	{
		/*lấy ra khỏi ngăn xếp*/
		int v = st.top();
		st.pop();
	/*lấy ra khỏi ngăn xếp*/

		if (v == end)//nếu = end trả về đường đi và chi phí
		{
			return cost[v];
		}
		else if (labels[v] == true) //nếu đỉnh đã đc xét rồi bỏ qua khối else sau
			continue;
		else
		{
			labels[v] = true; ///gán nhãn
			for (int i = 0; i < soDinh; i++)
			{
				/*nếu đỉnh i chưa đc xét và có đường đi từ v tới i*/
				if (labels[i] == false && Dinh[v][i] != 0)
				{
					Previous[i] = v;
					st.push(i);
					cost[i] = cost[v] + Dinh[v][i];//tính chi phí
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
		cost = ISC(*this, start, end, Previous, h);
		++h;
		if (h > 100)
			break;
	}
	return cost;
}

float ISC(const CMyGraph& G, const int & start, const int & end, vector<int>& Previous, int h)
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
