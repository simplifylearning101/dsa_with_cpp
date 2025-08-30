# C++ Project Idea: Library Management System

**Project Title**: Library Management System  
**Description**: Build a console-based application to manage a library’s book inventory, like a librarian organizing books. Students will use classes, inheritance, and basic data structures to implement this system, covering Hours 1-8 concepts.

**Requirements**:
- Create a `Book` class with private attributes (title, author, ID, availability) and public methods to display details and update status.
- Use a constructor to initialize book details and a destructor to clean up any dynamic memory.
- Implement a `Library` class to store an array of `Book` objects (use dynamic memory for flexibility).
- Support adding a book, removing a book, and searching by title or ID using string operations.
- Use control structures to handle user input (menu-driven interface with options like add, remove, search, display).
- Implement function overloading for search (e.g., by title or ID).
- Use pointers and references to manage book objects efficiently in the `Library` class.
- Ensure proper encapsulation with private data and public interfaces.
- Handle edge cases (e.g., invalid IDs, full library) using conditional statements.
- Use I/O operations for user interaction and displaying results.

**Expected Outcome**:  
A console application where users can:  
- Add books (e.g., “C++ Primer”, “Stroustrup”, 101, true → added successfully).  
- Remove books by ID (e.g., ID 101 → removed).  
- Search books by title or ID (e.g., “C++” → displays matching books).  
- Display all books with details.  
The program runs in a loop until the user exits, with clear console output for all operations.