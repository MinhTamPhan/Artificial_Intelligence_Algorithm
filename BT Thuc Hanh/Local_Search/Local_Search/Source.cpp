#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
using namespace std;

int maxKill(vector<int> Chessboard)
{
	int n = Chessboard.size();
	int count = 0,max = -1,pos = 0;
	
	for (int i = 0; i < n; i++)
	{
		bool TopLeft = false, TopRight = false, BottomLeft = false, BottomRight = false;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (Chessboard[i] == Chessboard[j]) ////cùng 1 hàng
				{
					count++;
				}
				else if (Chessboard[j] == Chessboard[i] + j - i && BottomRight == false)
					////cùng đường chéo chính,chưa xét theo hướng bottom Right
				{
					count++;
					BottomRight = true;
				}
				else if (Chessboard[i] == Chessboard[j] - (j - i) && TopLeft == false)
					////cùng đường chéo chính,chưa xét theo hướng top left
				{
					count++;
					TopLeft = true;
				}
				else if (Chessboard[j] == Chessboard[i] - (j - i) && TopRight == false)
					////cùng đường chéo phụ,và chưa xét theo hướng top Right
				{
					count++;
					TopRight = true;
				}

				else if (Chessboard[i] == Chessboard[j] + j - i && BottomLeft == false)
					////cùng đường chéo phụ,và chưa xét hướng BottomLeft
				{
					count++;
					BottomLeft = true;
				}
			}
		}
		
		if (count > max)
		{
			max = count;
			pos = i;
		}
		count = 0;
	}
	return pos;
}

int numberQkillQ(vector<int> Chessboard,int x,int y)
{
	Chessboard[x] = y;
	int count = 0;
	int n = Chessboard.size();
	for (int i = 0;i < n-1;i++)
	{
		for (int j = i + 1; j<  n; j++)
		{
			if (Chessboard[i] == Chessboard[j]) ////cùng 1 hàng
				count++;
			if (Chessboard[j] == Chessboard[i] + j - i)////cùng đường chéo chính
				count++;
			if (Chessboard[j] == Chessboard[i] - (j - i))////cùng đường chéo phụ
				count++;
		}
	}
	return count;
}

int localSearch(vector<int> &Chessboard)
{
	int MaxNumberLoop = 1001;
	int i = 0;
	int n = Chessboard.size();
	int minH = n*n;
	while (i < MaxNumberLoop && numberQkillQ(Chessboard,0,Chessboard[0]) != 0)
	{
		int pos = maxKill(Chessboard);
		
		int PosMinH = 0;
		for (size_t j = 0; j < n; j++)
		{
			int H = numberQkillQ(Chessboard, pos, j);
			
			if (H <= minH && Chessboard[pos] != j)
			{
				minH = H;
				PosMinH = j;
			}
		}
		Chessboard[pos] = PosMinH;
		
		
		i++;
	}
	return i;
}

int main(int argc,char* agrv[])
{
	srand(time(nullptr));
	int n = atoi(agrv[1]);
	vector<int>Chessboard(n);
	Chessboard[0] = 2; Chessboard[1] = 1; Chessboard[2] = 2; Chessboard[3] = 1;
	for ( int &i : Chessboard)
	{
		i = rand() % n;
		cout << i << " ";//ghi ra console phép gán
	}
	fstream f;
	f.open(agrv[2], fstream::out);

	int nLoop = localSearch(Chessboard);
	f << nLoop << endl;
	for (int i : Chessboard)
	{
		f << i << " ";
	}
	return 0;
}