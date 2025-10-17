#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++){
		L[i] = arr[left + i];}
	for (int j = 0; j < n2; j++){
		R[j] = arr[mid + 1 + j];
	}
	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]){
			arr[k++] = L[i++];}
		else{
			arr[k++] = R[j++];}
	}

	while (i < n1){
		arr[k++] = L[i++];
	}
	while (j < n2){
		arr[k++] = R[j++];
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main()
{
	int arr1[10] = {12, 7, 45, 23, 89, 3, 67, 5, 34, 20};
	int arr2[10] = {15, 1, 40, 22, 88, 9, 60, 4, 35, 19};

	int combined[20];
	for (int i = 0; i < 10; i++)
	{
		combined[i] = arr1[i];
	}
	for (int i = 0; i < 10; i++)
	{
		combined[10 + i] = arr2[i];
	}

	int n = 20;
	mergeSort(combined, 0, n - 1);

	cout << "Sorted array using Merge Sort: \n";
	for (int i = 0; i < n; i++){
		cout << combined[i] << " ";
	}
	cout << endl;
}
//============================================================//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

// Median of three pivot
int medianOfThree(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    if ((a > b) != (a > c)) return low;
    else if ((b > a) != (b > c)) return mid;
    else return high;
}

int partition(int arr[], int low, int high, int pivotIndex) {
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, string method) {
    if (low < high) {
        int pivotIndex;
        if (method == "first") pivotIndex = low;
        else if (method == "random") pivotIndex = low + rand() % (high - low + 1);
        else if (method == "middle") pivotIndex = (low + high) / 2;
        else if (method == "median") pivotIndex = medianOfThree(arr, low, high);
        else pivotIndex = high;

        int pi = partition(arr, low, high, pivotIndex);

        quickSort(arr, low, pi - 1, method);
        quickSort(arr, pi + 1, high, method);
    }
}

void runQuickSort(string method, int arr[], int n) {
    int temp[20];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    comparisons = 0;
    quickSort(temp, 0, n - 1, method);
    cout << method << " pivot -> comparisons: " << comparisons << endl;
}

int main() {
    srand(time(0));

    int arr1[10] = {12, 7, 45, 23, 89, 3, 67, 5, 34, 20};
    int arr2[10] = {15, 1, 40, 22, 88, 9, 60, 4, 35, 19};
    int combined[20];
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[10 + i] = arr2[i];

    int n = 20;

    runQuickSort("first", combined, n);
    runQuickSort("random", combined, n);
    runQuickSort("middle", combined, n);
    runQuickSort("median", combined, n);

    return 0;
}

//
