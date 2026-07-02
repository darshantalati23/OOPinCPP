# OOP in CPP

## Class and Objects

```cpp
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
    void getdata()
    {
        cout << this->name << ", " << this->id << ", " << this->sid << "\n";
    }
    ~student()
    {
        cout << this->name << "'s destructor called" << endl;
    }
};
```

### Static Allocation

`student a("rohan", 55, 123321);`
No `new` keyword used - stored statically as **object**.

Stores all the info automatically using **Parameterised** _constructor_.
**STATIC ALLOCATION -> auto-destroyed**

### Dynamic Allocation

`student *b = new student("baloo", 12, 142324);`
Stored dynamically as **pointer**.

`delete(b);` **MUST** be called manually - else Memory leak happens.
**DYNAMIC ALLOCATION -> call destructor manually**

## Encapsulation (Data Hiding)

### Theory

- Binds data and methods in class
- Functions:
  - Providex secure layer
  - Hides internal implementation of code and data in class
  - Exposes only necessary information to external world
- Prevent unauth access/modificaton of original contents of class by instances (objects)
- Prevent exposure of underlying algorithms (working details) of data members to outer world (many times: `int main()`)

### Access Modifiers

**Default**: _`private`_

**Private**:

- Access from same class ONLY
- **Cannot** be accessed from Derived
- **Cannot** be accessed from `main()`

**Protected**:

- Access from same class
- Access from Derived
- **Cannot** be accessed from `main()`

**Public**:

- Access from same class
- Access from Derived
- Access from `main()`

![image](./assets/perfect_encapsulation.png)

## Inheritance

### Theory

- Child inherits attrivutes and behaviours from Parent
- Way to create _class_ from existing _class_
- _Derived/Child/Sub_ classinherits from _Base/Parent/Super_ class
- _Protected_ can be accessed by sub-classes
- Whenever we use derived class:
  - Base Class Constructor
  - Derived Class Constructor

    ... _(Operations AND/OR ladder continuation)_

  - Derived Class Destructor
  - Base Class Destructor

### Access Specifier - Protected

![image](./assets/protected_members.png)

**Question:** What _scope_ of attributes of parents will be inherited to child class and with what _scope_?

![image](./assets/mode_of_inheritance.png)

### When to Use?

- **IS-A** relationship
- Hierarchical relationship
- Specialised-Generalized connection

### Types

C++ supports several types of inheritance:

- **Single Inheritance**: A derived class with only one base class.
- **Multiple Inheritance**: A derived class with multiple base classes.
- **Multilevel Inheritance**: A class derived from another derived class.
- **Hierarchical Inheritance**: Multiple classes derived from a single base class.
- **Hybrid Inheritance**: A combination of two or more types of inheritance.

![image](./assets/types_of_inheritance.png)

### Importance

- **Code Reusability**: Avoids redundancy by enabling child classes to reuse methods and properties of parent classes.
- **Extensibility**: Easy to extend existing code for new requirements.
- **Maintenance**: Simplified adjustments with changes concentrated in base classe

### Example

![image](./assets/inheritance_vehicle.png)

### Implementation Example

```cpp
class Base {
    int a;

    Base() {
        this->a = a;
        cout << "Base Constructor called" << endl;
    }
};

class Derived : accessSpecifier Base {
    int b;

    Derived(int a, int b) : Base(a) {
        this->b = b;
        cout << "Derived Constructor called" << endl;

    }
};
```

**Multiple Inheritance**

```cpp
// constructor
Derived(int a, int b, int c) : Base1(a), Base2(b) {
    this->a=a;
}
```

## Polymorphism

### Theory

- The ability to process objects differently depending on their data type or class is crucial for dynamic and flexible code.

### Types

1. _Compile Time Polymorphism (Static)_
2. _Run Time Polymorphism (Dynamic)_

### Compile Time Polymorphism (Static)

**Function Overloading**

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
    double add(double a, double b) {
        return a + b;
    }
};
```

**Operator Overloading**

_Syntax:_

```cpp
return_type operator<op>(args) {
    <!-- operation -->
    return <>
}
```

**Note:**

1. The function name **MUST** start with `operator`

2. We can override several operators including:
   - _Arithmetic Operators:_ `+`, `-`, `*`, `/`, `%`
   - _Relational Operators:_ `==`, `!=`, `<`, `>`, `<=`, `>=`
   - _Logical Operators:_ `&&`, `||`, `!`
   - _Bitwise Operators:_ `&`, `|`, `^`, `~`, `<<`, `>>`
   - _Assignment Operators:_ `=`, `+=`, `-=`, `*=`
   - _Increment/Decrement Operators:_ `++`, `--`
   - _Subscript Operator:_ `[]`
   - _Function call Operator:_ `()`
   - _Allocation Operators:_ `new`, `delete`
   - _Class Member Access Operators:_ `->`, `->*`
   - _Others:_ `,`

3. Cannot override these operators:
   - _Member Access Operators:_ `.` (dot), `.*` (dereference dot)
   - _SizeOf Operator:_ `sizeof`
   - _Ternary Operator:_ `?:`
   - _Scope Resolution Operator:_ `::`

_Example Code:_

```cpp
// Complex number addition
class Complex {
    int real, imag;
public:
    Complex(int real, int imag) {
        this->real = real;
        this->imag = imag;
    }
    Complex operator+(const &obj) {
        Complex temp;
        temp.real = this->real + obg.real;
        temp.imag = this->imag + obj.imaj;
        return temp;
    }
    void print() {
        cout << this->real << " + " << this->imag << "i" << endl;
    }
};
```

This will allow us to use the `+` operator as it is - but for objects of `class Complex`.

_Usage:_ `Complex c1(1, 2), c2(3, 4); Complex c3 = c1 + c2;`\
_Output_ (for `c3.print()`): `4 + 6i`

### Runtime Polymorphism (Dynamic)

1. **Function Overriding** makes it polymorphic
2. **Early v/s Late binding** - Early is by compiler, Late is during runtime
3. `Virtual` **Keyword** -> used in Base Class
4. `Override` **Keyword** -> used in Derived Class
5. **Upcasting/Downcasting** -> pointers/ref to base class pointing/referring to derived class objects
6. Without `virtual`, the method called in `Class1 *obj = new Class2()` will be always of `Class1` -> _left_ side.
7. `final` **Keyword** -> after using this along with virtual, further derived classes _CANNOT_ override the base method/class.

**IMPORTANT:** Refer the file - `5runtimepolymorphism.cpp`

## Abstraction

- Process of masking the complexity of a system by separating its functionalities into more understandable layers.
- Focusing on the most relevant aspects and ignoring the unneeded details -> better communication, understanding
- **Advantages**:
  - _Simplification_: Simplifies coding by reducing complexity.
  - _Reusability_: Promotes the creation of reusable code.
  - _Maintainability_: Enhances ease of maintenance and updates.
  - _Security_: Protects sensitive parts of the code from misuse.
- Many times, done using header files `<something>.h` or abstraction classes.

**Interface**:

- An interface defines a blueprint of methods that a class must implement.
- When atleast one pure virtual function is implemented within a class, it becomes interface.

**Important:** Refer - `6abstraction.cpp`

---

### With God's Grace

#### DKT_Ekantik
