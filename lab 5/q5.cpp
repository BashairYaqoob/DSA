#include <iostream>
using namespace std;

int SumDigits(int number){
    if(number==0){
        return number;
    }
    return (number%10)+SumDigits(number/10);
}

int nestedSum(int number){
    if(number<10){
        return number;
    }
    return nestedSum(SumDigits(number));
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of digits: " << nestedSum(n)<< endl;
    return 0;
}
