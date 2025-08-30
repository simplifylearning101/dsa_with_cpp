# C++ Project Idea: Student Grade Tracker

**Project Title**: Student Grade Tracker  
**Description**: Develop a console-based application to track student grades, like a digital gradebook. This project reinforces classes, inheritance, and operator overloading, integrating Hours 1-8 concepts with a focus on data management.

**Requirements**:
- Create a base class `Person` with attributes (name, ID) and a virtual method to display details.
- Derive a `Student` class from `Person` with private attributes for grades (dynamic array) and methods to add grades and compute average.
- Use constructors to initialize student data and a destructor to free the grades array.
- Overload the `+` operator to combine grades of two students (e.g., append grades).
- Implement function overloading for adding grades (e.g., single grade vs. array of grades).
- Use recursion to calculate statistics like highest/lowest grade.
- Store students in a dynamic array with pointers for memory efficiency.
- Provide a menu-driven interface using control structures (add student, add grade, display average, etc.).
- Use strings for name handling and I/O for user input/output.
- Ensure encapsulation with private data and public getter/setter methods.

**Expected Outcome**:  
A console application where users can:  
- Add students (e.g., “Alice”, 101 → added).  
- Add grades (e.g., ID 101, grade 85 → added).  
- Combine grades of two students using `+` (e.g., merges grade lists).  
- Display student details and average grades (e.g., “Alice, ID: 101, Avg: 90”).  
The program handles invalid inputs and exits gracefully.