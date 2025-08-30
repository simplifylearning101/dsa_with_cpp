# C++ Project Idea: Inventory Management with Multiple Inheritance

**Project Title**: Inventory Management with Multiple Inheritance  
**Description**: Build a console-based inventory system for a store, like a warehouse manager tracking products. This project uses multiple inheritance, dynamic memory, and operator overloading to manage items with dual characteristics (e.g., perishable and electronic goods).

**Requirements**:
- Create base classes `Perishable` (expiration date) and `Electronic` (warranty period) with virtual methods for display.
- Derive an `Item` class using multiple inheritance from `Perishable` and `Electronic` to represent dual-nature products.
- Use constructors to initialize item details and destructors for dynamic memory cleanup.
- Overload the `==` operator to compare items by ID or attributes.
- Implement function overloading for adding items (e.g., by single entry vs. bulk import).
- Use a dynamic array of `Item*` pointers for polymorphic storage of items.
- Provide a menu-driven interface using control structures (add, remove, compare, display items).
- Use recursion to calculate total inventory value (summing prices).
- Ensure encapsulation with private data and public methods for access.
- Use strings for item names and I/O for user interaction.

**Expected Outcome**:  
A console application where users can:  
- Add items (e.g., “Milk”, ID 101, expires in 5 days, no warranty → added).  
- Compare items (e.g., ID 101 == ID 102 → equal or not).  
- Display all items with details (e.g., “Milk, Perishable, Expires: 5 days”).  
- Calculate total inventory value (e.g., $500).  
The program manages memory correctly and handles invalid inputs.