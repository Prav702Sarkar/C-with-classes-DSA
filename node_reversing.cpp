#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class linkedlist {
public:
    node *head;
    node *tail;

    linkedlist() {
        head = NULL;
        tail = NULL;
    }


    void insertAtbeginning(int value) {
        node *newNode = new node(value);
        if (head == NULL) {
            head = tail = newNode; 
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void printF() {
        node *temp = head;
        cout << "\nForward: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void printB() {
        node *temp = tail;
        cout << "\nBackward: ";
        while (temp != NULL) {
            cout << temp->data << " <- ";
            temp = temp->prev;
        }
        cout << "NULL";
    }
};

int main() {
    system("cls");
    linkedlist l1;
    l1.insertAtbeginning(10);
    l1.insertAtbeginning(20);
    l1.insertAtbeginning(30);

    l1.printF();
    l1.printB();
    
    return 0;
}
