#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Node
{
    string url;
    Node* next;
    Node(string u){
        url=u;
        next=NULL;
    }
};

class Stack
{
    int top;
    string a[MAX];

public:
    Stack()
    {
        top = -1;
    }
    bool push(string x)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack Overflow";
            return false;
        }
        else
        {
            a[++top] = x;
            return true;
        }
    }
    string pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return "";
        }
        else
        {
            return a[top--];
        }
    }
    string peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty";
            return "";
        }
        else
        {
            return a[top];
        }
    }
    bool isEmpty()
    {
        return (top < 0);
    }
};

struct Node *top;
void pushtohistory(Node*& head, string url)
{
    Node* n= new Node(url);
    n->next=head;
    head=n;
}
void popoutofhistory(Node*& head){
    if(head==NULL){
        cout<<"History is empty!\n";
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
void display(Node* head){
    cout<<"Browsing History:\n";
    while(head != NULL){
        cout<<head->url;
         if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head=NULL;
    Stack s;
    string arr[]= {"Google", "Insta", "Snapchat", "X", "LinkedIn"};
    for(int i=0; i<5; i++){
        string u=arr[i];
        pushtohistory(head, u);
        s.push(u);
    }
    display(head);
    cout << "\nAfter clicking BACK twice...\n";
    s.pop();
    popoutofhistory(head);
    s.pop();
    popoutofhistory(head);
    display(head);
    if (!s.isEmpty()){
        cout<<"Current page: " << s.pop() << endl;
    }
    else{
        cout << "No pages left in history.\n";
    }
    return 0;
}
