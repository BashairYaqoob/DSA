//Shell sort
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Orignal array elements:\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    for(int gap=n/2; gap>0; gap/=2){
        for(int j=gap; j<n; j++){
            int temp=arr[j];
            int res=j;
            while (res>=gap && arr[res-gap]>temp)
            {
                arr[res]=arr[res-gap];
                res-=gap;
            }
            arr[res]=temp;   
        }
    }
    cout<<"\nElements after Shell sort:\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
