#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class Doubly
{
public:
    Node *head;
    Node *tail;
    Doubly()
    {
        head = NULL;
        tail = NULL;
    }
    void insertatEnd(int val)
    {
        Node *n = new Node(val);
        if (tail == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void deleteatFront()
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node *n = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        delete n;
    }
    bool Search(int val)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "\nInteger "<<val<<" found!\n";
                return true;
            }
            temp = temp->next;
        }
        cout << "Integer "<<val<<" was not found!\n";
        return false;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Doubly d1;

    d1.insertatEnd(10);
    d1.insertatEnd(20);
    d1.insertatEnd(30);

    cout << "Doubly Linked List: ";
    d1.display();

    d1.deleteatFront();
    cout << "\nAfter deleting front: ";
    d1.display();

    d1.Search(20);
    d1.Search(35);

    return 0;
}
