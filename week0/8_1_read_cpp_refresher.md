# C++ Refresher for DSA Cohort: Hour 8 - Deep Dive into Inheritance, Polymorphism, Function Overloading, and Operator Overloading

This is the eighth hour of a C++ refresher for students preparing for a 10-week Data Structures and Algorithms (DSA) cohort. This session dives deeply into inheritance, polymorphism, function overloading, and operator overloading. Inheritance is like a family tree where children inherit traits, polymorphism allows objects to behave differently based on their type, function overloading lets you reuse function names with different parameters, and operator overloading redefines operators like `+` for custom types. These concepts are critical for advanced DSA implementations (e.g., polymorphic trees) and coding interviews, explained with real-world analogies, detailed examples, and heavily commented code.

## Hour 8: Topics Covered
We will cover:  
1. Inheritance (Single, Multiple, Hierarchical)  
2. Polymorphism (Compile-time and Runtime)  
3. Function Overloading  
4. Operator Overloading  

---

### Concept 1: Inheritance
Inheritance is like a child inheriting traits from parents. A derived class (child) inherits members from a base class (parent), promoting code reuse. Use `public`, `private`, or `protected` inheritance to control access. In DSA, inheritance is used in structures like generic nodes or containers. Interviews often test inheritance for designing extensible systems.

**Example Program 1: Single Inheritance for a Vehicle Hierarchy**
```cpp
#include <iostream>  // For input/output
#include <string>    // For string

class Vehicle {  // Base class
protected:  // Accessible to derived classes
    std::string brand;
    int year;
public:
    Vehicle(std::string b, int y) : brand(b), year(y) {}  // Constructor
    void display() {  // Base method
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

class Car : public Vehicle {  // Derived class (inherits publicly)
private:
    int doors;
public:
    Car(std::string b, int y, int d) : Vehicle(b, y), doors(d) {}  // Constructor
    void display() {  // Override base method
        std::cout << "Car - Brand: " << brand << ", Year: " << year 
                  << ", Doors: " << doors << std::endl;
    }
};

int main() {  // Main function
    Vehicle v("Toyota", 2020);  // Base class object
    v.display();
    Car c("Honda", 2022, 4);  // Derived class object
    c.display();
    return 0;
}
```
**Expected Outcome**:  
```
Brand: Toyota, Year: 2020
Car - Brand: Honda, Year: 2022, Doors: 4
```
This is like a car inheriting general vehicle traits but adding specific features like doors.

**Example Program 2: Hierarchical Inheritance**
```cpp
#include <iostream>
#include <string>

class Animal {  // Base class
protected:
    std::string name;
public:
    Animal(std::string n) : name(n) {}
    virtual void sound() {  // Virtual for polymorphism
        std::cout << name << " makes a sound" << std::endl;
    }
};

class Dog : public Animal {  // Derived class 1
public:
    Dog(std::string n) : Animal(n) {}
    void sound() override {  // Override base method
        std::cout << name << " barks" << std::endl;
    }
};

class Cat : public Animal {  // Derived class 2
public:
    Cat(std::string n) : Animal(n) {}
    void sound() override {
        std::cout << name << " meows" << std::endl;
    }
};

int main() {
    Dog d("Rex");
    Cat c("Whiskers");
    d.sound();
    c.sound();
    return 0;
}
```
**Expected Outcome**:  
```
Rex barks
Whiskers meows
```
This is like siblings inheriting from a parent but expressing unique traits.

---

### Concept 2: Polymorphism
Polymorphism allows objects to be treated as instances of their base class while invoking derived class behavior (runtime polymorphism via virtual functions) or using different function signatures (compile-time via overloading). It’s like a remote control working differently for a TV or a fan. In DSA, polymorphism is key for generic data structures (e.g., abstract list interfaces).

**Example Program: Runtime Polymorphism with Virtual Functions**
```cpp
#include <iostream>
#include <string>

class Shape {  // Abstract base class
protected:
    std::string type;
public:
    Shape(std::string t) : type(t) {}
    virtual double area() = 0;  // Pure virtual function (abstract)
    virtual void display() {  // Virtual method
        std::cout << "Shape: " << type << std::endl;
    }
    virtual ~Shape() {}  // Virtual destructor for proper cleanup
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    double area() override { return 3.14159 * radius * radius; }
    void display() override {
        std::cout << "Circle, Radius: " << radius << ", Area: " << area() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}
    double area() override { return length * width; }
    void display() override {
        std::cout << "Rectangle, Length: " << length << ", Width: " << width 
                  << ", Area: " << area() << std::endl;
    }
};

int main() {
    Shape* shapes[2];  // Array of base class pointers
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 3.0);
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();  // Polymorphic call
        delete shapes[i];  // Free memory
    }
    return 0;
}
```
**Expected Outcome**:  
```
Circle, Radius: 5, Area: 78.5397
Rectangle, Length: 4, Width: 3, Area: 12
```
This is like using a universal remote to control different devices, each responding uniquely.

---

### Concept 3: Function Overloading
Function overloading allows multiple functions with the same name but different parameter lists (number, type, or order). It’s like a chef preparing different dishes with the same recipe name based on ingredients. In DSA, overloading simplifies interfaces for operations like inserting into different data structures.

**Example Program: Function Overloading for Math Operations**
```cpp
#include <iostream>

class Math {
public:
    int add(int a, int b) {  // Overload 1: Two integers
        return a + b;
    }
    double add(double a, double b) {  // Overload 2: Two doubles
        return a + b;
    }
    int add(int a, int b, int c) {  // Overload 3: Three integers
        return a + b + c;
    }
};

int main() {
    Math m;
    std::cout << "Int sum: " << m.add(2, 3) << std::endl;
    std::cout << "Double sum: " << m.add(2.5, 3.7) << std::endl;
    std::cout << "Three int sum: " << m.add(1, 2, 3) << std::endl;
    return 0;
}
```
**Expected Outcome**:  
```
Int sum: 5
Double sum: 6.2
Three int sum: 6
```
This is like a chef making different soups based on the number or type of ingredients.

---

### Concept 4: Operator Overloading
Operator overloading redefines operators (`+`, `==`, etc.) for user-defined types, like teaching a calculator to add custom objects. It’s useful in DSA for intuitive operations on complex types (e.g., adding vectors). In interviews, overloading shows mastery of custom type design.

**Example Program: Operator Overloading for Complex Numbers**
```cpp
#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}  // Constructor
    Complex operator+(const Complex& other) {  // Overload +
        return Complex(real + other.real, imag + other.imag);
    }
    bool operator==(const Complex& other) {  // Overload ==
        return real == other.real && imag == other.imag;
    }
    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex sum = c1 + c2;  // Use overloaded +
    sum.display();
    std::cout << "Equal: " << (c1 == c2 ? "Yes" : "No") << std::endl;
    return 0;
}
```
**Expected Outcome**:  
```
4 + 6i
Equal: No
```
This is like redefining `+` to add two custom number pairs.

---

### Points to Remember for Interview Preparation
- Use inheritance to model hierarchies (e.g., base `Node` for trees); explain access specifiers clearly.  
- Virtual functions enable runtime polymorphism; always include a virtual destructor in base classes with virtual methods.  
- Avoid multiple inheritance unless necessary, as it complicates design (e.g., diamond problem).  
- Function overloading improves code readability but ensure signatures are distinct to avoid ambiguity.  
- Operator overloading should be intuitive (e.g., `+` for addition-like operations) to impress interviewers.  
- Combine with Hours 1-7: pointers for dynamic objects, recursion for tree traversal, classes for encapsulation.  
- Handle edge cases (e.g., null pointers in polymorphic arrays, invalid inputs in operators).  
- Practice explaining polymorphic behavior in interviews, especially virtual function dispatch.  
- Debug memory leaks in inheritance hierarchies, as they’re common interview traps.  
- Write clean, commented code to demonstrate OOP mastery in whiteboard sessions.