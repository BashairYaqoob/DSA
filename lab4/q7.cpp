#include <iostream>
using namespace std;

void combSort(int arr[], int n){
    float shrink=1.3;
    int gap=n;
    bool swapped=true;
    while(gap>1 || swapped){
        gap=(int)(gap/shrink);
        if(gap<1){
            gap=1;
        }
        swapped=false;
        for(int i=0; i+gap<n;++i){
            if(arr[i]>arr[i+gap]){
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swapped=true;
            }
        }
    }
}

int main()
{
     int n;
    cout << "Enter number of trading cards: ";
    cin >> n;

    int arr[n];
    cout << "Enter card values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    combSort(arr, n);

    cout << "\nTrading cards values (after Comb Sort):\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
