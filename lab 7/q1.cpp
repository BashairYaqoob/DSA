#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

void addNode(Node*& head, string name, int score) {
    Node* n = new Node(name, score);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next){
        temp = temp->next;
	}
    temp->next = n;
}

int getMax(Node* head){
	int max=head->score;
	for(Node* temp=head; temp!=NULL; temp=temp->next){
		if(temp->score>max){
			max=temp->score;
		}
	}
	return max;
}

void countingSort(Node*& head, int exp) {
    Node* buckets[10] = {nullptr};
	Node* bucketTails[10] = {nullptr};

	for (Node* temp = head; temp != nullptr; temp = temp->next) {
        int digit = (temp->score / exp) % 10;
        Node* newNode = new Node(temp->name, temp->score);

        if (!buckets[digit]) {
            buckets[digit] = newNode;
            bucketTails[digit] = newNode;
        } else {
            bucketTails[digit]->next = newNode;
            bucketTails[digit] = newNode;
        }
    }
	Node* n = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < 10; i++) {
        if (buckets[i]) {
            if (!n) {
                n = buckets[i];
                tail = bucketTails[i];
            } else {
                tail->next = buckets[i];
                tail = bucketTails[i];
            }
        }
    }
    head = n;
}
void radixSort(Node*& head) {
    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(head, exp);
    }
}
void display(Node* head) {
    cout << "Sorted list of student Records:\n";
    while (head != nullptr) {
        cout << head->name << " - " << head->score << endl;
        head = head->next;
    }
}

int main() {
	Node* head=NULL;
	addNode(head, "Ayan", 90);
    addNode(head, "Ali", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Zara", 50);
    addNode(head, "Jeena", 40);
	radixSort(head);
	display(head);
    return 0;
}
