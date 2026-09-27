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

    void insertEnd(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertPos(int val, int pos){
        if(pos<1){
            cout << "Invalid pos";
            return;
        }
        if(pos==1){
            insertBeg(val); 
            return;
        }
            
        
        Node* curr = head;
        Node* pre;
        for(int i=1; i<pos; i++){
            if(curr==NULL) return;
            pre = curr;
            curr = curr->next;
        }
        
        Node* newnode = new Node(val);
        pre->next = newnode;
        newnode->next = curr;
        if(curr==NULL){
            tail = newnode;
        } 
    }

    void deleteStart(){
        if(head == NULL) return;
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd(){
        if(head == NULL) return;
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void deletePos(int pos){
        if(pos<1){
            cout << "Invalid pos";
            return;
        }
        if(pos==1){
            deleteStart(); 
            return;
        }
        Node* curr = head;
        Node* pre;
        for(int i=1; i<pos; i++){
            if(curr == NULL) return;
            pre = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Position out of bounds";
            return;
        }

        if (curr == tail) {
            tail = pre;
        }

        pre->next = curr->next;
        curr->next = NULL;
        delete curr;

    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }
};

int main(){
    SL s;

    cout << "Enter 7 values: ";
    for(int i=1; i<=7; i++){
        int x;
        cin >> x;
        s.insertEnd(x);
    }
    s.display();

    cout << "Deleting at End" << endl;
    s.deleteEnd();
    s.display();

    cout << "Deleting at Start" << endl;
    s.deleteStart();
    s.display();

    int pos;
    cout << "Enter a position: ";
    cin >> pos;
    s.deletePos(pos);
    s.display();

}