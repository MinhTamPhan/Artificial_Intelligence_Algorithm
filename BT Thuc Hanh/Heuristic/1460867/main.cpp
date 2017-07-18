#include"Pacman.h"

void main(int argc,char* agrv[])
{
	Point start, end;
	fstream ft;
	ft.open(agrv[1], fstream::in);
	CPacman pm;
	pm.readInput(start, end, ft);
	ft.close();
	vector<vector<Point> >rsl;
	pm.runAStar(start, end, rsl);
	ft.open(agrv[2], fstream::out);
	pm.write_road(rsl, start, end, ft);
	ft.close();
}