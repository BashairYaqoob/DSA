#include <iostream>
using namespace std;

class ProductStocklManager{
    private:
    int* stock;
    int size;
    public:
    ProductStocklManager(int n, int v):size(n) {
        stock=new int[size];
        for(int i=0; i<size; i++){
            stock[i]=v;
        }
    }
    ProductStocklManager(const ProductStocklManager& other){
        size=other.size;
        stock=new int[size];
        for(int i=0; i<size; i++){
            stock[i]=other.stock[i];
        }
    }
    ProductStocklManager& operator=(const ProductStocklManager& other){
        if(this!=&other){
            delete[] stock;
            size=other.size;
            stock=new int[size];
            for(int i=0;i<size;i++){
                stock[i]=other.stock[i];
            }
            return *this;
        }
    }
    ~ProductStocklManager(){
        delete[] stock;
    }
    void setStock(int index, int newstock) const{
        if(index>=0 && index<size){
            stock[index]=newstock;
        }
        else{
            cout<<"Boundary error!"<<endl;
        }
    }
    int getStock(int index){
        if(index>=0 && index<size){
            return stock[index];
        }
        else{
            cout<<"Boundary error!"<<endl;
            return -1;
        }
    }
    void display(){
        cout<<"Product stock levels: ";
        for(int i=0; i<size; i++){
            cout<<stock[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    ProductStocklManager p1(3, 10);
    ProductStocklManager p2=p1;
    p1.display();
    p2.display();
    p1.setStock(2, 20);
    p1.setStock(0,13);
    p1.display();
    p2.display();
    
    p1.setStock(4, 11);
    return 0;
}
