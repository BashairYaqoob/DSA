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

class Stack{
    private:
    static const int MAX=100;
    Node* arr[MAX];
    int top;
    public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){ 
        return (top == -1); 
    }
    bool isFull() { 
        return (top == MAX - 1); 
    }
    void push(Node* n){
        if(!isFull()){
            arr[++top]=n;
        }
    }
    Node* pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        else{
            return NULL;
        }
    }
    Node* peek(){
        if(!isEmpty()){
            return arr[top];
        }
        else{
            return NULL;
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
        cout<<"Customer already exists!\n";
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
    cout << "Customer ID: " << root->ID << ", Customer name: " << root->name << endl;
    inorder_traversal(root->right);
}
void preorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "Customer ID: " << root->ID << ", Customer name: " << root->name << endl;
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
    cout << "Customer ID: " << root->ID << ", Customer name: " << root->name << endl;
}

int main()
{
    Node *root=NULL;
    root=insert(root, 50, "Ali Abbas");
    root = insert(root, 35, "Rania Khan");
    root = insert(root, 70, "Firaun Khan");
    root = insert(root, 20, "Shehbaz not so Sharif");
    root = insert(root, 40, "Yajuj Majuj");
    root = insert(root, 60, "Aaron Smith");
    root = insert(root, 80, "Diana Dead");
    
    cout<<"Result of preorder traversal: "<<endl;
    preorder_traversal(root);
    cout<<"\nResult of inorder traversal: "<<endl;
    inorder_traversal(root);
    cout<<"\nResult of postorder traversal: "<<endl;
    postorder_traversal(root);
    return 0;
}
/*
        50
       /  \
     35    70
    /  \   /  \
  20   40 60  80
*/
