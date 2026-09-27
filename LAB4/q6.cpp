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

class CL{
    Node* head;
    Node* tail;

    public:
    CL(){
        head = tail = NULL;
    }

    void insertEnd(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertBeg(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
            newnode->next = head;
            head = newnode;
            tail->next = head;
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
                tail->next = head;
                delete temp;
            }
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

        Node* temp = curr->next;

        if(temp == head){
            cout << "Position out of bounds" << endl;
            return;
        }

        curr->next = temp->next;

        if(temp == tail){
            tail = curr;
        }

        delete temp;
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
    CL c;

    cout << "Enter 5 values: ";

    for(int i=1; i<=5; i++){
        int x;
        cin >> x;
        c.insertEnd(x);
    }

    cout << "Circular Linked List:" << endl;
    c.display();

    int x, pos;

    cout << "Enter value to insert at beginning: ";
    cin >> x;
    c.insertBeg(x);
    c.display();

    cout << "Enter value to insert at end: ";
    cin >> x;
    c.insertEnd(x);
    c.display();

    cout << "Enter value and position: ";
    cin >> x >> pos;
    c.insertPos(x, pos);
    c.display();

    cout << "Enter position to delete: ";
    cin >> pos;
    c.deleteNode(pos);
    c.display();
}