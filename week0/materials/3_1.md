# C++ Refresher for DSA Cohort: Hour 3 - Concepts

This is the third hour of a 5-6 hour C++ refresher designed for students preparing for a 10-week Data Structures and Algorithms (DSA) cohort. In this session, we cover functions, scope, and basic arrays. These are like tools in a toolbox: functions organize tasks, scope defines where tools are accessible, and arrays store multiple items like a shelf. The focus is on clarity for beginners, with real-world analogies and heavily commented programs to prepare for coding interviews.

## Hour 3: Topics Covered
We will revise the following concepts:  
1. Functions and Function Prototypes  
2. Scope and Lifetime of Variables  
3. Basic Arrays  

---

### Concept 1: Functions and Function Prototypes
Functions are like recipes in a cookbook: they define a specific task (e.g., bake a cake) that can be reused with different inputs (ingredients). In C++, functions have a return type, name, parameters, and body. Use function prototypes to declare them before `main` if defined later. Functions reduce code duplication and are critical for modular code in interviews.

**Example Program: Calculate Square of a Number**
```cpp
#include <iostream>  // For input/output

// Function prototype: declares function before main
int square(int num);  // Returns int, takes int parameter

int main() {  // Main function
    int number;  // Variable for user input
    std::cout << "Enter a number: ";  // Prompt
    std::cin >> number;  // Read input
    int result = square(number);  // Call function and store result
    std::cout << "Square of " << number << " is " << result << std::endl;  // Output
    return 0;  // End program
}

// Function definition: computes square
int square(int num) {  // Takes int parameter, returns int
    return num * num;  // Return square
}
```
**Expected Outcome** (assuming input of 4):  
```
Enter a number: 4
Square of 4 is 16
```
This is like using a calculator’s square button—input a number, get the result.

---

### Concept 2: Scope and Lifetime of Variables
Scope is like the visibility of a tool: a hammer in your garage (local scope) isn’t available in your neighbor’s house (global scope). Lifetime is how long the tool exists (e.g., during a project or forever). In C++, variables can be local (inside a function/block) or global (outside functions). Local variables are preferred in interviews for safety; global variables can cause conflicts.

**Example Program: Local vs Global Scope**
```cpp
#include <iostream>  // For output

int globalVar = 100;  // Global variable: accessible everywhere, exists entire program

int main() {  // Main function
    int localVar = 50;  // Local to main: only accessible here
    {  // Inner block
        int blockVar = 10;  // Local to block: only accessible here
        std::cout << "Inside block: " << blockVar << ", " << localVar << ", " << globalVar << std::endl;
    }  // blockVar dies here
    // std::cout << blockVar;  // Error: blockVar out of scope
    std::cout << "In main: " << localVar << ", " << globalVar << std::endl;
    return 0;
}
```
**Expected Outcome**:  
```
Inside block: 10, 50, 100
In main: 50, 100
```
This is like tools staying in their designated workspace—blockVar is only in the inner room.

---

### Concept 3: Basic Arrays
Arrays are like a row of mailboxes: each holds one item (same type), accessed by an index (starting at 0). They’re fixed-size and contiguous in memory, ideal for storing lists like exam scores. In interviews, arrays are fundamental for DSA problems (e.g., searching, sorting).

**Example Program: Sum of Array Elements**
```cpp
#include <iostream>  // For input/output

int main() {  // Main function
    int arr[5] = {10, 20, 30, 40, 50};  // Array of 5 integers
    int sum = 0;  // Variable to store sum
    
    // Loop through array to calculate sum
    for (int i = 0; i < 5; i++) {  // Index from 0 to 4
        sum += arr[i];  // Add element at index i
    }
    
    std::cout << "Sum of array: " << sum << std::endl;  // Output sum
    return 0;  // End program
}
```
**Expected Outcome**:  
```
Sum of array: 150
```
This is like adding up all items in a shopping list.

---

### Points to Remember for Interview Preparation
- Write functions with clear parameter and return types; explain their purpose in interviews.  
- Use pass-by-value for simple types, but understand pass-by-reference (covered later) for efficiency.  
- Avoid global variables in interviews unless explicitly needed—local variables are safer.  
- Know array bounds to avoid out-of-bounds errors, a common interview mistake.  
- Practice iterating arrays with loops; interviewers test index manipulation (e.g., reverse array).  
- Functions should be short and focused (single responsibility) for clean code.  
- Understand variable shadowing (same name in different scopes) to avoid bugs.  
- Arrays are fixed-size; explain why you’d choose them over dynamic structures (e.g., vectors) in interviews.  
- Combine with Hour 1 (variables, operators) and Hour 2 (control structures) for problems like array sum or max.  
- Debug scope issues (e.g., accessing a variable outside its block) as they’re common in interviews.