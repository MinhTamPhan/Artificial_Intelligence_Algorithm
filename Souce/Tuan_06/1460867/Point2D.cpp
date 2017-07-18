#include "StdAfx.h"
#include "Point2D.h"


CPoint2D::CPoint2D(void)
{
}

CPoint2D::CPoint2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

CPoint2D::~CPoint2D(void)
{
}

int CPoint2D::GetX()const
{
	return x;
}

int CPoint2D::GetY()const
{
	return y;
}

