#include <iostream>
using namespace std;

struct Result{
    int comparisons;
    int swaps;
};

Result bubbleSort(int arr[], int n){
    int comparisons = 0;
    int swaps = 0;

    for(int i=0; i<n-1; i++){
        bool swapped = false;

        for(int j=0; j<n-i-1; j++){
            comparisons++;

            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped = true;
                swaps++;
            }
        }

        if(!swapped) break;
    }

    return {comparisons, swaps};
}

Result selectionSort(int arr[], int n){
    int comparisons = 0;
    int swaps = 0;

    for(int i=0; i<n-1; i++){
        int minIdx = i;

        for(int j=i+1; j<n; j++){
            comparisons++;

            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }

        if(minIdx != i){
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;

            swaps++;
        }
    }

    return {comparisons, swaps};
}

Result insertionSort(int arr[], int n){
    int comparisons = 0;
    int swaps = 0;

    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0){
            comparisons++;

            if(arr[j] > key){
                arr[j+1] = arr[j];
                swaps++;
                j--;
            }
            else{
                break;
            }
        }

        arr[j+1] = key;
    }

    return {comparisons, swaps};
}

Result shellSort(int arr[], int n){
    int comparisons = 0;
    int swaps = 0;

    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int key = arr[i];
            int j = i-gap;

            while(j>=0){
                comparisons++;

                if(arr[j] > key){
                    arr[j+gap] = arr[j];
                    swaps++;
                    j = j-gap;
                }
                else{
                    break;
                }
            }

            arr[j+gap] = key;
        }
    }

    return {comparisons, swaps};
}

Result combSort(int arr[], int n){
    int comparisons = 0;
    int swaps = 0;

    int gap = n;
    bool swapped = true;

    while(gap>1 || swapped){
        gap /= 1.3;

        if(gap<1) gap = 1;

        swapped = false;

        for(int j=0; j+gap<n; j++){
            comparisons++;

            if(arr[j] > arr[j+gap]){
                int temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;

                swapped = true;
                swaps++;
            }
        }
    }

    return {comparisons, swaps};
}

int linearSearch(int arr[], int n, int key, int &comparisons){
    comparisons = 0;

    for(int i=0; i<n; i++){
        comparisons++;

        if(arr[i] == key){
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int n, int key, int &comparisons){
    int low = 0;
    int high = n-1;

    comparisons = 0;

    while(low <= high){
        int mid = (low+high)/2;

        comparisons++;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return -1;
}

int interpolationSearch(int arr[], int n, int key, int &comparisons){
    int low = 0;
    int high = n-1;

    comparisons = 0;

    while(low <= high && key >= arr[low] && key <= arr[high]){

        if(arr[low] == arr[high]){
            comparisons++;

            if(arr[low] == key){
                return low;
            }
            else{
                return -1;
            }
        }

        int pos = low + ((key-arr[low])*(high-low))
                       /(arr[high]-arr[low]);

        comparisons++;

        cout << "Estimated Position: " << pos << endl;

        if(arr[pos] == key){
            return pos;
        }
        else if(arr[pos] > key){
            high = pos-1;
        }
        else{
            low = pos+1;
        }
    }

    return -1;
}

void copyArray(int original[], int copy[], int n){
    for(int i=0; i<n; i++){
        copy[i] = original[i];
    }
}

void displayArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int original[n];

    for(int i=0; i<n; i++){
        cout << "Enter Element " << i+1 << ": ";
        cin >> original[i];
    }

    cout << "\nOriginal Array: ";
    displayArray(original, n);

    int arr[n];
    Result result;

    copyArray(original, arr, n);
    result = bubbleSort(arr, n);

    cout << "\nBubble Sort:";
    cout << "\nComparisons: " << result.comparisons;
    cout << "\nSwaps: " << result.swaps;
    cout << "\nSorted Array: ";
    displayArray(arr, n);

    copyArray(original, arr, n);
    result = selectionSort(arr, n);

    cout << "\nSelection Sort:";
    cout << "\nComparisons: " << result.comparisons;
    cout << "\nSwaps: " << result.swaps;
    cout << "\nSorted Array: ";
    displayArray(arr, n);

    copyArray(original, arr, n);
    result = insertionSort(arr, n);

    cout << "\nInsertion Sort:";
    cout << "\nComparisons: " << result.comparisons;
    cout << "\nShifts: " << result.swaps;
    cout << "\nSorted Array: ";
    displayArray(arr, n);

    copyArray(original, arr, n);
    result = shellSort(arr, n);

    cout << "\nShell Sort:";
    cout << "\nComparisons: " << result.comparisons;
    cout << "\nShifts: " << result.swaps;
    cout << "\nSorted Array: ";
    displayArray(arr, n);

    copyArray(original, arr, n);
    result = combSort(arr, n);

    cout << "\nComb Sort:";
    cout << "\nComparisons: " << result.comparisons;
    cout << "\nSwaps: " << result.swaps;
    cout << "\nSorted Array: ";
    displayArray(arr, n);

    copyArray(original, arr, n);
    combSort(arr, n);

    int key;

    cout << "\nEnter value to search: ";
    cin >> key;

    cout << "\nSearching in Sorted Array:\n";
    displayArray(arr, n);

    int comparisons;

    int linearResult = linearSearch(arr, n, key, comparisons);

    cout << "\nLinear Search:";
    if(linearResult == -1){
        cout << "\nElement Does Not Exist";
    }
    else{
        cout << "\nElement found at index: " << linearResult;
    }
    cout << "\nComparisons: " << comparisons << endl;

    int binaryResult = binarySearch(arr, n, key, comparisons);

    cout << "\nBinary Search:";
    if(binaryResult == -1){
        cout << "\nElement Does Not Exist";
    }
    else{
        cout << "\nElement found at index: " << binaryResult;
    }
    cout << "\nComparisons: " << comparisons << endl;

    cout << "\nInterpolation Search:";
    int interpolationResult = interpolationSearch(arr, n, key, comparisons);

    if(interpolationResult == -1){
        cout << "Element Does Not Exist";
    }
    else{
        cout << "Element found at index: " << interpolationResult;
    }
    cout << "\nComparisons: " << comparisons << endl;

    cout << "\n\nComplexity Comparison:\n";

    cout << "\nBubble Sort";
    cout << "\nBest: O(n)";
    cout << "\nAverage: O(n^2)";
    cout << "\nWorst: O(n^2)";
    cout << "\nSpace: O(1)\n";

    cout << "\nSelection Sort";
    cout << "\nBest: O(n^2)";
    cout << "\nAverage: O(n^2)";
    cout << "\nWorst: O(n^2)";
    cout << "\nSpace: O(1)\n";

    cout << "\nInsertion Sort";
    cout << "\nBest: O(n)";
    cout << "\nAverage: O(n^2)";
    cout << "\nWorst: O(n^2)";
    cout << "\nSpace: O(1)\n";

    cout << "\nShell Sort";
    cout << "\nBest: O(n log n)";
    cout << "\nAverage: Depends on gap sequence";
    cout << "\nWorst: O(n^2)";
    cout << "\nSpace: O(1)\n";

    cout << "\nComb Sort";
    cout << "\nBest: O(n log n)";
    cout << "\nAverage: O(n^2)";
    cout << "\nWorst: O(n^2)";
    cout << "\nSpace: O(1)\n";

    cout << "\nLinear Search";
    cout << "\nBest: O(1)";
    cout << "\nAverage: O(n)";
    cout << "\nWorst: O(n)";
    cout << "\nSpace: O(1)\n";

    cout << "\nBinary Search";
    cout << "\nBest: O(1)";
    cout << "\nAverage: O(log n)";
    cout << "\nWorst: O(log n)";
    cout << "\nSpace: O(1)\n";

    cout << "\nInterpolation Search";
    cout << "\nBest: O(1)";
    cout << "\nAverage: O(log log n)";
    cout << "\nWorst: O(n)";
    cout << "\nSpace: O(1)\n";

    cout << "\nAppropriate Technique Based on Data:\n";
    cout << "Sorting: Comb Sort or Shell Sort can be considered for general unsorted data.\n";
    cout << "Searching: Binary Search is suitable for sorted data.\n";
    cout << "Interpolation Search is suitable when sorted values are approximately uniformly distributed.\n";

    return 0;
}
