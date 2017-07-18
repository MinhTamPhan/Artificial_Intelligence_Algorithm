#pragma once

#include"Point2D.h"
using namespace std;

class Pri_Point
{
private:
	float key;
	CPoint2D data;
public:
	CPoint2D GetPoit() { return data; }
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
		std::swap(key,pr1.key);
		std::swap(data, pr1.data);
		return *this;
	}

	Pri_Point operator =(const Pri_Point &pr1)
	{
		Pri_Point copy = pr1;
		std::swap(*this, copy);
		return *this;
	}

	Pri_Point(float &&k, CPoint2D &&p) :key(std::move(k)), data(std::move(p))
	{}
	Pri_Point(const Pri_Point& p) :key(p.key), data(p.data)
	{
	}
	Pri_Point(Pri_Point&& p) :key(p.key), data(p.data)
	{
	}
	Pri_Point(float k, const CPoint2D &p) :key(k), data(p)
	{}

	Pri_Point() :key(0)
	{
		data = *new CPoint2D();
	}
	~Pri_Point() {}
};


class myGraph
{
private:
	vector<CPoint2D> Succesor(CPoint2D p) const;
	vector<string>maze;
public:
	friend float H(const float &cost, const float &distance);
	void readInput(CPoint2D &start, CPoint2D &end, istream &in, vector<string> &mzout);
	float runAStar(CPoint2D start, CPoint2D end, vector<vector<CPoint2D> >&privious)const;

	float  myGraph::runAStar1(const CPoint2D &start,const CPoint2D &end, vector<vector<CPoint2D> >& privious,
		void(*Draw)(const CPoint2D &p1, const CPoint2D &p2))const;

	myGraph::myGraph(const myGraph &rsh);
	myGraph();
	~myGraph();
};

