#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void reverseDoublyLinkedList(Node*& head) {
    Node* curr = head;
    Node* temp = NULL;
    
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    
    if (temp != NULL) {
        head = temp->prev;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, NULL, NULL};
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

int main() {
    system("cls");
    Node* head = NULL;
    
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    
    cout << "Original List: ";
    print(head);
    
    reverseDoublyLinkedList(head);
    
    cout << "Reversed List: ";
    print(head);
    
    return 0;
}

// stl- standard template libraries