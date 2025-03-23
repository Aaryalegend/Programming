#include<iostream>
using namespace std;

class A {
    public:
    void sayHello() {
        cout << "Hello from A" << endl;
    }
    void sayHello(string name) {
        cout << "Hello from " << name << endl;
    }
    void sayHello(int a, int b) {
        cout<< a + b <<endl;
    }
    int sayHello(double a, double b) {
        cout<< a + b << endl;
        return 1;
    }
};

class B {
    public:
    int a;
    int b;

    public:
    int add() {
        return a + b;
    }

    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout<< "output " << value1 + value2 <<endl;
    }
};

int main() {
    // A obj;
    // obj.sayHello("Aryan");
    // obj.sayHello(9, 9);
    // obj.sayHello(9.0, 9.0);

    B obj1, obj2;
    obj1.a = 9;
    obj2.a = 9;
    obj1 + obj2;
    return 0;
}