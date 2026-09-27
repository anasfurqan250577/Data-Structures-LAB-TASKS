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
	}
}

int binarySearch(int arr[], int n, int key){
	int low = 0;
	int high = n-1;
	
	while(low <= high){
		int mid = (low+high)/2;
		
		cout << "low: " << low << ", high: " << high << ", mid: " << mid << endl;
		
		if(arr[mid] == key) return mid;
		else if(arr[mid] > key) high = mid-1;
		else low = mid+1; 
	}
	
	return -1;
}

int main(){
	int n;
	cout << "Enter number of products: ";
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		cout << "Enter Product " << i+1 << " ID: ";
		cin >> arr[i];
	}
	
	cout << "\nArray Before Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	combSort(arr, n);
	
	cout << "\nArray After Sorting: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	
	int key;
	cout << "Enter Product ID to search: ";
	cin >> key;
	
	cout << "\nBinary Search Pointer Values\n";
	int result = binarySearch(arr, n, key);
	
	if(result == -1){
		cout << "Element Does Not Exist!!" << endl;
	}
	else{
		cout << "Element found at index: " << result << endl;
	}
	
	return 0;
}
