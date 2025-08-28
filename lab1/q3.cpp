#include <iostream>
using namespace std;

class Box{
    private:
    int* integer; 
    public:
    Box(int data=0){
        integer = new int(data);
    }
    Box(const Box& other){
        integer=new int(*other.integer);
    }
    Box& operator=(const Box& other){
        if(this!=&other){
            delete integer;
            integer= new int(*other.integer);
        }
        return *this;
    }
    void updateInteger(int data){
        *integer=data;
    }
    int getInteger()const{
        return *integer;
    }
    void display(){
        cout<<"Integer value: "<<*integer<<endl;

    } 
    ~Box(){
        delete integer;
    }
};

int main(){
    Box b1(10);
    b1.display();
    Box b2=b1;
    b2.display();
    b2.updateInteger(20);
    b1.display();
    b2.display();
    //As rule of three is being applied, deep copy is occuring. 
    //If that wouldn't be the case, Shallow copy would have occured
    return 0;
}
