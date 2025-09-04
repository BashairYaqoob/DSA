#include <iostream>
using namespace std;

class Node{
    public:
    string photo;
    Node* next;
    Node(string p){
        photo=p;
        next=NULL;
    }
};

class PhotoGallery{
    public:
    Node* head;
    Node* tail;
    PhotoGallery(){
        head=NULL;
        tail=NULL;
    }
    void insertatTail(string p){
        Node* n=new Node(p); 
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
        cout<<"Photo added\n";
    }
    void insertatHead(string p){
        Node* n=new Node(p);
        n->next=head;
        head=n;
    }
    void insertatMiddle(int pos, string p){
        Node* n=new Node(p);
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
        cout<<"Photo removed\n";
    }
    void Recursiveprint(Node* n){
        if(n==NULL){
            return;
        }
        Recursiveprint(n->next);
        cout<<n->photo<<"\n";
    }
    void display(){
        cout<<"Latest Photos: "<<endl;
        Recursiveprint(head);
        cout<<endl;
    }

};
int main(){
    PhotoGallery s1;
    s1.insertatTail("Cat photo");
    s1.insertatTail("Eid photos");
    s1.insertatTail("Beach Party");
    s1.insertatTail("Bali photos");
    s1.display();
    return 0;
}
