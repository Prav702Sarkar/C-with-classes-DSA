#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    Node *head;  

public:
    Stack() { head = NULL; }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    s.print();
    
    cout << "Top element: " << s.top() << endl;
    
    s.pop();
    s.print();

    cout << "Top element: " << s.top() << endl;
    
    return 0;
}
