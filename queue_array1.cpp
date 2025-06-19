#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << element << endl;
            return;
        }
        
        rear = (rear + 1) % capacity;
        arr[rear] = element;
        count++;
        cout << element << " enqueued to queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
            return -1;
        }
        
        int element = arr[front];
        front = (front + 1) % capacity;
        count--;
        return element;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == capacity);
    }

    int size() {
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        int i, index;
        for (i = 0; i < count; i++) {
            index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.display();
    cout << "Front element: " << queue.peek() << endl;
    cout << "Queue size: " << queue.size() << endl;
    return 0;
}
