#include"MyGraph.h"


template<typename Comparable>
void BinaryHeap<Comparable>::insert3(const Comparable & x)
{
	if (currentSize == arr.size() - 1)
		arr.resize(arr.size() * 2);
	//percolate up
	int hole = ++currentSize;
	Comparable copy = x;
	size_t i;

	for ( i = 1; i <= currentSize; i++)
	{
		if (equals(arr[i],x))break;
	}

	if (i <= currentSize && x < arr[i])
	{
		modify(arr[i],copy);
	}

	arr[0] = std::move(copy);
	for (; arr[0] < arr[hole / 2]; hole /= 2)
		arr[hole] = std::move(arr[hole / 2]);
	arr[hole] = std::move(arr[0]);
}

void Print2(map<int, string> gr, const vector<int> &result, int end,ostream &out = cout)
{
	stack<int>kq;
	int i = end;
	kq.push(i);
	while (result[i] != -1)
	{
		kq.push(result[i]);
		i = result[i];
	}
	i = kq.top();
	kq.pop();
	while (!kq.empty())
	{
		out << gr[i*h1 + kq.top()*h2 + h3];
		i = kq.top();
		kq.pop();
		if (!kq.empty())
			out << "->";
	}
}

void main(int argc, char* argv[])
{
	fstream ft;
	ft.open(argv[1], fstream::in);
	fstream ft2;
	ft2.open(argv[2], fstream::out);

	int start, end;
	float t;
	CMyGraph mygp;
	mygp.readInput(start, end,ft);
	ft.close();
	vector<int>result;
	t = mygp.RunUSC(start,end,result);
	cout << t << endl;
	if(t!=-1)
		Print2(mygp.nStreet, result, end,cout);
	ft2.close();
}