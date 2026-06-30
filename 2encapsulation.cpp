#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class student
{
public:
    string name;
    int roll;
    long long sid;

private:
    int age;

public:
    student()
    {
        cout << this->name << "'s constructor called" << endl;
    }
    student(string name, int roll, long long sid, int age)
    {
        this->name = name;
        this->roll = roll;
        this->sid = sid;
        this->age = age;
        cout << this->name << "'s constructor called" << endl;
    }
    student(student &obj) // COPY Constructor - passing by reference - &obj
    {
        this->name = obj.name;
        this->roll = obj.roll;
        this->sid = obj.sid;
        cout << this->name << "'s copy constructor called" << endl;
    }
    void getdata()
    {
        cout << this->name << ", " << this->roll << ", " << this->sid << "\n";
    }
    ~student()
    {
        cout << this->name << "'s destructor called" << endl;
    }

    int getage()
    {
        return this->age;
    }

    void setage(int age)
    {
        if (age > 0 && age <= 100)
            this->age = age;
        else
        {
            cout << "Invalid age " << age << " \n";
        }
    }
};

int main()
{
    student a("shubham", 53, 646565, 15);
    cout << a.getage() << endl;
    a.setage(200);
    cout << a.getage() << endl;
    // cout << a.age << endl;
}