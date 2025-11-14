#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int heap[100];
    int size;
    int capacity;

    MaxHeap()
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
        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        cout << "Inserted package with priority " << val << endl;
    }
    
    void maxHeapify(int i){
        int largest=i;
        int left=leftchild(i);
        int right=rightchild(i);
        if(left<size && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<size && heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
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
        maxHeapify(0);
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
};
int main()
{

    MaxHeap h;
    h.insert(5);
    h.insert(3);
    h.insert(1);
    h.insert(2);
    h.insert(4);
    h.printHeap();
    h.removeMax();
    h.printHeap();
    return 0;
}
