#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
public:
    Node* head;

    DLL() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void deletionAtBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deletionAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void insertBeforeValue(int target, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Target value not found\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = newNode;
        else
            head = newNode;

        temp->prev = newNode;
    }

    void deleteBeforeValue(int target) {
        Node* temp = head;

        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp == NULL || temp->prev == NULL) {
            cout << "No node exists before the target\n";
            return;
        }

        Node* delNode = temp->prev;

        if (delNode->prev != NULL) {
            delNode->prev->next = temp;
            temp->prev = delNode->prev;
        } else {
            head = temp;
            temp->prev = NULL;
        }

        delete delNode;
    }

    void insertAfterValue(int target, int value) {
        Node* temp = head;

        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Target value not found\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void deleteAfterValue(int target) {
        Node* temp = head;

        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Target value not found or no node exists after it\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;

        if (delNode->next != NULL)
            delNode->next->prev = temp;

        delete delNode;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DLL l;
    l.insertAtBeginning(10);
    l.insertAtBeginning(20);
    l.insertAtBeginning(30);
    l.insertAtBeginning(40);
    l.print();

    l.insertAtEnd(15);
    l.print();

    // l.deletionAtBeginning();
    // l.deletionAtEnd();
    // l.insertBeforeValue(20, 15);
    // l.deleteBeforeValue(20);
    // l.insertAfterValue(10, 35);
    // l.deleteAfterValue(10);

    return 0;
}
