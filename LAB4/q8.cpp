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

class CDL{
    Node* head;
    Node* tail;

    public:
    CDL(){
        head = tail = NULL;
    }

    void insertEnd(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else{
            newnode->prev = tail;
            newnode->next = head;
            tail->next = newnode;
            head->prev = newnode;
            tail = newnode;
        }
    }

    void insertBeg(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else{
            newnode->next = head;
            newnode->prev = tail;
            head->prev = newnode;
            tail->next = newnode;
            head = newnode;
        }
    }

    void insertPos(int val, int pos){
        if(pos < 1){
            cout << "Invalid pos" << endl;
            return;
        }

        if(pos == 1){
            insertBeg(val);
            return;
        }

        Node* curr = head;

        for(int i=1; i<pos-1; i++){
            curr = curr->next;

            if(curr == head){
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        Node* newnode = new Node(val);

        newnode->next = curr->next;
        newnode->prev = curr;
        curr->next->prev = newnode;
        curr->next = newnode;

        if(curr == tail){
            tail = newnode;
        }
    }

    void deleteNode(int pos){
        if(head == NULL){
            return;
        }

        if(pos < 1){
            cout << "Invalid pos" << endl;
            return;
        }

        if(pos == 1){
            if(head == tail){
                delete head;
                head = tail = NULL;
            }
            else{
                Node* temp = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delete temp;
            }
            return;
        }

        Node* curr = head;

        for(int i=1; i<pos; i++){
            curr = curr->next;

            if(curr == head){
                cout << "Position out of bounds" << endl;
                return;
            }
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if(curr == tail){
            tail = curr->prev;
        }

        delete curr;
    }

    void display(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);

        cout << endl << endl;
    }
};

int main(){
    CDL c;

    cout << "Enter 5 values: ";

    for(int i=1; i<=5; i++){
        int x;
        cin >> x;
        c.insertEnd(x);
    }

    cout << "After insertion at end:" << endl;
    c.display();

    int x, pos;

    cout << "Enter value to insert at beginning: ";
    cin >> x;
    c.insertBeg(x);
    cout << "After insertion at beginning:" << endl;
    c.display();

    cout << "Enter value and position: ";
    cin >> x >> pos;
    c.insertPos(x, pos);
    cout << "After insertion at position:" << endl;
    c.display();

    cout << "Enter position to delete: ";
    cin >> pos;
    c.deleteNode(pos);
    cout << "After deletion:" << endl;
    c.display();
}