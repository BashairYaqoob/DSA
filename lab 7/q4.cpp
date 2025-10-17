#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

class Singly
{
	Node *head;
	Node *getTail(Node *temp)
	{
		while (temp != nullptr && temp->next != nullptr)
		{
			temp = temp->next;
		}
		return temp;
	}
	Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
	{
		Node *pivot = end;
		Node *prev = nullptr, *cur = head, *tail = pivot;
		while (cur != pivot)
		{
			if (cur->data < pivot->data)
			{
				if ((*newHead) == nullptr)
					(*newHead) = cur;
				prev = cur;
				cur = cur->next;
			}
			else
			{
				if (prev)
					prev->next = cur->next;
				Node *tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail = cur;
				cur = tmp;
			}
		}
		if ((*newHead) == nullptr)
			(*newHead) = pivot;

		(*newEnd) = tail;
		return pivot;
	}
	Node *quickSort(Node *head, Node *end)
	{
		if (!head || head == end)
			return head;

		Node *newHead = nullptr, *newEnd = nullptr;
		Node *pivot = partition(head, end, &newHead, &newEnd);

		if (newHead != pivot)
		{
			Node *temp = newHead;
			while (temp->next != pivot)
				temp = temp->next;
			temp->next = nullptr;

			newHead = quickSort(newHead, temp);

			temp = getTail(newHead);
			temp->next = pivot;
		}

		pivot->next = quickSort(pivot->next, newEnd);
		return newHead;
	}

public:
	Singly()
	{
		head = NULL;
	}
	void push(int data)
	{
		Node *newNode = new Node(data);
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		Node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void display()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void quicksort() {
        head = quickSort(head, getTail(head));
    }
};

int main()
{
	Singly s;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        s.push(arr[i]);

    cout << "Original List: ";
    s.display();

    s.quicksort();

    cout << "Sorted List: ";
    s.display();
	return 0;
}
