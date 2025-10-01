#include <iostream>
using namespace std;

void shellsort(int arr[], int n){
	for(int i=n/2; i>0; i/=2){
		for(int j=i; j<n; j++){
			int temp=arr[j];
			int k;
			for(k=j; k>=i && arr[k-i]>temp; k-=i){
			arr[k]=arr[k-i];
			}
			arr[k]=temp;
		}
	}
}

int main(){
	int n=6;
	int bookIDs[n]={205,102,310,450, 120, 90};
	shellsort(bookIDs, n);
	cout<<"Sorted book IDS: ";
	for(int i=0; i<6; i++){
	cout<<bookIDs[i]<<" ";
	}
	
	return 0;
}
