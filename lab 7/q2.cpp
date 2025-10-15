#include <iostream>
using namespace std;

class Runner{
public:
string name;
int finishTime;
};

class Marathon{
private:
Runner runners[10];
int count ;

void merge(Runner arr[], int l, int m, int r) {
       int i = l, j = m + 1, k = l;
       Runner temp[10];

       while (i <= m && j <= r) {
           if (arr[i].finishTime < arr[j].finishTime) {
               temp[k] = arr[i];
               i++;
           } else {
               temp[k] = arr[j];
               j++;
           }
           k++;
       }

       while (i <= m) {
           temp[k] = arr[i];
           i++;
           k++;
       }

       while (j <= r) {
           temp[k] = arr[j];
           j++;
           k++;
       }

       for (int s = l; s <= r; s++) {
           arr[s] = temp[s];
       }
   }

   void mergesort(Runner arr[], int l, int r) {
       if (l < r) {
           int mid = (l + r) / 2;
           mergesort(arr, l, mid);
           mergesort(arr, mid + 1, r);
           merge(arr, l, mid, r);
    }
  }
 
public:
  Marathon():count(10){
 };
 
  void inputRunners() {
       for (int i = 0; i < count; i++) {
           cout << "Enter name and finish time of runner " << i + 1 << ": ";
           cin >> runners[i].name;
           cin >> runners[i].finishTime;
       }
    }
   
    void displayRunners() {
        cout << "\nTop 5 fastest runners:\n";
        for (int i = 0; i < 5; i++) {
            cout << runners[i].name << " - " << runners[i].finishTime << " seconds\n";
        }
    }

    void sortRunners() {
        mergesort(runners, 0, count - 1);
    }
};

int main() {
    Marathon marathon;

    marathon.inputRunners();
    marathon.sortRunners();  
    marathon.displayRunners();

    return 0;
}
