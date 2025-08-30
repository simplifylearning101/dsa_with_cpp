# C++ Refresher for DSA Cohort: Hour 1

This is a 1-hour refresher session designed to revise foundational C++ concepts for students preparing for a 10-week Data Structures and Algorithms (DSA) cohort. The focus is on variables and data types, input/output operations, operators, and basic program structure. These are explained with real-world analogies and example programs to ensure clarity for beginners, with an emphasis on interview preparation.

## Hour 1: Topics Covered
We will revise the following concepts:  
1. Variables and Data Types  
2. Input/Output Operations  
3. Operators  
4. Basic Program Structure  

---

### Concept 1: Variables and Data Types
Variables are like containers in a kitchen where you store ingredients—each has a name and holds a specific type of item (e.g., a jar for flour or a bowl for eggs). In C++, variables store data, and data types define what kind of data they can hold (`int` for whole numbers, `double` for decimals, `char` for single characters, `bool` for true/false, etc.). Declaring a variable tells the compiler to reserve space in memory. Always initialize variables to avoid unexpected values.

**Example Program: Basic Variable Declaration and Usage**
```cpp
#include <iostream>  // Include the input/output stream library for cout and cin

int main() {  // Main function: entry point of every C++ program
    int age = 25;  // Declare an integer variable 'age' and initialize it to 25 (whole number, like a person's age)
    double height = 5.9;  // Declare a double variable 'height' for decimal values (like height in feet)
    char initial = 'A';  // Declare a char variable 'initial' for a single character (like first letter of a name)
    bool isStudent = true;  // Declare a boolean variable 'isStudent' (true or false, like yes/no for student status)
    
    // Output the values to the console
    std::cout << "Age: " << age << std::endl;  // Print age followed by a newline
    std::cout << "Height: " << height << std::endl;  // Print height
    std::cout << "Initial: " << initial << std::endl;  // Print initial
    std::cout << "Is Student: " << (isStudent ? "Yes" : "No") << std::endl;  // Print yes/no based on bool value
    
    return 0;  // Return 0 to indicate successful program execution
}
```
**Expected Outcome**:  
```
Age: 25
Height: 5.9
Initial: A
Is Student: Yes
```
This program is like listing out personal details on a form—simple storage and display.

---

### Concept 2: Input/Output Operations
Input/output (I/O) is like talking to a cashier: input is what you tell them (e.g., your order), output is what they say back (e.g., total cost). In C++, we use `std::cin` for input from the keyboard and `std::cout` for output to the screen. Always include `<iostream>` and use `std::` namespace or `using namespace std;` for simplicity. Handle inputs carefully to avoid errors, like reading extra spaces.

**Example Program: Simple Input and Output**
```cpp
#include <iostream>  // For cin and cout

int main() {  // Program starts here
    std::string name;  // Declare a string variable to hold text (like a full name)
    int quantity;  // Declare an int for a number (like items in a shopping cart)
    
    // Prompt user for input
    std::cout << "Enter your name: ";  // Output a message
    std::cin >> name;  // Read input into 'name' (stops at space, so first name only)
    
    std::cout << "Enter quantity of apples: ";  // Another prompt
    std::cin >> quantity;  // Read integer input
    
    // Output the results
    std::cout << "Hello, " << name << "! You want " << quantity << " apples." << std::endl;  // Combine and print
    
    return 0;  // End program
}
```
**Expected Outcome** (assuming user inputs "Alice" and "5"):  
```
Enter your name: Alice
Enter quantity of apples: 5
Hello, Alice! You want 5 apples.
```
This is like a basic shopping interaction—get user info and respond.

---

### Concept 3: Operators
Operators are like math tools in a calculator: arithmetic (`+`, `-`, `*`, `/`, `%` for remainder), relational (`==`, `!=`, `>`, `<`, `>=`, `<=` for comparisons), logical (`&&` for AND, `||` for OR, `!` for NOT), and assignment (`=`). They help manipulate variables, like adding items to a bill or checking if stock is low. Be careful with division (integer division truncates decimals) and operator precedence (use parentheses for clarity).

**Example Program: Using Operators for a Simple Calculator**
```cpp
#include <iostream>  // For I/O

int main() {  // Main function
    int a = 10;  // First number (like price of item 1)
    int b = 3;   // Second number (like price of item 2)
    
    // Arithmetic operators
    int sum = a + b;  // Addition: total cost
    int diff = a - b; // Subtraction: difference in prices
    int prod = a * b; // Multiplication: repeated addition
    int quot = a / b; // Division: integer division (truncates to 3)
    int rem = a % b;  // Modulus: remainder (1)
    
    // Relational and logical (checking if a > b AND sum > 10)
    bool isGreaterAndSumBig = (a > b) && (sum > 10);  // True if both conditions hold
    
    // Output results
    std::cout << "Sum: " << sum << std::endl;  // 13
    std::cout << "Difference: " << diff << std::endl;  // 7
    std::cout << "Product: " << prod << std::endl;  // 30
    std::cout << "Quotient: " << quot << std::endl;  // 3
    std::cout << "Remainder: " << rem << std::endl;  // 1
    std::cout << "Is a > b and sum > 10? " << (isGreaterAndSumBig ? "Yes" : "No") << std::endl;  // Yes
    
    return 0;
}
```
**Expected Outcome**:  
```
Sum: 13
Difference: 7
Product: 30
Quotient: 3
Remainder: 1
Is a > b and sum > 10? Yes
```
This mimics calculating a restaurant bill with checks.

---

### Concept 4: Basic Program Structure
Every C++ program is like a story: it has a beginning (`#include` directives and `main()`), middle (code body), and end (`return 0;`). Use comments (`//` or `/* */`) for notes, like labels on kitchen shelves. Compile with `g++` and run the executable. Common errors: missing semicolons or unmatched braces.

**Example Program: Hello World with Structure**
```cpp
// This is a single-line comment: Program to greet the world

/* This is a multi-line comment:
   Author: Your Teacher
   Purpose: Demonstrate basic structure */

#include <iostream>  // Header for I/O

int main() {  // Function where execution begins
    std::cout << "Hello, World!" << std::endl;  // Print greeting
    return 0;  // Successful exit
}
```
**Expected Outcome**:  
```
Hello, World!
```
This is the "first recipe" every programmer learns.

---

### Points to Remember for Interview Preparation
- Understand data type sizes (e.g., `int` is usually 4 bytes) and ranges to avoid overflow in interviews (e.g., use `long long` for large numbers).  
- Know the difference between signed and unsigned types for edge cases in problems.  
- Master operator precedence and associativity—interviews often test tricky expressions like `a + b * c`.  
- Use `std::endl` vs `\n` for output: `endl` flushes the buffer, which can be slower in performance-critical code.  
- Always handle input validation; `cin` can fail—use `cin.fail()` in robust code for interviews.  
- Remember `#include` guards and namespaces to avoid conflicts in larger programs.  
- In interviews, explain why you choose a data type (e.g., `float` vs `double` for precision).  
- Practice writing clean, commented code—interviewers value readability.  
- Know common pitfalls: uninitialized variables lead to undefined behavior.  
- For DSA prep, these basics are key for implementing algorithms without syntax errors.

---

### Homework
Practice these 15 problems to reinforce the concepts. They increase in complexity to build your skills.

1. **Problem**: Write a program to declare and print three variables: an `int` for age, a `double` for salary, and a `char` for grade.  
   **Outcome**: Output the values in a formatted sentence.  
   **Example**: Age: 30, Salary: 50000.50, Grade: A → "I am 30 years old, earn 50000.50, and my grade is A."

2. **Problem**: Create a program that takes two integers as input and swaps their values without using a temporary variable (use arithmetic operators).  
   **Outcome**: Output the swapped values.  
   **Example**: Input 5 and 10 → Output: 10 and 5.

3. **Problem**: Write a program to calculate the area of a circle using `double` for pi (3.14159) and radius input.  
   **Outcome**: Print the area with two decimal places.  
   **Example**: Radius 7 → Area: 153.94

4. **Problem**: Develop a program that reads a full name (first and last) using `std::string` and outputs initials.  
   **Outcome**: Combine and print initials.  
   **Example**: "John Doe" → "J.D."

5. **Problem**: Make a program to demonstrate all arithmetic operators on two floats input by user.  
   **Outcome**: Print sum, difference, product, quotient, and modulus (if applicable).  
   **Example**: 4.5 and 2.0 → Sum: 6.5, etc.

6. **Problem**: Write a program to check if a number is even or odd using modulus operator.  
   **Outcome**: Output "Even" or "Odd".  
   **Example**: 4 → "Even"

7. **Problem**: Create a basic converter: input temperature in Celsius, output in Fahrenheit (F = C*9/5 + 32).  
   **Outcome**: Print converted value.  
   **Example**: 25 → 77

8. **Problem**: Program to take three numbers and find the maximum using relational operators (no if statements yet).  
   **Outcome**: Output the max.  
   **Example**: 1, 3, 2 → 3 (hint: use nested ternary, but keep simple).

9. **Problem**: Write a program to demonstrate logical operators: check if age >=18 and height >=5.5 for eligibility.  
   **Outcome**: "Eligible" or "Not Eligible".  
   **Example**: Age 20, Height 6.0 → "Eligible"

10. **Problem**: Develop a program that calculates simple interest: principal, rate, time as inputs (I = P*R*T/100).  
    **Outcome**: Print interest.  
    **Example**: 1000, 5, 2 → 100

11. **Problem**: Create a program to read a character and check if it's a vowel using logical OR.  
    **Outcome**: "Vowel" or "Consonant".  
    **Example**: 'a' → "Vowel"

12. **Problem**: Write a program to demonstrate assignment operators: start with x=10, then x+=5, x*=2, etc., printing each.  
    **Outcome**: Show step-by-step changes.  
    **Example**: Outputs 10, 15, 30, etc.

13. **Problem**: Program to calculate BMI: weight (kg) and height (m) inputs, BMI = weight / (height*height).  
    **Outcome**: Print BMI category (underweight <18.5, normal 18.5-24.9, etc.) using relational ops.  
    **Example**: 70, 1.75 → ~22.86, "Normal"

14. **Problem**: Create a program that takes a string password and checks length >=8 using relational.  
    **Outcome**: "Valid" or "Invalid".  
    **Example**: "secret" → "Invalid"

15. **Problem**: Write a program to convert seconds to hours, minutes, seconds using arithmetic.  
    **Outcome**: Print in format HH:MM:SS.  
    **Example**: 3661 → 01:01:01

---

### Homework Solutions
1.  
```cpp
#include <iostream>
int main() {
    int age = 30;
    double salary = 50000.50;
    char grade = 'A';
    std::cout << "I am " << age << " years old, earn " << salary << ", and my grade is " << grade << "." << std::endl;
    return 0;
}
```

2.  
```cpp
#include <iostream>
int main() {
    int a, b;
    std::cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    std::cout << a << " " << b << std::endl;
    return 0;
}
```

3.  
```cpp
#include <iostream>
#include <iomanip>  // For setprecision
int main() {
    double radius, pi = 3.14159;
    std::cin >> radius;
    double area = pi * radius * radius;
    std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    return 0;
}
```

4.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string first, last;
    std::cin >> first >> last;
    std::cout << first[0] << "." << last[0] << "." << std::endl;
    return 0;
}
```

5.  
```cpp
#include <iostream>
int main() {
    float a, b;
    std::cin >> a >> b;
    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Diff: " << a - b << std::endl;
    std::cout << "Prod: " << a * b << std::endl;
    std::cout << "Quot: " << a / b << std::endl;
    // Modulus not for float, skip or cast
    return 0;
}
```

6.  
```cpp
#include <iostream>
int main() {
    int num;
    std::cin >> num;
    std::cout << (num % 2 == 0 ? "Even" : "Odd") << std::endl;
    return 0;
}
```

7.  
```cpp
#include <iostream>
int main() {
    double c;
    std::cin >> c;
    double f = c * 9 / 5 + 32;
    std::cout << f << std::endl;
    return 0;
}
```

8.  
```cpp
#include <iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int max = (a > b ? (a > c ? a : c) : (b > c ? b : c));
    std::cout << max << std::endl;
    return 0;
}
```

9.  
```cpp
#include <iostream>
int main() {
    int age;
    double height;
    std::cin >> age >> height;
    std::cout << (age >= 18 && height >= 5.5 ? "Eligible" : "Not Eligible") << std::endl;
    return 0;
}
```

10.  
```cpp
#include <iostream>
int main() {
    double p, r, t;
    std::cin >> p >> r >> t;
    double i = p * r * t / 100;
    std::cout << i << std::endl;
    return 0;
}
```

11.  
```cpp
#include <iostream>
int main() {
    char ch;
    std::cin >> ch;
    bool isVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    std::cout << (isVowel ? "Vowel" : "Consonant") << std::endl;
    return 0;
}
```

12.  
```cpp
#include <iostream>
int main() {
    int x = 10;
    std::cout << x << std::endl;
    x += 5; std::cout << x << std::endl;
    x *= 2; std::cout << x << std::endl;
    x -= 10; std::cout << x << std::endl;
    x /= 5; std::cout << x << std::endl;
    return 0;
}
```

13.  
```cpp
#include <iostream>
int main() {
    double w, h;
    std::cin >> w >> h;
    double bmi = w / (h * h);
    std::string cat = (bmi < 18.5 ? "Underweight" : (bmi < 25 ? "Normal" : "Overweight"));
    std::cout << bmi << " " << cat << std::endl;
    return 0;
}
```

14.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string pass;
    std::cin >> pass;
    std::cout << (pass.length() >= 8 ? "Valid" : "Invalid") << std::endl;
    return 0;
}
```

15.  
```cpp
#include <iostream>
#include <iomanip>
int main() {
    int sec;
    std::cin >> sec;
    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    int s = sec % 60;
    std::cout << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ":" << std::setw(2) << s << std::endl;
    return 0;
}
```

---

### Quiz
Test your understanding with these 30 questions covering today's topics.

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

---

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

---

**Additional Practice**: Solve problems on platforms like LeetCode or NeetCode that involve basic arithmetic or string manipulation (e.g., "Add Two Integers" or "Reverse String") to reinforce these concepts. Focus on writing clean, commented code to prepare for coding interviews.