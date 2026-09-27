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
            tail = curr;
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

    cout << "Enter 5 values: ";
    for(int i=1; i<=5; i++){
        int x;
        cin >> x;
        s.insertEnd(x);
    }

    s.display();

    int pos, x;
    cout << "Enter a position: ";
    cin >> pos;
    cout << "Enter a value: ";
    cin >> x;
    s.insertPos(x, pos);
    s.display();

}