#include <iostream>
using namespace std;

int main(){
    int r, c;
    cout << "Enter the number of rows and columns: ";
    cin >> r >> c;

    int **arr = new int*[r];

    for(int i=0; i<r; i++){
        arr[i] = new int[c];
    }

    int sum = 0;

    cout << "\nEnter values\n";
    for(int i=0; i<r; i++){
        cout << "Row " << i+1 << ": " << endl;
        for(int j=0; j<c; j++){
            cout << "Value " << j+1 << ": ";
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    cout << "\nMatrix\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\nSum: " << sum << endl << endl;

    for(int i=0; i<r; i++){
        delete[] arr[i];
    }
    delete[] arr;
}