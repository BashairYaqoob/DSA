#include <iostream>
#include <cstring>
using namespace std;

class Node{
	public:
		string name;
		Node * next;
		
		Node(string s){
			name=s;
			next=NULL;
		}
};

class CustomerQueue{
	public:
		Node * head;
		Node * tail;
		CustomerQueue(){
			head=NULL;
			tail=NULL;
		}
		void insertatTail(string s){
			Node * n= new Node(s);
			if(head==NULL){
				head=n;
				return;
			}
			Node * temp=head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			 
			cout<<temp->name<<" was added to the queue"<<endl;
			 temp->next=n;
			 n->next=tail;
		}
		
		void deleteAtFront(){
			Node* temp=head;
			cout<<temp->name<<" is served amd removed!"<<endl;
			head=head->next;
			delete temp;
		}
		
		void deleteAtEnd(){
			Node* temp=head;
			Node* pre;
			while(temp->next!=NULL){
				pre=temp;
				temp=temp->next;
			}
			cout<<temp->name<<" has left the queue from the end!"<<endl;
			tail=pre;
			tail->next=NULL;
			
			
		}
		void deleteAfter(int pos){
			Node* pre;
			Node* curr;
			curr=head;
			for(int i=0; i<pos; i++){
				pre=curr;
				curr=curr->next;
			}
			cout<<pre->name<<" has left the queue from the middle!"<<endl;
			pre->next=curr->next;
			delete curr;
			
		}
		
		 
		bool SearchbyName(string s){
		Node * temp=head;
		while(temp!=NULL){
			if(temp->name==s){
				cout<<temp->name<<" found in queue!"<<endl;
				return true;
			}
			temp=temp->next;
		}
		cout<<"\nNot found!"<<endl;
		return false;
		}
		
		void SearchbyPos(int pos){
			if (pos <= 0) {
            cout << "Invalid position entered.\n";
            return;
        	}
		Node * temp=head;
		int currentpos=1;
		
		while(temp!=NULL && currentpos<pos){
			temp=temp->next;
			currentpos++;
		}
		if (temp != NULL) {
            cout<<temp->name<<" found in queue!"<<endl;
        } else {
            cout<<"\nNot found!"<<endl;
        }
		}
    
};

int main(){
	CustomerQueue s1;
	s1.insertatTail("Alice");
	s1.insertatTail("Bob");
	s1.insertatTail("Charlie");
	s1.insertatTail("David");
	s1.deleteAtFront();
	s1.deleteAtEnd();
	s1.deleteAfter(1);
	return 0;
}
