#include <iostream>
using namespace std;

class student
{
private:
    int *marks;

public:
    student(int m)
    {
        marks = new int(m);
    }

    student(const student &other)
    { // Proper copy constructor
        marks = new int(*other.marks);
    }

    student &operator=(const student &other)
    {
        if (this != &other)
        {
            delete marks;
            marks = new int(*other.marks);
        }
        return *this;
    }

    void display()
    {
        cout << "Marks: " << *marks << endl;
    }

    void modify(int m)
    {
        delete marks; // Release old heap memory
        marks = new int(m);
    }
    
    ~student()
    {
        delete marks;
    }
};

int main()
{
    student s1(80);
    student s2 = s1; // invokes copy constructor
    student s3(90);
    s3 = s1; // invokes copy assignment operator
    cout << "Before modification:" << endl;
    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    cout << "s3: ";
    s3.display();
    s2.modify(70);
    s3.modify(60);

    cout << "\nAfter modification:" << endl;
    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    cout << "s3: ";
    s3.display();

    return 0;
}
