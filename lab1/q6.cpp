#include <iostream>
using namespace std;

class Shop{
    private:
    string productname;
    int* quantity;
    int b;
    public:
    Shop(){
        quantity=nullptr;
    }
    Shop(int b, string n):productname(n), b(b){
        quantity= new int[b];
        for (int i = 0; i < b; i++) {
            quantity[i] = 0;
        }
    }
    Shop(const Shop& other){
        productname=other.productname;
        b=other.b;
        quantity= new int[b];
        for (int i = 0; i < b; i++){
            quantity[i]=other.quantity[i];
        }
    }
    Shop& operator=(const Shop& other){
        if(this!=&other){
        delete[] quantity;
        this->productname=other.productname;
        this->b=other.b;
        this->quantity=new int[b];
        for(int i=0; i<b; i++){
            quantity[i]=other.quantity[i];
        }
    }
        return *this;
    }
    void changeName(string n){
        productname=n;
    }
    void setQuantity(){
        cout<<"Enter "<<b<<" quantities: "<<endl;
        for(int i=0; i<b; i++){
            cin>>quantity[i];
        }
    }
    void display(){
        cout<<"Product name: "<<productname<<endl;
        cout<<"Quantities in each branch: ";
        for(int i=0; i<b;i++){
            cout<<quantity[i]<<" ";
        }
        cout<<endl;
    }
    ~Shop(){
        delete[] quantity;
    }
};

int main(){
    Shop s1(2, "Gannay ka Juice");
    s1.setQuantity();
    s1.display();
    Shop s2=s1;
    s2.changeName("Meetha Malta");
    s2.setQuantity();
    s1.display();
    s2.display();
    return 0;
}
