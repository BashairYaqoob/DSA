#include <iostream>
using namespace std;

const int SIZE = 15;



class HashTable
{
private:
    int rollnum[SIZE];
    string name[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            rollnum[i]=-1;
            name[i]="";
        }
    }
    int hashFunction(int key)
    {
        return key%SIZE;
    }
    void InsertRecord(int rollnumber, string sname)
    {
        int index = hashFunction(rollnumber);
        for(int attempt=0; attempt<SIZE; attempt++){
            int newindex=(index+attempt*attempt)%SIZE;
            if(rollnum[newindex]==-1){
                rollnum[newindex]=rollnumber;
                name[newindex]=sname;
                cout<<"Record inserted at index "<<newindex<<endl;
                return;
            }
        }
        cout<<"Hash Table is full. ReHash now!\n";
    }
    void SearchRecord(int rollnumber){
        int index=hashFunction(rollnumber);
        for(int attempt=0; attempt<SIZE; attempt++){
            int newindex=(index+attempt*attempt)%SIZE;
            if(rollnum[newindex]==rollnumber){
                cout << "Record found: " << name[newindex] << endl;
                return;
            }
            if (rollnum[newindex] == -1) {
                cout << "Record not found\n";
                return;
            }
        }
        cout << "Record not found\n";
        return;
    }
};
int main()
{
    HashTable h;

    h.InsertRecord(101, "Ali");
    h.InsertRecord(116, "Bashair");
    h.InsertRecord(146, "Hamza");
    h.InsertRecord(131, "Ayesh");

    h.SearchRecord(116);
    h.SearchRecord(150);

    return 0;
}
