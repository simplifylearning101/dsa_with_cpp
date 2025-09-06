# Easy Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 10 easy interview questions covering Hours 1–14 (vectors, arrays, deques, strings, stacks, queues, priority queues, sets, maps, multisets, multimaps, unordered sets, unordered maps, unordered multimaps, STL algorithms, advanced algorithms, iterators). These questions test basic understanding and are suitable for beginners preparing for coding interviews.

1. **Question**: What is the time complexity of accessing an element in a `std::vector`?  
   **Answer**: O(1)  
   **Explanation**: Vector stores elements contiguously, allowing constant-time access via indexing.  
   **Interviewer’s Intention**: Tests understanding of vector’s random-access capability (Hour 1).

2. **Question**: How do you push an element onto a `std::stack`?  
   **Answer**: Use `s.push(element)`.  
   **Explanation**: `push` adds an element to the top of the stack in O(1).  
   **Interviewer’s Intention**: Tests basic stack operations (Hour 5).

3. **Question**: What does `std::set` guarantee about its elements?  
   **Answer**: Elements are unique and sorted.  
   **Explanation**: Set uses a balanced binary search tree (e.g., red-black tree) to maintain order and uniqueness.  
   **Interviewer’s Intention**: Tests set properties (Hour 8).

4. **Question**: Write a program to print all elements of a `std::vector` using a range-based for loop.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   int main() {
       std::vector<int> v = {1, 2, 3};
       for (int x : v) std::cout << x << " ";
       return 0;
   }
   ```
   **Explanation**: Range-based for loop simplifies iteration (Hour 1).  
   **Interviewer’s Intention**: Tests basic vector iteration.

5. **Question**: What is the purpose of `std::sort` in the `<algorithm>` library?  
   **Answer**: Sorts a range of elements in ascending order by default.  
   **Explanation**: Uses introsort with O(n log n) complexity (Hour 12).  
   **Interviewer’s Intention**: Tests basic STL algorithm knowledge.

6. **Question**: How do you check if a `std::queue` is empty?  
   **Answer**: Use `q.empty()`.  
   **Explanation**: Returns `true` if queue has no elements, O(1) (Hour 6).  
   **Interviewer’s Intention**: Tests queue operations.

7. **Question**: What is the difference between `std::map` and `std::unordered_map`?  
   **Answer**: `map` is sorted, O(log n) operations; `unordered_map` is unsorted, O(1) average operations.  
   **Explanation**: `map` uses a tree; `unordered_map` uses a hash table (Hours 9, 13).  
   **Interviewer’s Intention**: Tests container properties.

8. **Question**: Write a program to find the maximum element in a `std::vector` using `std::max_element`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   int main() {
       std::vector<int> v = {1, 5, 3};
       auto max_it = std::max_element(v.begin(), v.end());
       std::cout << *max_it << std::endl;  // Output: 5
       return 0;
   }
   ```
   **Explanation**: `max_element` returns iterator to max value (Hour 12).  
   **Interviewer’s Intention**: Tests basic algorithm usage.

9. **Question**: What does `std::rbegin()` return for a container?  
   **Answer**: A reverse iterator pointing to the last element.  
   **Explanation**: Enables backward traversal (Hour 14).  
   **Interviewer’s Intention**: Tests iterator basics.

10. **Question**: How do you add an element to a `std::priority_queue`?  
    **Answer**: Use `pq.push(element)`.  
    **Explanation**: Adds element and maintains heap property, O(log n) (Hour 7).  
    **Interviewer’s Intention**: Tests priority queue operations.