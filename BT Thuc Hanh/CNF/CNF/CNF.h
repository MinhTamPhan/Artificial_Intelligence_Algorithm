#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
#include<queue>
#include"CExpression.h"
using namespace std;
class CCNF
{
private:
	vector<string> input;
public:
	void readInput();
	void Convert_prefix_to_suffixes(vector<queue<string>> &output);
	void createTree(vector<queue<string>> input);
	
	CCNF();
	~CCNF();
};

