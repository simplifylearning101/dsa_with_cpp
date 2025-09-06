# C++ Refresher for DSA Cohort: Simple Interview Questions

These 25 simple interview questions cover foundational C++ concepts from Hours 1-8, suitable for beginners preparing for DSA interviews. Each question includes a detailed response with examples where applicable.

1. **What is a variable in C++?**  
   **Response**: A variable is a named storage location to hold data, like a labeled box. It has a type (e.g., `int`, `double`) and value.  
   **Example**: `int x = 5;` stores 5 in a variable named `x`.

2. **How do you perform console input/output in C++?**  
   **Response**: Use `std::cin` for input and `std::cout` for output, with `<<` and `>>` operators.  
   **Example**: `std::cin >> x; std::cout << x;` reads and prints an integer.

3. **What are arithmetic operators in C++?**  
   **Response**: Operators like `+`, `-`, `*`, `/`, `%` perform math operations.  
   **Example**: `int a = 10, b = 3; int sum = a + b;` yields 13.

4. **What is the purpose of `if-else` statements?**  
   **Response**: They control program flow based on conditions, like choosing a path.  
   **Example**: `if (x > 0) std::cout << "Positive"; else std::cout << "Non-positive";`

5. **How do you define a function in C++?**  
   **Response**: A function is a reusable code block with a return type, name, and parameters.  
   **Example**: `int add(int a, int b) { return a + b; }`

6. **What is variable scope?**  
   **Response**: Scope defines where a variable is accessible (e.g., local, global). Local variables exist within a block; globals are outside functions.  
   **Example**: `int x = 10; void func() { int x = 5; }` — global `x` is 10, local `x` is 5.

7. **How do you declare an array in C++?**  
   **Response**: An array is a fixed-size collection of elements, declared as `type name[size]`.  
   **Example**: `int arr[5] = {1, 2, 3, 4, 5};`

8. **What is a pointer in C++?**  
   **Response**: A pointer stores a memory address, like a GPS location.  
   **Example**: `int x = 5; int* ptr = &x;` — `ptr` points to `x`’s address.

9. **What is a reference in C++?**  
   **Response**: A reference is an alias for a variable, like a nickname.  
   **Example**: `int x = 5; int& ref = x; ref = 10;` changes `x` to 10.

10. **How do you declare a string in C++?**  
    **Response**: Use `std::string` for dynamic strings or `char[]` for C-style strings.  
    **Example**: `std::string s = "hello"; char cs[] = "world";`

11. **What is dynamic memory allocation?**  
    **Response**: Allocating memory at runtime using `new`, freed with `delete`.  
    **Example**: `int* ptr = new int(5); delete ptr;`

12. **What is a structure in C++?**  
    **Response**: A `struct` groups related variables, like a form with fields.  
    **Example**: `struct Point { int x, y; }; Point p = {3, 4};`

13. **What is recursion?**  
    **Response**: A function calling itself to solve smaller problems, like breaking a task into sub-tasks.  
    **Example**: `int fact(int n) { if (n <= 1) return 1; return n * fact(n-1); }` computes factorial.

14. **What is a class in C++?**  
    **Response**: A class is a blueprint for objects, defining data and methods.  
    **Example**: `class Car { public: string model; void drive() { cout << model << " drives"; } };`

15. **How do you create an object in C++?**  
    **Response**: Instantiate a class using its name.  
    **Example**: `Car c; c.model = "Toyota"; c.drive();`

16. **What is a constructor?**  
    **Response**: A special method called when an object is created to initialize it.  
    **Example**: `class Car { public: Car(string m) : model(m) {} string model; };`

17. **What is a destructor?**  
    **Response**: A method called when an object is destroyed to clean up resources.  
    **Example**: `class MyClass { public: ~MyClass() { cout << "Destroyed"; } };`

18. **What is the `public` access specifier?**  
    **Response**: Allows members to be accessed from outside the class.  
    **Example**: `class X { public: int a; }; X x; x.a = 5;` is valid.

19. **What is inheritance in C++?**  
    **Response**: A derived class inherits members from a base class, like a child inheriting traits.  
    **Example**: `class Vehicle { public: string brand; }; class Car : public Vehicle {};`

20. **What is function overloading?**  
    **Response**: Multiple functions with the same name but different parameters.  
    **Example**: `int add(int a, int b) { return a + b; } double add(double a, double b) { return a + b; }`

21. **What is operator overloading?**  
    **Response**: Redefining operators for user-defined types.  
    **Example**: `class Complex { public: int r; Complex operator+(Complex c) { return Complex(r + c.r); } };`

22. **What is polymorphism?**  
    **Response**: Objects behaving differently based on their type, via virtual functions or overloading.  
    **Example**: `class Shape { virtual void draw() {} }; class Circle : public Shape { void draw() { cout << "Circle"; } };`

23. **How do you access a class member?**  
    **Response**: Use the dot operator (`.`) for objects, `->` for pointers.  
    **Example**: `Car c; c.model = "Honda"; Car* ptr = &c; ptr->model = "Toyota";`

24. **What is the `protected` access specifier?**  
    **Response**: Allows access within the class and derived classes.  
    **Example**: `class Base { protected: int x; }; class Derived : public Base { void set() { x = 5; } };`

25. **What is the purpose of `std::getline`?**  
    **Response**: Reads a line including spaces into a `std::string`.  
    **Example**: `string s; getline(cin, s);` reads “Hello World”.