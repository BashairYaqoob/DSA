#include <iostream>
using namespace std;

class Node{
    public:
    int productID;
    Node* next;
    Node(int id){
        productID=id;
        next=NULL;
    }
};
class InventoryManagementSystem{
    private:
    Node* head;
    Node* tail;
    void insertatHead(int id){
        Node* n=new Node(id);
        n->next=head;
        head=n;
    }
    void insertatTail(int id){
        Node* n=new Node(id);
        if(head==NULL){
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->next=tail;
    }
    void insertatMiddle(Node* prev, int id){
        Node* n=new Node(id);
        n->next=prev->next;
        prev->next=n;
    }

    public:
    InventoryManagementSystem(){
        head=NULL;
        tail=NULL;
    }
    void insert(int id){
        if(head==NULL || id<head->productID){
            insertatHead(id);
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL && temp->next->productID<id){
            temp=temp->next;
        }
        if(temp->next==NULL){
            insertatTail(id);
        }
        else{
            insertatMiddle(temp, id);
        }
    }
    void display(){
        cout<<"Product IDs: ";
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->productID<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    InventoryManagementSystem i1;
    i1.insert(505);
    i1.insert(243);
    i1.insert(608);
    i1.insert(704);
    i1.insert(391);
    i1.display();
    return 0;
}
