#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot insert " << value << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = value;

        cout << "Enqueued: " << value << endl;
        display();
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to remove." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }

        display();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue: Empty" << endl;
            cout << endl;
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
        cout << "Front: " << arr[front] << endl;
        cout << "Rear: " << arr[rear] << endl;
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    cout << "----- Waiting System -----\n\n";

    // Insert elements
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);

    q.enqueue(106);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(106);
    q.enqueue(107);
    q.enqueue(108);

    cout << "Checking Queue Status:\n";

    if (q.isEmpty())
        cout << "Queue is Empty." << endl;
    else
        cout << "Queue is not Empty." << endl;

    return 0;
}
