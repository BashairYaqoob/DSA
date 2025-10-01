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
	int n=7;
	int luggage[n]={32,25,40,12,18,50,28};
	shellsort(luggage, n);
	cout<<"Sorted luggage weights: ";
	for(int i=0; i<6; i++){
	cout<<luggage[i]<<" ";
	}
	
	return 0;
}

//Bubble sort would make O(n^2) comparisons, resulting in unnecessary swaps wheras shell sort requires a few comparisons, thus it would reduce the processing time for luggage sorting, making the system more efficient for handling large numbers of passengers.

//If most of the luggage is already nearly sorted, Shell Sort's performance improves significantly. The algorithm will make fewer swaps compared to the worst-case scenario
