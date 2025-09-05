# C++ Refresher for DSA Cohort: Hour 5 - Concepts

This is the fifth hour of a 5-6 hour C++ refresher for students preparing for a 10-week Data Structures and Algorithms (DSA) cohort. In this session, we cover dynamic memory allocation, structures, and basic recursion. Dynamic memory is like renting storage space, structures are like blueprints for custom objects, and recursion is like solving a puzzle by breaking it into smaller pieces. These concepts are critical for DSA and interviews, explained with real-world analogies and heavily commented code for clarity.

## Hour 5: Topics Covered
We will revise the following concepts:  
1. Dynamic Memory Allocation  
2. Structures  
3. Basic Recursion  

---

### Concept 1: Dynamic Memory Allocation
Dynamic memory allocation is like renting a storage unit: you request space (using `new`) when needed and return it (using `delete`) when done. It allows flexible memory management for arrays or objects, unlike fixed-size arrays. In interviews, dynamic memory is key for data structures like linked lists, but always check for allocation failures and avoid memory leaks.

**Example Program: Dynamic Array Allocation**
```cpp
#include <iostream>  // For input/output

int main() {  // Main function
    int size;  // Variable for array size
    std::cout << "Enter array size: ";  // Prompt user
    std::cin >> size;  // Read size
    
    int* arr = new int[size];  // Allocate dynamic array
    for (int i = 0; i < size; i++) {  // Input elements
        arr[i] = i + 1;  // Fill with 1, 2, 3, ...
    }
    
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {  // Print elements
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] arr;  // Free memory to prevent leak
    arr = nullptr;  // Avoid dangling pointer
    return 0;  // End program
}
```
**Expected Outcome** (assuming input of 3):  
```
Enter array size: 3
Array: 1 2 3
```
This is like renting a storage unit, filling it with items, and returning it when done.

---

### Concept 2: Structures
Structures (`struct`) are like a form with multiple fields: they group related data (e.g., name, age, grade) into a single unit. Access fields with the dot operator (`.`). Structures are foundational for custom data types in DSA (e.g., nodes in linked lists) and are common in interviews for organizing data.

**Example Program: Student Record Using Structure**
```cpp
#include <iostream>  // For input/output
#include <string>    // For string

struct Student {  // Define structure
    std::string name;  // Field for name
    int age;           // Field for age
    char grade;        // Field for grade
};

int main() {  // Main function
    Student s;  // Create a student object
    std::cout << "Enter name, age, grade: ";  // Prompt
    std::cin >> s.name >> s.age >> s.grade;  // Read fields
    
    std::cout << "Student: " << s.name << ", Age: " << s.age 
              << ", Grade: " << s.grade << std::endl;  // Print fields
    return 0;  // End program
}
```
**Expected Outcome** (assuming input "Alice 20 A"):  
```
Enter name, age, grade: Alice 20 A
Student: Alice, Age: 20, Grade: A
```
This is like filling out a student ID card with multiple details.

---

### Concept 3: Basic Recursion
Recursion is like solving a puzzle by breaking it into smaller, identical puzzles. A function calls itself with a smaller input until it reaches a base case (stopping condition). Recursion is common in DSA for problems like tree traversal or factorials, but in interviews, ensure base cases are clear to avoid infinite recursion.

**Example Program: Factorial Using Recursion**
```cpp
#include <iostream>  // For input/output

unsigned long long factorial(int n) {  // Recursive function
    if (n == 0 || n == 1) {  // Base case: 0! = 1, 1! = 1
        return 1;
    }
    return n * factorial(n - 1);  // Recursive case: n! = n * (n-1)!
}

int main() {  // Main function
    int n;  // Variable for input
    std::cout << "Enter a number: ";  // Prompt
    std::cin >> n;  // Read input
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;  // Call and print
    return 0;  // End program
}
```
**Expected Outcome** (assuming input of 5):  
```
Enter a number: 5
Factorial of 5 is 120
```
This is like breaking down a big task (5!) into smaller ones (5 * 4!).

---

### Points to Remember for Interview Preparation
- Always use `delete` to free dynamic memory and set pointers to `nullptr` to avoid leaks or dangling pointers.  
- Check for allocation failures (`new` maywindow.  
- Use structures to organize data clearly; interviewers value well-structured data for problems like graph nodes.  
- Ensure recursion has a clear base case to prevent stack overflow, a common interview question.  
- Combine dynamic arrays with pointers (Hour 4) for flexible data structures.  
- Practice recursive solutions for problems like Fibonacci or tree traversal, explaining each step clearly.  
- Structures are lightweight compared to classes; use them for simple data grouping in interviews.  
- Avoid uninitialized pointers or accessing freed memory, as these are common bugs tested in interviews.  
- Combine with Hours 1-4 concepts (e.g., loops for arrays, strings for processing) for problems like parsing input or managing lists.  
- Write clean, commented code to show clarity in whiteboard interviews.