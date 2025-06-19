#include <iostream>
#include <climits>
using namespace std;

int arr[5];
int size = 5;
int top = -1;

bool isFull() {
    return top == size - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        cout << "Stack is full." << endl;
        return;
    }
    top++;
    arr[top] = data;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    top--;
}

int Top() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return INT_MIN;
    }
    return arr[top];
}

void print(){
    cout<<"Stack elements: ";
    for(int i=0; i<=top; i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    system("cls");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    print();
    cout << "\nTop element: " << Top() << endl;
    
    pop();
    cout << "Top element after pop: " << Top() << endl;
    print();

    return 0;
}
