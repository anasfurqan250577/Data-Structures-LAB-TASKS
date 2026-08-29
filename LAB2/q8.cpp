#include <iostream>
using namespace std;

int main(){
    int r;
    cout << "Enter number of rows: ";
    cin >> r;

    int **arr = new int*[r];

    int col[r];

    for(int i=0; i<r; i++){
        cout << "Enter col of row " << i+1 << ": ";
        cin >> col[i];

        arr[i] = new int[col[i]];
    }

    for(int i=0; i<r; i++){
        cout << "Enter Row " << i+1 << " values\n";
        for(int j=0; j<col[i]; j++){
            cout << "Enter Value " << j+1 << ": ";
            cin >> arr[i][j];
        }
    }

    cout << "\nMATRIX\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<col[i]; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    int max = 0; 
    for(int i=0; i<r; i++){
        for(int j=0; j<col[i]; j++){
            if(arr[i][j] > max) max = arr[i][j];
        }
        cout << "Row " << i+1 << " maximum value: " << max << endl;
    }  

    for(int i=0; i<r; i++){
        delete[] arr[i];
    }

    delete[] arr;
}