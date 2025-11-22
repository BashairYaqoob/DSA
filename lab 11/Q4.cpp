#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable
{
private:
    int table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }
    int hashFunction(int key)
    {
        return key%SIZE;
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        for(int i=0; i<SIZE; i++){
            int newindex=(index+i)%SIZE;
            if(table[newindex]==-1){
                table[newindex]=key;
                cout<<key<<" Inserted\n";
                return;
            }
        }
        cout<<"Hash Table is full. ReHash now!\n";
    }
    void remove(int key){
        int index=hashFunction(key);
        for(int i=0; i<SIZE; i++){
            int newindex=(index+i)%SIZE;
            if(table[newindex]==key){
                table[newindex]=-1;
                cout<<key<<" removed\n";
                return;
            }
        }
        cout<<key<<" not found\n";
    }
    bool search(int key){
        int index=hashFunction(key);
        for(int i=0; i<SIZE; i++){
            int newindex=(index+i)%SIZE;
            if(table[newindex]==key){
                cout<<key<<" found\n";
                return true;
            }
        }
        cout<<key<<" not found\n";
        return false;
    }
    void display()
    {
        cout<<"HashTable\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout <<"Index "<< i << ": ";
            if(table[i]==-1){
                cout<<"EMPTY";
            }
            else{
                cout<<table[i];
            }
            cout << endl;
        }
    }
};
int main()
{
    HashTable h;

    h.insert(12);
    h.insert(22);
    h.insert(32);
    h.insert(5);

    h.display();

    h.search(22);
    h.remove(22);

    h.display();

    return 0;
}
