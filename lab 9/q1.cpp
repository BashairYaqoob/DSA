#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
	int key;
	Node *left;
	Node *right;
	int height;
	Node(int val)
	{
		key = val;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

int height(Node *n)
{
	return n ? n->height : 0;
}

int getBalance(Node *n)
{
	int b = height(n->left) - height(n->right);
	return b;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}
Node *insert(Node *node, int key)
{
	if (node == NULL)
	{
		return new Node(key);
	}
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	else
	{
		return node;
	}
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

Node *minValueNode(Node *node)
{
	Node *current = node;
	while (current->left)
	{
		current = current->left;
	}
	return current;
}

Node *deleteNode(Node *root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	if (key < root->key)
	{
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			Node *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
				delete temp;
			}
		}
		else
		{
			Node *temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
	{
		return root;
	}
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
	{
		return rightRotate(root);
	}
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
	{
		return leftRotate(root);
	}
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

bool search(Node *root, int key)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->key == key)
	{
		return true;
	}
	else if (root->key > key)
	{
		return search(root->left, key);
	}
	else
	{
		return search(root->right, key);
	}
}

void preorder(Node *root)
{
	if (root)
	{
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	Node *root = NULL;
	int arr[] = {10, 20, 30, 40, 50};
	for (int i = 0; i < 5; i++)
	{
		root = insert(root, arr[i]);
	}
	root = insert(root, 15);
	preorder(root);
	cout << "\nHeight: " << height(root) << endl;
	bool found = search(root, 25);
	cout << (found ? "Found\n" : "Not Found\n");
	root = deleteNode(root, 20);
	preorder(root);
	cout << endl;
	return 0;
}
