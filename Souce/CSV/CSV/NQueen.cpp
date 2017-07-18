#include "NQueen.h"




void CNQueen::Solution(int j)
{
	//lặp qua các cột có thể dặt hậu
	for (int i = 0; i < size; i++)
	{
		///nếu có cột và dường chéo trống
		if (Cot[i] && DuongCheoChinh[j-i + size - 1] && Duongcheophu[i + j])
		{
			loiGiai[j] = i;/*ghi nhận lại vị trí*/

			///đánh đấu cột đường chéo xuôi,ngược
			Cot[i] = false;
			DuongCheoChinh[j-i + size - 1] = false;
			Duongcheophu[i + j] = false;

			if (j == size - 1)
				return;
			else
				Solution(j + 1);

			Cot[i] = true;
			DuongCheoChinh[j-i + size - 1] = true;
			Duongcheophu[i + j] = true;
		}
	}
}

void CNQueen::PrintSolution()
{
	for (size_t i = 0; i < loiGiai.size(); i++)
	{
		if(loiGiai[i]>-1)
			chessBoard[loiGiai[i]][i] = 'Q';
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if(chessBoard[i][j]=='Q')
				cout << chessBoard[i][j] << "  ";
			else cout << "P"<<"  ";
		}
		cout << endl;
	}
}

CNQueen::CNQueen(int n)
{
	size = n;
	chessBoard.resize(n);
	DuongCheoChinh.resize(n*2-1, true);
	Duongcheophu.resize(n*2-1, true);
	loiGiai.resize(n, -1);
	Cot.resize(n, true);
	for (size_t i = 0; i < size; i++)
	{
		chessBoard[i].resize(size, 'S');
	}
}

CNQueen::CNQueen()
{
}


CNQueen::~CNQueen()
{
}


bool CNQueen2::CheckConstraint(Point p)
{
	int n = p.x, m = p.y;
	if (Cot[n] && Dong[m] && DuongCheoChinh[m - n + N - 1] && Duongcheophu[m + n])
		return true;
	return false;
}

void CNQueen2::UpdateDomaints(Point P)
{
	int i = P.x, j = P.y;
	Cot[i] = false; Dong[j] = false;
	DuongCheoChinh[j - i + N - 1] = false;
	Duongcheophu[i + j] = false;
}

void CNQueen2::UpdateDomaints2(Point P)
{
	int i = P.x, j = P.y;
	Cot[i] = true; Dong[j] = true;
	DuongCheoChinh[j - i + N - 1] = true;
	Duongcheophu[i + j] = true;
}

vector<Point> CNQueen2::findDomains()
{
	vector<Point>rsl;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (Cot[i] && Dong[j] && DuongCheoChinh[j - i + N - 1] && Duongcheophu[i + j])
				rsl.push_back(Point(j, i));
		}
	}
	return rsl;
}

void CNQueen2::BackTrack(int cur, vector<Point> Domains)
{
	if (cur == N)//phép gán đầy đủ
		return;
	else
	{
		vector<Point>DomainsJ = findDomains();
		for (size_t i = 0; i < DomainsJ.size() && cur < N; i++)
		{
			x[cur] = DomainsJ[i];
			if (!CheckConstraint(x[cur]))
				continue;
			UpdateDomaints(x[cur]);
			vector<Point>Domainsji = findDomains();
			BackTrack(cur + 1, Domainsji);

			UpdateDomaints2(x[cur+1]);
			//UpdateDomaints2(x[cur]);
			//Domainsji = findDomains();
		}
	}
}

CNQueen2::CNQueen2(int n)
{
	N = n;
	chessBoard.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		chessBoard[i] = "S";
	}
	Cot.resize(N, true);
	DuongCheoChinh.resize(N*2-1, true);
	Duongcheophu.resize(N*2-1, true);
	Dong.resize(N, true);
	x.resize(n);
}
