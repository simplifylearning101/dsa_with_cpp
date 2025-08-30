# C++ Refresher for DSA Cohort: Hour 7 - Classes, Objects, Constructors, Destructors, and Access Mechanisms

This is the seventh hour of a C++ refresher for students preparing for a 10-week Data Structures and Algorithms (DSA) cohort. This session introduces classes, objects, constructors, destructors, and access mechanisms. Classes are like blueprints for a house, objects are the actual houses built from the blueprint, constructors set up the house, destructors clean it up, and access mechanisms control who can enter which rooms. These concepts are foundational for object-oriented programming (OOP) in DSA (e.g., implementing nodes or trees) and are critical for coding interviews.

## Hour 7: Topics Covered
We will cover:  
1. Classes and Objects  
2. Constructors and Destructors  
3. Access Mechanisms (Public, Private, Protected)  

---

### Concept 1: Classes and Objects
A class is like a blueprint for a product, defining its properties (data members) and behaviors (member functions). An object is an instance of a class, like a specific product built from the blueprint. Classes encapsulate data and functionality, making them ideal for DSA structures like stacks or queues.

**Example Program: Simple Student Class**
```cpp
#include <iostream>  // For input/output
#include <string>    // For string

class Student {  // Class definition (blueprint)
public:  // Access specifier: members accessible outside
    std::string name;  // Data member
    int age;           // Data member
    
    void display() {  // Member function
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {  // Main function
    Student s1;  // Object creation (instance of Student)
    s1.name = "Alice";  // Set data
    s1.age = 20;
    s1.display();  // Call member function
    
    Student s2;  // Another object
    s2.name = "Bob";
    s2.age = 22;
    s2.display();
    
    return 0;  // End program
}
```
**Expected Outcome**:  
```
Name: Alice, Age: 20
Name: Bob, Age: 22
```
This is like building two houses (objects) from the same blueprint (class) with different details.

---

### Concept 2: Constructors and Destructors
Constructors are special member functions that initialize objects, like setting up a new house with furniture. They have the same name as the class and no return type. Destructors, named `~ClassName`, clean up resources (e.g., dynamic memory) when an object is destroyed, like demolishing a house. Constructors are critical for initializing DSA objects, and destructors prevent memory leaks in interviews.

**Example Program: Class with Constructor and Destructor**
```cpp
#include <iostream>  // For input/output
#include <string>    // For string

class Book {  // Class definition
public:
    std::string title;  // Data member
    int* pages;         // Pointer for dynamic memory
    
    Book(std::string t, int p) {  // Constructor
        title = t;
        pages = new int(p);  // Allocate dynamic memory
        std::cout << "Constructor: Book " << title << " created" << std::endl;
    }
    
    ~Book() {  // Destructor
        delete pages;  // Free memory
        pages = nullptr;  // Avoid dangling pointer
        std::cout << "Destructor: Book " << title << " destroyed" << std::endl;
    }
    
    void display() {  // Member function
        std::cout << "Title: " << title << ", Pages: " << *pages << std::endl;
    }
};

int main() {  // Main function
    Book b1("C++ Guide", 300);  // Object creation, calls constructor
    b1.display();
    
    {  // Inner scope
        Book b2("DSA Book", 500);  // Constructor called
        b2.display();
    }  // b2 goes out of scope, destructor called
    
    return 0;  // b1's destructor called at end
}
```
**Expected Outcome**:  
```
Constructor: Book C++ Guide created
Title: C++ Guide, Pages: 300
Constructor: Book DSA Book created
Title: DSA Book, Pages: 500
Destructor: Book DSA Book destroyed
Destructor: Book C++ Guide destroyed
```
This is like building a house, furnishing it (constructor), and cleaning up when moving out (destructor).

---

### Concept 3: Access Mechanisms
Access specifiers (`public`, `private`, `protected`) control access to class members, like locking rooms in a house. `public` members are accessible everywhere, `private` are only accessible within the class, and `protected` are accessible in the class and derived classes (covered later). In interviews, use `private` for data encapsulation and `public` for interfaces.

**Example Program: Access Control in a Class**
```cpp
#include <iostream>  // For input/output
#include <string>    // For string

class BankAccount {  // Class definition
private:  // Only accessible within class
    double balance;  // Sensitive data
    std::string accountNumber;
    
public:  // Accessible outside class
    BankAccount(std::string acc, double bal) {  // Constructor
        accountNumber = acc;
        balance = bal;
    }
    
    void deposit(double amount) {  // Public interface
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << std::endl;
        }
    }
    
    void display() {  // Public interface
        std::cout << "Account: " << accountNumber << ", Balance: " << balance << std::endl;
    }
};

int main() {  // Main function
    BankAccount acc("12345", 1000.0);  // Object creation
    acc.deposit(500.0);  // Access public method
    acc.display();
    // acc.balance = 2000;  // Error: balance is private
    return 0;
}
```
**Expected Outcome**:  
```
Deposited: 500
Account: 12345, Balance: 1500
```
This is like a bank vault: only authorized methods (public) can access the money (private data).

---

### Points to Remember for Interview Preparation
- Use classes to encapsulate data and behavior for DSA structures (e.g., linked list nodes).  
- Always initialize objects with constructors to ensure valid state in interviews.  
- Implement destructors to free dynamic memory, preventing leaks in problems like trees.  
- Use `private` for data members and `public` for methods to show encapsulation skills.  
- Avoid accessing private members directly; use getter/setter methods for controlled access.  
- Combine with Hours 1-6 (e.g., pointers for dynamic members, recursion for tree operations).  
- Explain class design clearly in interviews, emphasizing why you chose certain access specifiers.  
- Handle edge cases (e.g., negative deposits, null pointers) to make code robust.  
- Practice debugging destructor issues, as memory management is a common interview focus.  
- Write clean, commented code to demonstrate OOP principles in whiteboard sessions.