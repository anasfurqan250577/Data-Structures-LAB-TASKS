#include <iostream>
using namespace std;

void shellSort(int arr[], int n){
	for(int gap=n/2; gap>0; gap/=2){
		
		for(int i=gap; i<n; i++){
			int key = arr[i];
			int j = i- gap;
			
			while(j>=0 && arr[j]>key){
				arr[j+gap] = arr[j];
				j = j-gap;
			}
			
			arr[j+gap] = key;
		}
		
		cout << "After gap " << gap << ": ";
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
	}
}

int main(){
	int n;
	cout << "Enter number of employees: ";
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		cout << "Enter Employee " << i+1 << " Score: ";
		cin >> arr[i];
	}
	
	cout << "\nArray Before Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	cout << "\n\nShell Sort Passes:\n";
	shellSort(arr, n);
	
	cout << "\nArray After Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}
