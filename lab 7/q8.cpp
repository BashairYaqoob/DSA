//Q8: How would you convert the infix expression a+b*(c^d-e)^(f+g*h)-i 
//to postfix notation.
//Analyze (A+B/C*(D+C)-F)
#include <iostream>
#include <string>
using namespace std;

const int MAX=100;

class Stack {
	int top;
	char a[MAX];
public:
	
	Stack(){
		top=-1;
	}
	bool push(char x);
	char pop();
	char peek();
	bool isEmpty();
};
bool Stack :: push(char x){
	if(top>= (MAX-1)){
		cout<<"Stack Overflow";
		return false;
	}
	else{
		a[++top]=x;
		return true;
	}
}
char Stack::pop(){
	if(top<0){
		cout<<"Stack Underflow";
		return '\0';
	}
	else{
		return a[top--];
	}
}
char Stack::peek(){
	if(top<0){
		cout<<"Stack is Empty";
		return '\0';
	}
	else{
		return a[top];
	}
}
bool Stack :: isEmpty(){
	return (top<0);
}

int precedence(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

string infixtopostfix(string infix){
	string postfix="";
	Stack s;
	for(int i=0; i<infix.length(); i++){
		char c=infix[i];
		if((c>='a' && c<='z') || (c>='A' && c<='Z')){
			postfix+=c;
		}
		else if(c=='('){
			s.push(c);
		}
		else if(c==')'){
			while(!s.isEmpty() && s.peek() != '('){
				char op=s.pop();
				postfix+=op;
			}
			s.pop();
		}
		else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix += s.pop();
            }
            s.push(c);
        }
	}
	while(!s.isEmpty()){
		char op=s.pop();
		postfix+=op;
	}
	return postfix;
}

int main(){
	string infix = "A+B/C*(D+C)-F";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixtopostfix(infix) << endl;
	return 0;
}
