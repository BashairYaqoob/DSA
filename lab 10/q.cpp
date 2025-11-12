#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	int priority;
	Node *next;
	Node(int val, int pri) : value(val), priority(pri), next(NULL) {}
};

class PriorityQueue
{
private:
	Node *front;

public:
	PriorityQueue()
	{
		front = NULL;
	}
	~PriorityQueue()
	{
		while (front)
		{
			Node *temp = front;
			front = front->next;
			delete temp;
		}
	}
	void insert(int val, int pri)
	{
		Node *n = new Node(val, pri);
		if (!front || pri > front->priority)
		{
			n->next = front;
			front = n;
		}
		else
		{
			Node *current = front;
			while (current->next && current->next->priority >= pri)
			{
				current = current->next;
			}
			n->next = current->next;
			current->next = n;
		}
	}
	void remove()
	{
		if (!front)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		Node *temp = front;
		front = front->next;
		delete temp;
	}
	int peek()
	{
		if (!front)
		{
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		return front->value;
	}
	void printQueue()
	{
		if (!front)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		Node *current = front;
		while (current)
		{
			cout<<"("<<current->value<<", "<<current->priority<<")";
			current = current->next;
		}
		cout<<endl;
	}
};



int main(){

    return 0;
}
