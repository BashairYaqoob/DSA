#include <iostream>
using namespace std;

struct Entry {
    int sum;
    int a;
    int b;
    bool used;
};
const int SIZE = 1000;
Entry hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

bool findPairs(int arr[], int n) {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].used = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int a = arr[i];
            int b = arr[j];
            int sum = a + b;

            int index = hashFunction(sum);
            while (hashTable[index].used && hashTable[index].sum != sum) {
                index = (index + 1) % SIZE;
            }

            if (!hashTable[index].used) {
                hashTable[index].sum = sum;
                hashTable[index].a = a;
                hashTable[index].b = b;
                hashTable[index].used = true;
            }
            else {
                int c = hashTable[index].a;
                int d = hashTable[index].b;

                if (a != c && a != d && b != c && b != d) {
                    cout << "(" << c << ", " << d << ") and ("
                         << a << ", " << b << ")\n";
                    return true;
                }
            }
        }
    }

    cout << "No pairs found\n";
    return false;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    cout << "Test 1: ";
    findPairs(arr1, 7);

    int arr2[] = {3, 4, 7, 1, 12, 9};
    cout << "Test 2: ";
    findPairs(arr2, 6);

    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    cout << "Test 3: ";
    findPairs(arr3, 7);

    return 0;
}
