#include "Pacman.h"



vector<Point> CPacman::Succesor(Point p) const
{
	vector<Point>rsl;
	int x = p.getx(), y = p.gety();
	int left = x - 1, right = x+ 1, top = y - 1, bottom = y + 1;
	if (maze[y][left] != '%')
	{
		rsl.push_back(*new Point(left,y));
	}
	if (maze[y][right] != '%')
	{
		rsl.push_back(*new Point(right, y));
	}
	if (maze[top][x] != '%')
	{
		rsl.push_back(*new Point(x, top));
	}
	if (maze[bottom][x] != '%')
	{
		rsl.push_back(*new Point(x, bottom));
	}
	return rsl;
}

void CPacman::readInput(Point & start, Point & end, istream & in)
{
	while (!in.eof())
	{
		string temp;
		getline(in, temp);
		size_t x = temp.find('P');
		if (x != string::npos)
		{
			start.setx(x);
			start.sety(maze.size());
		}
		x = temp.find('G');
		if (x != string::npos)
		{
			end.setx(x);
			end.sety(maze.size());
		}
		maze.push_back(temp);
	}
}

float CPacman::runAStar(Point start,Point end, vector<vector<Point> >& privious)
{
	//BinaryHeap<Pri_Point>pQ;
	priority_queue<Pri_Point, deque<Pri_Point>, greater<Pri_Point> > pQ;
	//queue<Point>pQ;
	vector<vector<bool>> label(maze.size());
	vector<vector<int>>cost(maze.size());
	privious.resize(maze.size());
	for (size_t i = 0; i < maze.size(); i++)
	{
		label[i].resize(maze[0].size(), false);
		cost[i].resize(maze[0].size(),0);
		privious[i].resize(maze[0].size());
	}
	pQ.push(*new Pri_Point(start.Distance(end), start));

	//privious[v.x + v.x*v.y] = *new Point(-1, -1);
	while (!pQ.empty())
	{
		Pri_Point t = pQ.top();
		Point v = t.GetPoit();
		pQ.pop();
		int x = v.getx(), y = v.gety();
		label[y][x] = true;
		if (end == v)
			return cost[y][x];
		else
		{
			vector<Point> dv = Succesor(v);
			for (int i = 0; i < dv.size(); i++)
			{
				int dx = dv[i].getx(), dy = dv[i].gety();
				if (label[dy][dx] == false)
				{
					float k;
					k = cost[dy][dx] = cost[y][x] + 1;

					pQ.push(*new Pri_Point(H(k, dv[i].Distance(end)), dv[i]));
					//pQ.push(dv[i]);
					label[dy][dx] = true;
					privious[dv[i].gety()][dv[i].getx()] = v;
				}
			}
		}
	}
}

void CPacman::write_road(const vector<vector<Point>>& privious, const Point & s, const Point & e, ostream & out)
{
	Point v = privious[e.gety()][e.getx()];
	while (v!=s)
	{
		int x = v.getx(), y = v.gety();
		maze[y][x] = '*';
		v = privious[y][x];
	}
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			out << maze[i][j];
		}
		out << endl;
	}
}

CPacman::CPacman()
{
	maze.resize(0);
}


CPacman::~CPacman()
{
}

float H(const float & cost, const float & distance)
{
	return cost + distance;
}
