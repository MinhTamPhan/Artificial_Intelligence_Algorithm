// 1460867.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include"myGraph.h"



using namespace std;

static HWND consoleHandle;

void DrawGraph();
int DrawLine(HWND,const CPoint2D &, const CPoint2D &, int = 0, HDC = 0);
int DrawCircle(HWND,const CPoint2D&, int, int = 0, int = 0, HDC = 0);
int DrawSquare(HWND,const CPoint2D &, int = 0, int = 0, HDC = 0);
void DrawmyGraph(vector<string> a);
void DrawRoad(vector<vector<CPoint2D> > R,const CPoint2D &end,const CPoint2D &start);
void Drawpoint(const CPoint2D &end, const CPoint2D &start);

int main(int argc,char *argv[])
{
	vector<string>input;
	fstream ft;
	ft.open(argv[1], fstream::in);
	CPoint2D start, end;
	myGraph myGp;
	myGp.readInput(start, end, ft, input);
	ft.close();
	vector<vector<CPoint2D> >result;
	void(*Draw)(const CPoint2D &end, const CPoint2D &start) = Drawpoint;
	consoleHandle = GetConsoleWindow();

	DrawmyGraph(input);
	///myGp.runAStar(start, end, result); --- chạy thật toán,k vẽ
	myGp.runAStar1(start, end, result, Draw);
	
	DrawRoad(result, end, start);
	
	return 0;
}


void DrawmyGraph(vector<string> a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < a[0].size(); j++)
		{
			if (a[i][j] == '%')
				DrawSquare(consoleHandle, CPoint2D(50 + j * 15, i * 15 + 50)
					, RGB(0, 0, 253), RGB(206, 255, 0));
			else if (a[i][j] == 'P')
				DrawSquare(consoleHandle, CPoint2D(50 + j * 15, i * 15 + 50)
					, RGB(255, 0, 0), RGB(255, 0, 0));
			else if (a[i][j] == 'G')
				DrawSquare(consoleHandle, CPoint2D(50 + j * 15, i * 15 + 50)
					, RGB(0, 255, 0), RGB(255, 0, 0));
			///this_thread::sleep_for(chrono::milliseconds(10));
		}
	}
}

void DrawRoad(vector<vector<CPoint2D> > R,const CPoint2D &end, const CPoint2D &start)
{
	stack<CPoint2D> st;
	st.push(end);
	CPoint2D v = R[end.GetY()][end.GetX()];
	while (v != start)
	{
		st.push(v);
		v = R[v.GetY()][v.GetX()];
	}
	st.push(start);
	v = st.top();
	st.pop();
	while (!st.empty())
	{
		DrawLine(consoleHandle, v, st.top(), RGB(0,191,255));
		this_thread::sleep_for(chrono::milliseconds(50));
		v = st.top();
		st.pop();
	}
}

void DrawGraph()
{
	for (int i = 0; i < 10; i++)
	{
		///DrawCircle(consoleHandle, CPoint2D(50 + i * 20, 50 + i * 20), 10, RGB(i * 5, i * 15, 255), RGB(206, 255, 0));

		DrawSquare(consoleHandle, CPoint2D(50 + i * 30, 50), RGB(i * 5, i * 15, 255), RGB(206, 255, 0));
		// sleep for 1s
		this_thread::sleep_for(chrono::seconds(1));
	}
}

// Vẽ đường thẳng
int DrawLine(HWND windowHandle, const CPoint2D &start, const CPoint2D &end, int color, HDC deviceContext) {
	int a, b = 0;
	HPEN oldPen;

	//Tạo pen mới
	HPEN newPen = CreatePen(PS_SOLID, 2, color);

	// Tạo device context
	if (!deviceContext) deviceContext = GetDC(windowHandle), b = 1;

	// Chọn pen mới
	oldPen = (HPEN)SelectObject(deviceContext, newPen);

	// Di chuyển đến điểm bắt đầu đường thẳng
	MoveToEx(deviceContext, start.GetX() * 15 + 57, start.GetY() * 15 + 57, NULL);

	// Vẽ đường thẳng
	a = LineTo(deviceContext, end.GetX() * 15 + 57, end.GetY() * 15 + 57);

	// Chọn lại pen cũ
	DeleteObject(SelectObject(deviceContext, oldPen));

	// Giải phóng device context
	if (b) ReleaseDC(windowHandle, deviceContext);
	return a;
}

// Vẽ hình tròn C(center, radius)
int DrawCircle(HWND windowHandle,const CPoint2D &center, int radius, int color, int fillColor, HDC deviceContext)
{
	int a, b = 0;
	// Tạo device context
	if (!deviceContext) deviceContext = GetDC(windowHandle), b = 1;
	// Tạo pen mới với màu yêu cầu
	HPEN newPen = CreatePen(PS_SOLID, 2, color);
	// Chọn pen mới và lưu lại pen cũ
	HPEN oldPen = (HPEN)SelectObject(deviceContext, newPen);
	HBRUSH oldBrush;
	HBRUSH newBrush;

	// Trong trường hợp yêu cầu tô màu cho hình tròn
	if (fillColor) {
		newBrush = CreateSolidBrush(color);
		oldBrush = (HBRUSH)SelectObject(deviceContext, newBrush);
	}
	else {
		newBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		oldBrush = (HBRUSH)SelectObject(deviceContext, newBrush);
	}
	// Vẽ hình tròn
	a = Ellipse(deviceContext, center.GetX() - radius, center.GetY() + radius, center.GetX() + radius, center.GetY() - radius);

	// Chọn lại pen cũ
	DeleteObject(SelectObject(deviceContext, oldPen));
	DeleteObject(SelectObject(deviceContext, oldBrush));

	// Giải phóng device context
	if (b) ReleaseDC(windowHandle, deviceContext);
	return a;
}
// vẽ hình vuông
int DrawSquare(HWND windowHandle, const CPoint2D &center, int color, int fillColor, HDC deviceContext)
{
	int a, b = 0;
	// Tạo device context
	if (!deviceContext) deviceContext = GetDC(windowHandle), b = 1;
	// Tạo pen mới với màu yêu cầu
	HPEN newPen = CreatePen(PS_SOLID, 2, color);
	// Chọn pen mới và lưu lại pen cũ
	HPEN oldPen = (HPEN)SelectObject(deviceContext, newPen);
	HBRUSH oldBrush;
	HBRUSH newBrush;

	// Trong trường hợp yêu cầu tô màu cho hình tròn
	if (fillColor) {
		newBrush = CreateSolidBrush(color);
		oldBrush = (HBRUSH)SelectObject(deviceContext, newBrush);
	}
	else {
		newBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		oldBrush = (HBRUSH)SelectObject(deviceContext, newBrush);
	}
	// Vẽ hình Vuông
	a = Rectangle(deviceContext, center.GetX(), center.GetY(), center.GetX() + 15, center.GetY() + 15);

	// Chọn lại pen cũ
	DeleteObject(SelectObject(deviceContext, oldPen));
	DeleteObject(SelectObject(deviceContext, oldBrush));

	// Giải phóng device context
	if (b) ReleaseDC(windowHandle, deviceContext);
	return a;
}

void Drawpoint(const CPoint2D &start, const CPoint2D &end)
{
	DrawLine(consoleHandle,start,end, RGB(255, 0, 0));
	this_thread::sleep_for(chrono::milliseconds(100));
}
