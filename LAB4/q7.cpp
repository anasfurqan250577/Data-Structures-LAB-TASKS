#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DL{
    Node* head;
    Node* tail;

    public:
    DL(){
        head = tail = NULL;
    }

    void insertEnd(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void displayForward(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayBackward(){
        Node* temp = tail;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main(){
    DL d;

    cout << "Enter 5 values: ";

    for(int i=1; i<=5; i++){
        int x;
        cin >> x;
        d.insertEnd(x);
    }

    cout << "Forward Traversal: ";
    d.displayForward();

    cout << "Backward Traversal: ";
    d.displayBackward();
}