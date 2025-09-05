#include <iostream>
using namespace std;

class Node
{
public:
    int taskID;
    Node *next;
    Node(int id)
    {
        taskID = id;
        next = NULL;
    }
};
class TaskSchedule
{
private:
    Node *head;
    Node *tail;
    void insertatHead(int id)
    {
        Node *n = new Node(id);
        n->next = head;
        head = n;
    }
    void insertatEnd(int id) {
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
    void insertatMiddle(Node *prev, int id){
        Node* n=new Node(id);
        n->next=prev->next;
        prev->next=n;
    }

public:
    TaskSchedule()
    {
        head = NULL;
        tail = NULL;
    }
    Node* getHead() {
        return head;
    }
    void insert(int id){
        if(head==NULL || id<head->taskID){
            insertatHead(id);
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL && temp->next->taskID<id){
            temp=temp->next;
        }
        if(temp->next==NULL){
            insertatEnd(id);
        }
        else{
            insertatMiddle(temp,id);
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->taskID<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    Node* mergeList(Node* l1, Node* l2){
        Node dummy(0);
        Node* curr=&dummy;

        while(l1!=NULL && l2!=NULL){
            if(l1->taskID<=l2->taskID){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=NULL){
            curr->next=l1;
        }
        if(l2!=NULL){
            curr->next=l2;
        }
        return dummy.next;
    }
    void mergedisplay(Node* n) {
        while (n != NULL) {
            cout << n->taskID << " ";
            n=n->next;
        }
        cout << endl;
    }
};

int main() {
    TaskSchedule l1;
    TaskSchedule l2;

    l1.insert(1);
    l1.insert(5);
    l1.insert(3);
    l1.insert(8);

    l2.insert(6);
    l2.insert(3);
    l2.insert(4);
    l2.insert(7);

    cout << "Sorted TaskIDs List 1: ";
    l1.display();

    cout << "Sorted TaskIDs List 2: ";
    l2.display();

    TaskSchedule l3;
    Node* m1 = l3.mergeList(l1.getHead(),l2.getHead());

    cout << "Merged list of TaskIDs: ";
    l3.mergedisplay(m1);

    return 0;
}
