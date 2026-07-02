#if !defined(BIRD_H)
#define BIRD_H

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Bird {
public:
    string name;
    Bird() {
        this->name = "Unknown Bird";
        cout << "Default constructor called" << "\n";
    }

    Bird(string name) {
        this->name = name;
        cout << this->name << "'s constructor called" << "\n";
    }

    virtual ~Bird() {
        cout << this->name << "'s destructor called" << "\n";
    }

    virtual void eat() {
        cout << "bird eats" << "\n";
    }

    virtual void fly() {
        cout << "bird flies" << "\n";
    }
};

class Sparrow : public Bird {
public:
    void eat() override {
        cout << "sparrow eats" << "\n";
    }
    void fly() override {
        cout << "sparrow flies" << "\n";
    }
};

class Eagle : public Bird { // Wait, double public is a typo, let's use single public
public:
    void eat() override {
        cout << "eagle eats" << "\n";
    }
    void fly() override {
        cout << "eagle flies" << "\n";
    }
};

class Peacock : public Bird {
public:
    void eat() override {
        cout << "peacock eats" << "\n";
    }
    void fly() override {
        cout << "peacock flies" << "\n";
    }
};

#endif
