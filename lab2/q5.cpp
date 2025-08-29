#include <iostream>
#include <string>
using namespace std;

int main() {
    int row=5;
    int **arr= new int*[row];
    int numofcourse[5];
    string ID[5];

    for(int i=0; i<row; i++){
        cout<<"Enter Student ID: ";
        cin>>ID[i];
        cout<<"Enter number of Courses: ";
        cin>>numofcourse[i];
        arr[i]=new int[numofcourse[i]];
        cout<<"Enter Obtained marks for "<<numofcourse[i]<<" courses: ";
        for(int j=0;j<numofcourse[i]; j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\nStudent ID\tNum of Courses \t Obtained Marks\t\n";
    for(int i=0; i<row; i++){
        cout<<ID[i]<<"\t"<<numofcourse[i]<<"\t\t";
        for(int j=0; j<numofcourse[i]; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<row; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
}
