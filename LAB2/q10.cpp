#include <iostream>
using namespace std;

int* resize1DArray(int* oldArr, int oldSize, int newSize) {
    int* newArr = new int[newSize];
    int minSize = (oldSize < newSize) ? oldSize : newSize;
    
    for (int i = 0; i < minSize; ++i) {
        newArr[i] = oldArr[i];
    }
    
    delete[] oldArr;
    return newArr;
}

int main() {
    cout << "=== Part 1: Resizable 1D Dynamic Array ===" << endl;

    int size1D;
    cout << "Enter initial size for 1D array: ";
    cin >> size1D;
    
    int* arr1D = new int[size1D];
    
    cout << "Enter " << size1D << " integer values: ";
    for (int i = 0; i < size1D; ++i) {
        cin >> arr1D[i];
    }
    
    cout << "\nCurrent 1D Array elements: ";
    for (int i = 0; i < size1D; ++i) {
        cout << arr1D[i] << " ";
    }
    cout << endl;
    
    int readIndex;
    cout << "\nEnter index to access safely: ";
    cin >> readIndex;

    if (readIndex >= 0 && readIndex < size1D) {
        cout << "Value at index " << readIndex << ": " << arr1D[readIndex] << endl;
    } else {
        cout << "Error: Index " << readIndex << " is out of bounds!" << endl;
    }
    
    int writeIndex, newVal;
    cout << "Enter index to modify safely: ";
    cin >> writeIndex;

    cout << "Enter new value: ";
    cin >> newVal;

    if (writeIndex >= 0 && writeIndex < size1D) {
        arr1D[writeIndex] = newVal;
        cout << "Successfully updated index " << writeIndex << endl;
    } else {
        cout << "Error: Index " << writeIndex << " is out of bounds! Operation canceled." << endl;
    }
    
    int newSize1D;
    cout << "\nEnter new size to resize 1D array: ";
    cin >> newSize1D;
    
    arr1D = resize1DArray(arr1D, size1D, newSize1D);
    size1D = newSize1D;
    
    cout << "Resized 1D Array elements (preserved data): ";
    for (int i = 0; i < size1D; ++i) {
        cout << arr1D[i] << " ";
    }
    cout << "\n\n";

    cout << "=== Part 2: 2D Dynamic Jagged Array ===" << endl;
    
    int rows;
    cout << "Enter number of rows for jagged array: ";
    cin >> rows;
    
    int** jagged = new int*[rows];
    int* rowSizes = new int[rows];
    
    for (int i = 0; i < rows; ++i) {
        cout << "Enter number of columns for Row " << i << ": ";
        cin >> rowSizes[i];
        jagged[i] = new int[rowSizes[i]];
    }
    
    cout << "\n--- Input Values for Jagged Array ---" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i << " (" << rowSizes[i] << " elements): ";
        for (int j = 0; j < rowSizes[i]; ++j) {
            cin >> jagged[i][j];
        }
    }
    
    cout << "\n--- Jagged Array Elements & Row Maximums ---" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i << ": ";
        int rowMax = 0;
        
        for (int j = 0; j < rowSizes[i]; ++j) {
            cout << jagged[i][j] << " ";
            if (jagged[i][j] > rowMax) {
                rowMax = jagged[i][j];
            }
        }
        cout << " | Max: " << rowMax << endl;
    }
    
    delete[] arr1D;
    arr1D = nullptr;
    
    for (int i = 0; i < rows; ++i) {
        delete[] jagged[i];
    }
    delete[] jagged;
    delete[] rowSizes;
    
    cout << "\nMemory successfully released." << endl;
    
    return 0;
}