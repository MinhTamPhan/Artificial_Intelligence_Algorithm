#pragma once
#ifndef MY_GRAPH
#define  MY_GRAPH

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
using namespace std;
class MyGraph
{
	int soDinh;
	vector<vector<int> > dinh;
public:
	void readInput(int &start,int &end);
	int runBFS(int start, int end, vector<int> &previous);
	MyGraph();
	MyGraph(const MyGraph &rhs);
	~MyGraph();
};

#endif // !MY_GRAPH