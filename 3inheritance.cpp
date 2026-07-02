#include <iostream>
#include <string>
using namespace std;

class vehicle
{
private:
    int wheels;

protected:
    string color;

public:
    string brand;

    vehicle(string color, string brand) {
        this->color=color;
        this->brand=brand;
        cout << "constructor for vehicle" << endl;
    }

    void startEngine() {
        cout << "Engine Started of brand: " << this->brand << "\n";
    }

    ~vehicle() {
        cout << "destructor for vehicle" << endl;
    }
};

class car : public vehicle
{
public:
    int nDoors;
    string transmission;

    car(int nDoors, string transmission, string brand, string color) : vehicle (color, brand) {
        this->nDoors = nDoors;
        this->transmission = transmission;
        cout << "constructor for car" << endl;
    }
    void getCarData() {
        cout << "Enter number of doors: " << this->nDoors << endl;
        cout << "Enter transmission type: " << this->transmission << endl;
        // cout << "wheels: " << wheels << endl; // invalid - private
        cout << "color: " << color << endl; // valid - protected
        cout << "brand: " << brand << endl; // valid - public
    }

    void startCar() {
        this->startEngine();
    }

    ~car() {
        cout << "destructor for car" << endl;
    }
};

int main() {
    car c(2, "Manual", "Mercedes", "Black");
    c.getCarData();
    c.startCar();
}