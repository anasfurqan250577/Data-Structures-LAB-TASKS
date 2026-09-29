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
            cout << "Queue is Full!" << endl;
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
            cout << "Queue is Empty!" << endl;
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

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    return 0;
}