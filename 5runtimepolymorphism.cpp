#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "Shape Constructor called" << endl;
    }
    // Base class destructor must be virtual to ensure proper cleanup of derived objects
    virtual ~Shape() {
        cout << "Shape Destructor called" << endl;
    }
    virtual void draw() {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    Circle() {
        cout << "Circle Constructor called" << endl;
    }
    ~Circle() {
        cout << "Circle Destructor called" << endl;
    }
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Triangle : public Shape {
public:
    Triangle() {
        cout << "Triangle Constructor called" << endl;
    }
    ~Triangle() {
        cout << "Triangle Destructor called" << endl;
    }
    void draw() override {
        cout << "Drawing Triangle" << endl;
    }
};

int main() {
    // Correct Upcasting for Runtime Polymorphism: Base class pointer pointing to Derived class object
    Shape *s = new Triangle();
    
    // Calls the overridden draw() in Triangle at runtime (Late Binding)
    s->draw();
    
    // Calls virtual destructor starting from Triangle (~Triangle then ~Shape)
    delete s;
    
    // can convert from derived to base
    // CANNOT convert from base to derived directly
    // Triangle *t = new Shape(); // error 

    // Jugaad-approach
    Shape *s2 = new Triangle();
    Triangle *t2 = (Triangle*)s2;
    t2->draw();
    delete(t2);

    Shape *s3 = new Circle();
    Circle *c3 = (Circle*)s3;
    c3->draw();
    delete(c3);

    return 0;
}