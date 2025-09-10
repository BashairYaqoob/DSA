#include <iostream>
using namespace std;

int main() {
    int n;

    cout<<"Enter number of crates: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the shipping time: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    //selection sort:comparing cost is low + extra space for temporary storage
    for(int i=0; i<n-1;i++){
        int min_index=i;
        for(int j=i+1; j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    cout<<"Sorted order of shipping time: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
