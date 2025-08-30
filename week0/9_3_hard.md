# C++ Refresher for DSA Cohort: Hard Interview Questions

These 25 hard interview questions test advanced concepts from Hours 1-8, challenging students to apply knowledge in complex scenarios for DSA interviews.

1. **How do you implement a function to reverse an array in-place using pointers?**  
   **Response**: Swap elements from both ends using pointer arithmetic.  
   ```cpp
   void reverse(int* arr, int size) {
       for (int i = 0; i < size / 2; i++) {
           int temp = *(arr + i);
           *(arr + i) = *(arr + size - 1 - i);
           *(arr + size - 1 - i) = temp;
       }
   }
   ```

2. **What is a double pointer and how is it used in dynamic memory allocation?**  
   **Response**: A pointer to a pointer, used to modify pointers or allocate 2D arrays.  
   ```cpp
   void allocate(int**& arr, int rows, int cols) {
       arr = new int*[rows];
       for (int i = 0; i < rows; i++) arr[i] = new int[cols];
   }
   ```

3. **Write a recursive function to generate all permutations of a string.**  
   **Response**: Swap characters and recurse to generate all combinations.  
   ```cpp
   void permute(string& str, int l, int r) {
       if (l == r) { cout << str << endl; return; }
       for (int i = l; i <= r; i++) {
           swap(str[l], str[i]);
           permute(str, l + 1, r);
           swap(str[l], str[i]);
       }
   }
   ```

4. **How do you avoid memory leaks in a class hierarchy?**  
   **Response**: Use virtual destructors in base classes and ensure all dynamic memory is freed.  
   ```cpp
   class Base { public: virtual ~Base() {} };
   class Derived : public Base { int* p; public: Derived() { p = new int; } ~Derived() { delete p; } };
   ```

5. **What is the diamond problem in multiple inheritance and how to resolve it?**  
   **Response**: Ambiguity when a class inherits from two classes sharing a common base. Use virtual inheritance.  
   ```cpp
   class A { public: int x; };
   class B : virtual public A {};
   class C : virtual public A {};
   class D : public B, public C {};
   ```

6. **Write a class with overloaded `+` and `==` operators for a complex number.**  
   **Response**:  
   ```cpp
   class Complex {
       double real, imag;
   public:
       Complex(double r, double i) : real(r), imag(i) {}
       Complex operator+(const Complex& c) { return Complex(real + c.real, imag + c.imag); }
       bool operator==(const Complex& c) { return real == c.real && imag == c.imag; }
       void display() { cout << real << " + " << imag << "i"; }
   };
   ```

7. **How do you implement a function pointer to call different functions?**  
   **Response**: Declare a pointer to a function type and assign it to matching functions.  
   ```cpp
   int add(int a, int b) { return a + b; }
   int sub(int a, int b) { return a - b; }
   int (*func)(int, int);
   func = add; cout << func(5, 3); // 8
   func = sub; cout << func(5, 3); // 2
   ```

8. **What is the difference between compile-time and runtime polymorphism?**  
   **Response**: Compile-time uses overloading/templates; runtime uses virtual functions.  
   **Example**: Overloading `add(int, int)` vs. `virtual void draw()` in a class hierarchy.

9. **Write a recursive function to solve the Tower of Hanoi for n disks.**  
   **Response**:  
   ```cpp
   void towerOfHanoi(int n, char src, char aux, char dest) {
       if (n == 1) { cout << "Move disk 1 from " << src << " to " << dest << endl; return; }
       towerOfHanoi(n-1, src, dest, aux);
       cout << "Move disk " << n << " from " << src << " to " << dest << endl;
       towerOfHanoi(n-1, aux, src, dest);
   }
   ```

10. **How do you overload the `<<` operator for a class?**  
    **Response**: Use a friend function to access private members and output to `ostream`.  
    ```cpp
    class X {
        int a;
    public:
        X(int x) : a(x) {}
        friend ostream& operator<<(ostream& os, const X& x) {
            os << x.a; return os;
        }
    };
    ```

11. **What is the role of `override` keyword in C++?**  
    **Response**: Ensures a function overrides a virtual base function, catching errors at compile time.  
    ```cpp
    class Base { virtual void f() {} };
    class Derived : public Base { void f() override {} };
    ```

12. **How do you implement a 2D array in a class with proper memory management?**  
    **Response**:  
    ```cpp
    class Matrix {
        int** mat; int rows, cols;
    public:
        Matrix(int r, int c) : rows(r), cols(c) {
            mat = new int*[r];
            for (int i = 0; i < r; i++) mat[i] = new int[c];
        }
        ~Matrix() { for (int i = 0; i < rows; i++) delete[] mat[i]; delete[] mat; }
    };
    ```

13. **What is the purpose of `const` correctness in class methods?**  
    **Response**: Prevents modification of object state in const contexts, enhancing safety.  
    ```cpp
    class X { int a; public: int get() const { return a; } };
    ```

14. **How do you handle null pointer dereferencing in a program?**  
    **Response**: Check pointers before use and set to `nullptr` after deletion.  
    ```cpp
    int* p = nullptr; if (p) cout << *p; // Avoids dereferencing
    ```

15. **Write a class hierarchy for shapes with polymorphic area calculation.**  
    **Response**:  
    ```cpp
    class Shape {
    public:
        virtual double area() = 0;
        virtual ~Shape() {}
    };
    class Circle : public Shape {
        double r;
    public:
        Circle(double r_) : r(r_) {}
        double area() override { return 3.14159 * r * r; }
    };
    ```

16. **What is the difference between deep and shallow copy in classes?**  
    **Response**: Shallow copy copies pointers; deep copy copies pointed-to data.  
    ```cpp
    class X {
        int* p;
    public:
        X(const X& other) { p = new int(*other.p); } // Deep copy
    };
    ```

17. **How do you implement function overloading for different return types?**  
    **Response**: Not possible directly; overload by parameter types/number.  
    ```cpp
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    ```

18. **Write a recursive function to check if a number is a palindrome.**  
    **Response**:  
    ```cpp
    bool isPalindrome(int n, int orig, int rev = 0) {
        if (n == 0) return rev == orig;
        return isPalindrome(n / 10, orig, rev * 10 + n % 10);
    }
    ```

19. **What is the purpose of `friend` functions in a class?**  
    **Response**: Grant non-member functions access to private members.  
    ```cpp
    class X {
        int a;
        friend void print(X x) { cout << x.a; }
    };
    ```

20. **How do you use `protected` inheritance in a class hierarchy?**  
    **Response**: Makes public/protected base members protected in the derived class.  
    ```cpp
    class Base { protected: int x; };
    class Derived : protected Base { void f() { x = 5; } };
    ```

21. **What is the output of a polymorphic call via a base class pointer?**  
    **Response**: Calls the derived class method if virtual.  
    ```cpp
    class Base { public: virtual void f() { cout << "Base"; } };
    class Derived : public Base { void f() override { cout << "Derived"; } };
    Base* b = new Derived; b->f(); // Derived
    ```

22. **How do you overload the assignment operator (`=`) for a class?**  
    **Response**:  
    ```cpp
    class X {
        int a;
    public:
        X& operator=(const X& other) { a = other.a; return *this; }
    };
    ```

23. **What is the role of virtual inheritance in multiple inheritance?**  
    **Response**: Prevents multiple copies of a base class in the hierarchy.  
    ```cpp
    class A {}; class B : virtual public A {}; class C : virtual public A {};
    class D : public B, public C {};
    ```

24. **How do you count words in a C-style string using pointers?**  
    **Response**:  
    ```cpp
    int countWords(char* str) {
        int count = 0; bool inWord = false;
        while (*str) {
            if (*str == ' ') inWord = false;
            else if (!inWord) { inWord = true; count++; }
            str++;
        }
        return count;
    }
    ```

25. **What are the implications of not defining a copy constructor in a class with dynamic memory?**  
    **Response**: Shallow copy leads to multiple pointers to the same memory, causing double-free errors.  
    ```cpp
    class X { int* p; public: X(int x) { p = new int(x); } ~X() { delete p; } }; // Needs copy constructor
    ```