### Quiz
Test your understanding with these 30 questions, mixing Hour 1 (variables, I/O, operators) and Hour 2 topics.

1. What is the purpose of an `if` statement?  
2. How does a `switch` statement differ from `if-else`?  
3. What does `break` do in a `switch`?  
4. Write a `for` loop to print 1 to 5.  
5. What’s the difference between `while` and `do-while`?  
6. What happens if you omit `break` in a `switch` case?  
7. How do you avoid an infinite loop in `while`?  
8. Write an `if` statement to check if a number is divisible by 3.  
9. What is the output of `for (int i = 0; i < 3; i++) { cout << i; }`?  
10. How many times does a `do-while` loop execute at minimum?  
11. What is the size of an `int` variable typically?  
12. Write a `switch` case for converting 1-3 to "Low", "Medium", "High".  
13. Explain operator precedence in `a + b * c`.  
14. What does `std::cin >> x` return if input fails?  
15. Write a `while` loop to sum numbers until negative input.  
16. What is the role of `default` in a `switch`?  
17. How to declare a `double` variable initialized to 3.14?  
18. What is the output of `10 % 3`?  
19. Write a nested `for` loop to print a 3x3 grid of numbers.  
20. What happens if a loop condition is initially false in `while`?  
21. Explain logical AND with an example.  
22. Write a program to check if input is a vowel using `if`.  
23. What is the purpose of `#include <iostream>`?  
24. How to ensure a `for` loop runs 10 times starting from 0?  
25. What does `++i` do in a loop?  
26. Write a `do-while` to read inputs until a positive number.  
27. What is the range of `char` in C++?  
28. How to handle decimal output with 2 places?  
29. What is undefined behavior in loops?  
30. Why use curly braces in control structures?

---

### Quiz Solutions
1. Executes code based on a condition.  
2. `switch` handles discrete values, `if-else` for ranges/conditions.  
3. Exits the `switch` to prevent fall-through.  
4. `for (int i = 1; i <= 5; i++) { cout << i << " "; }`  
5. `while` checks condition first; `do-while` runs at least once.  
6. Executes next cases (fall-through).  
7. Ensure condition eventually becomes false.  
8. `if (num % 3 == 0) cout << "Divisible";`  
9. 012  
10. Once.  
11. 4 bytes typically.  
12. `switch (x) { case 1: cout << "Low"; break; case 2: cout << "Medium"; break; case 3: cout << "High"; break; }`  
13. `*` before `+`, so `b * c` first.  
14. Sets failbit, input fails.  
15. `while (num >= 0) { sum += num; cin >> num; }`  
16. Handles unmatched cases.  
17. `double pi = 3.14;`  
18. 1  
19. `for (int i = 1; i <= 3; i++) { for (int j = 1; j <= 3; j++) { cout << i << j << " "; } cout << endl; }`  
20. Loop doesn’t execute.  
21. `true && true = true`, e.g., `age > 18 && height > 5.5`.  
22. `if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cout << "Vowel";`  
23. Includes I/O library.  
24. `for (int i = 0; i < 10; i++)`  
25. Increments `i` before use.  
26. `do { cin >> num; } while (num <= 0);`  
27. -128 to 127 (signed).  
28. `cout << fixed << setprecision(2);`  
29. E.g., infinite loop or uninitialized variables.  
30. Ensures clarity, avoids errors like dangling `else`.
