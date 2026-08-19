#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    //allocating the array
    int* arr = new int[n];

    int max = 0;
    int min = 999;

    for(int i=0; i<n; i++){
        cout << "Enter Student " << i+1 << " marks: ";
        cin >> arr[i];
        
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }


    for(int i=0; i<n; i++){
        cout << "Student " << i+1 << " marks = " << arr[i] << endl;
    }

    cout << "\nHighest Marks: " << max << endl;
    cout << "Minimum Marks: " << min << endl;

    //deallocating array 
    delete[] arr;

    return 0;
}
