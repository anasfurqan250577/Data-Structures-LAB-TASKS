#include <iostream>
using namespace std;

class box
{
private:
    int *num;

public:
    box(int m)
    {
        num = new int(m);
    }

    box(const box &other)
    { // Proper copy constructor
        cout << "copy constructor is called" << endl;
        num = new int(*other.num);

        cout << "New memory allocated for copied object with value: " << *num << endl;
    }

    box &operator=(const box &other)
    {
        cout << "copy assignment operator is called" << endl;
        if (this != &other)
        {
            delete num;
            num = new int(*other.num);
        }

        else
        {
            cout << "Self-assignment detected. No memory changed." << endl;
        }
        return *this;
    }

    void display()
    {
        cout << "Value: " << *num << endl;
    }

    void modify(int m)
    {
        cout << "Call for modification: " << endl;
        cout << "Modifying value from " << *num << " to " << m << endl;
        delete num; // Release old heap memory
        num = new int(m);
    }
    
    ~box()
    {
        cout << "Destructor is called" << endl;
        delete num;
    }
};

int main()
{
    cout << "===== Creating box1 =====" << endl;
    box box1(80);

    cout << "\n===== Creating box2 =====" << endl;
    box box2(90);

    cout << "\n===== Copying box1 into box3 =====" << endl;
    box box3 = box1;
    cout << "box1: ";
    box1.display();

    cout << "box2: ";
    box2.display();

    cout << "box3: ";
    box3.display();

    cout << "\n===== Modifying box1 =====" << endl;
    box1.modify(60);
    cout << "box1: ";
    box1.display();

    cout << "box3: ";
    box3.display();
    cout << "\n===== Assigning box1 to box2 =====" << endl;
    box2 = box1;

    cout << "box1: ";
    box1.display();

    cout << "box2: ";
    box2.display();
    cout << "\n===== New scope =====" << endl;

    {
        box box4(200);

        cout << "box4: ";
        box4.display();

        box box5 = box4; // Copy constructor

        cout << "box5: ";
        box5.display();

        box5.modify(300);

        cout << "After modifying box5:" << endl;

        cout << "box4: ";
        box4.display();

        cout << "box5: ";
        box5.display();

        cout << "inner scope ended" << endl;
    }
    cout << "\n===== End of main =====" << endl;
    return 0;
}
