#include <iostream>
using namespace std;

class DynamicArray{
private:
    int* data;
    int currentSize;
    int capacity;

public:
    DynamicArray(int size) : data(new int[size]), currentSize(0), capacity(size) {}

    ~DynamicArray(){ 
        delete[] data; 
    }

    bool isFull() const{
        return currentSize == capacity;
    }
    bool isEmpty() const{
        return currentSize == 0;
    }

    void insertAtStart(int element){
        if (isFull()) return;
        for (int i = currentSize; i > 0; i--){
            data[i] = data[i-1];
        }
        data[0] = element;
        currentSize++;
    }

    void insertAtEnd(int element){
        if (isFull()) return;
        data[currentSize++] = element;
    }

    void insertAtPosition(int index, int element){
        if (isFull() || index < 0 || index > currentSize) return;
        for (int i = currentSize; i > index; i--){
            data[i] = data[i-1];
        }
        data[index] = element;
        currentSize++;
    }

    void deleteAtStart(){
        if (isEmpty()) return;
        for (int i = 0; i < currentSize - 1; i++){
            data[i] = data[i+1];
        }
        currentSize--;
    }

    void deleteAtEnd(){
        if (isEmpty()) return;
        currentSize--;
    }

    void deleteAtPosition(int index){
        if (isEmpty() || index < 0 || index >= currentSize) return;
        for (int i = index; i < currentSize - 1; i++){
            data[i] = data[i+1];
        }
        currentSize--;
    }

    void display() const{
        if (isEmpty()){
            cout << "Array is empty." << endl;
            return;
        }
        for (int i = 0; i < currentSize; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;
    DynamicArray array(size);

    array.insertAtStart(10);
    array.insertAtStart(20);
    array.insertAtStart(30);
    array.insertAtEnd(100);

    cout << "Array after insertions: ";
    array.display();

    array.deleteAtEnd();
    array.deleteAtStart();
    array.deleteAtPosition(0);

    cout << "Array after deletions: ";
    array.display();

    return 0;
}
