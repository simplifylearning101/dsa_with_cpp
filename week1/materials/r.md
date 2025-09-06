# Phonebook Manager Documentation

## Overview
The **Phonebook Manager** is a C++ program that implements a simple phonebook application using STL containers and algorithms. It allows users to manage contacts by adding, deleting, updating, searching, and listing them. The program uses `std::map` for storing contacts (sorted by name), `std::string` for names and phone numbers, and STL algorithms like `std::for_each` and `std::transform` for operations.

## Features
1. **Add Contact**: Add a new contact with a name and phone number. Prevents duplicates by name.
2. **Delete Contact**: Remove a contact by name.
3. **Update Contact**: Update the phone number of an existing contact.
4. **Search Contact**: Find contacts by partial name match (case-insensitive).
5. **List All Contacts**: Display all contacts in alphabetical order.

## STL Components Used
- **Containers**:
  - `std::map` (Hour 9): Stores name-phone pairs, sorted by name, O(log n) operations.
  - `std::vector` (Hour 1): Stores search results.
  - `std::string` (Hour 4): Represents names and phone numbers.
- **Algorithms**:
  - `std::for_each` (Hour 13): Iterates over contacts for listing and searching.
  - `std::transform` (Hour 13): Converts strings to lowercase for case-insensitive search.
- **Iterators** (Hour 14): Used for traversing `std::map` and manipulating `std::vector`.

## How to Use
1. Compile and run `PhonebookManager.cpp` using a C++ compiler (e.g., `g++ PhonebookManager.cpp -o phonebook`).
2. Follow the menu prompts to:
   - Enter `1` to add a contact (provide name and phone number).
   - Enter `2` to delete a contact by name.
   - Enter `3` to update a contact’s phone number.
   - Enter `4` to search for contacts by partial name.
   - Enter `5` to list all contacts.
   - Enter `6` to exit.
3. Input names and phone numbers as strings. Search is case-insensitive.

## Example Usage
```
Phonebook Manager
1. Add contact
2. Delete contact
3. Update contact
4. Search contact
5. List all contacts
6. Exit
Enter command (1-6): 1
Enter name: Alice
Enter phone number: 123-456-7890
Added contact: Alice, 123-456-7890

Enter command (1-6): 4
Enter name to search: al
Search results:
Alice: 123-456-7890

Enter command (1-6): 5
All contacts:
Alice: 123-456-7890
```

## Implementation Notes
- **Data Structure**: `std::map` ensures contacts are stored in sorted order by name, with O(log n) insertion, deletion, and lookup.
- **Search**: Uses `std::for_each` with a lambda to check for partial matches, converting strings to lowercase for case-insensitive comparison.
- **Error Handling**: Checks for duplicate names when adding and validates existence for deletion/update.
- **Extensibility**: Can be extended to include additional fields (e.g., email) or use `std::unordered_map` for faster lookups.

## Learning Outcomes
- Understand `std::map` for key-value storage (Hour 9).
- Apply STL algorithms like `std::for_each` and `std::transform` (Hour 13).
- Use iterators for container traversal (Hour 14).
- Handle string operations with `std::string` (Hour 4).