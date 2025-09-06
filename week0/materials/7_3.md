# C++ Refresher for DSA Cohort: Hour 7 - Homework Solutions

Solutions to the 15 homework problems for Hour 7, covering classes, objects, constructors, destructors, and access mechanisms.

1. **Problem**: Create a class `Rectangle` with length and width, and a method to compute area.  
```cpp
#include <iostream>
class Rectangle {
public:
    double length, width;
    Rectangle(double l, double w) : length(l), width(w) {}  // Constructor
    double area() { return length * width; }  // Compute area
};
int main() {
    double l, w;
    std::cin >> l >> w;
    Rectangle r(l, w);
    std::cout << r.area() << std::endl;
    return 0;
}
```

2. **Problem**: Write a class `Circle` with a private radius and public method to compute circumference.  
```cpp
#include <iostream>
class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}  // Constructor
    double circumference() { return 2 * 3.14159 * radius; }
};
int main() {
    double r;
    std::cin >> r;
    Circle c(r);
    std::cout << c.circumference() << std::endl;
    return 0;
}
```

3. **Problem**: Create a class `Counter` with a private count and methods to increment and get count.  
```cpp
#include <iostream>
class Counter {
private:
    int count;
public:
    Counter() : count(0) {}  // Constructor
    void increment() { count++; }
    int getCount() { return count; }
};
int main() {
    Counter c;
    c.increment();
    c.increment();
    std::cout << c.getCount() << std::endl;
    return 0;
}
```

4. **Problem**: Write a class `Student` with a constructor to initialize name and ID.  
```cpp
#include <iostream>
#include <string>
class Student {
public:
    std::string name;
    int id;
    Student(std::string n, int i) : name(n), id(i) {}  // Constructor
    void display() { std::cout << name << ", " << id << std::endl; }
};
int main() {
    std::string n;
    int i;
    std::cin >> n >> i;
    Student s(n, i);
    s.display();
    return 0;
}
```

5. **Problem**: Create a class `DynamicArray` with a dynamic array and destructor to free memory.  
```cpp
#include <iostream>
class DynamicArray {
public:
    int* arr;
    int size;
    DynamicArray(int s) : size(s) {  // Constructor
        arr = new int[size];
        for (int i = 0; i < size; i++) arr[i] = i + 1;
    }
    ~DynamicArray() {  // Destructor
        delete[] arr;
        arr = nullptr;
    }
    void display() {
        for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};
int main() {
    DynamicArray da(3);
    da.display();
    return 0;
}
```

6. **Problem**: Write a class `Point` with private x, y coordinates and a method to compute distance from another point.  
```cpp
#include <iostream>
#include <cmath>
class Point {
private:
    double x, y;
public:
    Point(double x_, double y_) : x(x_), y(y_) {}  // Constructor
    double distance(Point p) { return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }
};
int main() {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    std::cout << p1.distance(p2) << std::endl;
    return 0;
}
```

7. **Problem**: Create a class `Bank` with private balance and methods for deposit and withdrawal.  
```cpp
#include <iostream>
class Bank {
private:
    double balance;
public:
    Bank(double b) : balance(b) {}  // Constructor
    void deposit(double amt) { if (amt > 0) balance += amt; }
    void withdraw(double amt) { if (amt > 0 && amt <= balance) balance -= amt; }
    double getBalance() { return balance; }
};
int main() {
    Bank b(1000);
    b.deposit(100);
    b.withdraw(50);
    std::cout << b.getBalance() << std::endl;
    return 0;
}
```

8. **Problem**: Write a class `Car` with a constructor and destructor to manage a dynamic license plate.  
```cpp
#include <iostream>
#include <string>
class Car {
public:
    std::string* license;
    Car(std::string l) {  // Constructor
        license = new std::string(l);
        std::cout << "Created: " << *license << std::endl;
    }
    ~Car() {  // Destructor
        std::cout << "Destroyed: " << *license << std::endl;
        delete license;
        license = nullptr;
    }
};
int main() {
    std::string l;
    std::cin >> l;
    Car c(l);
    return 0;
}
```

9. **Problem**: Create a class `Box` with private dimensions and a public method to compute volume.  
```cpp
#include <iostream>
class Box {
private:
    double length, width, height;
public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}  // Constructor
    double volume() { return length * width * height; }
};
int main() {
    double l, w, h;
    std::cin >> l >> w >> h;
    Box b(l, w, h);
    std::cout << b.volume() << std::endl;
    return 0;
}
```

10. **Problem**: Write a class `Employee` with private salary and public methods to set and get salary.  
```cpp
#include <iostream>
class Employee {
private:
    double salary;
public:
    Employee() : salary(0) {}  // Constructor
    void setSalary(double s) { if (s >= 0) salary = s; }
    double getSalary() { return salary; }
};
int main() {
    double s;
    std::cin >> s;
    Employee e;
    e.setSalary(s);
    std::cout << e.getSalary() << std::endl;
    return 0;
}
```

11. **Problem**: Create a class `String` with a private `std::string` and method to reverse it.  
```cpp
#include <iostream>
#include <string>
class String {
private:
    std::string str;
public:
    String(std::string s) : str(s) {}  // Constructor
    void reverse() {
        int n = str.length();
        for (int i = 0; i < n / 2; i++) {
            std::swap(str[i], str[n - 1 - i]);
        }
    }
    void display() { std::cout << str << std::endl; }
};
int main() {
    std::string s;
    std::getline(std::cin, s);
    String str(s);
    str.reverse();
    str.display();
    return 0;
}
```

12. **Problem**: Write a class `Inventory` with a dynamic array of items and destructor to free memory.  
```cpp
#include <iostream>
#include <string>
class Inventory {
public:
    std::string* items;
    int size;
    Inventory(int s) : size(s) {  // Constructor
        items = new std::string[size];
        for (int i = 0; i < size; i++) std::cin >> items[i];
    }
    ~Inventory() {  // Destructor
        delete[] items;
        items = nullptr;
    }
    void display() {
        for (int i = 0; i < size; i++) std::cout << items[i] << " ";
        std::cout << std::endl;
    }
};
int main() {
    Inventory inv(2);
    inv.display();
    return 0;
}
```

13. **Problem**: Create a class `Complex` for complex numbers with methods for addition.  
```cpp
#include <iostream>
class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}  // Constructor
    Complex add(Complex c) { return Complex(real + c.real, imag + c.imag); }
    void display() { std::cout << real << ", " << imag << std::endl; }
};
int main() {
    double r1, i1, r2, i2;
    std::cin >> r1 >> i1 >> r2 >> i2;
    Complex c1(r1, i1), c2(r2, i2);
    Complex sum = c1.add(c2);
    sum.display();
    return 0;
}
```

14. **Problem**: Write a class `Queue` with private array and methods to enqueue and dequeue.  
```cpp
#include <iostream>
class Queue {
private:
    int arr[100];
    int front, rear, size;
public:
    Queue() : front(0), rear(-1), size(0) {}  // Constructor
    void enqueue(int x) {
        if (size < 100) arr[++rear] = x, size++;
    }
    int dequeue() {
        if (size > 0) {
            size--;
            return arr[front++];
        }
        return -1;
    }
    void display() {
        for (int i = front; i <= rear; i++) std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.display();
    return 0;
}
```

15. **Problem**: Create a class `Matrix` with a dynamic 2D array and method to compute determinant (2x2).  
```cpp
#include <iostream>
class Matrix {
public:
    int** mat;
    Matrix() {  // Constructor
        mat = new int*[2];
        for (int i = 0; i < 2; i++) mat[i] = new int[2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                std::cin >> mat[i][j];
    }
    ~Matrix() {  // Destructor
        for (int i = 0; i < 2; i++) delete[] mat[i];
        delete[] mat;
        mat = nullptr;
    }
    int determinant() { return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]; }
};
int main() {
    Matrix m;
    std::cout << m.determinant() << std::endl;
    return 0;
}
```