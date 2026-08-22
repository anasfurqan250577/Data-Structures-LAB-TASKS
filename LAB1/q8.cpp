#include <iostream>
using namespace std;

class Box {
private:
    int *value;   

public:
    Box(int v) {
        value = new int(v);   
    }

    Box& operator=(const Box &other) {

        if (this != &other) {
	         cout << "Releasing old memory \n"; 	
	        delete value;           
	        value = new int(*other.value); 
	        cout << "New memory allocated \n";        	
        }
        else{
        	cout << "Self-assignment detected, skipping\n";
		}
       	  return *this;   
        }

    void display() {
        cout << "Box value: " << *value << endl;
    }

    ~Box() {
        cout << "Destructor called "<< *value << endl;
        delete value;   
    }
};

int main() {
    Box box1(10);
    Box box2(20);

    box2 = box1;
    box1.display();
    box2.display();

    box1 = box1;
    box1.display();

    return 0;
}

        