#include <iostream>
using namespace std;
class minheap
{
public:
	int heap[100];
	int size;
	int capacity;

	minheap()
	{
		size = 0;
		capacity = 30;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int leftchild(int i)
	{
		return (2 * i) + 1;
	}
	int rightchild(int i)
	{
		return (2 * i) + 2;
	}
	void insert(int val)
	{
		if (size == capacity)
		{
			cout << "Heap is full" << endl;
			return;
		}
		heap[size] = val;
		size++;
		int i = size - 1;
		while (i != 0 && heap[parent(i)] > heap[i])
		{
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
		cout << "inserted package with priority " << val << endl;
	}
	void display()
	{
		cout << "Heap: ";
		for (int i = 0; i < size; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
};
int main()
{

	minheap heap;
	heap.insert(5);
	heap.insert(3);
	heap.insert(1);
	heap.display();
	heap.insert(2);
	heap.display();
}
