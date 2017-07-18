#pragma once
#ifndef MY_GRAPH
#define  MY_GRAPH

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
#include<fstream>
using namespace std;
class MyGraph
{
	int soDinh;
	int** dinh;
public:
	void readInput(int &start, int &end,istream &in = cin);
	int runBFS(int*&pre, int start, int end);
	MyGraph();
	MyGraph(const MyGraph &rhs);
	~MyGraph();
};

#endif // !MY_GRAPH