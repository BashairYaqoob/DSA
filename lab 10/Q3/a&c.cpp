#include <iostream>
using namespace std;

const int capacity = 100;

class MaxHeap
{
public:
	int heap[100];
	int size;
	MaxHeap()
	{
		size = 0;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int leftChild(int i)
	{
		return (2 * i) + 1;
	}
	int rightChild(int i)
	{
		return (2 * i) + 2;
	}
	void MaxHeapify(int i)
	{
		int largest = i;
		int left = leftChild(i);
		int right = rightChild(i);

		if (left < size && heap[left] > heap[largest])
		{
			largest = left;
		}
		if (right < size && heap[right] > heap[largest])
		{
			largest = right;
		}
		if (largest != i)
		{
			swap(heap[i], heap[largest]);
			MaxHeapify(largest);
		}
	}
	int getMax()
	{
		if (size > 0)
		{
			return heap[0];
		}
		cout << "Heap is empty!" << endl;
		return -1;
	}
	void insert(int value)
	{
		if (size == capacity)
		{
			cout << "Heap is full!" << endl;
			return;
		}
		heap[size] = value;
		int i = size;
		size++;
		while (i != 0 && heap[parent(i)] < heap[i])
		{
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
	}
	void removeMax()
	{
		if (size <= 0)
		{
			cout << "Heap is empty!" << endl;
			return;
		}
		if (size == 1)
		{
			size--;
			return;
		}
		heap[0] = heap[size - 1];
		size--;
		MaxHeapify(0);
	}
	void printHeap()
	{
		cout << "Heap: ";
		for (int i = 0; i < size; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	void deleteValue(int val)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			if (heap[i] == val)
			{
				break;
			}
		}

		if (i == size)
		{
			cout << "value not found." << endl;
			return;
		}

		heap[i] = heap[size - 1];
		size--;
		MaxHeapify(i);
	}
	void heapSort()
	{
		int s = size;
		for (int i = size - 1; i > 0; i--)
		{
			swap(heap[0], heap[i]);
			size--;
			MaxHeapify(0);
		}

		cout << "Sorted array: ";
		for (int i = 0; i < s; i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
		size = s;
	}
};

int main()
{
	MaxHeap h;

	h.insert(25);
	h.insert(30);
	h.insert(35);
	h.insert(11);
	h.insert(15);
	h.insert(19);
	h.insert(18);
	h.insert(55);
	h.insert(78);
	h.insert(36);
	cout << "Current heap" << endl;
	h.printHeap();
	h.deleteValue(55);
	cout << "Heap after deleting 55:" << endl;
	h.printHeap();
	h.deleteValue(18);
	cout << "Heap after deleting 18:" << endl;
	h.printHeap();
	h.heapSort();

	return 0;
}
