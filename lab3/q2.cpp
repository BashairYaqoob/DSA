#include <iostream>
#include <cstring>
using namespace std;

class Node{
	public:
		string song;
		Node * next;
		
		Node(string s){
			song=s;
			next=NULL;
		}
};

class Singly{
	public:
		Node * head;
		Node * tail;
		Singly(){
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
			temp->next=n;
			n->next=tail;
			cout<<"Song added at end of playlist!"<<endl;
		}
		void deleteAtFront(){
			Node* temp=head;
			head=head->next;
			delete temp;
			cout<<"Song deleted from the front of playlist!"<<endl;
		}
		bool SearchbyName(string s){
		Node * temp=head;
		while(temp!=NULL){
			if(temp->song==s){
				cout<<"Song Found\n Title:"<<temp->song<<endl;
				return true;
			}
			temp=temp->next;
		}
		cout<<"\nSong not found!"<<endl;
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
            cout<<"Song Found\n Title:"<<temp->song<<endl;
        } else {
            cout<<"\nSong not found!"<<endl;
        }
		}
    
};

int main(){
	Singly s1;
	s1.insertatTail("Skies");
	s1.insertatTail("Champions");
	s1.insertatTail("Let it go");
	s1.deleteAtFront();
	s1.SearchbyName("Sapphire");
	s1.SearchbyPos(1);
	return 0;
}
