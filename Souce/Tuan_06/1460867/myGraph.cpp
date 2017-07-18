#include "stdafx.h"
#include "myGraph.h"


vector<CPoint2D> myGraph::Succesor(CPoint2D p) const
{
	vector<CPoint2D>rsl;
	int x = p.GetX(), y = p.GetY();
	int left = x - 1, right = x + 1, top = y - 1, bottom = y + 1;
	if (maze[y][left] != '%')
	{
		rsl.push_back(*new CPoint2D(left, y));
	}
	if (maze[y][right] != '%')
	{
		rsl.push_back(*new CPoint2D(right, y));
	}
	if (maze[top][x] != '%')
	{
		rsl.push_back(*new CPoint2D(x, top));
	}
	if (maze[bottom][x] != '%')
	{
		rsl.push_back(*new CPoint2D(x, bottom));
	}
	return rsl;
}

void myGraph::readInput(CPoint2D & start, CPoint2D & end, istream & in , vector<string> &mzout)
{
	while (!in.eof())
	{
		string temp;
		getline(in, temp);
		size_t x = temp.find('P');
		if (x != string::npos)
		{
			start.setX(x);
			start.setY(maze.size());
		}
		x = temp.find('G');
		if (x != string::npos)
		{
			end.setX(x);
			end.setY(maze.size());
		}
		maze.push_back(temp);
		mzout.push_back(temp);
	}
}


float  myGraph::runAStar(CPoint2D start, CPoint2D end, vector<vector<CPoint2D> >& privious)const
{
	priority_queue<Pri_Point, deque<Pri_Point>, greater<Pri_Point> > pQ;
	vector<vector<bool>> label(maze.size());
	vector<vector<int>>cost(maze.size());

	vector<vector<float> >pri_v(maze.size());///lưu độ ưu tiên của mỗi đinh

	privious.resize(maze.size());
	for (size_t i = 0; i < maze.size(); i++)
	{
		label[i].resize(maze[0].size(), false);
		cost[i].resize(maze[0].size(), 0);
		privious[i].resize(maze[0].size());
		pri_v[i].resize(maze[0].size(), -1);
	}

	pQ.push(*new Pri_Point(start.Distance(end), start));
	pri_v[start.GetY()][start.GetX()] = start.Distance(end);
	privious[start.GetY()][start.GetX()] = CPoint2D(-1, -1);

	while (!pQ.empty())
	{
		Pri_Point t = pQ.top();
		CPoint2D v = t.GetPoit();
		pQ.pop();
		int x = v.GetX(), y = v.GetY();
		//label[y][x] = true;
		if (end == v)
			return cost[y][x];
		else
		{
			vector<CPoint2D> dv = Succesor(v);
			for (int i = 0; i < dv.size(); i++)
			{
				int dx = dv[i].GetX(), dy = dv[i].GetY();

				if (label[dy][dx] == false)//nếu đỉnh dv[i] chưa đc xét
				{
					float k;
					cost[dy][dx] = cost[y][x] + 1;
					k = H(cost[dy][dx], end.Distance(dv[i]));
					//if (pri_v[dy][dx] == -1)
					//	//chưa có trong hàng đợi Hoặc
					//	//có trong hàng đợi và có chi phí nhỏ hơn
					//	//thì thêm vào hàng đợi		
					{
						privious[dy][dx] = CPoint2D(x, y);
						pQ.push(*new Pri_Point(k, dv[i]));
						label[dy][dx] = true;
						//if (k < pri_v[dy][dx])
							pri_v[dy][dx] = k;///cập nhật lại độ ưu tiên
					}
				}
				else
				{
					float k;
					cost[dy][dx] = cost[y][x] + 1;
					k = H(cost[dy][dx], end.Distance(dv[i]));
					if (k < pri_v[dy][dx])
						//có trong hàng đợi và có chi phí nhỏ hơn
						//thì thêm vào hàng đợi		
					{
						privious[dy][dx] = CPoint2D(x, y);
						pQ.push(*new Pri_Point(k, dv[i]));
						label[dy][dx] = true;
						//if (k < pri_v[dy][dx])
						pri_v[dy][dx] = k;///cập nhật lại độ ưu tiên
					}
				}
			}
		}
	}
	return 0;
}



float  myGraph::runAStar1(const CPoint2D &start, const CPoint2D &end, vector<vector<CPoint2D> >& previous,
	void(*Draw)(const CPoint2D &p1,const CPoint2D &p2))const
{
	priority_queue<Pri_Point, deque<Pri_Point>, greater<Pri_Point> > pQ;
	vector<vector<bool>> label(maze.size());
	vector<vector<int>>cost(maze.size());

	vector<vector<float> >pri_v(maze.size());///lưu độ ưu tiên của mỗi đinh

	previous.resize(maze.size());
	for (size_t i = 0; i < maze.size(); i++)
	{
		label[i].resize(maze[0].size(), false);
		cost[i].resize(maze[0].size(), 0);
		previous[i].resize(maze[0].size());
		pri_v[i].resize(maze[0].size(), -1);
	}

	pQ.push(*new Pri_Point(start.Distance(end), start));
	pri_v[start.GetY()][start.GetX()] = start.Distance(end);
	previous[start.GetY()][start.GetX()] = CPoint2D(-1, -1);

	while (!pQ.empty())
	{
		Pri_Point t = pQ.top();
		CPoint2D v = t.GetPoit();
		if(v!=start)
			Draw(previous[v.GetY()][v.GetX()], v);
		pQ.pop();
		int x = v.GetX(), y = v.GetY();
		//label[y][x] = true;
		if (end == v)
			return cost[y][x];
		else
		{
			vector<CPoint2D> dv = Succesor(v);
			for (int i = 0; i < dv.size(); i++)
			{
				int dx = dv[i].GetX(), dy = dv[i].GetY();

				if (label[dy][dx] == false)//nếu đỉnh dv[i] chưa đc xét
				{
					float k;
					cost[dy][dx] = cost[y][x] + 1;
					k = H(cost[dy][dx], end.Distance(dv[i]));
					//if (pri_v[dy][dx] == -1)
					//	//chưa có trong hàng đợi Hoặc
					//	//có trong hàng đợi và có chi phí nhỏ hơn
					//	//thì thêm vào hàng đợi		
					{
						previous[dy][dx] = CPoint2D(x, y);
						pQ.push(*new Pri_Point(k, dv[i]));
						label[dy][dx] = true;
						//if (k < pri_v[dy][dx])
						pri_v[dy][dx] = k;///cập nhật lại độ ưu tiên
						//p(v, dv[i]);
					}
				}
				else
				{
					float k;
					k = H(cost[dy][dx] + 1, end.Distance(dv[i]));
					if (k < pri_v[dy][dx])
						//có trong hàng đợi và có chi phí nhỏ hơn
						//thì thêm vào hàng đợi		
					{
						previous[dy][dx] = CPoint2D(x, y);
						pQ.push(*new Pri_Point(k, dv[i]));
						label[dy][dx] = true;
						//if (k < pri_v[dy][dx])
						pri_v[dy][dx] = k;///cập nhật lại độ ưu tiên
						///p(v, dv[i]);
					}
				}
			}
		}
	}
	return 0;
}


myGraph::myGraph(const myGraph &rsh)
{
	for (size_t i = 0; i < rsh.maze.size(); i++)
	{
		maze[i] = rsh.maze[i];
	}
}

myGraph::myGraph()
{
}


myGraph::~myGraph()
{
}

float H(const float & cost, const float & distance)
{
	return cost + distance;
}
