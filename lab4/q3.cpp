#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n=20;
    int arr[100];
    int arrB[20], arrI[20], arrSel[20], arrSh[20];
    int cb=0, ci=0, csh=0, csel=0;

    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%100+1;
    }

    cout<<"Original array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        arrB[i]=arr[i];
        arrI[i]=arr[i];
        arrSel[i]=arr[i];
        arrSh[i]=arr[i];
    }


    //bubble sort
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cb++;
            if(arrB[j]>arrB[j+1]){
                int temp=arrB[j];
                arrB[j]=arrB[j+1];
                arrB[j+1]=temp;
            }
        }
    }

    cout<<"\nBubble Sorted: ";
    for(int i=0; i<n; i++){
        cout<<arrB[i]<<" ";
    }
    cout<<"\nComparisons made in Bubble sort: "<<cb<<endl;

    //Insertion sort
    for(int i=1; i<n; i++){
        int key=arrI[i];
        int j=i-1;
        while(j>=0 &&arrI[j]>key){
            ci++;
            arrI[j+1]=arrI[j];
            j--;
        }
        arrI[j+1]=key;
    }
    cout<<"\nInsertion Sorted: ";
    for(int i=0; i<n; i++){
        cout<<arrI[i]<<" ";
    }
    cout<<"\nComparisons made in Insertion sort: "<<ci<<endl;

    //Selection Sort
    for(int i=0; i<n-1; i++){
        int min_index=i;
        for (int j=i+1; j<n; j++)
        {
            csel++;
            if(arrSel[j]<arrSel[min_index]){
                min_index=j;
            }
        }
        int temp=arrSel[i];
        arrSel[i]=arrSel[min_index];
        arrSel[min_index]=temp;
    }
    cout<<"\nSelection Sorted: ";
    for(int i=0; i<n; i++){
        cout<<arrSel[i]<<" ";
    }
    cout<<"\nComparisons made in Selection sort: "<<csel<<endl;

    //shell sort
    for(int gap=n/2; gap>0; gap/=2){
        for(int j=gap; j<n; j++){
            int temp=arrSh[j];
            int res=j;
            while(res>=gap&& arrSh[res-gap]>temp){
                csh++;
                arrSh[res]=arrSh[res-gap];
                res-=gap;
            }
            arrSh[res]=temp;
        }
    }
    cout<<"\nShell Sorted: ";
    for(int i=0; i<n; i++){
        cout<<arrSh[i]<<" ";
    }
    cout<<"\nComparisons made in shell sort: "<<csh<<endl;

    return 0;
}
