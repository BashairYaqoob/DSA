#include <iostream>
using namespace std;

class Node{
    public:
    int seatNo;
    bool reserved;
    Node* next;
    Node(int no){
        seatNo=no;
        reserved=false;
        next=NULL;
    }
};
class RideManagement{
    public:
    Node* head;
    Node* tail;
    RideManagement(){
        head=NULL;
        tail=NULL;
    }
    void insertatEnd(int s){
        Node* n=new Node(s);
        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        else{
        tail->next=n;
        tail=tail->next;
        tail->next=head;
        }
    }
    void insertatFront(int s){
        Node* n=new Node(s);
        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        else{
            n->next=head;
            head=n;
            tail->next=head;
        }
    }
    void reserveSeat(int s){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        do
        {
            if(temp->seatNo==s){
                if(!temp->reserved){
                    temp->reserved=true;
                    cout<<"Seat "<<s<<" reserved successfully.\n";
                }
                else{
                    cout<<"Seat "<<s<<" is already reserved.\n";
                }
                return;
            }
            temp=temp->next;
        } while (temp!=head);
        cout << "Invalid seat number!\n";   
    }
    void displaySeats(){
        if(head==NULL){
            cout<<"No seats availaible\n";
            return;
        }
        Node* temp=head;
        cout<<"Ride seats status:\n";
        do
        {
            cout<<"Seat: "<<temp->seatNo<<" "<<(temp->reserved? "[Reserved]":"[Available]")<<endl;
            temp=temp->next;
        } while (temp!=head);
        
    }
};
int main(){
    RideManagement r1;
    r1.insertatFront(12);
    r1.insertatEnd(15);
    r1.insertatEnd(20);
    r1.insertatEnd(25);
    r1.insertatEnd(27);
    r1.reserveSeat(15);
    r1.reserveSeat(14);
    r1.reserveSeat(27);
    r1.displaySeats();
    return 0;
}
