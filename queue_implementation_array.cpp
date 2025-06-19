#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

template <typename T>
class CircularQueue {
private:
    T* queue;
    int front, rear, size, capacity;
    string queueName;
    bool verbose;

    void validateCapacity(int cap) const {
        if (cap <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
        if (cap > 10000) {
            throw invalid_argument("Capacity too large (max 10000)");
        }
    }

public:
    // Constructor
    CircularQueue(int cap, const string& name = "CircularQueue", bool verboseMode = true) 
        : capacity(cap), queueName(name), verbose(verboseMode) {
        validateCapacity(cap);
        queue = new T[capacity];
        front = rear = -1;
        size = 0;
        if (verbose) {
            cout << queueName << " created with capacity " << capacity << ".\n";
        }
    }

    // Copy constructor
    CircularQueue(const CircularQueue& other) 
        : capacity(other.capacity), front(other.front), rear(other.rear), 
          size(other.size), queueName(other.queueName + "_copy"), verbose(other.verbose) {
        queue = new T[capacity];
        for (int i = 0; i < capacity; ++i) {
            queue[i] = other.queue[i];
        }
        if (verbose) {
            cout << queueName << " created as copy of " << other.queueName << ".\n";
        }
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
        if (verbose) {
            cout << queueName << " destroyed.\n";
        }
    }

    // Assignment operator
    CircularQueue& operator=(const CircularQueue& other) {
        if (this != &other) {
            delete[] queue;
            capacity = other.capacity;
            front = other.front;
            rear = other.rear;
            size = other.size;
            queueName = other.queueName + "_assigned";
            verbose = other.verbose;
            
            queue = new T[capacity];
            for (int i = 0; i < capacity; ++i) {
                queue[i] = other.queue[i];
            }
        }
        return *this;
    }

    bool isFull() const { return size == capacity; }
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    const string& getName() const { return queueName; }
    void setVerbose(bool mode) { verbose = mode; }

    void enqueue(T value) {
        if (isFull()) {
            throw overflow_error(queueName + " overflow - cannot enqueue");
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        
        if (verbose) {
            cout << "--> " << queueName << ": " << value << " enqueued.\n";
        }
    }

    T dequeue() {
        if (isEmpty()) {
            throw underflow_error(queueName + " underflow - cannot dequeue");
        }

        T removedValue = queue[front];
        front = (front + 1) % capacity;
        size--;

        if (isEmpty()) {
            front = rear = -1;
        }

        if (verbose) {
            cout << "<-- " << queueName << ": " << removedValue << " dequeued.\n";
        }
        
        return removedValue;
    }

    T peekFront() const {
        if (isEmpty()) {
            throw underflow_error(queueName + " is empty - nothing to peek");
        }
        return queue[front];
    }

    T peekRear() const {
        if (isEmpty()) {
            throw underflow_error(queueName + " is empty - nothing to peek");
        }
        return queue[rear];
    }

    void clear() {
        front = rear = -1;
        size = 0;
        if (verbose) {
            cout << queueName << " cleared.\n";
        }
    }

    void display(bool detailed = false) const {
        cout << "\n=== " << queueName << " ===\n";
        cout << "Capacity: " << capacity << " | Size: " << size << "\n";
        cout << "Front: " << (front == -1 ? "N/A" : to_string(front)) 
             << " | Rear: " << (rear == -1 ? "N/A" : to_string(rear)) << "\n";
        cout << "Empty: " << (isEmpty() ? "Yes" : "No") 
             << " | Full: " << (isFull() ? "Yes" : "No") << "\n";

        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Elements: [ ";
        for (int i = 0; i < size; ++i) {
            int index = (front + i) % capacity;
            cout << queue[index];
            if (i < size - 1) cout << ", ";
        }
        cout << " ]\n";

        if (detailed) {
            cout << "\nDetailed Layout:\n";
            int cellWidth = 5;
            for (int i = 0; i < capacity; i++) {
                if (i == front && i == rear) {
                    cout << setw(cellWidth) << "[F/R]";
                } else if (i == front) {
                    cout << setw(cellWidth) << "[F]";
                } else if (i == rear) {
                    cout << setw(cellWidth) << "[R]";
                } else {
                    cout << setw(cellWidth) << "[" << i << "]";
                }
            }
            cout << "\n";

            for (int i = 0; i < capacity; i++) {
                if ((front <= rear && i >= front && i <= rear) || 
                    (front > rear && (i >= front || i <= rear))) {
                    cout << setw(cellWidth) << queue[i];
                } else {
                    cout << setw(cellWidth) << "X";
                }
            }
            cout << "\n";
        }
    }

    void resize(int newCapacity) {
        validateCapacity(newCapacity);
        
        if (newCapacity == capacity) return;
        
        T* newQueue = new T[newCapacity];
        int newSize = min(size, newCapacity);
        
        for (int i = 0; i < newSize; ++i) {
            int index = (front + i) % capacity;
            newQueue[i] = queue[index];
        }
        
        delete[] queue;
        queue = newQueue;
        capacity = newCapacity;
        size = newSize;
        front = newSize > 0 ? 0 : -1;
        rear = newSize > 0 ? newSize - 1 : -1;
        
        if (verbose) {
            cout << queueName << " resized to capacity " << capacity << ".\n";
        }
    }

    string toString() const {
        ostringstream oss;
        oss << queueName << " [Size: " << size << "/" << capacity << "]";
        if (!isEmpty()) {
            oss << " Front: " << peekFront() << ", Rear: " << peekRear();
        }
        return oss.str();
    }
};

void displayMainMenu() {
    cout << "\n===== Circular Queue System =====\n";
    cout << "1. Create a new queue\n";
    cout << "2. Enqueue element\n";
    cout << "3. Dequeue element\n";
    cout << "4. Display queue\n";
    cout << "5. Queue information\n";
    cout << "6. Resize queue\n";
    cout << "7. Clear queue\n";
    cout << "8. Toggle verbose mode\n";
    cout << "9. Exit\n";
    cout << "================================\n";
    cout << "Enter your choice (1-9): ";
}

void displayQueueInfoMenu() {
    cout << "\n===== Queue Information Options =====\n";
    cout << "1. Basic status\n";
    cout << "2. Detailed display\n";
    cout << "3. Peek front element\n";
    cout << "4. Peek rear element\n";
    cout << "5. Back to main menu\n";
    cout << "====================================\n";
    cout << "Enter your choice (1-5): ";
}

template <typename T>
void handleQueueOperations(CircularQueue<T>& cq) {
    int choice;
    bool running = true;
    
    while (running) {
        displayMainMenu();
        cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    // This would actually create a new queue, but we'll handle it in main
                    cout << "Returning to queue creation...\n";
                    running = false;
                    break;
                }
                case 2: {
                    T value;
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    cq.enqueue(value);
                    break;
                }
                case 3: {
                    T val = cq.dequeue();
                    cout << "Dequeued value: " << val << "\n";
                    break;
                }
                case 4: {
                    cq.display(true);
                    break;
                }
                case 5: {
                    int subChoice;
                    do {
                        displayQueueInfoMenu();
                        cin >> subChoice;
                        
                        switch (subChoice) {
                            case 1:
                                cq.display(false);
                                break;
                            case 2:
                                cq.display(true);
                                break;
                            case 3:
                                cout << "Front element: " << cq.peekFront() << "\n";
                                break;
                            case 4:
                                cout << "Rear element: " << cq.peekRear() << "\n";
                                break;
                            case 5:
                                cout << "Returning to main menu...\n";
                                break;
                            default:
                                cout << "Invalid choice! Please try again.\n";
                        }
                    } while (subChoice != 5);
                    break;
                }
                case 6: {
                    int newCapacity;
                    cout << "Enter new capacity: ";
                    cin >> newCapacity;
                    cq.resize(newCapacity);
                    break;
                }
                case 7: {
                    cq.clear();
                    cout << "Queue cleared.\n";
                    break;
                }
                case 8: {
                    bool current = cq.getVerbose();
                    cq.setVerbose(!current);
                    cout << "Verbose mode " << (!current ? "enabled" : "disabled") << ".\n";
                    break;
                }
                case 9: {
                    cout << "Exiting program.\n";
                    return;
                }
                default: {
                    cout << "Invalid choice! Please enter a number between 1 and 9.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }
}

int main() {
    system("cls");
    cout << "===== Enhanced Circular Queue System =====\n";
    
    int capacity;
    string queueName;
    bool verbose = true;
    
    cout << "Enter queue name: ";
    getline(cin, queueName);
    
    while (true) {
        cout << "Enter queue capacity: ";
        cin >> capacity;
        
        try {
            CircularQueue<int> cq(capacity, queueName, verbose);
            cout << "Queue created: " << cq.toString() << "\n";
            handleQueueOperations(cq);
            break;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    return 0;
}