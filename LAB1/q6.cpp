#include <iostream>
#include <cstring>
using namespace std;

class Exam{
    char *studentName;

    public:
    Exam(char* name){
        studentName = new char[strlen(name)+1];  
        strcpy(studentName, name); 
    }

    void setName(char* name){
        strcpy(studentName, name);
    }

    Exam(const Exam &other){
        studentName = new char[strlen(other.studentName)+1];
        strcpy(studentName, other.studentName);
    }

    void display(){
        cout << "Name: " << studentName << endl;
    }

    ~Exam(){
        delete[] studentName;
    }
};

int main(){
    Exam e1("Anas"); 
    Exam e2 = e1;
    
    e1.display();
    e2.display();

    e2.setName("Ali");

    e1.display();
    e2.display();
}