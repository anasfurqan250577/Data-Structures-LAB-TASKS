#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key){
	int low = 0;
	int high = n-1;
	
	while(low <= high && key <= arr[high] && key >= arr[low]){
		
		if(arr[low] == arr[high]){
    		if(arr[low] == key){
        		cout << "estimated position: " << low << endl;
        		return low;
    		}
    		else{
        		return -1;
    		}
		}
		
		int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
		
		cout << "estimated position: " << pos << endl;
		
		if(arr[pos] == key) return pos;
		else if(arr[pos] > key) high = pos-1;
		else low = pos+1;
	}
	
	return -1;
}

int main(){
	int n;
	cout << "Enter number of students: ";
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		cout << "Enter Student " << i+1 << " Score: ";
		cin >> arr[i];
	}
	
	cout << "\nArray: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	
	int key;
	cout << "\n\nEnter Student Score to search: ";
	cin >> key;
	
	cout << "\n\nInterpolation Search Estimations:\n";
	int result = interpolationSearch(arr, n, key);
	
	if(result == -1){
		cout << "Element Does Not Exist!!" << endl;
	}
	else{
		cout << "Element found at index: " << result << endl;
	}
	
	return 0;
}
