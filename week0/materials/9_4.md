# C++ Refresher for DSA Cohort: Very Hard Interview Questions

These 25 very hard interview questions challenge advanced mastery of Hours 1-8, focusing on complex scenarios for DSA interviews.

1. **How do you implement a deep copy for a class with a pointer to a dynamic array?**  
   **Response**: Copy each element of the array in the copy constructor.  
   ```cpp
   class Array {
       int* arr; int size;
   public:
       Array(int s) : size(s) { arr = new int[s]; }
       Array(const Array& other) : size(other.size) {
           arr = new int[size];
           for (int i = 0; i < size; i++) arr[i] = other.arr[i];
       }
       ~Array() { delete[] arr; }
   };
   ```

2. **Write a recursive function to generate all subsets of a string.**  
   **Response**: Include or exclude each character recursively.  
   ```cpp
   void subsets(string str, string curr, int i) {
       if (i == str.length()) { cout << curr << endl; return; }
       subsets(str, curr, i + 1);
       subsets(str, curr + str[i], i + 1);
   }
   ```

3. **How do you handle the diamond problem without virtual inheritance?**  
   **Response**: Use scope resolution to disambiguate or redesign to avoid multiple inheritance.  
   ```cpp
   class A { public: int x; };
   class B : public A {}; class C : public A {};
   class D : public B, public C { void f() { B::x = 5; } };
   ```

4. **Implement a polymorphic binary tree node class with inorder traversal.**  
   **Response**:  
   ```cpp
   class TreeNode {
   public:
       int val;
       virtual void inorder() = 0;
       virtual ~TreeNode() {}
   };
   class BinaryNode : public TreeNode {
       BinaryNode* left, *right;
   public:
       BinaryNode(int v) { val = v; left = right = nullptr; }
       void inorder() override {
           if (left) left->inorder();
           cout << val << " ";
           if (right) right->inorder();
       }
       ~BinaryNode() { delete left; delete right; }
   };
   ```

5. **How do you overload the `*` operator for matrix multiplication?**  
   **Response**:  
   ```cpp
   class Matrix {
       int mat[2][2];
   public:
       Matrix() { /* input */ }
       Matrix operator*(const Matrix& m) {
           Matrix result;
           for (int i = 0; i < 2; i++)
               for (int j = 0; j < 2; j++) {
                   result.mat[i][j] = 0;
                   for (int k = 0; k < 2; k++)
                       result.mat[i][j] += mat[i][k] * m.mat[k][j];
               }
           return result;
       }
   };
   ```

6. **What is the virtual function table (vtable) and how does it work?**  
   **Response**: A vtable is a compiler-generated table storing pointers to virtual functions for a class, used for runtime polymorphism. Each object has a vptr pointing to its class’s vtable.  
   **Example**: `class Base { virtual void f() {} };` creates a vtable for `Base`.

7. **Write a class with a custom copy assignment operator handling dynamic memory.**  
   **Response**:  
   ```cpp
   class X {
       int* p;
   public:
       X(int x) { p = new int(x); }
       X& operator=(const X& other) {
           if (this != &other) {
               delete p;
               p = new int(*other.p);
           }
           return *this;
       }
       ~X() { delete p; }
   };
   ```

8. **How do you implement a stack using a class with inheritance from a container?**  
   **Response**:  
   ```cpp
   class Container { public: virtual void push(int) = 0; virtual ~Container() {} };
   class Stack : public Container {
       int arr[100]; int top = -1;
   public:
       void push(int x) override { arr[++top] = x; }
   };
   ```

9. **What are the risks of multiple inheritance and how to mitigate them?**  
   **Response**: Risks include ambiguity and diamond problem. Mitigate with virtual inheritance, scope resolution, or composition.  
   **Example**: `class B : virtual public A {};`

10. **Write a recursive function to compute the sum of digits in a number.**  
    **Response**:  
    ```cpp
    int sumDigits(int n) {
        if (n == 0) return 0;
        return (n % 10) + sumDigits(n / 10);
    }
    ```

11. **How do you overload the subscript operator (`[]`) for a class?**  
    **Response**:  
    ```cpp
    class Array {
        int arr[100];
    public:
        int& operator[](int i) { return arr[i]; }
    };
    ```

12. **What is the difference between early and late binding in C++?**  
    **Response**: Early binding resolves function calls at compile time (e.g., overloading); late binding uses vtables at runtime (e.g., virtual functions).  
    **Example**: `virtual void f()` uses late binding.

13. **Write a class hierarchy for a polymorphic file system (File, Directory).**  
    **Response**:  
    ```cpp
    class FSObject {
    public:
        virtual void print() = 0;
        virtual ~FSObject() {}
    };
    class File : public FSObject {
        string name;
    public:
        File(string n) : name(n) {}
        void print() override { cout << "File: " << name << endl; }
    };
    class Directory : public FSObject {
        string name;
    public:
        Directory(string n) : name(n) {}
        void print() override { cout << "Directory: " << name << endl; }
    };
    ```

14. **How do you handle exceptions in a class destructor?**  
    **Response**: Avoid throwing exceptions in destructors; use try-catch if necessary to log errors.  
    ```cpp
    class X { public: ~X() { try { /* cleanup */ } catch (...) { /* log */ } } };
    ```

15. **What is the rule of three/five in C++?**  
    **Response**: If a class manages resources, define destructor, copy constructor, copy assignment (three); add move constructor, move assignment (five).  
    **Example**: Class with dynamic memory needs all five.

16. **Write a recursive function to compute binary representation of a number.**  
    **Response**:  
    ```cpp
    void toBinary(int n) {
        if (n == 0) return;
        toBinary(n / 2);
        cout << n % 2;
    }
    ```

17. **How do you implement a polymorphic iterator for a custom container?**  
    **Response**: Use an abstract iterator class with derived concrete iterators.  
    ```cpp
    class Iterator {
    public:
        virtual int next() = 0;
        virtual ~Iterator() {}
    };
    class ArrayIterator : public Iterator {
        int* arr; int i, size;
    public:
        ArrayIterator(int* a, int s) : arr(a), i(0), size(s) {}
        int next() override { return i < size ? arr[i++] : -1; }
    };
    ```

18. **What is the impact of not using virtual functions in a polymorphic hierarchy?**  
    **Response**: Base class method is called instead of derived, breaking polymorphism.  
    ```cpp
    class Base { void f() { cout << "Base"; } };
    class Derived : public Base { void f() { cout << "Derived"; } };
    Base* b = new Derived; b->f(); // Base
    ```

19. **How do you overload the function call operator (`()`) for a class?**  
    **Response**:  
    ```cpp
    class Functor {
        int x;
    public:
        Functor(int x_) : x(x_) {}
        int operator()(int y) { return x + y; }
    };
    ```

20. **What is the role of `explicit` keyword in constructors?**  
    **Response**: Prevents implicit conversions, ensuring explicit object creation.  
    ```cpp
    class X { public: explicit X(int a) {} };
    X x = 5; // Error if explicit
    ```

21. **Write a class to implement a linked list node with inheritance.**  
    **Response**:  
    ```cpp
    class Node {
    public:
        virtual void print() = 0;
        virtual ~Node() {}
    };
    class ListNode : public Node {
        int val; ListNode* next;
    public:
        ListNode(int v) : val(v), next(nullptr) {}
        void print() override { cout << val; }
    };
    ```

22. **How do you optimize a recursive function like Fibonacci?**  
    **Response**: Use memoization or iteration to avoid redundant calculations.  
    ```cpp
    int fib(int n, int* memo) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = fib(n-1, memo) + fib(n-2, memo);
    }
    ```

23. **What are the pitfalls of operator overloading?**  
    **Response**: Overloading non-intuitive operators or ignoring operator precedence can confuse users. Ensure natural semantics.  
    **Example**: Overloading `+` for subtraction is misleading.

24. **How do you implement a polymorphic queue with dynamic memory?**  
    **Response**:  
    ```cpp
    class Queue {
    public:
        virtual void enqueue(int) = 0;
        virtual ~Queue() {}
    };
    class ArrayQueue : public Queue {
        int* arr; int size, cap;
    public:
        ArrayQueue(int c) : cap(c), size(0) { arr = new int[c]; }
        void enqueue(int x) override { if (size < cap) arr[size++] = x; }
        ~ArrayQueue() { delete[] arr; }
    };
    ```

25. **What is the difference between `new` and `malloc` in C++?**  
    **Response**: `new` calls constructors and is type-safe; `malloc` allocates raw memory without initialization.  
    ```cpp
    class X { public: X() { cout << "Constructor"; } };
    X* x = new X; // Calls constructor
    X* y = (X*)malloc(sizeof(X)); // No constructor
    ```