#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int bookID;
	string name;
	Node *left;
	Node *right;
	Node(int id, string n)
	{
		bookID = id;
		name = n;
		left = NULL;
		right = NULL;
	}
};

Node *insert(Node *root, int id, string n)
{
	if (root == NULL)
	{
		return new Node(id, n);
	}
	if (id < root->bookID)
	{
		root->left = insert(root->left, id, n);
	}
	else if (id > root->bookID)
	{
		root->right = insert(root->right, id, n);
	}
	else
	{
		cout<<"Book is already inserted!\n";
	}
	return root;
}
Node *search(Node *root, int id)
{
	if (root == NULL || root->bookID == id)
	{
		return root;
	}
	if (id < root->bookID)
	{
		return search(root->left, id);
	}
	else
	{
		return search(root->right, id);
	}
}
void inorder_traversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder_traversal(root->left);
	cout << "Book ID: " << root->bookID << ", Book name: " << root->name << endl;
	inorder_traversal(root->right);
}
void preorder_traversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << "Book ID: " << root->bookID << ", Book name: " << root->name << endl;
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}
void postorder_traversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout << "Book ID: " << root->bookID << ", Book name: " << root->name << endl;
}

int main()
{
	Node *root=NULL;
	root=insert(root, 1001, "Harry potter");
	root = insert(root, 2002, "Railway Children");
    root = insert(root, 3003, "Kite Runner");
	root = insert(root, 2000, "Malory Towers");
	root = insert(root, 5000, "Diary of a Wimpy Kid");
	root = insert(root, 4040, "Maze Runner");
	cout<<"Result of preorder traversal: "<<endl;
	preorder_traversal(root);
	cout<<"Result of inorder traversal: "<<endl;
	inorder_traversal(root);
	cout<<"Result of postorder traversal: "<<endl;
	postorder_traversal(root);
	return 0;
}
/*
  1001
     \
     2002
     /   \
  2000  3003
           \
           4040
              \
              5000

*/
