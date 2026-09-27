#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key){
    int count = 0;

    for(int i=0; i<n; i++){
        count++;

        if(arr[i] == key){
            cout << "Element found at index: " << i << endl;
            cout << "Total Comparisons: " << count << endl;
            return;
        }
    }

    cout << "Element does not exist in this array" << endl;
    cout << "Total Comparisons: " << count << endl;
}

int main(){

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cout << "Enter Roll Number " << i+1 << ": ";
        cin >> arr[i];
    }

    int key;

    cout << "Enter Roll Number to search: ";
    cin >> key;

    
    cout << "Sorting Necessary: No (because we are using linear search in which we compare one by one each element)" << endl;

    linearSearch(arr, n, key);

    return 0;
}
