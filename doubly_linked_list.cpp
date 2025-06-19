#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *pre;
    node *next;

    node(int data) {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

class DLL {
public:
    node *head;
    node *tail;

    DLL() {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int value) {
        node *newnode = new node(value);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        newnode->next = head;
        head->pre = newnode;
        head = newnode;
    }

    void insertAtEnd(int value) {
        node *newnode = new node(value);
        if (tail == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
    }

    void deleteAtBeginning() {
        if (head == NULL) return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        node *temp = head;
        head = head->next;
        head->pre = NULL;
        delete temp;
    }

    void deleteAtEnd() {
        if (tail == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        node *temp = tail;
        tail = tail->pre;
        tail->next = NULL;
        delete temp;
    }

    void printF() {
        node *temp = head;
        cout << "Forward: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void printB() {
        node *temp = tail;
        cout << "Backward: ";
        while (temp != NULL) {
            cout << temp->data << " <- ";
            temp = temp->pre;
        }
        cout << "NULL\n";
    }
};

int main() {
    system("CLS");
    DLL l;
    l.insertAtBeginning(10);
    l.insertAtEnd(20);
    l.insertAtEnd(-1);
    
    l.printF();
    l.printB();

    l.deleteAtBeginning();
    l.deleteAtEnd();
    
    l.printF();
    l.printB();
    
    return 0;
}


// void insertAftergivenNode(int value, int data){
//     node* temp=head;
//     while (head!=NULL && temp+data!=value){
//     }

//     if (temp==NULL){
//         Node* copy = temp->next;
//         temp->next=newnode;
//         newNode->next = copy;
//     }
// }