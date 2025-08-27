#include <iostream>
using namespace std;

class Document{
    private:
    string content;
    public:
    Document(){
        content="";
    }
    Document(const string& content): content(content){
	}
    ~Document(){}
    Document(const Document &other){
        this->content=other.content;
    }
    Document& operator=(const Document& other){
        if(this!=&other){
            content=other.content;
        }
        else{
            return *this;
        }
    }
    void setContent(const string &c){
    	content=c;
	}

    void display(){
        cout<<content<<endl;
    }
};
int main(){
    Document d1("Hello World");
    Document d2=d1;
    d1.display();
    d2.display();
    d2.setContent("Hi from DSA Lab7");
    d1.display();
    d2.display();
    return 0;
}
