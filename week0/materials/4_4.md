# C++ Refresher for DSA Cohort: Hour 4 - Quiz

Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators), Hour 2 (control structures), Hour 3 (functions, scope, arrays), and Hour 4 (pointers, references, strings).

1. What is a pointer in C++?  
2. How do you declare a pointer to an integer?  
3. What does the `&` operator do when used with a variable?  
4. What is dereferencing a pointer?  
5. Write a statement to initialize a pointer to `nullptr`.  
6. What is a reference in C++?  
7. How does a reference differ from a pointer?  
8. Write a function to triple a number using a reference.  
9. What is `std::string` used for?  
10. How do you read a string with spaces?  
11. What happens if you dereference a null pointer?  
12. Write a loop to print characters of a string.  
13. What is the output of `int x = 5; int* p = &x; *p = 10; cout << x;`?  
14. How to concatenate two `std::string` objects?  
15. What is the scope of a reference?  
16. Write a function to swap two strings using references.  
17. What does `std::getline` do?  
18. How to access the third element of an array using a pointer?  
19. What is the output of `for (int i = 0; i < 2; i++) cout << i;`?  
20. Explain logical AND with an example.  
21. Write a function to check if a string is a palindrome.  
22. What is the size of a pointer typically?  
23. How to declare an array of 3 strings?  
24. What does `break` do in a `switch`?  
25. Write a pointer-based function to find array sum.  
26. What is the range of `int` typically?  
27. How to avoid dangling pointers?  
28. Write an `if` statement to check if a string is longer than 5.  
29. What is undefined behavior with pointers?  
30. Why use references in function parameters for interviews?

## Quiz Solutions
1. A variable storing a memory address.  
2. `int* ptr;`  
3. Returns the address of the variable.  
4. Accessing the value at the pointer’s address using `*`.  
5. `int* ptr = nullptr;`  
6. An alias for an existing variable.  
7. References are aliases, cannot be null or reassigned; pointers store addresses.  
8. `void triple(int& n) { n *= 3; }`  
9. Storing and manipulating sequences of characters.  
10. Use `std::getline(std::cin, str);`  
11. Undefined behavior, likely crash.  
12. `for (char c : str) cout << c;`  
13. 10  
14. `s1 + s2` or `s1 += s2;`  
15. Same as the variable it aliases.  
16. `void swap(std::string& s1, std::string& s2) { std::string t = s1; s1 = s2; s2 = t; }`  
17. Reads a full line including spaces into a string.  
18. `*(arr + 2)` or `arr[2]`  
19. 01  
20. `true && true = true`, e.g., `x > 0 && y > 0`.  
21. `bool isPalindrome(std::string& s) { int n = s.length(); for (int i = 0; i < n/2; i++) if (s[i] != s[n-1-i]) return false; return true; }`  
22. 4 or 8 bytes depending on system (32/64-bit).  
23. `std::string arr[3];`  
24. Exits the switch to prevent fall-through.  
25. `int sum(int* arr, int size) { int s = 0; for (int i = 0; i < size; i++) s += *(arr + i); return s; }`  
26. -2,147,483,648 to 2,147,483,647 (32-bit).  
27. Initialize pointers, set to `nullptr` after deletion.  
28. `if (str.length() > 5) cout << "Long";`  
29. E.g., dereferencing null or dangling pointers.  
30. Simplifies syntax, avoids copying, shows efficiency awareness.