#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool availability;

    Product() {}
    Product(string n, double p, string d, bool a)
        : name(n), price(p), description(d), availability(a) {}
       
       
     void quickSort(Product arr[], int left, int right) {
        if (left >= right) return;

        double pivot = arr[right].price;  
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr[j].price < pivot) {
                Product temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
        }
        Product temp = arr[i];
        arr[i] = arr[right];
        arr[right] = temp;

        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
};

int main() {
    Product products[3] = {
        Product("Product 1", 10.99, "This is product 1.", true),
        Product("Product 2", 5.99, "This is product 2.", false),
        Product("Product 3", 2.99, "This is product 3.", true)
    };
   
    products[0].quickSort(products, 0, 2);

    cout << "Products sorted by price:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << products[i].name << " - $" << products[i].price << endl;
    }

    return 0;
}
