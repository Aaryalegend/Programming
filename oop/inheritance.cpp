#include<iostream>
using namespace std;

class Vehicle {

    public:
    int model;
    int year;
    string brand;

    int getYear() {
        return this->year;
    }
    void setYear(int year) {
        this->year = year;
    }   
};

class Car : public Vehicle {
    public:
    string color;

    void ignition() {
        cout << "Car is starting" << endl;
    }

};


int  main() {
    Car obj1;
    cout<<obj1.model<<endl;
    obj1.ignition();
    obj1.setYear(2020);
    cout<<obj1.getYear()<<endl;
}