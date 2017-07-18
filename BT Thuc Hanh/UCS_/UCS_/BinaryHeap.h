#pragma once
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include<vector>
#include<exception>

///using namespace std;
template<typename Comparable>
class BinaryHeap
{
private:
	int currentSize;   ////munber of elenemt in heap
	std::vector<Comparable>arr; /// the heap array
	void builHeap();
	void percolateDown(int hole);
public:
	explicit BinaryHeap(int capaccity=100);
	explicit BinaryHeap(const std::vector<Comparable> &item);
	bool isEmpty()const;
	const Comparable& findMin()const;
	void insert(const Comparable& x);
	void insert(Comparable && x);
	void deleteMin();
	void deleteMin(Comparable &minItem);
	void makeEmpty();
	~BinaryHeap() { makeEmpty(); }
	void insert3(const Comparable & x);
};
/*
	establish heap order property from arbitary
	arrangement of items.runs in linear time
*/
template<typename Comparable>
void BinaryHeap<Comparable>::builHeap()
{
	for (int i = currentSize / 2; i > 0; --i)
		percolateDown(i);
}
/*
	internal method to percolate dow in the heap
	hole is the index at which the percolate begins
*/
template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
	int child;
	Comparable tmp = std::move(arr[hole]);

	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize&&arr[child + 1] < arr[child])
			++child;
		if (arr[child] < tmp)
			arr[hole] = std::move(arr[child]);
		else
			break;
	}
	arr[hole] = std::move(tmp);
}

template<typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capaccity):currentSize(0)
{
	arr.resize(capaccity);
}

template<typename Comparable>
inline BinaryHeap<Comparable>::BinaryHeap(const std::vector<Comparable>& item)
	:arr(item.size()+10),currentSize(item.size())
{
	for (int i = 0; i < currentSize; i++)
		arr[i + 1] = item[i];
	builHeap();
}

template<typename Comparable>
inline bool BinaryHeap<Comparable>::isEmpty() const
{
	return currentSize == 0;
}

template<typename Comparable>
inline const Comparable & BinaryHeap<Comparable>::findMin() const
{
	// TODO: insert return statement here
	return arr[1];
}

/*
	insert item X allowing duplicates
*/
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable & x)
{
	if (currentSize == arr.size() - 1)
		arr.resize(arr.size() * 2);
	//percolate up
	int hole = ++currentSize;
	Comparable copy = x;

	arr[0] = std::move(copy);
	for (; x < arr[hole / 2]; hole /= 2)
		arr[hole] = std::move(arr[hole / 2]);
	arr[hole] = std::move(arr[0]);
}

template<typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable && x)
{
	Comparable x1 = std::move(x);
	if (currentSize == arr.size() - 1)
		arr.resize(arr.size() * 2);
	//percolate up
	int hole = ++currentSize;
	Comparable copy = x1;

	arr[0] = std::move(copy);
	for (; x1 < arr[hole / 2]; hole /= 2)
		arr[hole] = std::move(arr[hole / 2]);
	arr[hole] = std::move(arr[0]);
}
/*
	remove the minimun item
	throws UnderflowException if Empty
*/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
	if (isEmpty())
		return;/// throw UnderflowException{};

	arr[1] = std::move(arr[currentSize--]);
	percolateDown(1);
}
/*
	remove minimun item ang place it in minItem.
	throws UnderflowException if Empty
*/
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem)
{
	if (isEmpty())
		return;///throw std::underflow_error; ////UnderflowException{};

	minItem = std::move(arr[1]);
	arr[1] = std::move(arr[currentSize--]);
	percolateDown(1);
}

template<typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
	currentSize = 0;
	arr.clear();
	arr.resize(0);
}





#endif // !BINARY_HEAP_H