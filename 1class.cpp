#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class student
{
private:
    string name;
    int id;
    long long sid;

public:
    student()
    {
        cout << this->name << "'s constructor called" << endl;
    }
    student(string name, int id, long long sid)
    {
        this->name = name;
        this->id = id;
        this->sid = sid;
        cout << this->name << "'s constructor called" << endl;
    }
    student(student &obj) // COPY Constructor - passing by reference - &obj
    {
        this->name = obj.name;
        this->id = obj.id;
        this->sid = obj.sid;
        cout << this->name << "'s copy constructor called" << endl;
    }
    void getdata()
    {
        cout << this->name << ", " << this->id << ", " << this->sid << "\n";
    }
    ~student()
    {
        cout << this->name << "'s destructor called" << endl;
    }
};

int main()
{
    student a("rohan", 55, 123321);
    a.getdata();
    student *b = new student("baloo", 12, 142324);
    b->getdata(); // pointer
    // b is a pointer - does NOT get auto-destroyed
    delete (b); // DYNAMIC Allocation - Delete yourself
}