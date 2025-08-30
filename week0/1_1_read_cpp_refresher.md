# C++ Refresher for DSA Cohort:

This is a 1-hour refresher session designed to revise your foundational C++ concepts so you are ready for this 10-week Data Structures and Algorithms (DSA) cohort. 

## Topics Covered
We will revise the following concepts:  
1. Variables and Data Types  
2. Input/Output Operations  
3. Operators  
4. Basic Program Structure  

### Concept 1: Variables and Data Types
Variables are like containers in a kitchen where you store ingredients—each has a name and holds a specific type of item (e.g., a jar for flour or a bowl for eggs). In C++, variables store data, and data types define what kind of data they can hold (`int` for whole numbers, `double` for decimals, `char` for single characters, `bool` for true/false, etc.). Declaring a variable tells the compiler to reserve space in memory. Always initialize variables to avoid unexpected values.

**Example Program: Basic Variable Declaration and Usage**
```cpp
#include <iostream>  // Include the input/output stream library for cout and cin

int main() {
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
Tip: can we reduce typing std:: everytime?

### Concept 2: Input/Output Operations
In C++, we use `std::cin` for input from the keyboard and `std::cout` for output to the screen. Always include `<iostream>` and use `std::` namespace or `using namespace std;` for simplicity. Handle inputs carefully to avoid errors, like reading extra spaces.

**Example Program: Simple Input and Output**
```cpp
#include <iostream>  // For cin and cout

int main() {
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
**Expected Outcome**
Enter your name: Alice
Enter quantity of apples: 5
Hello, Alice! You want 5 apples.

### Concept 3: Operators
Operators are like math tools in a calculator: 
- arithmetic (`+`, `-`, `*`, `/`, `%` for remainder) 
- relational (`==`, `!=`, `>`, `<`, `>=`, `<=` for comparisons)
- logical (`&&` for AND, `||` for OR, `!` for NOT) 
- and assignment (`=`) 

Be careful with division (integer division truncates decimals) and operator precedence (use parentheses for clarity).

**Example Program: Using Operators for a Simple Calculator**
```cpp
#include <iostream>

int main() {
    int a = 10;
    int b = 3;
    
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

### Concept 4: Basic Program Structure
Every C++ program is like a story: it has a beginning (`#include` directives and `main()`), middle (code body), and end (`return 0;`). 

Use comments (`//` or `/* */`) for notes, like labels on kitchen shelves. Compile with `g++` and run the executable. Common errors: missing semicolons or unmatched braces.

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