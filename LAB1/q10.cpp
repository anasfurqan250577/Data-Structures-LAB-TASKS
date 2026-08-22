#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class StudentRecord
{
private:
    char *name;
    int *marks;
    int size;

public:
    StudentRecord(const char *n, int s)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        size = s;
        marks = new int[size];
        cout << "Enter " << size << " marks of student: " << name << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> marks[i];
        }
    }

    StudentRecord(const StudentRecord &other)
    {
        cout << "[Copy Constructor] copying from " << other.name << endl;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        size = other.size;

        marks = new int[size];
        for (int i = 0; i < size; i++)
        {
            marks[i] = other.marks[i];
        }
    }

    StudentRecord &operator=(const StudentRecord &other)
    {
        cout << "[Copy Assignment] " << name << " assigned from " << other.name << endl;
        if (this != &other)
        {
            delete[] name;
            delete[] marks;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            size = other.size;

            marks = new int[size];
            for (int i = 0; i < size; i++)
            {
                marks[i] = other.marks[i];
            }
        }
        return *this;
    }

    void setMark(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            marks[index] = value;
        }
    }

    void display()
    {
        cout << "Marks of student " << name << endl;
        for (int i = 0; i < size; i++)
        {
            cout << marks[i] << "  ";
        }
        cout << endl;
    }

    ~StudentRecord()
    {
        cout << "Destructor " << name << " destroyed\n";
        delete[] name;
        delete[] marks;
        cout << endl;
    }
};

class BrokenRecord
{
private:
    int *marks;
    int size;

public:
    BrokenRecord(int s)
    {
        size = s;
        marks = new int[size];
        cout << "Enter " << size << " marks of student: " << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> marks[i];
        }
    }

    void setMark(int index, int value)
    {
        marks[index] = value;
    }

    void display()
    {
        cout << "Marks of student " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << marks[i] << "  ";
        }
        cout << endl;
    }

    ~BrokenRecord()
    {
        cout << "Destructor BrokenRecord destroyed\n";
        delete[] marks; // shallow copy ki wajah se ye DOUBLE DELETION karega
    }
};

int main()
{
    StudentRecord s1("Anas", 3);
    StudentRecord s2("Ali", 2);
    StudentRecord s3("Ahmed", 3);

    StudentRecord s4 = s1;

    s3 = s1;
    s1 = s1;
    cout << endl;

    s2.setMark(0, 11);
    s3.setMark(0, 22);

    s1.display();
    s2.display();
    s3.display();
    s4.display();

    cout << "\nNested Scope\n";
    {
        StudentRecord s5 = s1;
        s5.display();
    }

    {
        BrokenRecord b1(2);
        BrokenRecord b2 = b1;
        b2.setMark(0, 999); // b2.setMark(0, 999) karne se b1 bhi affect hoga (shared data)
        b1.display();
        b2.display();

        // DOUBLE DELETION -> undefined behavior / crash
    }
}
