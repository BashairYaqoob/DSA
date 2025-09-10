#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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
    int x;
    cout << "Enter elements of array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nEnter a value to search:";
    cin >> x;
    int res = BinarySearch(arr, n, x);
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
