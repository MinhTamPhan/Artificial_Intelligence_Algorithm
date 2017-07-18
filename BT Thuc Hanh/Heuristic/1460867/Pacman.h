#include<functional>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<queue>
#include"BinaryHeap.h"
using namespace std;
#pragma once
class Point
{
private:
	int x, y;
public:
	int getx()const { return x; }
	int gety()const { return y; }
	void setx(int dx) { x = dx; }
	void sety(int dy) { y = dy; }
	Point(int x0 = 0,int y0 = 0):x(x0),y(y0)
	{}
	float Distance(const Point &p1)
	{
		return sqrt(pow(x - p1.x, 2) + pow(y - p1.y, 2));
	}
	bool operator ==(const Point &p1)const
	{
		return x == p1.x && y == p1.y;
	}
	bool operator !=(const Point &p1)
	{
		return !(*this == p1);
	}
	Point operator =(const Point &p1)
	{
		x = p1.x;
		y = p1.y;
		return *this;
	}
	Point operator =(Point &&p1)
	{
		x = p1.x;
		y = p1.y;
		return *this;
	}
	Point(const Point & p):x(p.x),y(p.y)
	{
	}
	Point(Point && p) :x(std::move(p.x)), y(std::move(p.y))
	{
	}
	~Point(){}
};

class Pri_Point
{
private:
	float key;
	Point data;
public:
	Point GetPoit() { return data; }
	bool operator >(const Pri_Point & pr1) const
	{
		if (key > pr1.key)
			return true;
		return false;
	}
	bool operator <(const Pri_Point & pr1)const
	{
		if (key < pr1.key)
			return true;
		return false;
	}

	Pri_Point operator =(Pri_Point &&pr1)
	{
		key = std::move(pr1.key);
		data = pr1.data;
		return *this;
	}

	Pri_Point operator =(const Pri_Point &pr1)
	{
		key = pr1.key;
		data = pr1.data;
		return *this;
	}

	Pri_Point(const float &k, const Point &p) :key(k), data(p)
	{}
	Pri_Point(float &&k, Point &&p) :key(std::move(k)), data(std::move(p))
	{}
	Pri_Point(const Pri_Point& p):key(p.key),data(p.data)
	{
	}
	Pri_Point(Pri_Point&& p) :key(p.key), data(p.data)
	{
	}
	Pri_Point(int k,const Point &p):key(k),data(p)
	{}
	Pri_Point(int &&k, Point &&p) :key(k), data(p)
	{}
	Pri_Point() :key(0)
	{
		data = *new Point();
	}
	~Pri_Point(){}
};

class CPacman
{
private:
	vector<string>maze;
	vector<Point> Succesor(Point p) const;
public:
	friend float H(const float &cost,const float &distance);
	void readInput(Point &start,Point &end,istream &in);
	float runAStar(Point start, Point end, vector<vector<Point> >&privious);
	void write_road(const vector<vector<Point> >&privious, const Point &s, const Point&e, ostream &out);
	CPacman();
	~CPacman();
};

