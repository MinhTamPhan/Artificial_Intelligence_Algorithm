#ifndef MY_GRAPH2_H
#define MY_GRAPH2_H

#include<functional>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<map>
using namespace std;
#pragma once
const int h1 = 3, h2 = 103, h3 = 7;


class Street
{
	int vertex1;
	int vertex2;
	string name;
	float length;
public:
	int getvt1() { return vertex1; }
	int getvt2() { return vertex2; }
	float getLeng() { return length; }
	string Getmane() { return name; }
	Street()
	{
		vertex1 = 0;
		vertex2 = 0;
		name = '\0';
		length = 0;
	}
	Street(const Street &rhs)
	{
		vertex1 = rhs.vertex1;
		vertex2 = rhs.vertex2;
		name = rhs.name;
		length = rhs.length;
	}
	Street(Street &&rhs)
	{
		vertex1 = std::move(rhs.vertex1);
		vertex2 = std::move(rhs.vertex2);
		name = std::move(rhs.name);
		length = std::move(rhs.length);
	}
	Street operator = (const Street &st1)
	{
		return *(new Street(st1));
	}
	Street operator = (Street &&st1)
	{
		return *(new Street(st1));
	}
	friend istream& operator >> (istream& in,Street &st)
	{
		in >> st.vertex1;
		in >> st.vertex2;
		in >> st.name;
		in >> st.length;
		return in;
	}
};

struct priority_vetex
{
	int vertex;
	float cost;
	friend bool operator < (const priority_vetex &vt1,const priority_vetex &vt2)
	{
		return vt1.cost < vt2.cost;
	}
	friend bool operator > (const priority_vetex &vt1, const priority_vetex &vt2)
	{
		return !(vt1.cost < vt2.cost);
	}
	priority_vetex(const int &vt = 0, const float &c = 0) :vertex(vt), cost(c){ }
	priority_vetex(int &&vt, float &&c) :vertex(std::move(vt)), cost(std::move(c)) { }
};

class CMyGraph
{
	int soDinh;
	vector<vector<float> >Dinh;
	vector<Street> arrStreet;
public:
	static map<int, string>nStreet;
	void readInput(int &start,int &end);
	float RunDFS(const int &start,const int &end, vector<int> &Previous);

	float RunUSC(const int &start, const int &end, vector<int> &Previous);

	float RunISC(const int &start, const int &end, vector<int> &Previous);

	friend float IDS(const CMyGraph&,const int & start, const int & end, vector<int>& Previous, int h);

	CMyGraph operator = (const CMyGraph &rhs);
	CMyGraph operator = (CMyGraph &&rhs);
	CMyGraph(const CMyGraph &rhs);
	CMyGraph(CMyGraph &&rhs);
	CMyGraph();
	~CMyGraph();
};

#endif // !MY_GRAPH2_H

