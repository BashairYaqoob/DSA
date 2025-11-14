#include <iostream>
using namespace std;

const int capacity = 100;

class MinHeap
{
public:
    int heap[100];
    int size;
    MinHeap()
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
    void minHeapify(int i)
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
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
        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void removeMin()
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
        minHeapify(0);
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
        minHeapify(i);
    }

};
int main()
{
    MinHeap h;
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
    cout<<"Heap before deleting 18: "<<endl;
    h.printHeap();
    h.deleteValue(18);
    cout<<"Heap after deleting 18: "<<endl;
    h.printHeap();
    return 0;
}
