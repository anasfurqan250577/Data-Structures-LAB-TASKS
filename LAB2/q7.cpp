#include <iostream>
using namespace std;

int main() {
    int startIdx = 0;
    int size = 0;

    cout << "Enter custom starting index: ";
    cin >> startIdx;

    cout << "Enter array size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int endIdx = startIdx + size - 1;
    
    int* arr = new int[size];

    cout << "\nValid index range: [" << startIdx << " to " << endIdx << "]" << endl;

    cout << "\nInput Elements" << endl;
    for (int idx = startIdx; idx <= endIdx; ++idx) {
        int internalIdx = idx - startIdx;
        cout << "Enter value for index [" << idx << "]: ";
        cin >> arr[internalIdx];
    }

    cout << "\nArray Elements" << endl;
    for (int idx = startIdx; idx <= endIdx; ++idx) {
        int internalIdx = idx - startIdx;
        cout << "Index [" << idx << "] = " << arr[internalIdx] << endl;
    }

    cout << "\nSafe Index Access Check" << endl;
    int userIdx = 0;
    cout << "Enter custom index to access: ";
    cin >> userIdx;

    if (userIdx >= startIdx && userIdx <= endIdx) {
        int internalIdx = userIdx - startIdx;
        cout << "Value at index [" << userIdx << "] is: " << arr[internalIdx] << endl;
    } else {
        cout << "Error: Index " << userIdx << " is OUT OF BOUNDS! Valid range is [" 
             << startIdx << " to " << endIdx << "]." << endl;
    }

    cout << "\nSafe Index Modification Check" << endl;
    cout << "Enter custom index to modify: ";
    cin >> userIdx;

    if (userIdx >= startIdx && userIdx <= endIdx) {
        int internalIdx = userIdx - startIdx;
        int newVal;
        cout << "Enter new value: ";
        cin >> newVal;
        arr[internalIdx] = newVal;
        cout << "Successfully updated index [" << userIdx << "] to " << newVal << endl;
    } else {
        cout << "Error: Index " << userIdx << " is OUT OF BOUNDS! Valid range is [" 
             << startIdx << " to " << endIdx << "]." << endl;
    }

    cout << "\nFinal Array State" << endl;
    for (int idx = startIdx; idx <= endIdx; ++idx) {
        int internalIdx = idx - startIdx;
        cout << "Index [" << idx << "] = " << arr[internalIdx] << endl;
    }

    delete[] arr;

    return 0;
}