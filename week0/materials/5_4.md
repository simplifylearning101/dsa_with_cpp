# C++ Refresher for DSA Cohort: Hour 5 - Quiz

Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators), Hour 2 (control structures), Hour 3 (functions, scope, arrays), Hour 4 (pointers, references, strings), and Hour 5 (dynamic memory, structures, recursion).

1. What is dynamic memory allocation?  
2. How do you allocate a single integer dynamically?  
3. What does `delete` do in C++?  
4. Why set a pointer to `nullptr` after `delete`?  
5. Write a statement to allocate a dynamic array of 5 doubles.  
6. What is a structure in C++?  
7. How do you access a structure’s field?  
8. Write a structure for a car (make, model, year).  
9. What is recursion?  
10. What is a base case in recursion?  
11. Write a recursive function to compute 3! (factorial).  
12. What happens if you forget to free dynamic memory?  
13. How to declare a pointer to a structure?  
14. What is the output of `int x = 5; int* p = &x; cout << *p;`?  
15. Write a loop to read a string with spaces.  
16. What is the size of `float` typically?  
17. How to allocate a 2D dynamic array?  
18. Write a function to sum an array using pointers (Hour 4).  
19. What is the purpose of `std::getline`?  
20. Write a recursive function to compute sum of 1 to n.  
21. What is the dot operator (`.`) used for?  
22. How to avoid infinite recursion?  
23. Write a structure for a circle (radius) and compute area.  
24. What does `new` return if allocation fails?  
25. What is the output of `for (int i = 1; i <= 3; i++) cout << i;`?  
26. Explain logical OR with an example.  
27. Write a program to swap two numbers using references (Hour 4).  
28. How to initialize a dynamic array with zeros?  
29. What is a memory leak?  
30. Why use structures in DSA problems?

## Quiz Solutions
1. Allocating memory at runtime using `new`.  
2. `int* ptr = new int;`  
3. Frees dynamically allocated memory.  
4. Prevents accidental use of dangling pointers.  
5. `double* arr = new double[5];`  
6. A user-defined type grouping related variables.  
7. Using the dot operator, e.g., `struct.field`.  
8. `struct Car { string make; string model; int year; };`  
9. A function calling itself to solve smaller problems.  
10. Condition to stop recursion.  
11. `unsigned long long fact(int n) { if (n <= 1) return 1; return n * fact(n-1); }` → 6  
12. Memory leak, wasting resources.  
13. `structName* ptr;`  
14. 5  
15. `string s; getline(cin, s);`  
16. 4 bytes typically.  
17. `int** arr = new int*[rows]; for (int i = 0; i < rows; i++) arr[i] = new int[cols];`  
18. `int sum(int* arr, int size) { int s = 0; for (int i = 0; i < size; i++) s += *(arr + i); return s; }`  
19. Reads a line including spaces into a string.  
20. `int sum(int n) { if (n <= 0) return 0; return n + sum(n-1); }`  
21. Accesses structure fields.  
22. Ensure a base case stops recursion.  
23. `struct Circle { double radius; }; double area(Circle c) { return 3.14159 * c.radius * c.radius; }`  
24. Throws `std::bad_alloc` or returns `nullptr` (older systems).  
25. 123  
26. `true || false = true`, e.g., `x < 0 || x > 10`.  
27. `void swap(int& a, int& b) { int t = a; a = b; b = t; }`  
28. `int* arr = new int[size]();` or loop to set zeros.  
29. Unfreed dynamic memory, causing resource waste.  
30. Organizes related data for clarity in problems like linked lists.