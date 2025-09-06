# Little Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 25 moderately challenging interview questions covering Hours 1–14. These questions test deeper understanding of STL containers, algorithms, and iterators, suitable for intermediate candidates.

1. **Question**: Write a program to remove duplicates from a `std::vector` using `std::set`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <set>
   int main() {
       std::vector<int> v = {1, 2, 2, 3};
       std::set<int> s(v.begin(), v.end());
       v.assign(s.begin(), s.end());
       for (int x : v) std::cout << x << " ";  // Output: 1 2 3
       return 0;
   }
   ```
   **Explanation**: `set` ensures uniqueness, `assign` updates vector (Hours 1, 8).  
   **Interviewer’s Intention**: Tests container conversion.

2. **Question**: What happens to iterators when `std::vector::push_back` exceeds capacity?  
   **Answer**: All iterators, pointers, and references are invalidated.  
   **Explanation**: Reallocation copies elements to a new buffer (Hour 1).  
   **Interviewer’s Intention**: Tests iterator invalidation.

3. **Question**: Write a program to reverse a `std::string` using `std::reverse`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <string>
   #include <algorithm>
   int main() {
       std::string s = "hello";
       std::reverse(s.begin(), s.end());
       std::cout << s << std::endl;  // Output: olleh
       return 0;
   }
   ```
   **Explanation**: `reverse` swaps elements in range (Hours 4, 12).  
   **Interviewer’s Intention**: Tests string and algorithm usage.

4. **Question**: How do you sum elements in a `std::vector` using `std::accumulate`?  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <numeric>
   int main() {
       std::vector<int> v = {1, 2, 3};
       int sum = std::accumulate(v.begin(), v.end(), 0);
       std::cout << sum << std::endl;  // Output: 6
       return 0;
   }
   ```
   **Explanation**: `accumulate` sums range, O(n) (Hour 12).  
   **Interviewer’s Intention**: Tests numeric algorithms.

5. **Question**: What is the difference between `std::deque` and `std::vector` for insertions?  
   **Answer**: `deque` has O(1) front/back insertions; `vector` has O(1) back, O(n) front.  
   **Explanation**: `deque` uses chunked storage (Hour 3).  
   **Inter局

System: **Continuation of Response**

---

### File 2: Little_Hard_Interview_Questions.md (Continued)

<xaiArtifact artifact_id="12dbae71-4489-4c6a-b4fa-fdd1e9d4c89f" artifact_version_id="9a954887-c2b4-474d-8f4c-86bf5767d0ef" title="Little_Hard_Interview_Questions.md" contentType="text/markdown">

# Little Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 25 moderately challenging interview questions covering Hours 1–14. These questions test deeper understanding of STL containers, algorithms, and iterators, suitable for intermediate candidates.

1. **Question**: Write a program to remove duplicates from a `std::vector` using `std::set`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <set>
   int main() {
       std::vector<int> v = {1, 2, 2, 3};
       std::set<int> s(v.begin(), v.end());
       v.assign(s.begin(), s.end());
       for (int x : v) std::cout << x << " ";  // Output: 1 2 3
       return 0;
   }
   ```
   **Explanation**: `set` ensures uniqueness, `assign` updates vector (Hours 1, 8).  
   **Interviewer’s Intention**: Tests container conversion.

2. **Question**: What happens to iterators when `std::vector::push_back` exceeds capacity?  
   **Answer**: All iterators, pointers, and references are invalidated.  
   **Explanation**: Reallocation copies elements to a new buffer (Hour 1).  
   **Interviewer’s Intention**: Tests iterator invalidation.

3. **Question**: Write a program to reverse a `std::string` using `std::reverse`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <string>
   #include <algorithm>
   int main() {
       std::string s = "hello";
       std::reverse(s.begin(), s.end());
       std::cout << s << std::endl;  // Output: olleh
       return 0;
   }
   ```
   **Explanation**: `reverse` swaps elements in range (Hours 4, 12).  
   **Interviewer’s Intention**: Tests string and algorithm usage.

4. **Question**: How do you sum elements in a `std::vector` using `std::accumulate`?  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <numeric>
   int main() {
       std::vector<int> v = {1, 2, 3};
       int sum = std::accumulate(v.begin(), v.end(), 0);
       std::cout << sum << std::endl;  // Output: 6
       return 0;
   }
   ```
   **Explanation**: `accumulate` sums range, O(n) (Hour 12).  
   **Interviewer’s Intention**: Tests numeric algorithms.

5. **Question**: What is the difference between `std::deque` and `std::vector` for insertions?  
   **Answer**: `deque` has O(1) front/back insertions; `vector` has O(1) back, O(n) front.  
   **Explanation**: `deque` uses chunked storage (Hour 3).  
   **Interviewer’s Intention**: Tests container performance.

6. **Question**: Write a program to copy a `std::vector` to a `std::deque` using `back_inserter`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <deque>
   #include <algorithm>
   #include <iterator>
   int main() {
       std::vector<int> v = {1, 2, 3};
       std::deque<int> dq;
       std::copy(v.begin(), v.end(), std::back_inserter(dq));
       for (int x : dq) std::cout << x << " ";  // Output: 1 2 3
       return 0;
   }
   ```
   **Explanation**: `back_inserter` appends to `deque` (Hour 14).  
   **Interviewer’s Intention**: Tests iterator adaptors.

7. **Question**: How does `std::priority_queue` maintain its order?  
   **Answer**: Uses a max-heap (default) or min-heap with custom comparator.  
   **Explanation**: Heap operations ensure top element is max/min, O(log n) for push/pop (Hour 7).  
   **Interviewer’s Intention**: Tests heap-based container knowledge.

8. **Question**: Write a program to count occurrences in a `std::multimap` for a given key.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <map>
   int main() {
       std::multimap<std::string, int> mm = {{"a", 1}, {"a", 2}, {"b", 3}};
       std::string key = "a";
       int count = mm.count(key);
       std::cout << "Count of " << key << ": " << count << std::endl;  // Output: 2
       return 0;
   }
   ```
   **Explanation**: `count` returns number of key occurrences (Hour 10).  
   **Interviewer’s Intention**: Tests multimap usage.

9. **Question**: What is the purpose of `std::transform`?  
   **Answer**: Applies a function to a range, storing results in another range.  
   **Explanation**: O(n) operation, often used with lambdas or functors (Hour 13).  
   **Interviewer’s Intention**: Tests advanced algorithm knowledge.

10. **Question**: Why can’t `std::sort` be used with `std::set`?  
    **Answer**: `set` provides bidirectional iterators; `sort` requires random-access.  
    **Explanation**: Set’s tree structure prevents random access (Hours 8, 14).  
    **Interviewer’s Intention**: Tests iterator and algorithm compatibility.

11. **Question**: Write a program to find the minimum element in a `std::vector` using `std::min_element`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {3, 1, 4};
        auto min_it = std::min_element(v.begin(), v.end());
        std::cout << *min_it << std::endl;  // Output: 1
        return 0;
    }
    ```
    **Explanation**: `min_element` returns iterator to smallest element (Hour 12).  
    **Interviewer’s Intention**: Tests algorithm usage.

12. **Question**: How do you erase an element from a `std::map` by key?  
    **Answer**: Use `m.erase(key)`.  
    **Explanation**: Removes key-value pair, O(log n) (Hour 9).  
    **Interviewer’s Intention**: Tests map operations.

13. **Question**: Write a program to concatenate two `std::string`s using `+=`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <string>
    int main() {
        std::string s1 = "hello", s2 = "world";
        s1 += s2;
        std::cout << s1 << std::endl;  // Output: helloworld
        return 0;
    }
    ```
    **Explanation**: `+=` appends strings, O(n) (Hour 4).  
    **Interviewer’s Intention**: Tests string manipulation.

14. **Question**: What is the time complexity of `std::unordered_set::find`?  
    **Answer**: O(1) average, O(n) worst case.  
    **Explanation**: Hash table lookup depends on collisions (Hour 11).  
    **Interviewer’s Intention**: Tests unordered container performance.

15. **Question**: Write a program to print a `std::vector` in reverse using reverse iterators.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    int main() {
        std::vector<int> v = {1, 2, 3};
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            std::cout << *it << " ";  // Output: 3 2 1
        }
        return 0;
    }
    ```
    **Explanation**: `rbegin()` and `rend()` enable reverse traversal (Hour 14).  
    **Interviewer’s Intention**: Tests reverse iterators.

16. **Question**: How do you check if a `std::multiset` contains an element?  
    **Answer**: Use `ms.find(element) != ms.end()`.  
    **Explanation**: `find` returns iterator, O(log n) (Hour 10).  
    **Interviewer’s Intention**: Tests multiset operations.

17. **Question**: Write a program to copy a `std::set` to a `std::vector` using `std::copy`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <set>
    #include <vector>
    #include <algorithm>
    #include <iterator>
    int main() {
        std::set<int> s = {1, 2, 3};
        std::vector<int> v;
        std::copy(s.begin(), s.end(), std::back_inserter(v));
        for (int x : v) std::cout << x << " ";  // Output: 1 2 3
        return 0;
    }
    ```
    **Explanation**: `copy` with `back_inserter` transfers elements (Hours 8, 14).  
    **Interviewer’s Intention**: Tests iterator adaptors.

18. **Question**: What is the difference between `std::map::insert` and `std::map::operator[]`?  
    **Answer**: `insert` adds if key doesn’t exist; `operator[]` adds with default value if absent.  
    **Explanation**: `operator[]` modifies, `insert` preserves existing keys (Hour 9).  
    **Interviewer’s Intention**: Tests map operation nuances.

19. **Question**: Write a program to count elements in a `std::vector` greater than 5 using `std::count_if`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {4, 6, 7, 3};
        int count = std::count_if(v.begin(), v.end(), [](int x) { return x > 5; });
        std::cout << count << std::endl;  // Output: 2
        return 0;
    }
    ```
    **Explanation**: `count_if` uses lambda predicate, O(n) (Hour 13).  
    **Interviewer’s Intention**: Tests algorithm with predicates.

20. **Question**: How does `std::array` differ from `std::vector`?  
    **Answer**: `array` has fixed compile-time size; `vector` is dynamic.  
    **Explanation**: `array` is stack-allocated, `vector` is heap-allocated (Hours 1, 2).  
    **Interviewer’s Intention**: Tests container properties.

21. **Question**: Write a program to pop all elements from a `std::stack` and print them.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <stack>
    int main() {
        std::stack<int> s;
        s.push(1); s.push(2); s.push(3);
        while (!s.empty()) {
            std::cout << s.top() << " ";  // Output: 3 2 1
            s.pop();
        }
        return 0;
    }
    ```
    **Explanation**: `top` and `pop` process LIFO order (Hour 5).  
    **Interviewer’s Intention**: Tests stack iteration.

22. **Question**: What iterator type does `std::set` provide?  
    **Answer**: Bidirectional iterator.  
    **Explanation**: Supports forward/backward traversal (Hour 14).  
    **Interviewer’s Intention**: Tests iterator knowledge.

23. **Question**: Write a program to append a character to a `std::string` using `push_back`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <string>
    int main() {
        std::string s = "hello";
        s.push_back('!');
        std::cout << s << std::endl;  // Output: hello!
        return 0;
    }
    ```
    **Explanation**: `push_back` adds character, O(1) amortized (Hour 4).  
    **Interviewer’s Intention**: Tests string operations.

24. **Question**: What is the time complexity of `std::unordered_map::insert`?  
    **Answer**: O(1) average, O(n) worst case.  
    **Explanation**: Hash table insertion depends on collisions (Hour 9).  
    **Interviewer’s Intention**: Tests unordered container performance.

25. **Question**: Write a program to check if a `std::vector` contains a value using `std::find`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {1, 2, 3};
        int x = 2;
        auto it = std::find(v.begin(), v.end(), x);
        std::cout << (it != v.end() ? "Found" : "Not found") << std::endl;  // Output: Found
        return 0;
    }
    ```
    **Explanation**: `find` returns iterator, O(n) (Hour 12).  
    **Interviewer’s Intention**: Tests basic algorithm usage.