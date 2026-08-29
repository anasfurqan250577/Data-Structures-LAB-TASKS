#include <iostream>
using namespace std;

int isValid(int size, int idx){
    if(idx < 0 || idx >=size) return false;
    return true;
}

void access(int arr[], int size, int idx){
    if(isValid(size, idx)){
        cout << "Element at index " << idx << ": " << arr[idx] << endl << endl; 
    }
    else{
        cout << "Index out of bound!"<< endl << endl;
    }
}

void modify(int arr[], int size, int idx, int update){
    if(isValid(size, idx)){
        arr[idx] = update;
        cout << "Updated Array: ";
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        } 
        cout << endl << endl;
    }
    else{
        cout << "Index out of bound!"<< endl << endl;
    }
}

int main(){
    int n;
    cout << "Enter size of an array: ";
    cin >> n;
    
    int *arr = new int[n];

    for(int i=0; i<n; i++){
        cout << "Enter Value " << i+1 << ": ";
        cin >> arr[i];
    }


    int choice, idx;
    cout << "\nChoose from the options\n";
    do{
        cout << "1. Access \n2. Modify \n3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter index: ";
                cin >> idx;
                access(arr, n, idx);
                break;
            case 2:
                int val;
                cout << "Enter index: ";
                cin >> idx;
                cout << "Enter new value: ";
                cin >> val;
                modify(arr, n, idx, val);
                break;
            case 3:
                cout << "Exiting!!!\n\n";
                break;
        }
    }while(choice != 3);
}