#include<functional>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<queue>
#include<stack>
#pragma once
class CPoint2D
{
private:
	int x;
	int y;
public:

	float Distance(const CPoint2D &p1)const
	{
		return (float)abs(x - p1.x) + abs(y - p1.y);
	}

	bool operator ==(const CPoint2D &p1)const
	{
		return x == p1.x && y == p1.y;
	}

	bool operator !=(const CPoint2D &p1)const
	{
		return !(*this == p1);
	}

	void setX(int dx) { x = dx; }
	void setY(int dy) { y = dy; }

	CPoint2D operator =(const CPoint2D &p1)
	{
		x = p1.x;
		y = p1.y;
		return *this;
	}
	CPoint2D operator = (CPoint2D && p1)
	{
		std::swap(x , (p1.x));
		std::swap(y , (p1.y));
		return *this;
	}

	CPoint2D(const CPoint2D & p):x(p.x),y(p.y)
	{
	}

	CPoint2D(CPoint2D && p) :x(p.x), y(p.y)
	{
		p.x = 0;
		p.y = 0;
	}

	CPoint2D(void);
	CPoint2D(int x, int y);
	~CPoint2D(void);

	int GetX()const;
	int GetY()const;
};

