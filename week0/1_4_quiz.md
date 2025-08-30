
### Quiz
Test your understanding with these 30 questions covering today's topics.

Do not jump to answers

1. What is a variable in C++?  
2. Name three basic data types in C++.  
3. What does `#include <iostream>` do?  
4. Explain the difference between `int` and `double`.  
5. What is the output of `10 / 3` in integer division?  
6. How do you read input from the user?  
7. What operator is used for modulus?  
8. What does `&&` mean?  
9. Write a line to declare a `bool` variable initialized to `false`.  
10. What is the entry point of a C++ program?  
11. Explain operator precedence with an example.  
12. What happens if you don't initialize a variable?  
13. How to output a newline without `endl`?  
14. What is the size of `char` in bytes?  
15. Difference between `=` and `==`.  
16. Write code to swap two variables using a temp.  
17. What is `unsigned int`?  
18. How to handle decimal precision in output?  
19. Explain logical NOT with example.  
20. What is `std::string`?  
21. Why use comments in code?  
22. What is undefined behavior?  
23. Convert 100 Fahrenheit to Celsius (formula).  
24. Check if `5 > 3 || 2 < 1`.  
25. What does `cin >>` do if input is invalid?  
26. Name assignment operators besides `=`.  
27. What is the range of `short int`?  
28. How to include multiple headers?  
29. Explain `%` for negative numbers.  
30. Why avoid `using namespace std;` in large programs?


### Quiz Solutions
1. A named storage location for data.  
2. `int`, `double`, `char` (or others like `bool`, `float`).  
3. Includes library for input/output.  
4. `int` for whole numbers, `double` for floating-point.  
5. 3 (truncates).  
6. Using `std::cin >> variable;`  
7. `%`  
8. Logical AND.  
9. `bool flag = false;`  
10. `int main()`  
11. Multiplication before addition, e.g., `2 + 3 * 4 = 14`.  
12. Undefined behavior, garbage value.  
13. Use `"\n"`  
14. 1 byte.  
15. `=` is assignment, `==` is equality check.  
16. `int temp = a; a = b; b = temp;`  
17. Int that can't be negative, larger positive range.  
18. Use `<iomanip>` and `std::setprecision(n)`  
19. `!true = false`, inverts bool.  
20. Data type for strings of characters.  
21. To explain code for readability.  
22. Unpredictable results from invalid operations.  
23. `(F - 32) * 5/9 = 37.777...`  
24. `true` (since first is true).  
25. Sets failbit, input fails.  
26. `+=`, `-=`, `*=`, `/=`, `%=`  
27. -32768 to 32767 (typically).  
28. Multiple `#include` lines.  
29. Implementation-defined, often negative remainder.  
30. Avoids name conflicts with other namespaces.
