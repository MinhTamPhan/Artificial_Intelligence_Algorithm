#ifndef Queen_H
#define Queen_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;
#pragma once
struct Point
{
	int x, y;
	Point(int dx,int dy):x(dx),y(dy)
	{}
	Point(){}
};
class CNQueen
{
private:
	//bàn cờ
	vector<string>chessBoard;
	//đường chéo
	vector<bool>DuongCheoChinh, Duongcheophu;
	//cột
	vector<bool>Cot;
	//hậu thứ i đặt dạt vị trí loigiai[i]
	vector<int>loiGiai;
	int size;
public:
	void Solution(int n);
	void PrintSolution();
	CNQueen(int n);
	CNQueen();
	~CNQueen();
};

class CNQueen2
{
private:
	//bàn cờ
	vector<string>chessBoard;

	//lưu Dộ lớn của bàn cờ NxN
	int N;
	//đường chéo
	vector<bool>DuongCheoChinh, Duongcheophu;
	//cột
	vector<bool>Cot,Dong;
	vector<Point>x;

	vector<Point> findDomains();
	bool CheckConstraint(Point x);
	void UpdateDomaints(Point P);
	void UpdateDomaints2(Point P);
public:
	void BackTrack(int x,vector<Point>Domains);
	void PrintSolution();
	
	CNQueen2(int n);
	CNQueen2() {};
	~CNQueen2() {};
};

#endif // !Queen_H
