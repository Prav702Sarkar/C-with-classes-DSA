#include <iostream>
#include <climits>
using namespace std;

class Stack {
    int top;
    int capacity;
    int *stack;
    
public:
    Stack(int capacity) {  // Fixed constructor name
        this->top = -1;
        this->capacity = capacity;
        this->stack = new int[capacity];
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int data) {
        if (isFull()) {
            cout << "\nStack overflow";
            return; // Prevent pushing when full
        }
        top++;
        stack[top] = data;
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack underflow";
            return; // Prevent decrementing when empty
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "\nStack underflow";
            return INT_MAX;
        }
        return stack[top];  // Fixed missing return
    }

    void print() {
        cout << "Elements are: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
    }

};

int main() {
    Stack s(5); // Create stack of size 5
    
    cout << "\nChecking isEmpty(): " << (s.isEmpty() ? "Stack is empty" : "Stack is not empty");

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    cout << "\nAfter pushing elements:";
    s.print();
    
    cout << "\nTrying to push 60 (should show Overflow message)";
    s.push(60); // Overflow test
    
    cout << "\nChecking peek(): Top element is " << s.peek();
    
    s.pop();
    cout << "\nAfter popping one element:";
    s.print();
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
    cout << "\nAfter popping all elements:";
    s.print();

    cout << "\nTrying to pop from empty stack (should show Underflow message)";
    s.pop(); // Underflow test

    cout << "\nChecking isEmpty(): " << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;

}
