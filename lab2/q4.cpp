#include <iostream>
using namespace std;

int main(){
	int dep=4;
	string deparment[4]={"SE", "AI", "CS", "DS"};
	int **arr= new int*[dep];
	int size[4];
	
	for(int i=0; i<dep; i++){
		cout<<"Enter the number of coure courses for "<<department[i]<<": ";
		cin<<size[i];
		arr[i]= new int[size[i]];
	}
	for(int i=0; i<dep;i++){
		for(int j=0; j<size[i]; j++){
			cout<<"Enter GPA for course "<< j+1<<" in "<<department[i]<<": ";
			cin>>arr[i][j];
		}
	}
	
	for(int i=0; i<dep; i++){
		cout<<"Department: "<<department[i]<<endl;
		cout<<"Courses GPAs:\n"
		for(int j=0;j<size[i];j++){
			cout<<"Course "<<j+1<<arr[i][j]<<endl;
		}
		cout<<endl;
	}

    return 0;
}
