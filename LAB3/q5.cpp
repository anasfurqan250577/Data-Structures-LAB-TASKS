#include <iostream>
using namespace std;

void combSort(int arr[], int n){
	int gap = n;
	bool swapped = true;
	
	while(gap > 1 || swapped){
		gap /= 1.3;
		
		if(gap < 1) gap = 1;
		
		swapped = false;
		
		for(int j=0; j+gap<n; j++){
			if(arr[j] > arr[j+gap]){
				int temp = arr[j];
				arr[j] = arr[j+gap];
				arr[j+gap] = temp;
				swapped = true;
			}
		}
		
		cout << "Gap: " << gap << endl;
	}
}

int main(){
	int n;
	cout << "Enter number of products: ";
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		cout << "Enter Product " << i+1 << " Code: ";
		cin >> arr[i];
	}
	
	cout << "\nArray Before Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	cout << "\n\nComb Sort Gaps:\n";
	combSort(arr, n);
	
	cout << "\nArray After Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}
