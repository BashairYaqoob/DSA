//Linear search
#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 5)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = LinearSearch(arr, n);
    if (index != -1)
    {
        cout << "Value 5 found at index: " << index << endl;
    }
    else
    {
        cout << "Value 5 not found in the array." << endl;
    }
    return 0;
}
