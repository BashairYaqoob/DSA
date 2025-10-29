#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
        Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
Node* insert(Node* node, int key){
    if(node==NULL){
        return new Node(key);
    }
    if(key<node->data){
        node->left=insert(node->left, key);
    }
    else if(key>node->data){
        node->right=insert(node->right, key);
    }
    else{
        return node;
    }
    node->height= 1+ max(height(node->left), height(node->right));
    int balance=getBalance(node);
    if(balance >1 && key<node->left->data){
        return rightRotate(node);
    }
    if(balance >-1 && key<node->right->data){
        return leftRotate(node);
    }
    if(balance >1 && key>node->left->data){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance >-1 && key<node->right->data){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preorder(Node* root) {
    if (root) {
        cout << char( root->data ) << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 'A');
    root = insert(root, 'C');
    root = insert(root, 'B');
    preorder(root);
    cout<<endl;
    return 0;
}
