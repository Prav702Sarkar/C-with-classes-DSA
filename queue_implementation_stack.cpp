#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;
    string stackName;
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
    Stack(int cap, const string& name = "Stack", bool verboseMode = true) 
        : capacity(cap), stackName(name), verbose(verboseMode) {
        validateCapacity(cap);
        arr = new T[capacity];
        top = -1;
        if (verbose) {
            cout << stackName << " created with capacity " << capacity << ".\n";
        }
    }

    // Copy constructor
    Stack(const Stack& other) 
        : capacity(other.capacity), top(other.top), 
          stackName(other.stackName + "_copy"), verbose(other.verbose) {
        arr = new T[capacity];
        for (int i = 0; i <= top; ++i) {
            arr[i] = other.arr[i];
        }
        if (verbose) {
            cout << stackName << " created as copy of " << other.stackName << ".\n";
        }
    }

    // Destructor
    ~Stack() {
        delete[] arr;
        if (verbose) {
            cout << stackName << " destroyed.\n";
        }
    }

    // Assignment operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            top = other.top;
            stackName = other.stackName + "_assigned";
            verbose = other.verbose;
            
            arr = new T[capacity];
            for (int i = 0; i <= top; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    bool isFull() const { return top == capacity - 1; }
    bool isEmpty() const { return top == -1; }
    int getSize() const { return top + 1; }
    int getCapacity() const { return capacity; }
    const string& getName() const { return stackName; }
    void setVerbose(bool mode) { verbose = mode; }
    bool getVerbose() const { return verbose; }

    void push(T value) {
        if (isFull()) {
            throw overflow_error(stackName + " overflow - cannot push");
        }
        arr[++top] = value;
        
        if (verbose) {
            cout << "↑ " << stackName << ": " << value << " pushed.\n";
        }
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error(stackName + " underflow - cannot pop");
        }
        T value = arr[top--];
        
        if (verbose) {
            cout << "↓ " << stackName << ": " << value << " popped.\n";
        }
        
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw underflow_error(stackName + " is empty - nothing to peek");
        }
        return arr[top];
    }

    void clear() {
        top = -1;
        if (verbose) {
            cout << stackName << " cleared.\n";
        }
    }

    void display(bool detailed = false) const {
        cout << "\n=== " << stackName << " ===\n";
        cout << "Capacity: " << capacity << " | Size: " << getSize() << "\n";
        cout << "Top position: " << (isEmpty() ? "N/A" : to_string(top)) << "\n";
        cout << "Empty: " << (isEmpty() ? "Yes" : "No") 
             << " | Full: " << (isFull() ? "Yes" : "No") << "\n";

        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Elements (top to bottom): [ ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i];
            if (i > 0) cout << ", ";
        }
        cout << " ]\n";

        if (detailed) {
            cout << "\nDetailed Layout:\n";
            int cellWidth = 5;
            for (int i = capacity - 1; i >= 0; i--) {
                if (i == top) {
                    cout << setw(cellWidth) << "[T]";
                } else {
                    cout << setw(cellWidth) << "[" << i << "]";
                }
            }
            cout << "\n";

            for (int i = capacity - 1; i >= 0; i--) {
                if (i <= top) {
                    cout << setw(cellWidth) << arr[i];
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
        
        T* newArr = new T[newCapacity];
        int newTop = min(top, newCapacity - 1);
        
        for (int i = 0; i <= newTop; ++i) {
            newArr[i] = arr[i];
        }
        
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        top = newTop;
        
        if (verbose) {
            cout << stackName << " resized to capacity " << capacity << ".\n";
        }
    }

    string toString() const {
        ostringstream oss;
        oss << stackName << " [Size: " << getSize() << "/" << capacity << "]";
        if (!isEmpty()) {
            oss << " Top: " << peek();
        }
        return oss.str();
    }
};

void displayMainMenu() {
    cout << "\n===== Stack System =====\n";
    cout << "1. Create a new stack\n";
    cout << "2. Push element\n";
    cout << "3. Pop element\n";
    cout << "4. Display stack\n";
    cout << "5. Stack information\n";
    cout << "6. Resize stack\n";
    cout << "7. Clear stack\n";
    cout << "8. Toggle verbose mode\n";
    cout << "9. Exit\n";
    cout << "========================\n";
    cout << "Enter your choice (1-9): ";
}

void displayStackInfoMenu() {
    cout << "\n===== Stack Information Options =====\n";
    cout << "1. Basic status\n";
    cout << "2. Detailed display\n";
    cout << "3. Peek top element\n";
    cout << "4. Back to main menu\n";
    cout << "====================================\n";
    cout << "Enter your choice (1-4): ";
}

template <typename T>
void handleStackOperations(Stack<T>& stack) {
    int choice;
    bool running = true;
    
    while (running) {
        displayMainMenu();
        cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    cout << "Returning to stack creation...\n";
                    running = false;
                    break;
                }
                case 2: {
                    T value;
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack.push(value);
                    break;
                }
                case 3: {
                    T val = stack.pop();
                    cout << "Popped value: " << val << "\n";
                    break;
                }
                case 4: {
                    stack.display(true);
                    break;
                }
                case 5: {
                    int subChoice;
                    do {
                        displayStackInfoMenu();
                        cin >> subChoice;
                        
                        switch (subChoice) {
                            case 1:
                                stack.display(false);
                                break;
                            case 2:
                                stack.display(true);
                                break;
                            case 3:
                                cout << "Top element: " << stack.peek() << "\n";
                                break;
                            case 4:
                                cout << "Returning to main menu...\n";
                                break;
                            default:
                                cout << "Invalid choice! Please try again.\n";
                        }
                    } while (subChoice != 4);
                    break;
                }
                case 6: {
                    int newCapacity;
                    cout << "Enter new capacity: ";
                    cin >> newCapacity;
                    stack.resize(newCapacity);
                    break;
                }
                case 7: {
                    stack.clear();
                    cout << "Stack cleared.\n";
                    break;
                }
                case 8: {
                    bool current = stack.getVerbose();
                    stack.setVerbose(!current);
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
    cout << "===== Enhanced Stack System =====\n";
    
    int capacity;
    string stackName;
    bool verbose = true;
    
    cout << "Enter stack name: ";
    getline(cin, stackName);
    
    while (true) {
        cout << "Enter stack capacity: ";
        cin >> capacity;
        
        try {
            Stack<int> stack(capacity, stackName, verbose);
            cout << "Stack created: " << stack.toString() << "\n";
            handleStackOperations(stack);
            break;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    return 0;
}