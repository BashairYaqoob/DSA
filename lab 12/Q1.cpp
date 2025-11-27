#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 20;
const int ChainSIZE = 20;

class Library {
private:
    string shelves[SIZE][ChainSIZE]; 
    int chainCount[SIZE];

public:
    Library() {
        for (int i = 0; i < SIZE; i++){
            chainCount[i] = 0;
        }
    }

    int hashFunction(const string& name) {
        int first = name[0] - 'A';
        int second = name[1] - 'A';
        return (first * 26 + second) % SIZE;
    }

    void addBook(const string& name) {
        int index = hashFunction(name);

        if (chainCount[index] >= ChainSIZE) {
            cout << "Shelf " << index << " is full!\n";
            return;
        }

        shelves[index][chainCount[index]] = name;
        chainCount[index]++;

        cout<<"Added "<<name<<" to shelf "<<index<< " (position " << chainCount[index] - 1 << ")\n";
    }

    void searchBook(const string& name) {
        int index = hashFunction(name);

        for (int i = 0; i < chainCount[index]; i++) {
            if (shelves[index][i] == name) {
                cout << "Book " << name << " found at shelf " << index<< ", position " << i << "\n";
                return;
            }
        }
        cout << "Book " << name << " NOT found.\n";
    }

    void displayShelves() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Shelf " << i << ": ";
            if (chainCount[i] == 0) {
                cout << "EMPTY";
            } else {
                for (int j = 0; j < chainCount[i]; j++) {
                    cout << shelves[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
};

int main() {
    Library l;

    l.addBook("AB");
    l.addBook("CD");
    l.addBook("EF");
    l.addBook("AB");

    l.searchBook("AB");
    l.searchBook("XY");

    l.displayShelves();

    return 0;
}
