# C++ Refresher for DSA Cohort: Hour 6 - Quiz

Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators), Hour 2 (control structures), Hour 3 (functions, scope, arrays), Hour 4 (pointers, references, strings), Hour 5 (dynamic memory, structures, recursion), and Hour 6 (advanced pointers, strings, recursion).

1. What is pointer arithmetic?  
2. How do you access the third element of an array using pointer arithmetic?  
3. What is a function pointer?  
4. Write a function pointer declaration for a function returning int and taking two ints.  
5. What is a double pointer?  
6. How do you reverse a C-style string using pointers?  
7. What is the difference between `std::string` and C-style string?  
8. Write a loop to count characters in a C-style string.  
9. What is tail recursion?  
10. What is backtracking in recursion?  
11. Write a recursive function to compute 4!.  
12. What does `*(ptr + 2)` do for an array pointer?  
13. How to declare a C-style string of size 50?  
14. What is the output of `int x = 5; int* p = &x; int** pp = &p; **pp = 10; cout << x;`?  
15. Write a function to concatenate two C-style strings.  
16. What is the purpose of `std::getline` for strings?  
17. How to avoid stack overflow in recursion?  
18. Write a recursive function to sum 1 to 5.  
19. What is the size of a pointer on a 64-bit system?  
20. How to check if two C-style strings are equal?  
21. What does `delete[]` do for dynamic arrays?  
22. Write a function pointer to call a function that triples a number.  
23. What is the output of `for (int i = 0; i < 3; i++) cout << i;`?  
24. Explain divide-and-conquer with an example.  
25. Write a recursive function to check if a string is a palindrome.  
26. How to allocate a dynamic C-style string?  
27. What is the role of `nullptr` in pointer operations?  
28. Write a program to swap two numbers using pointers (Hour 4).  
29. What is undefined behavior with C-style strings?  
30. Why use recursion for problems like Tower of Hanoi in interviews?

## Quiz Solutions
1. Performing arithmetic on pointers to navigate memory (e.g., `ptr + 1`).  
2. `*(arr + 2)` or `arr[2]`.  
3. A pointer to a function’s address, used to call functions dynamically.  
4. `int (*func)(int, int);`  
5. A pointer to another pointer, e.g., `int** pp`.  
6. `while (*s1 && *s2) { if (*s1 != *s2) return false; s1++; s2++; } return *s1 == *s2;`  
7. `std::string` is a class with dynamic size; C-style is a null-terminated char array.  
8. `int len = 0; while (str[len]) len++;`  
9. Recursion where the recursive call is the last operation.  
10. Exploring all possibilities, undoing changes if needed (e.g., permutations).  
11. `unsigned long long fact(int n) { if (n <= 1) return 1; return n * fact(n-1); }` → 24  
12. Accesses the third element of the array.  
13. `char str[50];`  
14. 10  
15. `void concat(char* dest, char* src) { while (*dest) dest++; while (*src) *dest++ = *src++; *dest = '\0'; }`  
16. Reads a line including spaces into a `std::string`.  
17. Use clear base cases and optimize with tail recursion or iteration.  
18. `int sum(int n) { if (n <= 0) return 0; return n + sum(n-1); }` → 15  
19. 8 bytes typically.  
20. Compare characters using pointers until null or mismatch.  
21. Frees memory allocated for a dynamic array.  
22. `int triple(int x) { return x * 3; } int (*funcPtr)(int) = triple;`  
23. 012  
24. Splitting problem into smaller parts, e.g., merge sort divides array.  
25. `bool isPal(string s, int i) { if (i >= s.length()/2) return true; if (s[i] != s[s.length()-1-i]) return false; return isPal(s, i+1); }`  
26. `char* str = new char[size];`  
27. Indicates a null pointer, prevents accidental dereferencing.  
28. `void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }`  
29. E.g., accessing beyond null terminator or buffer overflow.  
30. Shows problem-solving clarity, handles complex problems like tree traversals elegantly.