# C++ Refresher for DSA Cohort: Hour 3 - Quiz

Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators), Hour 2 (control structures), and Hour 3 (functions, scope, arrays).

1. What is a function in C++?  
2. Why use a function prototype?  
3. What does `return` do in a function?  
4. Write a function to double a number.  
5. What is the scope of a variable declared inside a function?  
6. What is a global variable?  
7. How do you access a global variable if shadowed?  
8. What is an array in C++?  
9. What is the index of the first element in an array?  
10. Write a loop to print array elements.  
11. What happens if you access an array out of bounds?  
12. Write a function to return sum of two integers.  
13. What is variable lifetime?  
14. How to declare an array of 5 floats?  
15. What is the output of `int arr[3] = {1, 2, 3}; cout << arr[1];`?  
16. Explain operator precedence in `a + b * c`.  
17. Write an `if` statement to check if a number is positive.  
18. What does `#include <iostream>` do?  
19. Write a `for` loop to sum an array of 4 integers.  
20. What is the difference between local and global scope?  
21. How to avoid variable shadowing?  
22. What does `break` do in a loop?  
23. Write a function to check if a number is odd.  
24. What is the size of `double` typically?  
25. How to initialize an array with zeros?  
26. What is the output of `for (int i = 0; i < 3; i++) cout << i;`?  
27. Explain logical OR with an example.  
28. Write a program to reverse a 3-element array.  
29. What happens if a function doesn’t return a value when expected?  
30. Why use functions in coding interviews?

## Quiz Solutions
1. A reusable block of code performing a specific task.  
2. Allows function declaration before definition.  
3. Sends a value back to the caller and exits function.  
4. `int doubleNum(int n) { return n * 2; }`  
5. Local to the function/block.  
6. Variable declared outside functions, accessible everywhere.  
7. Use `::variableName` to access global.  
8. A fixed-size collection of same-type elements.  
9. 0  
10. `for (int i = 0; i < size; i++) cout << arr[i];`  
11. Undefined behavior, likely crash.  
12. `int sum(int a, int b) { return a + b; }`  
13. Duration a variable exists in memory.  
14. `float arr[5];`  
15. 2  
16. `*` before `+`, so `b * c` first.  
17. `if (num > 0) cout << "Positive";`  
18. Includes I/O library.  
19. `int sum = 0; for (int i = 0; i < 4; i++) sum += arr[i];`  
20. Local is limited to block/function; global is program-wide.  
21. Use unique variable names or `::` for global.  
22. Exits the loop immediately.  
23. `bool isOdd(int n) { return n % 2 != 0; }`  
24. 8 bytes typically.  
25. `int arr[5] = {0};`  
26. 012  
27. `true || false = true`, e.g., `age < 18 || height < 5.5`.  
28. `int arr[3]; for (int i = 0; i < 3/2; i++) { int t = arr[i]; arr[i] = arr[2-i]; arr[2-i] = t; }`  
29. Undefined behavior or compiler error if return type expected.  
30. Shows modularity, readability, and problem-solving skills.