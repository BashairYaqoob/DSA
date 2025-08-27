#include <iostream>
#include <string>
using namespace std;

class Librarian{
	private:
		string name;
		int ID, YOE;
	public:
		Librarian(){}
		Librarian(string n, int id, int yoe): name(n), ID(id), YOE(yoe){}
		void display(){
			cout<<"Name: "<<name<<"\nID: "<<ID<<"\nYears of experience: "<<YOE<<endl;
		}
};

int main(){
	string Name;
	int id, yoe;
	cout<<"Enter Librarian name: ";
	getline(cin, Name);
	cout<<"Enter Librarian ID: ";
	cin>>id;
	cout<<"Enter Librarian Years of Experience: ";
	cin>>yoe;
	Librarian l1(Name, id, yoe);
	l1.display();
	const int bookcnt=5;
	int BookIDs[bookcnt]={101, 55, 21,05, 26};
	cout << "\nAvailable Books in Library:\n";
    for (int i = 0; i < bookcnt; i++) {
        cout << "Book ID: " << BookIDs[i] << endl;
    }
    int newcnt;
    cout << "\nNew book Count: ";
    cin >> newcnt;

    int* newBookIDs = new int[newcnt];

    cout << "\nEnter the new Book IDs:\n";
    for (int i = 0; i < newcnt; i++) {
        cout << "Enter Book ID #" << i + 1 << ": ";
        cin >> newBookIDs[i];
    }

    cout << "\nThe new books you have added are:\n";
    for (int i = 0; i < newcnt; i++) {
        cout << "Book ID: " << newBookIDs[i] << endl;
    }

    delete[] newBookIDs;

    return 0;
}
