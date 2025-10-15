#include <iostream>
#include <string>
using namespace std;

const int MAX=10;

class Stack {
	int top;
public:
	string a[MAX];
	Stack(){
		top=-1;
	}
	bool push(string x);
	string pop();
	string peek();
	bool isEmpty();
};
bool Stack :: push(string x){
	if(top>= (MAX-1)){
		cout<<"Stack Overflow";
		return false;
	}
	else{
		a[++top]=x;
		cout<<x<<" pushed into the stack\n";
		return true;
	}
}
string Stack::pop(){
	if(top<0){
		cout<<"Stack Underflow";
		return "";
	}
	else{
		return a[top--];
	}
}
string Stack::peek(){
	if(top<0){
		cout<<"Stack is Empty";
		return "";
	}
	else{
		return a[top];
	}
}
bool Stack :: isEmpty(){
	return (top<0);
}

int main() {
    Stack s1;
    s1.push("Finish report");
    s1.push("Email client");
    s1.push("Prepare food");
    if(s1.isEmpty()){
    	cout << "To-do list is empty.\n";
	}
	else {
        cout << "To-do list is not empty.\n";
    }
    cout << "Top item: " << s1.peek() << endl;
    string removed = s1.pop();
    cout << "Removed from stack: " << removed << endl;
    cout << "Now top item: " << s1.peek() << "\n";
    return 0;
}
