# C++ Refresher for DSA Cohort: Hour 8 - Quiz

Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators), Hour 2 (control structures), Hour 3 (functions, scope, arrays), Hour 4 (pointers, references, strings), Hour 5 (dynamic memory, structures, recursion), Hour 6 (advanced pointers, strings, recursion), Hour 7 (classes, objects, constructors, destructors, access mechanisms), and Hour 8 (inheritance, polymorphism, function overloading, operator overloading).

1. What is inheritance in C++?  
2. How do you declare a derived class `Car` from base class `Vehicle`?  
3. What is the difference between public and private inheritance?  
4. Write a virtual function declaration for `area` in a `Shape` class.  
5. What is polymorphism?  
6. What is a pure virtual function?  
7. Why is a virtual destructor needed in a base class?  
8. Write a function `add` overloaded for `int` and `double`.  
9. How do you overload the `+` operator for a class?  
10. What is the diamond problem in multiple inheritance?  
11. Write a base class `Animal` with a virtual `move` method.  
12. What is the output of `int x = 5; cout << x;`?  
13. How to call a base class constructor from a derived class?  
14. What happens if you forget to make a base class destructor virtual?  
15. Write a class `Point` with overloaded `==` operator.  
16. What is compile-time polymorphism?  
17. How to declare a C-style string in a class?  
18. Write a recursive function to compute Fibonacci 6 (Hour 5).  
19. What is the size of a pointer on a 32-bit system?  
20. How to overload `<<` for a custom class?  
21. What does `override` keyword do?  
22. Write a base class `Container` and derived `Queue` with virtual `add`.  
23. What is the role of `protected` access specifier?  
24. How to reverse an array using pointers (Hour 6)?  
25. Write a class `Time` with overloaded `+` for adding minutes.  
26. What happens if function overloading signatures are ambiguous?  
27. How to implement hierarchical inheritance for `Shape`, `Circle`, `Triangle`?  
28. Write a program to swap two numbers using references (Hour 4).  
29. What is a memory leak in an inheritance hierarchy?  
30. Why use polymorphism in DSA problems for interviews?

## Quiz Solutions
1. Mechanism where a derived class inherits members from a base class.  
2. `class Car : public Vehicle { /* members */ };`  
3. Public: base members retain access; Private: base members become private.  
4. `virtual double area() = 0;`  
5. Ability of objects to take different forms (compile-time or runtime).  
6. A virtual function set to `= 0`, making the class abstract.  
7. Ensures derived class destructors are called when deleting via base pointer.  
8. `int add(int a, int b) { return a + b; } double add(double a, double b) { return a + b; }`  
9. `Type operator+(const Type& other) { /* implementation */ }`  
10. Ambiguity in multiple inheritance when base classes share a common ancestor.  
11. `class Animal { public: virtual void move() { cout << "Moves"; } };`  
12. 5  
13. `: BaseClass(args)` in derived constructor’s initializer list.  
14. Derived class destructor may not be called, causing memory leaks.  
15. `class Point { double x, y; public: Point(double x_, double y_) : x(x_), y(y_) {} bool operator==(const Point& p) { return x == p.x && y == p.y; } };`  
16. Polymorphism via function overloading or templates.  
17. `char str[100];` or `char* str;`  
18. `unsigned long long fib(int n) { if (n <= 1) return n; return fib(n-1) + fib(n-2); }` → 8  
19. 4 bytes typically.  
20. `friend ostream& operator<<(ostream& os, const Class& obj) { /* output */ return os; }`  
21. Ensures a function overrides a virtual base function.  
22. `class Container { public: virtual void add(int x) = 0; }; class Queue : public Container { void add(int x) override { /* implement */ } };`  
23. Allows access to derived classes but not outside.  
24. `void reverse(int* arr, int size) { for (int i = 0; i < size/2; i++) swap(*(arr+i), *(arr+size-1-i)); }`  
25. `class Time { int h, m; public: Time(int h_, int m_) : h(h_), m(m_) {} Time operator+(int min) { int total = h*60 + m + min; return Time(total/60, total%60); } };`  
26. Compiler error due to inability to resolve which function to call.  
27. `class Shape { virtual double area() = 0; }; class Circle : public Shape { /* area */ }; class Triangle : public Shape { /* area */ };`  
28. `void swap(int& a, int& b) { int t = a; a = b; b = t; }`  
29. Unfreed memory in derived class objects when base pointer is deleted.  
30. Enables flexible, extensible designs for structures like trees or graphs.