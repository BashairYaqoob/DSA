#include <iostream>
#include <list>
using namespace std;

const int SIZE=10;

class HashTable{
    private:
    list<int>* table;
    public:
    HashTable(){
    table=new list<int>[SIZE];
    }
    int hashFunction(int key){
        return key%SIZE;
    }
    void insert(int key){
        int index=hashFunction(key);
        table[index].push_back(key);
        cout<<key<<" inserted.\n";
    }
    void remove(int key){
        int index=hashFunction(key);
        bool found=false;
        for(int value:table[index]){
            if(value==key){
                found=true;
                break;
            }
        }
        if(found){
            table[index].remove(key);
            cout<<key<<" deleted\n";
        }
        else{
            cout<<key<<" not found\n";
        }
    }
    bool search(int key){
        int index=hashFunction(key);
        for(int value:table[index]){
            if(value==key){
                cout<<key<<" found\n";
                return true;
            }
        }
        cout<<key<<" not found\n";
        return false;
    }
    void display(){
        for (int i = 0; i < SIZE; i++)
        {
            cout<<"Index "<<i<<": ";
            for(int value:table[i]){
                cout<<value<<" -> ";
            }
            cout<<"NULL"<<endl;
        }
    }
    ~HashTable(){
        delete[] table;
    }
};

int main(){
    HashTable h;

    h.insert(12);
    h.insert(22);
    h.insert(13);

    h.display();

    h.search(14);
    h.remove(13);
    h.display();

    return 0;
}
