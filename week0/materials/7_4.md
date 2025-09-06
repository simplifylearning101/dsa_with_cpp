# C++ Refresher for DSA Cohort: Hour 7 - Quiz

Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators), Hour 2 (control structures), Hour 3 (functions, scope, arrays), Hour 4 (pointers, references, strings), Hour 5 (dynamic memory, structures, recursion), Hour 6 (advanced pointers, strings, recursion), and Hour 7 (classes, objects, constructors, destructors, access mechanisms).

1. What is a class in C++?  
2. What is an object?  
3. How do you declare a class named `Person`?  
4. Write a constructor for a class `Car` with a model string.  
5. What is the purpose of a destructor?  
6. What does the `public` access specifier do?  
7. What does the `private` access specifier do?  
8. Write a class `Point` with a method to print x, y coordinates.  
9. What happens if you access a private member outside the class?  
10. How to initialize a class member in a constructor?  
11. Write a destructor for a class with a dynamic array.  
12. What is encapsulation in OOP?  
13. How to create an object of class `Book`?  
14. What is the output of `int x = 5; cout << x;`?  
15. Write a class `Counter` with a private count and increment method.  
16. What is the role of `std::getline` for strings?  
17. How to allocate a dynamic array in a class constructor?  
18. Write a recursive function to compute 5! (Hour 5).  
19. What is the size of `double` typically?  
20. How to ensure a destructor frees all dynamic memory?  
21. Write a class `Rectangle` with a private area method.  
22. What is the difference between `struct` and `class`?  
23. How to use a pointer to a class object?  
24. What does `break` do in a loop (Hour 2)?  
25. Write a class `Student` with private name and public getter.  
26. What happens if a constructor is not defined?  
27. How to implement a getter for a private member?  
28. Write a program to swap two numbers using references (Hour 4).  
29. What is a memory leak in a class context?  
30. Why use classes in DSA problems for interviews?

## Quiz Solutions
1. A blueprint defining data and functions for objects.  
2. An instance of a class.  
3. `class Person { /* members */ };`  
4. `Car(string m) : model(m) {}`  
5. Cleans up resources (e.g., dynamic memory) when an object is destroyed.  
6. Allows access to members from outside the class.  
7. Restricts access to within the class.  
8. `class Point { public: double x, y; void print() { cout << x << ", " << y; } };`  
9. Compiler error.  
10. Use initializer list, e.g., `: member(value)`.  
11. `~Class() { delete[] arr; arr = nullptr; }`  
12. Hiding data (private) and exposing interfaces (public).  
13. `Book b;` or `Book b("title", 100);`  
14. 5  
15. `class Counter { private: int count; public: Counter() : count(0) {} void increment() { count++; } int getCount() { return count; } };`  
16. Reads a line including spaces into a `std::string`.  
17. `arr = new int[size];`  
18. `unsigned long long fact(int n) { if (n <= 1) return 1; return n * fact(n-1); }` → 120  
19. 8 bytes typically.  
20. Use `delete` for all dynamic allocations in destructor.  
21. `class Rectangle { private: double l, w; double area() { return l * w; } public: Rectangle(double l_, double w_) : l(l_), w(w_) {} double getArea() { return area(); } };`  
22. `struct` defaults to public; `class` defaults to private.  
23. `Class* ptr = new Class(); ptr->method();`  
24. Exits the loop immediately.  
25. `class Student { private: string name; public: Student(string n) : name(n) {} string getName() { return name; } };`  
26. Compiler provides a default constructor.  
27. `Type getMember() { return member; }`  
28. `void swap(int& a, int& b) { int t = a; a = b; b = t; }`  
29. Unfreed dynamic memory allocated in a class.  
30. Organizes data and behavior for DSA structures like stacks, queues, or trees.