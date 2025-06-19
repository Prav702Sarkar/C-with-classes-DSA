#include <iostream>
#include <climits>
using namespace std;

class Queue {
    int front, rear;
    int capacity;
    int* queue;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        front = rear = -1;
        queue = new int[capacity];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MAX;
        }
        return queue[front];
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.dequeue();
    q.print();
    cout << "Front: " << q.Front() << endl;
    return 0;
}
