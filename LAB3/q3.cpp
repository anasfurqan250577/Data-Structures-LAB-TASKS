#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
		
		cout << "After insertion " << i << ": ";
        for(int k=0; k<n; k++){
            cout << arr[k] << " ";
        }
        cout << endl;
	}
}

int main(){
	int n;
	cout << "Enter number of days: ";
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		cout << "Enter Day " << i+1 << " Temperature: ";
		cin >> arr[i];
	}
	
	cout << "\nArray Before Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	cout << "\n\nInsertion Sort Steps:\n";
	insertionSort(arr, n);
	
	cout << "\nArray After Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}
