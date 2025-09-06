# Easy Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 25 easy interview questions covering Hours 1–14 (vectors, arrays, deques, strings, stacks, queues, priority queues, sets, maps, multisets, multimaps, unordered sets, unordered maps, unordered multimaps, STL algorithms, advanced algorithms, iterators). These questions test basic understanding and are suitable for beginners preparing for coding interviews.

1. **Question**: What is the time complexity of accessing an element in a `std::vector`?  
   **Answer**: O(1)  
   **Explanation**: Vector stores elements contiguously, allowing constant-time access via indexing (Hour 1).  
   **Interviewer’s Intention**: Tests basic vector properties.

2. **Question**: How do you add an element to the end of a `std::vector`?  
   **Answer**: Use `v.push_back(element)`.  
   **Explanation**: Appends element in O(1) amortized time (Hour 1).  
   **Interviewer’s Intention**: Tests vector operations.

3. **Question**: What does `std::stack::top()` return?  
   **Answer**: Returns the top element without removing it.  
   **Explanation**: O(1) access to the most recently added element (Hour 5).  
   **Interviewer’s Intention**: Tests stack basics.

4. **Question**: How do you check if a `std::queue` is empty?  
   **Answer**: Use `q.empty()`.  
   **Explanation**: Returns `true` if queue is empty, O(1) (Hour 6).  
   **Interviewer’s Intention**: Tests queue operations.

5. **Question**: What is the purpose of `std::set`?  
   **Answer**: Stores unique, sorted elements.  
   **Explanation**: Uses a balanced binary search tree (Hour 8).  
   **Interviewer’s Intention**: Tests set properties.

6. **Question**: Write a program to print elements of a `std::vector` using a range-based for loop.  
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
   **Explanation**: Simplifies iteration over vector (Hour 1).  
   **Interviewer’s Intention**: Tests basic iteration.

7. **Question**: What is the default ordering of `std::priority_queue`?  
   **Answer**: Max-heap (largest element at top).  
   **Explanation**: Uses `std::less` for ordering (Hour 7).  
   **Interviewer’s Intention**: Tests priority queue basics.

8. **Question**: What header is required for `std::sort`?  
   **Answer**: `<algorithm>`  
   **Explanation**: Contains sorting and other algorithms (Hour 12).  
   **Interviewer’s Intention**: Tests STL library knowledge.

9. **Question**: How do you access a value in a `std::map` by key?  
   **Answer**: Use `m[key]` or `m.at(key)`.  
   **Explanation**: `at` throws if key is absent; `operator[]` inserts default (Hour 9).  
   **Interviewer’s Intention**: Tests map access methods.

10. **Question**: What does `std::deque::push_front` do?  
    **Answer**: Adds an element to the front in O(1).  
    **Explanation**: Deque supports efficient front/back operations (Hour 3).  
    **Interviewer’s Intention**: Tests deque operations.

11. **Question**: Write a program to check if an element exists in a `std::set` using `find`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <set>
    int main() {
        std::set<int> s = {1, 2, 3};
        int x = 2;
        std::cout << (s.find(x) != s.end() ? "Found" : "Not found") << std::endl;
        return 0;
    }
    ```
    **Explanation**: `find` returns iterator, O(log n) (Hour 8).  
    **Interviewer’s Intention**: Tests set search.

12. **Question**: What is the time complexity of inserting into a `std::map`?  
    **Answer**: O(log n)  
    **Explanation**: Uses a balanced tree for sorted storage (Hour 9).  
    **Interviewer’s Intention**: Tests map performance.

13. **Question**: How do you get the size of a `std::string`?  
    **Answer**: Use `s.size()` or `s.length()`.  
    **Explanation**: Both return number of characters, O(1) (Hour 4).  
    **Interviewer’s Intention**: Tests string basics.

14. **Question**: What does `std::rbegin()` return?  
    **Answer**: Reverse iterator to the last element.  
    **Explanation**: Enables backward traversal (Hour 14).  
    **Interviewer’s Intention**: Tests iterator basics.

15. **Question**: Write a program to push elements onto a `std::stack` and pop one.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <stack>
    int main() {
        std::stack<int> s;
        s.push(1); s.push(2);
        std::cout << s.top() << std::endl;  // Output: 2
        s.pop();
        return 0;
    }
    ```
    **Explanation**: `push` and `pop` manage LIFO (Hour 5).  
    **Interviewer’s Intention**: Tests stack usage.

16. **Question**: What is the difference between `std::set` and `std::multiset`?  
    **Answer**: `set` stores unique elements; `multiset` allows duplicates.  
    **Explanation**: Both are sorted, use trees (Hours 8, 10).  
    **Interviewer’s Intention**: Tests container differences.

17. **Question**: How do you clear all elements from a `std::vector`?  
    **Answer**: Use `v.clear()`.  
    **Explanation**: Removes all elements, sets size to 0, O(1) (Hour 1).  
    **Interviewer’s Intention**: Tests vector operations.

18. **Question**: What does `std::find` return if an element is not found?  
    **Answer**: Returns `end()` iterator.  
    **Explanation**: Indicates element absence (Hour 12).  
    **Interviewer’s Intention**: Tests algorithm behavior.

19. **Question**: Write a program to access the front element of a `std::queue`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <queue>
    int main() {
        std::queue<int> q;
        q.push(1); q.push(2);
        std::cout << q.front() << std::endl;  // Output: 1
        return 0;
    }
    ```
    **Explanation**: `front` accesses first element, O(1) (Hour 6).  
    **Interviewer’s Intention**: Tests queue access.

20. **Question**: What is the time complexity of `std::priority_queue::pop`?  
    **Answer**: O(log n)  
    **Explanation**: Maintains heap property (Hour 7).  
    **Interviewer’s Intention**: Tests priority queue performance.

21. **Question**: How do you iterate over a `std::map`?  
    **Answer**: Use range-based for loop or iterators.  
    **Explanation**: Iterates over key-value pairs (Hour 9).  
    **Interviewer’s Intention**: Tests map iteration.

22. **Question**: What does `std::array` guarantee about its size?  
    **Answer**: Fixed size at compile time.  
    **Explanation**: Unlike vector, size is static (Hour 2).  
    **Interviewer’s Intention**: Tests array properties.

23. **Question**: Write a program to sort a `std::vector` using `std::sort`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {3, 1, 2};
        std::sort(v.begin(), v.end());
        for (int x : v) std::cout << x << " ";  // Output: 1 2 3
        return 0;
    }
    ```
    **Explanation**: `sort` orders elements, O(n log n) (Hour 12).  
    **Interviewer’s Intention**: Tests basic sorting.

24. **Question**: What iterator type does `std::vector` provide?  
    **Answer**: Random-access iterator.  
    **Explanation**: Supports direct index access (Hour 14).  
    **Interviewer’s Intention**: Tests iterator knowledge.

25. **Question**: How do you add an element to a `std::set`?  
    **Answer**: Use `s.insert(element)`.  
    **Explanation**: Adds if unique, O(log n) (Hour 8).  
    **Interviewer’s Intention**: Tests set operations.