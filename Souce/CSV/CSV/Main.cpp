#include"NQueen.h"
void main()
{
	/*CNQueen Chess(8);
	Chess.Solution(0);
	Chess.PrintSolution();*/

	//lưu vị trí các quân hậu
	vector<Point>x,D;

	CNQueen2 Chess(4);
	Chess.BackTrack(0,D);
}