#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int rollnum){
        data=rollnum;
        next=NULL;
    }
};

class StudentCallSystem{
    public:
    Node* head;
    Node* tail;
    StudentCallSystem(){
        head=NULL;
        tail=NULL;
    }
    void insertatTail(int rollnum){
        Node* n=new Node(rollnum); 
        if(head==NULL){
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=n;
        n->next=tail;
        cout<<"Student added\n";
    }
    void insertatHead(int rollnum){
        Node* n=new Node(rollnum);
        n->next=head;
        head=n;
    }
    void insertatMiddle(int pos, int rollnum){
        Node* n=new Node(rollnum);
        Node* curr;
        Node* prev;
        curr=head;
        for(int i=0; i<pos; i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=n;
        n->next=curr;
    }
    void deleteatEnd(){
        Node* temp=head;
        Node* prev;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        tail=prev;
        tail->next=NULL;
        delete temp;
        cout<<"Student removed\n";
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};
int main(){
    StudentCallSystem s1;
    s1.insertatTail(10);
    s1.insertatTail(13);
    s1.insertatTail(15);
    s1.insertatTail(18);
    s1.deleteatEnd();
    s1.display();
    return 0;
}
