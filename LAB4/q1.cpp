#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class SL{
    Node* head;
    Node* tail;

    public:
    SL(){
        head = tail = NULL;
    }

    void insertBeg(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    SL s;
    cout << "Enter 3 values: ";
    for(int i=1; i<=3; i++){
        int x;
        cin >> x;
        s.insertBeg(x);
    }
    
    s.display();
}