#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class SLL{
    public:
    Node* head;

    SLL(){
        head=NULL;
    }

    void insertAtBeginning(int value){
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }

    void deletionAtBeginning(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void insertAtEnd(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=newNode;
            return;
        }

        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void deletionAtEnd(){
        if(head==NULL){
            cout<<"List is empty";
            return;
        }

        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }

        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }

        delete temp->next;
        temp->next=NULL;
    }

    void insertBeforeValue(int target,int value){
        Node* newNode=new Node(value);

        Node* temp=head;
        while(temp->next!=NULL && temp->next->data!=target){
            temp=temp->next;
        }

        if(temp->next==NULL){
            cout<<"Target value not found";
            delete newNode;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void deleteBeforeValue(int target) {

    Node* curr = head;
    Node* temp = head->next;

    while (temp->next != NULL && temp->next->data != target) {
        curr = temp;
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Target value not found\n";
        return;
    }

    curr->next = temp->next;
    delete temp;
}


void insertAfterValue(int target, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Target value not found\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAfterValue(int target) {
    Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Target value not found or no node exists after it\n";
        return;
    }

    Node* tempNode = temp->next;
    temp->next = tempNode->next;
    delete tempNode;
}

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    system("cls");
    SLL l;
    l.insertAtBeginning(10);
    l.insertAtBeginning(20);
    l.insertAtBeginning(30);
    l.insertAtBeginning(40);
    l.print();

    // l.deletionAtBeginning();
    l.insertAtEnd(15);
    l.print();

    // l.deletionAtEnd();
    // l.print();

    // l.insertBeforeValue(20, 15);
    // l.print();
    // l.deleteBeforeValue(20);
    // l.print();

    // l.insertAfterValue(10, 35);
    // l.print();
    // l.deleteAfterValue(10);
    // l.print();
    return 0;
}