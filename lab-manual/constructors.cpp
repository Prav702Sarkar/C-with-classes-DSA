#include <iostream>
using namespace std;

class Value{
    private:
    int value;

    public:
    Value(int val){
        value = val;
        cout<<"Constructor called! Value initialized to "<<value<<endl;
    }

    void display() const{
        cout<<"Value is: "<<value<<endl;
    }
};

int main(){
    Value obj(23);
    obj.display();
    return 0;
}