# C++ Refresher for DSA Cohort: Hour 8 - Homework Solutions

Solutions to the 20 homework problems for Hour 8, covering inheritance, polymorphism, function overloading, and operator overloading.

1. **Problem**: Create a base class `Shape` and derived class `Triangle` with area calculation.  
```cpp
#include <iostream>
class Shape {
public:
    virtual double area() = 0;  // Pure virtual
    virtual ~Shape() {}
};
class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() override { return 0.5 * base * height; }
};
int main() {
    double b, h;
    std::cin >> b >> h;
    Triangle t(b, h);
    std::cout << t.area() << std::endl;
    return 0;
}
```

2. **Problem**: Write a class `Employee` and derived class `Manager` with a bonus attribute.  
```cpp
#include <iostream>
#include <string>
class Employee {
protected:
    std::string name;
    double salary;
public:
    Employee(std::string n, double s) : name(n), salary(s) {}
    virtual void display() { std::cout << name << ", " << salary << std::endl; }
};
class Manager : public Employee {
private:
    double bonus;
public:
    Manager(std::string n, double s, double b) : Employee(n, s), bonus(b) {}
    void display() override { std::cout << name << ", " << salary << ", " << bonus << std::endl; }
};
int main() {
    std::string n;
    double s, b;
    std::cin >> n >> s >> b;
    Manager m(n, s, b);
    m.display();
    return 0;
}
```

3. **Problem**: Create a function `printArea` overloaded for `Circle` and `Rectangle`.  
```cpp
#include <iostream>
class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() { return 3.14159 * radius * radius; }
};
class Rectangle {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() { return length * width; }
};
void printArea(Circle c) { std::cout << c.area() << std::endl; }
void printArea(Rectangle r) { std::cout << r.area() << std::endl; }
int main() {
    double r, l, w;
    std::cin >> r >> l >> w;
    Circle c(r);
    Rectangle rect(l, w);
    printArea(c);
    printArea(rect);
    return 0;
}
```

4. **Problem**: Overload `+` operator for a `Vector` class (x, y coordinates).  
```cpp
#include <iostream>
class Vector {
private:
    double x, y;
public:
    Vector(double x_, double y_) : x(x_), y(y_) {}
    Vector operator+(const Vector& v) { return Vector(x + v.x, y + v.y); }
    void display() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};
int main() {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Vector v1(x1, y1), v2(x2, y2);
    Vector sum = v1 + v2;
    sum.display();
    return 0;
}
```

5. **Problem**: Implement a base class `Animal` and derived classes `Dog` and `Cat` with virtual `speak`.  
```cpp
#include <iostream>
#include <string>
class Animal {
protected:
    std::string name;
public:
    Animal(std::string n) : name(n) {}
    virtual void speak() = 0;
    virtual ~Animal() {}
};
class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}
    void speak() override { std::cout << name << " barks" << std::endl; }
};
class Cat : public Animal {
public:
    Cat(std::string n) : Animal(n) {}
    void speak() override { std::cout << name << " meows" << std::endl; }
};
int main() {
    Animal* animals[2];
    animals[0] = new Dog("Rex");
    animals[1] = new Cat("Whiskers");
    for (int i = 0; i < 2; i++) {
        animals[i]->speak();
        delete animals[i];
    }
    return 0;
}
```

6. **Problem**: Create a class `Matrix` with overloaded `==` operator to compare 2x2 matrices.  
```cpp
#include <iostream>
class Matrix {
private:
    int mat[2][2];
public:
    Matrix() { for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) std::cin >> mat[i][j]; }
    bool operator==(const Matrix& m) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (mat[i][j] != m.mat[i][j]) return false;
        return true;
    }
};
int main() {
    Matrix m1, m2;
    std::cout << (m1 == m2 ? "Yes" : "No") << std::endl;
    return 0;
}
```

7. **Problem**: Write a base class `Vehicle` and derived class `Bike` with overridden `describe`.  
```cpp
#include <iostream>
#include <string>
class Vehicle {
protected:
    std::string brand;
public:
    Vehicle(std::string b) : brand(b) {}
    virtual void describe() { std::cout << "Vehicle: " << brand << std::endl; }
};
class Bike : public Vehicle {
private:
    int wheels;
public:
    Bike(std::string b, int w) : Vehicle(b), wheels(w) {}
    void describe() override { std::cout << brand << ", " << wheels << " wheels" << std::endl; }
};
int main() {
    std::string b;
    int w;
    std::cin >> b >> w;
    Bike bike(b, w);
    bike.describe();
    return 0;
}
```

8. **Problem**: Overload `multiply` function for scalar and vector multiplication of a `Point`.  
```cpp
#include <iostream>
class Point {
private:
    double x, y;
public:
    Point(double x_, double y_) : x(x_), y(y_) {}
    Point multiply(double scalar) { return Point(x * scalar, y * scalar); }
    Point multiply(Point p) { return Point(x * p.x, y * p.y); }
    void display() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};
int main() {
    double x, y, s;
    std::cin >> x >> y >> s;
    Point p(x, y);
    Point result = p.multiply(s);
    result.display();
    return 0;
}
```

9. **Problem**: Create an abstract base class `Drawable` and derived `Square` with virtual `draw`.  
```cpp
#include <iostream>
class Drawable {
public:
    virtual void draw() = 0;
    virtual ~Drawable() {}
};
class Square : public Drawable {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void draw() override { std::cout << "Square drawn with side " << side << std::endl; }
};
int main() {
    double s;
    std::cin >> s;
    Square sq(s);
    sq.draw();
    return 0;
}
```

10. **Problem**: Implement multiple inheritance for a `FlyingCar` from `Car` and `Airplane`.  
```cpp
#include <iostream>
#include <string>
class Car {
protected:
    std::string brand;
public:
    Car(std::string b) : brand(b) {}
    virtual void drive() { std::cout << brand << " drives" << std::endl; }
};
class Airplane {
protected:
    int speed;
public:
    Airplane(int s) : speed(s) {}
    virtual void fly() { std::cout << "Speed: " << speed << " mph" << std::endl; }
};
class FlyingCar : public Car, public Airplane {
public:
    FlyingCar(std::string b, int s) : Car(b), Airplane(s) {}
    void drive() override { std::cout << brand << " drives and flies" << std::endl; }
    void fly() override { std::cout << brand << " flies at " << speed << " mph" << std::endl; }
};
int main() {
    std::string b;
    int s;
    std::cin >> b >> s;
    FlyingCar fc(b, s);
    fc.drive();
    fc.fly();
    return 0;
}
```

11. **Problem**: Overload `<<` operator for a `Time` class (hours, minutes).  
```cpp
#include <iostream>
class Time {
private:
    int hours, minutes;
public:
    Time(int h, int m) : hours(h), minutes(m) {}
    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << t.hours << ":" << (t.minutes < 10 ? "0" : "") << t.minutes;
        return os;
    }
};
int main() {
    int h, m;
    std::cin >> h >> m;
    Time t(h, m);
    std::cout << t << std::endl;
    return 0;
}
```

12. **Problem**: Create a base class `Person` and derived `Student` with overridden `introduce`.  
```cpp
#include <iostream>
#include <string>
class Person {
protected:
    std::string name;
public:
    Person(std::string n) : name(n) {}
    virtual void introduce() { std::cout << "I am " << name << std::endl; }
};
class Student : public Person {
private:
    int id;
public:
    Student(std::string n, int i) : Person(n), id(i) {}
    void introduce() override { std::cout << name << ", Student ID: " << id << std::endl; }
};
int main() {
    std::string n;
    int i;
    std::cin >> n >> i;
    Student s(n, i);
    s.introduce();
    return 0;
}
```

13. **Problem**: Write a function `scale` overloaded for `int` and `double` scaling of a `Box`.  
```cpp
#include <iostream>
class Box {
private:
    double length, width, height;
public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}
    void scale(int factor) { length *= factor; width *= factor; height *= factor; }
    void scale(double factor) { length *= factor; width *= factor; height *= factor; }
    void display() { std::cout << length << ", " << width << ", " << height << std::endl; }
};
int main() {
    double l, w, h, d;
    int i;
    std::cin >> l >> w >> h >> i >> d;
    Box b1(l, w, h), b2(l, w, h);
    b1.scale(i);
    b2.scale(d);
    b1.display();
    b2.display();
    return 0;
}
```

14. **Problem**: Overload `*` operator for matrix-vector multiplication in a `Matrix` class.  
```cpp
#include <iostream>
class Matrix {
private:
    int mat[2][2];
public:
    Matrix() { for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) std::cin >> mat[i][j]; }
    int* operator*(int* vec) {
        int* result = new int[2];
        result[0] = mat[0][0] * vec[0] + mat[0][1] * vec[1];
        result[1] = mat[1][0] * vec[0] + mat[1][1] * vec[1];
        return result;
    }
};
int main() {
    Matrix m;
    int vec[2];
    std::cin >> vec[0] >> vec[1];
    int* result = m * vec;
    std::cout << result[0] << ", " << result[1] << std::endl;
    delete[] result;
    return 0;
}
```

15. **Problem**: Create a base class `Container` and derived `Stack` with virtual `push`.  
```cpp
#include <iostream>
class Container {
public:
    virtual void push(int x) = 0;
    virtual void display() = 0;
    virtual ~Container() {}
};
class Stack : public Container {
private:
    int arr[100];
    int top;
public:
    Stack() : top(-1) {}
    void push(int x) override { arr[++top] = x; }
    void display() override {
        for (int i = 0; i <= top; i++) std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.display();
    return 0;
}
```

16. **Problem**: Implement hierarchical inheritance with `Shape`, `Circle`, and `Square`.  
```cpp
#include <iostream>
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14159 * radius * radius; }
};
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() override { return side * side; }
};
int main() {
    Shape* shapes[2];
    double r, s;
    std::cin >> r >> s;
    shapes[0] = new Circle(r);
    shapes[1] = new Square(s);
    for (int i = 0; i < 2; i++) {
        std::cout << shapes[i]->area() << std::endl;
        delete shapes[i];
    }
    return 0;
}
```

17. **Problem**: Overload `+=` operator for a `Counter` class.  
```cpp
#include <iostream>
class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}
    Counter& operator+=(int x) { count += x; return *this; }
    void display() { std::cout << count << std::endl; }
};
int main() {
    int c, x;
    std::cin >> c >> x;
    Counter counter(c);
    counter += x;
    counter.display();
    return 0;
}
```

18. **Problem**: Create a base class `Media` and derived `Book` and `Movie` with virtual `play`.  
```cpp
#include <iostream>
#include <string>
class Media {
protected:
    std::string title;
public:
    Media(std::string t) : title(t) {}
    virtual void play() = 0;
    virtual ~Media() {}
};
class Book : public Media {
public:
    Book(std::string t) : Media(t) {}
    void play() override { std::cout << "Read " << title << std::endl; }
};
class Movie : public Media {
public:
    Movie(std::string t) : Media(t) {}
    void play() override { std::cout << "Watch " << title << std::endl; }
};
int main() {
    Media* media[2];
    std::string t1, t2;
    std::cin >> t1 >> t2;
    media[0] = new Book(t1);
    media[1] = new Movie(t2);
    for (int i = 0; i < 2; i++) {
        media[i]->play();
        delete media[i];
    }
    return 0;
}
```

19. **Problem**: Overload `>` operator for a `Fraction` class.  
```cpp
#include <iostream>
class Fraction {
private:
    int num, den;
public:
    Fraction(int n, int d) : num(n), den(d) {}
    bool operator>(const Fraction& f) { return num * f.den > f.num * den; }
};
int main() {
    int n1, d1, n2, d2;
    std::cin >> n1 >> d1 >> n2 >> d2;
    Fraction f1(n1, d1), f2(n2, d2);
    std::cout << (f1 > f2 ? "Yes" : "No") << std::endl;
    return 0;
}
```

20. **Problem**: Implement a `TreeNode` class with inheritance for `BinaryNode` and virtual traversal.  
```cpp
#include <iostream>
class TreeNode {
public:
    int value;
    virtual void inorder() = 0;
    virtual ~TreeNode() {}
};
class BinaryNode : public TreeNode {
private:
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int v, BinaryNode* l = nullptr, BinaryNode* r = nullptr) 
        : left(l), right(r) { value = v; }
    void inorder() override {
        if (left) left->inorder();
        std::cout << value << " ";
        if (right) right->inorder();
    }
    ~BinaryNode() { delete left; delete right; }
};
int main() {
    BinaryNode* root = new BinaryNode(1);
    root->left = new BinaryNode(2);
    root->right = new BinaryNode(3);
    root->inorder();
    std::cout << std::endl;
    delete root;
    return 0;
}
```