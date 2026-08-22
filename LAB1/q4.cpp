#include <iostream>
#include <cstring>
using namespace std;

class Exam{
    char *studentName;

    public:
    Exam(char* name){
        studentName = new char[strlen(name)+1];  //dynamically allocating memory in the heap
        strcpy(studentName, name); //copying the name 
    }

    void display(){
        cout << "Name: " << studentName << endl;
    }

    ~Exam(){
        delete[] studentName;
    }
};

int main(){
    Exam e1("Anas"); //object memory is created here 
    Exam e2("Ali"); //another object memory is created here

    e1.display();
    e2.display();
}