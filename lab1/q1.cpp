#include <iostream>
using namespace std;

class BankAccount{
    private:
    float balance;
    public:
    BankAccount(){
        balance=500;
    }
    BankAccount(float balance): balance(balance){}
    void withdraw(float amount){
        balance-=amount;
    }
    BankAccount(const BankAccount& other){
        this->balance=other.balance;
    }
    BankAccount& operator=(const BankAccount& other){
        if(this!=&other){
            balance=other.balance;
        }
        return *this;
    }
    void deposit(float amount){
        balance+=amount;
    }
    void display(){
        cout<<"Balance: Rs. "<<balance<<endl;
    }
    ~BankAccount(){}
};

int main(){
    BankAccount account1;
    account1.display();
    BankAccount account2(1000);
    account2.display();
    BankAccount account3=account2;
    account3.withdraw(200);
    account3.display();
    account2.display();
    return 0;
}
 
