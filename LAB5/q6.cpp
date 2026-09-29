#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;

class Stack {
public:
    int top;
    char arr[SIZE];

    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top >= SIZE - 1) {
            cout << "Stack Overflow\n";
        }
        else {
            arr[++top] = c;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        }
        else {
            top--;
        }
    }

    char tope() {
        if (top == -1)
            return '\0';

        return arr[top];
    }

    int isEmpty() {
        return (top == -1) ? 1 : 0;
    }
};

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s) {

    int start = 0, end = s.length() - 1;
    while(start < end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    Stack stack;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {

            ans += c;
        }

        else if (c == '(') {
            stack.push(c);
        }

        else if (c == ')') {
            while (!stack.isEmpty() && stack.tope() != '(') {
                ans += stack.tope();
                stack.pop();
            }

            if (!stack.isEmpty() && stack.tope() == '(') {
                stack.pop();
            }
        }

        else {
            while (!stack.isEmpty() &&
                   stack.tope() != '(' &&
                   prec(c) <= prec(stack.tope())) {

                ans += stack.tope();
                stack.pop();
            }

            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        ans += stack.tope();
        stack.pop();
    }

    int st = 0, en = ans.length() - 1;
    while(st < en){
        char temp = ans[st];
        ans[st] = ans[en];
        ans[en] = temp;
        st++;
        en--;
    }

    return ans;
}

int main() {
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "\nInfix Expression: " << infix;
    cout << "\nPrefix Expression: " << prefix << endl;

    return 0;
}

