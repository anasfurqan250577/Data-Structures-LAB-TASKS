#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 5;

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(char x) {
        if (isFull()) {
            cout << "Stack is Full!\n";
        }
        else {
            arr[++top] = x;
        }
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }

        return arr[top--];
    }

    char peek() {
        if (isEmpty())
            return '\0';

        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }

        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class LinearQueue {
    int arr[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
        cout << x << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << arr[front] << " removed.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Front: " << arr[front] << endl;
        cout << "Rear: " << arr[rear] << endl;
    }
};

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

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue is Full!\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = x;
        cout << x << " inserted.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty!\n";
            return;
        }

        cout << arr[front] << " removed.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty!\n";
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
    }
};

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;

    return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' ||
           c == '/' || c == '^';
}

string infixToPostfix(string s) {
    Stack st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }

            if (!st.isEmpty())
                st.pop();
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() &&
                   st.peek() != '(' &&
                   precedence(c) <= precedence(st.peek())) {
                result += st.pop();
            }

            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += st.pop();
    }

    return result;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    string result = infixToPostfix(s);

    reverse(result.begin(), result.end());

    return result;
}

void stackMenu(Stack &st) {
    int choice;
    char value;

    do {
        cout << "\n--- Stack ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter character: ";
            cin >> value;
            st.push(value);
            st.display();
        }
        else if (choice == 2) {
            value = st.pop();

            if (value == '\0')
                cout << "Stack is Empty!\n";
            else
                cout << "Popped: " << value << endl;

            st.display();
        }
        else if (choice == 3) {
            st.display();
        }

    } while (choice != 4);
}

void linearQueueMenu(LinearQueue &q) {
    int choice, value;

    do {
        cout << "\n--- Linear Queue ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            q.display();
        }
        else if (choice == 2) {
            q.dequeue();
            q.display();
        }
        else if (choice == 3) {
            q.display();
        }

    } while (choice != 4);
}

void circularQueueMenu(CircularQueue &q) {
    int choice, value;

    do {
        cout << "\n--- Circular Queue ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isFull\n";
        cout << "4. isEmpty\n";
        cout << "5. Display\n";
        cout << "6. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            q.display();
        }
        else if (choice == 2) {
            q.dequeue();
            q.display();
        }
        else if (choice == 3) {
            if (q.isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is not Full.\n";
        }
        else if (choice == 4) {
            if (q.isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is not Empty.\n";
        }
        else if (choice == 5) {
            q.display();
        }

    } while (choice != 6);
}

void expressionMenu() {
    int choice;
    string expression;

    do {
        cout << "\n--- Expression Conversion ---\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter infix expression: ";
            cin >> expression;

            cout << "Postfix: "
                 << infixToPostfix(expression) << endl;
        }
        else if (choice == 2) {
            cout << "Enter infix expression: ";
            cin >> expression;

            cout << "Prefix: "
                 << infixToPrefix(expression) << endl;
        }

    } while (choice != 3);
}

int main() {
    Stack st;
    LinearQueue lq;
    CircularQueue cq;

    int choice;

    do {
        cout << "\n========== LAB 05 ==========\n";
        cout << "1. Stack\n";
        cout << "2. Linear Queue\n";
        cout << "3. Circular Queue\n";
        cout << "4. Infix to Postfix / Prefix\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            stackMenu(st);
        else if (choice == 2)
            linearQueueMenu(lq);
        else if (choice == 3)
            circularQueueMenu(cq);
        else if (choice == 4)
            expressionMenu();
        else if (choice == 5)
            cout << "Program Ended.\n";
        else
            cout << "Invalid Choice!\n";

    } while (choice != 5);

    return 0;
}
