#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int student) {
        if (rear == 4) {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = student;

        cout << "Student " << student << " added." << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Student " << arr[front] << " removed." << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
        cout << "Front: " << arr[front] << endl;
        cout << "Rear: " << arr[rear] << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);

    cout << "\nAfter Insertions:\n";
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "\nAfter Deletions:\n";
    q.display();

    q.enqueue(105);

    cout << "\nAfter Another Insertion:\n";
    q.display();

    return 0;
}

