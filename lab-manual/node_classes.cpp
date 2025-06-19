#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int val, int position) {
        Node* newNode = new Node(val);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp && i < position - 1; i++) {
            temp = temp->next;
        }
        if (!temp) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBeforeNode(int val, int key) {
        Node* newNode = new Node(val);
        if (!head) return;
        if (head->data == key) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }
        if (!temp->next) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfterNode(int val, int key) {
        Node* newNode = new Node(val);
        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }
        if (!temp) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPosition(15, 1);
    list.insertBeforeNode(5, 10);
    list.insertAfterNode(25, 20);

    list.printList();

    return 0;
}