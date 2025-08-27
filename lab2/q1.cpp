#include <iostream>
using namespace std;

class StudentFeeManager{
    private:
    int *fee;
    int size;
    public:
    StudentFeeManager(int n, int initialfee){
        size=n;
        fee= new int[size];
        for(int i=0; i<size;i++){
            fee[i]=initialfee;
        }
    }

    StudentFeeManager(const StudentFeeManager& other){
        size=other.size;
        fee=new int[size];
        for(int i=0; i<size; i++){
            fee[i]=other.fee[i];
        }
    }

    StudentFeeManager& operator=(const StudentFeeManager& other){
        if(this!=&other){
            delete[] fee;
            size=other.size; fee= new int[size];
            for(int i=0; i<size; i++){
                fee[i]=other.fee[i];
            }
        }
        return *this;
    }

    void setFee(int i, int newfee){
        if(i>=0 && i<size){
            fee[i]=newfee;
        }
        else{
            cout<<"Boundary error\n";
        }
    }

    int getFee(int i){
        if(i>=0 && i<size){
            return fee[i];
        }
        else{
            cout<<"Boundary Error\n";
            return -1;
        }
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<"Student "<<i+1<<" fee:"<<fee[i]<<endl;
        }
        cout<<endl;
    }


    ~StudentFeeManager(){
        delete[] fee;
    }
};

int main(){
    StudentFeeManager s1(2, 500);
    s1.display();
    StudentFeeManager s2=s1;
    s1.setFee(1, 700);
    s1.display();
    return 0;
}
