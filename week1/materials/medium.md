# Little Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 10 moderately challenging interview questions covering Hours 1–14. These questions test deeper understanding of STL containers, algorithms, and iterators, suitable for intermediate candidates.

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
   **Explanation**: `set` removes duplicates; `assign` updates vector (Hours 1, 8).  
   **Interviewer’s Intention**: Tests container conversion and uniqueness.

2. **Question**: What happens if you call `push_back` on a `std::vector` that exceeds its capacity?  
   **Answer**: Vector reallocates memory, potentially invalidating iterators.  
   **Explanation**: Copies elements to a larger buffer, O(n) in worst case (Hour 1).  
   **Interviewer’s Intention**: Tests memory management and iterator invalidation.

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
   **Interviewer’s Intention**: Tests string manipulation and algorithms.

4. **Question**: How do you use `std::for_each` to sum elements in a `std::vector`?  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   int main() {
       std::vector<int> v = {1, 2, 3};
       int sum = 0;
       std::for_each(v.begin(), v.end(), [&sum](int x) { sum += x; });
       std::cout << sum << std::endl;  // Output: 6
       return 0;
   }
   ```
   **Explanation**: Lambda captures `sum` for accumulation (Hour 13).  
   **Interviewer’s Intention**: Tests advanced algorithm usage.

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