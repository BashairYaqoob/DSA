#include <iostream>
using namespace std;

class Node{
	public:
		int data1;
		int data2;
		Node * next;
		
		Node(int v1, int v2){
			data1=v1; data2=v2;
			next=NULL;
		}
};

class Circular{
	public:
		Node * head;
		Node * tail;
		Circular() {
        head = NULL;
        tail = NULL;
    }
		void insertAtEnd(int v1, int v2){
			Node * n= new Node(v1, v2);
			if(head==NULL){
				head=n;
				tail=n;
				tail->next=head;
				return;
			}
			tail->next=n;
			tail=tail->next;
			tail->next=head;
		}
		
		void Display(){
			if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
			Node * temp=head;
			int i=1;
			do {
            cout << "Node " << i << ":\n Coin 1: " << temp->data1 << " Coin 2: " << temp->data2 << endl;
            temp = temp->next;
            i++;
        } while (temp != head);
		}
		
		void findvillage(int target){
			if (head == NULL) {
            cout << "List is empty\n";
            return;
        	}
			Node* temp=head;
		do {
            int sum = temp->data1 + temp->data2;
            if (sum != target) {
                cout << "Skipping this village (" << temp->data1 << ", " << temp->data2 << ")\n";
            } else {
                cout << "Desired Village found! (" << temp->data1 << " , " << temp->data2 << ")\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "No village found with the sum " << target << endl;
		}
		
    
};

int main() {
Circular villages;

villages.insertAtEnd(2, 2);
villages.insertAtEnd(3, 1);
villages.insertAtEnd(3, 1);
villages.insertAtEnd(3, 2);
villages.Display();
int target = 5;
cout<<endl;
villages.findvillage(target);
return 0;
}
