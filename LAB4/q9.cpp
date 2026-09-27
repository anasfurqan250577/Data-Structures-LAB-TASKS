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
            cout << "List is empty" << endl;
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

    void search(int val){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        int pos = 1;

        do{
            if(temp->data == val){
                cout << "Value found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }while(temp != head);

        cout << "Value not found" << endl;
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

        cout << endl;
    }
};

int main(){
    CL c;

    int choice, val, pos;

    do{
        cout << "\n1. Insert at End";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at Position";
        cout << "\n4. Delete Node";
        cout << "\n5. Search";
        cout << "\n6. Display";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter value: ";
                cin >> val;
                c.insertEnd(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                c.insertBeg(val);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                c.insertPos(val, pos);
                break;

            case 4:
                cout << "Enter position: ";
                cin >> pos;
                c.deleteNode(pos);
                break;

            case 5:
                cout << "Enter value: ";
                cin >> val;
                c.search(val);
                break;

            case 6:
                c.display();
                break;

            case 7:
                cout << "Program ended";
                break;

            default:
                cout << "Invalid choice";
        }

    }while(choice != 7);
}