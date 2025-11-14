#include <iostream>
using namespace std;

const int capacity=100;

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
            cout << "No tasks available!" << endl;
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
    void updatePriority(int ind, int newprior){
        if(ind<0 || ind>=size){
            cout<<"Invalid task index!"<<endl;
            return;
        }
        int oldpri=heap[ind];
        heap[ind]=newprior;
        cout<<"Priority at index "<<ind<<" updated!"<<endl;
        if(newprior>oldpri){
            while (ind != 0 && heap[parent(ind)] < heap[ind])
        {
            swap(heap[ind], heap[parent(ind)]);
            ind = parent(ind);
        }
        }
        else{
            maxHeapify(ind);
        }
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
    h.printHeap();
    h.insert(4);
    h.printHeap();
    h.insert(2);
    h.printHeap();
    h.insert(4);
    h.printHeap();
    h.insert(1);
    h.printHeap();
    cout<<"Removing the task with highest priority:"<<endl;
    h.removeMax();
    h.printHeap();
    h.updatePriority(2, 3);
    h.updatePriority(3, 5);
    cout<<"Final heap: "<<endl;
    h.printHeap();
    return 0;
}
