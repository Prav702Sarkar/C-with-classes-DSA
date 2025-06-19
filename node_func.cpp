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

        void insertAtBeginning(int data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        void insertAfterGivenNode(int value, int data) {
            Node* temp = head;

            while (temp != NULL && temp->data != value) {
                temp = temp->next;
            }

            if (temp != NULL) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                cout << "Given node not found!" << endl;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    cout << "Original List: ";
    list.printList();

    list.insertAfterGivenNode(20, 30);

    cout << "List After insertion: ";
    list.printList();

    return 0;
}
