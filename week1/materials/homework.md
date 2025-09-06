# Phonebook Manager Homework Exercises

Below are exercises to extend the **Phonebook Manager** project, reinforcing concepts from Hours 1–14 of the C++ STL containers roadmap. These tasks range from easy to advanced, helping learners deepen their understanding of STL containers, algorithms, and iterators.

## Easy Exercises
1. **Add Email Field**: Modify `PhonebookManager` to store an email address for each contact. Update `addContact`, `updateContact`, and `listContacts` to handle emails.  
   **Hint**: Use a `std::tuple<std::string, std::string>` or a custom struct for contact details (Hours 1, 9).

2. **Count Contacts**: Add a method to return the number of contacts using `std::map::size`.  
   **Hint**: Use O(1) size method (Hour 9).

3. **Clear Phonebook**: Implement a method to clear all contacts using `std::map::clear`.  
   **Hint**: Test empty state handling (Hour 9).

4. **Validate Phone Number**: Add validation in `addContact` to ensure phone numbers follow a format (e.g., digits and dashes).  
   **Hint**: Use `std::string` methods like `find` (Hour 4).

5. **Case-Sensitive Search Option**: Add an option to toggle case-sensitive search in `searchContact`.  
   **Hint**: Modify the lambda in `std::for_each` (Hour 13).

## Moderate Exercises
6. **Use `std::unordered_map`**: Replace `std::map` with `std::unordered_map` for faster lookups (O(1) average). Update `listContacts` to sort output manually using `std::sort`.  
   **Hint**: Copy keys to a `std::vector` and sort (Hours 9, 12, 13).

7. **Search by Phone Number**: Add a method to search contacts by partial phone number match.  
   **Hint**: Use `std::for_each` with `std::string::find` (Hours 4, 13).

8. **Reverse Listing**: Modify `listContacts` to optionally list contacts in reverse order using reverse iterators.  
   **Hint**: Use `rbegin()` and `rend()` (Hour 14).

9. **Batch Add**: Implement a method to add multiple contacts from a `std::vector<std::pair<std::string, std::string>>`.  
   **Hint**: Use `std::for_each` or range-based for loop (Hours 1, 13).

10. **Export to Vector**: Add a method to return all contacts as a `std::vector<std::pair<std::string, std::string>>` using `std::copy`.  
    **Hint**: Use `std::back_inserter` (Hours 1, 14).

11. **Find Contact with Iterator**: Rewrite `searchContact` to return an iterator to the first matching contact instead of a vector.  
    **Hint**: Use `std::find_if` (Hours 13, 14).

12. **Remove by Phone Number**: Add a method to delete contacts by phone number using `std::find_if`.  
    **Hint**: Iterate over `std::map` to find matching value (Hours 9, 13).

13. **Sort by Phone Number**: Modify `listContacts` to optionally sort by phone number using a temporary `std::vector`.  
    **Hint**: Use `std::sort` with a custom comparator (Hours 12, 13).

14. **Duplicate Name Handling**: Allow multiple contacts with the same name by using `std::multimap`.  
    **Hint**: Update all methods to handle multiple entries (Hour 10).

15. **Count Matches**: Modify `searchContact` to return the number of matches using `std::count_if`.  
    **Hint**: Use a lambda predicate (Hour 13).

## Hard Exercises
16. **Efficient Search with Prefix**: Optimize `searchContact` to only match prefixes using `std::string::starts_with` (C++20) or equivalent.  
    **Hint**: Check for prefix matches in lambda (Hours 4, 13).

17. **Undo Delete**: Implement an undo feature for `deleteContact` using a `std::stack` to store deleted contacts.  
    **Hint**: Push deleted pairs to stack (Hour 5).

18. **Recent Searches**: Store the last 5 searches in a `std::queue` and add a method to display them.  
    **Hint**: Use `std::queue` with size limit (Hour 6).

19. **Frequent Contacts**: Use a `std::priority_queue` to track the top 3 most frequently searched contacts.  
    **Hint**: Maintain a `std::unordered_map` for search counts (Hours 7, 9).

20. **Merge Phonebooks**: Add a method to merge another `PhonebookManager`’s contacts using `std::merge`.  
    **Hint**: Copy to `std::vector`, merge, and rebuild map (Hours 9, 12).

## Advanced Exercises
21. **Custom Comparator**: Allow `std::map` to sort contacts case-insensitively using a custom comparator.  
    **Hint**: Define a struct with `operator()` for case-insensitive comparison (Hour 9).

22. **Iterator-Based Operations**: Rewrite `listContacts` to use explicit iterators instead of `std::for_each`.  
    **Hint**: Use `begin()` and `end()` loops (Hour 14).

23. **Thread-Safe Add**: Make `addContact` thread-safe using a mutex (requires `<mutex>`).  
    **Hint**: Protect `std::map` access (beyond Hours 1–14, but tests understanding).

24. **Serialize to String**: Add a method to serialize contacts to a `std::string` using `std::accumulate`.  
    **Hint**: Concatenate key-value pairs (Hours 12, 13).

25. **Fuzzy Search**: Implement fuzzy search in `searchContact` using a simple edit distance algorithm with `std::string`.  
    **Hint**: Use dynamic programming and store results in `std::vector` (Hours 1, 4).

## Instructions
- Implement each exercise by modifying `PhonebookManager.cpp`.
- Test each change to ensure functionality (e.g., no duplicate names unless using `std::multimap`).
- Use STL containers and algorithms from Hours 1–14 where possible.
- Document your changes in comments, explaining which STL components are used.