#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int ID;
	string name;
	Node *left;
	Node *right;
	Node(int id, string n)
	{
		ID = id;
		name = n;
		left = NULL;
		right = NULL;
	}
};

class Queue{
	private:
	static const int MAX=100;
	Node* arr[MAX];
	int front, rear;
	public:
	Queue(){
		front=-1;
		rear=-1;
	}
	bool isEmpty(){ 
		return (front == -1 || front > rear); 
	}
    bool isFull() { 
		return (rear == MAX - 1); 
	}
	void enqueue(Node* n){
		if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear]=n;
        cout << "Patient added: " << n->name<< " (ID: " << n->ID << ")" << endl;
	}
	Node* dequeue(){
		if(!isEmpty()){
			cout<<"Patient served: "<<arr[front]->name<<" (ID: " << arr[front]->ID << ")" << endl;
			return arr[front++];
		}
		else{
			cout<<"Queue is Empty!\n";
			return NULL;
		}
	} 
	void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Current queue:" << endl;
        for (int i = front; i <= rear; i++) {
            cout << "Patient ID: " << arr[i]->ID << ", Name: " << arr[i]->name << endl;
        }
    }
};
Node *insert(Node *root, int id, string n)
{
	if (root == NULL)
	{
		return new Node(id, n);
	}
	if (id < root->ID)
	{
		root->left = insert(root->left, id, n);
	}
	else if (id > root->ID)
	{
		root->right = insert(root->right, id, n);
	}
	else
	{
		cout<<"Patient already exists!\n";
	}
	return root;
}
void inorder_traversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder_traversal(root->left);
	cout << "Patient ID: " << root->ID << ", Patient name: " << root->name << endl;
	inorder_traversal(root->right);
}

int main()
{
	Node *root=NULL;
	root = insert(root, 50, "Ali Abbas");
	root = insert(root, 35, "Rania Khan");
    root = insert(root, 70, "Firaun Khan");
	root = insert(root, 20, "Shehbaz Sharif");
	root = insert(root, 40, "Yajuj Majuj");
	root = insert(root, 60, "Aaron Smith");
	root = insert(root, 80, "Diana Dead");
	
	Queue q;
	cout<<"Current queue:"<<endl;
	q.enqueue(root);
	q.enqueue(root->left);
	q.enqueue(root->right);
	q.enqueue(root->left->left);
	q.enqueue(root->left->right);
	cout<<endl;
	q.dequeue();
	q.dequeue();
	cout<<endl;
	cout<<"After dequeue, ";
	q.display();
	return 0;
}
