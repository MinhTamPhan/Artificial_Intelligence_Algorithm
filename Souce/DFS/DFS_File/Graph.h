#ifndef MY_GRAPH2_H
#define MY_GRAPH2_H

#include<functional>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<map>
#include<fstream>
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
	static map<int, string>nStreet;
	int getvt1() { return vertex1; }
	int getvt2() { return vertex2; }
	float getLeng() { return length; }
	string Getmane() { return name; }

	/*big-five:Destructor,Copy Contructor,Move Contructor
	copy Assignment ,move Assignment */

	Street()
	{
		vertex1 = 0;
		vertex2 = 0;
		name = '\0';
		length = 0;
	}
	//Copy Contructor
	Street(const Street &rhs)
	{
		vertex1 = rhs.vertex1;
		vertex2 = rhs.vertex2;
		name = rhs.name;
		length = rhs.length;
	}
	//Move Contructor
	Street(Street &&rhs)
	{
		vertex1 = std::move(rhs.vertex1);
		vertex2 = std::move(rhs.vertex2);
		name = std::move(rhs.name);
		length = std::move(rhs.length);
	}
	//copy Assignment
	Street operator = (const Street &st1)
	{
		return *(new Street(st1));
	}
	//move Assignment
	Street operator = (Street &&st1)
	{
		return *(new Street(st1));
	}

	~Street(){}//Destructor
	///toán tử nhập
	friend istream& operator >> (istream& in, Street &st)
	{
		in >> st.vertex1;
		in >> st.vertex2;
		in >> st.name;
		in >> st.length;
		return in;
	}
};


class CMyGraph
{
	int soDinh;
	vector<vector<float> >Dinh;
	vector<Street> arrStreet;
public:
	
	void readInput(int &start, int &end,istream &in = cin);

	float RunDFS(const int &start, const int &end, vector<int> &Previous);

	float RunISC(const int &start, const int &end, vector<int> &Previous);

	friend float ISC(const CMyGraph&, const int & start, const int & end, vector<int>& Previous, int h);

	/*big-five:Destructor,Copy Contructor,Move Contructor
	copy Assignment ,move Assignment */
	//copy Assignment
	CMyGraph operator = (const CMyGraph &rhs);
	//move Assignment 
	CMyGraph operator = (CMyGraph &&rhs);
	//Copy Contructor
	CMyGraph(const CMyGraph &rhs);
	//Move Contructor
	CMyGraph(CMyGraph &&rhs);
	CMyGraph();
	~CMyGraph();
};

#endif // !MY_GRAPH2_H