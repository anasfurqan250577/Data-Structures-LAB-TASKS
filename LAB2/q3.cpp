#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int *arr = new int[n];
    int sum = 0;

    for(int i=0; i<n; i++){
        cout << "Enter value " << i+1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "\nArray Elements\n";
    for(int i=0; i<n; i++){
        cout << "index " << i << ": " << arr[i] << endl; 
    }
    cout << "Sum: " << sum << endl << endl;

    delete[] arr;
}