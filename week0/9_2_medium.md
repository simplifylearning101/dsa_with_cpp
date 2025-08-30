# C++ Refresher for DSA Cohort: Medium Interview Questions

These 25 medium-difficulty interview questions build on Hours 1-8, testing deeper understanding and application for DSA interviews.

1. **How do you swap two numbers using pointers?**  
   **Response**: Use pointers to modify variables directly via their addresses.  
   **Example**:  
   ```cpp
   void swap(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }
   int main() { int x = 5, y = 10; swap(&x, &y); cout << x << " " << y; }
   // Output: 10 5
   ```

2. **What is the difference between a pointer and a reference?**  
   **Response**: A pointer stores an address and can be reassigned or null; a reference is an alias, cannot be null, and cannot change what it refers to.  
   **Example**: `int x = 5; int* p = &x; int& r = x; p = nullptr; // OK, r = nullptr; // Error`

3. **Write a recursive function to compute the nth Fibonacci number.**  
   **Response**: Recursively compute Fib(n) = Fib(n-1) + Fib(n-2) with base cases Fib(0)=0, Fib(1)=1.  
   ```cpp
   int fib(int n) { if (n <= 1) return n; return fib(n-1) + fib(n-2); }
   // fib(6) = 8
   ```

4. **How do you handle memory leaks in dynamic memory allocation?**  
   **Response**: Use `delete` to free memory and set pointers to `nullptr`. Use smart pointers in modern C++.  
   **Example**: `int* p = new int(5); delete p; p = nullptr;`

5. **What is the difference between `struct` and `class`?**  
   **Response**: `struct` defaults to `public` members; `class` defaults to `private`. Both can have methods and inheritance.  
   **Example**: `struct S { int x; }; class C { int x; };` — `S::x` is accessible, `C::x` is not.

6. **Write a class with a constructor and destructor managing dynamic memory.**  
   **Response**:  
   ```cpp
   class MyClass {
       int* data;
   public:
       MyClass(int x) { data = new int(x); cout << "Created"; }
       ~MyClass() { delete data; data = nullptr; cout << "Destroyed"; }
   };
   ```

7. **How do you reverse a C-style string using pointers?**  
   **Response**: Swap characters from both ends using pointer arithmetic.  
   ```cpp
   void reverse(char* str) {
       int len = strlen(str);
       for (int i = 0; i < len / 2; i++) {
           char temp = *(str + i);
           *(str + i) = *(str + len - 1 - i);
           *(str + len - 1 - i) = temp;
       }
   }
   ```

8. **What is the purpose of `virtual` functions?**  
   **Response**: Enable runtime polymorphism by allowing derived class methods to be called via base class pointers.  
   **Example**: `class Base { virtual void f() {} }; class Derived : public Base { void f() override {} };`

9. **How do you overload a function with different parameter types?**  
   **Response**: Define multiple functions with the same name but different parameter lists.  
   ```cpp
   int sum(int a, int b) { return a + b; }
   double sum(double a, double b) { return a + b; }
   ```

10. **What is operator overloading and why use it?**  
    **Response**: Redefines operators for custom types to make code intuitive. Used for natural operations on objects like vectors.  
    ```cpp
    class Vector {
        int x;
    public:
        Vector(int x_) : x(x_) {}
        Vector operator+(Vector v) { return Vector(x + v.x); }
    };
    ```

11. **How do you allocate a 2D dynamic array?**  
    **Response**: Use an array of pointers, each pointing to a dynamic array.  
    ```cpp
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) arr[i] = new int[cols];
    ```

12. **What is the `protected` access specifier used for in inheritance?**  
    **Response**: Allows derived classes to access base class members while keeping them inaccessible externally.  
    **Example**: `class Base { protected: int x; }; class Derived : public Base { void f() { x = 5; } };`

13. **Write a recursive function to compute the power of a number.**  
    **Response**:  
    ```cpp
    double power(double base, int exp) {
        if (exp == 0) return 1;
        return base * power(base, exp - 1);
    }
    // power(2, 3) = 8
    ```

14. **How does a constructor differ from a regular member function?**  
    **Response**: Constructors have the same name as the class, no return type, and are called automatically when an object is created.  
    **Example**: `class X { public: X() { cout << "Constructor"; } };`

15. **What is a dangling pointer?**  
    **Response**: A pointer pointing to freed or invalid memory.  
    **Example**: `int* p = new int(5); delete p; cout << *p; // Undefined behavior`

16. **How do you implement a simple class hierarchy?**  
    **Response**: Use a base class and derived classes with inheritance.  
    ```cpp
    class Animal { public: virtual void sound() {} };
    class Dog : public Animal { void sound() override { cout << "Bark"; } };
    ```

17. **What is the difference between `public`, `private`, and `protected` inheritance?**  
    **Response**: Public retains access levels; private makes all inherited members private; protected makes public/protected members protected in the derived class.  
    **Example**: `class Derived : public Base {};`

18. **How do you use `std::string` for string manipulation?**  
    **Response**: Use methods like `length()`, `substr()`, `find()`.  
    ```cpp
    string s = "hello"; cout << s.substr(1, 3); // "ell"
    ```

19. **What is a virtual destructor and why is it needed?**  
    **Response**: Ensures derived class destructors are called when deleting via a base class pointer.  
    ```cpp
    class Base { public: virtual ~Base() {} };
    class Derived : public Base { public: ~Derived() { cout << "Derived destroyed"; } };
    ```

20. **How do you initialize class members using an initializer list?**  
    **Response**: Use `:` after the constructor to initialize members before the body.  
    ```cpp
    class X {
        int a;
    public:
        X(int x) : a(x) {}
    };
    ```

21. **What is the output of a recursive factorial function for n=4?**  
    **Response**: 24 (4 * 3 * 2 * 1).  
    ```cpp
    int fact(int n) { if (n <= 1) return 1; return n * fact(n-1); }
    ```

22. **How do you check if a string is a palindrome recursively?**  
    **Response**: Compare characters from both ends recursively.  
    ```cpp
    bool isPal(string s, int i) {
        if (i >= s.length()/2) return true;
        if (s[i] != s[s.length()-1-i]) return false;
        return isPal(s, i+1);
    }
    ```

23. **What is the purpose of `const` member functions?**  
    **Response**: Prevent modification of object data, ensuring safety in const objects.  
    ```cpp
    class X { public: int get() const { return x; } private: int x; };
    ```

24. **How do you use pointer arithmetic to traverse an array?**  
    **Response**: Increment a pointer to access elements.  
    ```cpp
    int arr[] = {1, 2, 3}; int* p = arr;
    for (int i = 0; i < 3; i++) cout << *(p + i) << " ";
    ```

25. **What is the role of `this` pointer in a class?**  
    **Response**: Refers to the current object, used to access members or return `*this`.  
    ```cpp
    class X { int a; public: X& set(int x) { a = x; return *this; } };
    ```