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

        if(head == NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
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
            if(curr == NULL){
                cout << "Position out of bounds" << endl;
                return;
            }
            curr = curr->next;
        }

        if(curr == NULL){
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newnode = new Node(val);

        newnode->next = curr->next;
        curr->next = newnode;

        if(newnode->next == NULL){
            tail = newnode;
        }
    }

    void deleteBeg(){
        if(head == NULL) return;

        Node* temp = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }

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
        if(head == NULL) return;

        if(pos < 1){
            cout << "Invalid pos" << endl;
            return;
        }

        if(pos == 1){
            deleteBeg();
            return;
        }

        Node* curr = head;

        for(int i=1; i<pos-1; i++){
            if(curr == NULL || curr->next == NULL){
                cout << "Position out of bounds" << endl;
                return;
            }
            curr = curr->next;
        }

        if(curr->next == NULL){
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;

        if(temp == tail){
            tail = curr;
        }

        delete temp;
    }

    void search(int val){
        Node* temp = head;
        int pos = 1;

        while(temp != NULL){
            if(temp->data == val){
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Not found" << endl;
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
        if(head == NULL) return;

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

    void search(int val){
        if(head == NULL){
            cout << "Not found" << endl;
            return;
        }

        Node* temp = head;
        int pos = 1;

        do{
            if(temp->data == val){
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }while(temp != head);

        cout << "Not found" << endl;
    }

    void display(){
        if(head == NULL){
            return;
        }

        Node* temp = head;

        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);

        cout << endl;
    }

    void reverse(){
        if(head == NULL || head == tail){
            display();
            return;
        }

        Node* curr = tail;

        do{
            cout << curr->data << " ";
            
            Node* temp = head;

            while(temp->next != curr){
                temp = temp->next;
            }

            curr = temp;

        }while(curr != tail);

        cout << endl;
    }
};

int main(){

    cout << "SINGLY LINKED LIST" << endl;

    SL s;

    s.insertEnd(10);
    s.insertEnd(20);
    s.insertBeg(5);
    s.insertPos(15, 3);

    cout << "List: ";
    s.display();

    cout << "Search 20: ";
    s.search(20);

    s.deleteBeg();
    cout << "After deleting start: ";
    s.display();

    s.deleteEnd();
    cout << "After deleting end: ";
    s.display();

    s.deletePos(2);
    cout << "After deleting position 2: ";
    s.display();


    cout << endl << "DOUBLY LINKED LIST" << endl;

    DL d;

    d.insertEnd(10);
    d.insertEnd(20);
    d.insertEnd(30);
    d.insertEnd(40);

    cout << "Forward: ";
    d.displayForward();

    cout << "Backward: ";
    d.displayBackward();


    cout << endl << "CIRCULAR LINKED LIST" << endl;

    CL c;

    c.insertEnd(10);
    c.insertEnd(20);
    c.insertEnd(30);
    c.insertBeg(5);
    c.insertPos(15, 3);

    cout << "List: ";
    c.display();

    cout << "Search 20: ";
    c.search(20);

    c.deleteNode(2);
    cout << "After deletion: ";
    c.display();

    cout << "Reverse: ";
    c.reverse();

    return 0;
}