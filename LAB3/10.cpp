#include <iostream>
using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int original[], int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = original[i];
    }
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;

        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void shellSort(int arr[], int n){
    for(int gap=n/2; gap>0; gap/=2){

        for(int i=gap; i<n; i++){
            int key = arr[i];
            int j = i-gap;

            while(j>=0 && arr[j]>key){
                arr[j+gap] = arr[j];
                j = j-gap;
            }

            arr[j+gap] = key;
        }
    }
}

void combSort(int arr[], int n){
    int gap = n;
    bool swapped = true;

    while(gap>1 || swapped){

        gap = gap / 1.3;

        if(gap<1)
            gap = 1;

        swapped = false;

        for(int j=0; j+gap<n; j++){
            if(arr[j] > arr[j+gap]){
                int temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
                swapped = true;
            }
        }
    }
}

int linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        cout << "Checking index " << i << endl;

        if(arr[i] == key)
            return i;
    }

    return -1;
}

int binarySearch(int arr[], int n, int key){
    int low = 0;
    int high = n-1;

    while(low<=high){

        int mid = (low+high)/2;

        cout << "Low: " << low
             << " High: " << high
             << " Mid: " << mid << endl;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] > key)
            high = mid-1;

        else
            low = mid+1;
    }

    return -1;
}

int interpolationSearch(int arr[], int n, int key){
    int low = 0;
    int high = n-1;

    while(low<=high && key>=arr[low] && key<=arr[high]){

        if(arr[low] == arr[high]){
            if(arr[low] == key)
                return low;
            else
                return -1;
        }

        int pos = low + ((key-arr[low])*(high-low))
                        / (arr[high]-arr[low]);

        cout << "Estimated Position: " << pos << endl;

        if(arr[pos] == key)
            return pos;

        else if(arr[pos] > key)
            high = pos-1;

        else
            low = pos+1;
    }

    return -1;
}

int main(){

    int n;

    cout << "Enter number of student marks: ";
    cin >> n;

    int original[n];
    int arr[n];

    cout << "Enter student marks:\n";

    for(int i=0; i<n; i++){
        cin >> original[i];
    }

    cout << "\nOriginal Data: ";
    display(original, n);

    int choice;

    do{
        cout << "\n========== MENU ==========\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Shell Sort\n";
        cout << "5. Comb Sort\n";
        cout << "6. Linear Search\n";
        cout << "7. Binary Search\n";
        cout << "8. Interpolation Search\n";
        cout << "9. Complexity Comparison\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice>=1 && choice<=5){

            copyArray(original, arr, n);

            if(choice==1){
                bubbleSort(arr, n);
                cout << "\nBubble Sort Result: ";
            }

            else if(choice==2){
                selectionSort(arr, n);
                cout << "\nSelection Sort Result: ";
            }

            else if(choice==3){
                insertionSort(arr, n);
                cout << "\nInsertion Sort Result: ";
            }

            else if(choice==4){
                shellSort(arr, n);
                cout << "\nShell Sort Result: ";
            }

            else if(choice==5){
                combSort(arr, n);
                cout << "\nComb Sort Result: ";
            }

            display(arr, n);
        }

        else if(choice>=6 && choice<=8){

            int key;
            cout << "\nEnter mark to search: ";
            cin >> key;

            copyArray(original, arr, n);

            if(choice==6){

                cout << "\nLinear Search:\n";

                int result = linearSearch(arr, n, key);

                cout << "Index: " << result << endl;

                cout << "Sorting Required: No\n";
                cout << "Reason: Linear Search can work on unsorted data.\n";
            }

            else{

                cout << "\nSorting is required before this search.\n";

                bubbleSort(arr, n);

                cout << "Sorted Data: ";
                display(arr, n);

                if(choice==7){

                    cout << "\nBinary Search Steps:\n";

                    int result = binarySearch(arr, n, key);

                    cout << "Index: " << result << endl;

                    cout << "Sorting Required: Yes\n";
                    cout << "Reason: Binary Search requires sorted data.\n";
                }

                else{

                    cout << "\nInterpolation Search Steps:\n";

                    int result = interpolationSearch(arr, n, key);

                    cout << "Index: " << result << endl;

                    cout << "Sorting Required: Yes\n";
                    cout << "Reason: Interpolation Search requires sorted data.\n";
                    cout << "It is most suitable for approximately uniform data.\n";
                }
            }
        }

        else if(choice==9){

            cout << "\n====== COMPLEXITY COMPARISON ======\n";

            cout << "\nSorting Algorithms:\n";

            cout << "Bubble Sort     : Best O(n), Average O(n^2), Worst O(n^2), Space O(1)\n";
            cout << "Selection Sort  : Best O(n^2), Average O(n^2), Worst O(n^2), Space O(1)\n";
            cout << "Insertion Sort  : Best O(n), Average O(n^2), Worst O(n^2), Space O(1)\n";
            cout << "Shell Sort      : Depends on gap sequence, Worst commonly O(n^2), Space O(1)\n";
            cout << "Comb Sort       : Best O(n log n), Average O(n^2), Worst O(n^2), Space O(1)\n";

            cout << "\nSearching Algorithms:\n";

            cout << "Linear Search       : Best O(1), Average O(n), Worst O(n), Space O(1)\n";
            cout << "Binary Search       : Best O(1), Average O(log n), Worst O(log n), Space O(1)\n";
            cout << "Interpolation Search: Best O(1), Average O(log log n), Worst O(n), Space O(1)\n";

            cout << "\n====== APPROPRIATE TECHNIQUE ======\n";

            cout << "Unsorted data: Linear Search can be used directly.\n";
            cout << "Nearly sorted data: Insertion Sort is suitable.\n";
            cout << "General unsorted data: Shell Sort or Comb Sort can be used.\n";
            cout << "Sorted data: Binary Search is suitable.\n";
            cout << "Approximately uniform sorted data: Interpolation Search can be suitable.\n";
        }

        else if(choice==0){
            cout << "\nProgram ended.\n";
        }

        else{
            cout << "\nInvalid choice!\n";
        }

    }while(choice!=0);

    return 0;
}