# C++ Project Idea: Console-Based Calculator with Polymorphism

**Project Title**: Console-Based Calculator with Polymorphism  
**Description**: Create a console-based calculator supporting different number types (integers, decimals, complex numbers), like a multi-mode calculator. This project emphasizes polymorphism, operator overloading, and recursion for advanced calculations.

**Requirements**:
- Create an abstract base class `Number` with pure virtual methods for operations (add, multiply).
- Derive classes `Integer`, `Decimal`, and `Complex` with specific implementations of operations.
- Overload operators `+` and `*` for each derived class to perform arithmetic.
- Use function overloading to handle input parsing (e.g., parse integer vs. complex number input).
- Implement a recursive function to compute factorials for integers (used in calculations).
- Use dynamic memory to store a history of operations (dynamic array of results).
- Provide a menu-driven interface using control structures to select number type and operation.
- Use pointers to `Number` objects for polymorphic behavior (e.g., array of `Number*`).
- Ensure proper memory management with destructors in all classes.
- Use strings and I/O for user interaction and result display.

**Expected Outcome**:  
A console application where users can:  
- Choose number type (e.g., Integer, Decimal, Complex).  
- Perform operations (e.g., Complex (1,2) + (3,4) → (4,6)).  
- Compute factorials for integers (e.g., 5! → 120).  
- Display operation history (e.g., “Add: 1 + 2 = 3”).  
The program handles invalid inputs and ensures no memory leaks.