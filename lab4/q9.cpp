#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high && x>=arr[low] && x<=arr[high])
    {
        if(low==high){
            if(arr[low]==x){
                return low;
            }
            return -1;
        }
        int pos = low + ((x-arr[low])*(high-low))/(arr[high]-arr[low]);
        if (arr[pos] == x)
        {
            return pos;
        }
        else if (arr[pos] < x)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

int main()
{
    int n=6;
    int arr[n]={1,10,15,17,19,30};
    int x;

    cout << "\nEnter a value to search:";
    cin >> x;
    int res = interpolationSearch(arr, n, x);
    if (res!= -1)
    {
        cout << "Value " << x << " found at index: " << res<< endl;
    }
    else
    {
        cout << "Value " << x << " not found in the array." << endl;
    }
    return 0;
}
