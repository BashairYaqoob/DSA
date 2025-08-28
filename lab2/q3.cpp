#include <iostream>
using namespace std;

class FruitShopInventory{
    public:
    int numofruit;
    int col;
    int** arr;
    
    FruitShopInventory(int r, int initialquantity, int initialprice){
        numofruit=r; col=2;
        arr= new int*[numofruit];
        for(int i=0; i<numofruit; i++){
            arr[i]= new int[col];
            arr[i][0]= initialquantity;
            arr[i][1]= initialprice;
        }
    }
    FruitShopInventory(const FruitShopInventory& other){
        numofruit=other.numofruit;
        col=other.col;
        arr= new int*[numofruit];
        for(int i=0; i<numofruit; i++){
            arr[i]= new int[col];
            for(int j=0; j<col; j++){
                arr[i][j]=other.arr[i][j];
            }
        }
    }
    FruitShopInventory& operator=(const FruitShopInventory& other){
        if(this!=&other){
            for(int i=0; i<numofruit; i++){
                delete[] arr[i];
            }
            delete[] arr;
            numofruit= other.numofruit;
            col=other.col;
            arr=new int*[numofruit];
            for(int i=0; i<numofruit; i++){
            arr[i]= new int[col];
            for(int j=0; j<col; j++){
                arr[i][j]=other.arr[i][j];
            }
        }
        }
        return *this;
    }
    ~FruitShopInventory(){
        for(int i=0; i<numofruit; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }

    void updateFruit(int index, int q, int p){
        if(index>=0 && index<numofruit){
            arr[index][0]=q;
            arr[index][1]=p;
        }
        else{
            cout<<"Boundary error\n";
        }
    }
    void display()const{
        cout<<"Fruit Inventory (Quantity | Price): \n";
        for(int i=0; i<numofruit; i++){
            cout<<arr[i][0]<<" | "<<arr[i][1]<<endl;
        }
    }
};

int main(){
    FruitShopInventory s1(3, 5, 500);
    FruitShopInventory s2=s1;
    s1.display();
    s1.updateFruit(1,7,200);
    s1.display();
    s2.display();
    return 0;
}
