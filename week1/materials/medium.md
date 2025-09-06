# Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 25 challenging interview questions covering Hours 1–14. These questions test advanced understanding of STL containers, algorithms, and iterators, suitable for experienced candidates.

1. **Question**: Write a program to merge two sorted `std::vector`s into a single sorted `std::vector` using `std::merge`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   #include <iterator>
   int main() {
       std::vector<int> v1 = {1, 3, 5}, v2 = {2, 4, 6}, result;
       std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));
       for (int x : result) std::cout << x << " ";  // Output: 1 2 3 4 5 6
       return 0;
   }
   ```
   **Explanation**: `merge` combines sorted ranges, O(n + m) (Hours 12, 14).  
   **Interviewer’s Intention**: Tests algorithm and iterator adaptor usage.

2. **Question**: How does iterator invalidation affect a `std::vector` during `push_back`?  
   **Answer**: If capacity is exceeded, all iterators, pointers, and references are invalidated due to reallocation.  
   **Explanation**: Vector may copy elements to a new buffer (Hour 1).  
   **Interviewer’s Intention**: Tests memory management.

3. **Question**: Write a program to partition a `std::vector` into even and odd numbers using `std::partition`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   int main() {
       std::vector<int> v = {1, 2, 3, 4};
       std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
       for (int x : v) std::cout << x << " ";  // Output: 2 4 1 3
       return 0;
   }
   ```
   **Explanation**: `partition` groups by predicate, O(n) (Hour 13).  
   **Interviewer’s Intention**: Tests advanced algorithm application.

4. **Question**: Explain the difference between `std::map::insert` and `std::map::operator[]`.  
   **Answer**: `insert` adds if key doesn’t exist; `operator[]` adds with default value if absent.  
   **Explanation**: `operator[]` modifies map, `insert` preserves existing keys (Hour 9).  
   **Interviewer’s Intention**: Tests map operation nuances.

5. **Question**: Write a program to transform a `std::vector` of strings to uppercase using `std::transform`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   #include <cctype>
   int main() {
       std::vector<std::string> v = {"cat", "dog"};
       std::transform(v.begin(), v.end(), v.begin(), [](std::string s) {
           for (char& c : s) c = std::toupper(c);
           return s;
       });
       for (const auto& s : v) std::cout << s << " ";  // Output: CAT DOG
       return 0;
   }
   ```
   **Explanation**: `transform` applies lambda to modify strings (Hour 13).  
   **Interviewer’s Intention**: Tests string and algorithm usage.

6. **Question**: How do you implement a custom comparator for a `std::priority_queue`?  
   **Answer**:  
   ```cpp
   #include <queue>
   struct Compare {
       bool operator()(int a, int b) { return a > b; }  // Min-heap
   };
   std::priority_queue<int, std::vector<int>, Compare> pq;
   ```
   **Explanation**: Custom comparator changes heap order (Hour 7).  
   **Interviewer’s Intention**: Tests priority queue customization.

7. **Question**: Write a program to copy even numbers from a `std::deque` to a `std::set` using `std::copy_if` and `inserter`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <deque>
   #include <set>
   #include <algorithm>
   #include <iterator>
   int main() {
       std::deque<int> dq = {1, 2, 3, 4};
       std::set<int> s;
       std::copy_if(dq.begin(), dq.end(), std::inserter(s, s.begin()), [](int x) { return x % 2 == 0; });
       for (int x : s) std::cout << x << " ";  // Output: 2 4
       return 0;
   }
   ```
   **Explanation**: `copy_if` filters, `inserter` adds to set (Hours 3, 8, 14).  
   **Interviewer’s Intention**: Tests iterator adaptors and filtering.

8. **Question**: What is the time complexity of inserting into a `std::unordered_multiset`?  
   **Answer**: O(1) average, O(n) worst case.  
   **Explanation**: Hash table insertion depends on collisions (Hour 11).  
   **Interviewer’s Intention**: Tests unordered container performance.

9. **Question**: Write a program to check if a `std::vector` is sorted using `std::is_sorted`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   int main() {
       std::vector<int> v = {1, 2, 3};
       bool sorted = std::is_sorted(v.begin(), v.end());
       std::cout << (sorted ? "Sorted" : "Not sorted") << std::endl;  // Output: Sorted
       return 0;
   }
   ```
   **Explanation**: `is_sorted` checks ascending order, O(n) (Hour 12).  
   **Interviewer’s Intention**: Tests algorithm usage.

10. **Question**: Why does `std::remove_if` require `erase` to actually remove elements?  
    **Answer**: `remove_if` shifts elements, doesn’t resize; `erase` removes trailing elements.  
    **Explanation**: Returns new logical end iterator (Hour 13).  
    **Interviewer’s Intention**: Tests algorithm mechanics.

11. **Question**: Write a program to reverse a `std::deque` using reverse iterators.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <deque>
    int main() {
        std::deque<int> dq = {1, 2, 3};
        for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
            std::cout << *it << " ";  // Output: 3 2 1
        }
        return 0;
    }
    ```
    **Explanation**: Reverse iterators traverse backwards (Hours 3, 14).  
    **Interviewer’s Intention**: Tests deque and iterators.

12. **Question**: How does `std::unordered_map` differ from `std::map` in terms of performance?  
    **Answer**: `unordered_map` has O(1) average lookup/insert; `map` has O(log n).  
    **Explanation**: Hash table vs. balanced tree (Hours 9, 13).  
    **Interviewer’s Intention**: Tests performance trade-offs.

13. **Question**: Write a program to find the second largest element in a `std::vector` using `std::nth_element`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {3, 1, 4, 2};
        if (v.size() >= 2) {
            std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
            std::cout << v[1] << std::endl;  // Output: 3
        }
        return 0;
    }
    ```
    **Explanation**: `nth_element` partially sorts, O(n) (Hour 12).  
    **Interviewer’s Intention**: Tests advanced sorting.

14. **Question**: What iterator type is required for `std::partition`?  
    **Answer**: Bidirectional iterator.  
    **Explanation**: Needs forward/backward movement (Hour 14).  
    **Interviewer’s Intention**: Tests iterator requirements.

15. **Question**: Write a program to copy a `std::vector` to a `std::multiset` using `inserter`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <set>
    #include <algorithm>
    #include <iterator>
    int main() {
        std::vector<int> v = {1, 2, 2};
        std::multiset<int> ms;
        std::copy(v.begin(), v.end(), std::inserter(ms, ms.begin()));
        for (int x : ms) std::cout << x << " ";  // Output: 1 2 2
        return 0;
    }
    ```
    **Explanation**: `inserter` handles duplicates (Hours 10, 14).  
    **Interviewer’s Intention**: Tests multiset and adaptors.

16. **Question**: How does `std::string::substr` work?  
    **Answer**: Returns substring from given position and length.  
    **Explanation**: O(n) for copying substring (Hour 4).  
    **Interviewer’s Intention**: Tests string operations.

17. **Question**: Write a program to sum even numbers in a `std::vector` using `std::for_each`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {1, 2, 3, 4};
        int sum = 0;
        std::for_each(v.begin(), v.end(), [&sum](int x) { if (x % 2 == 0) sum += x; });
        std::cout << sum << std::endl;  // Output: 6
        return 0;
    }
    ```
    **Explanation**: Lambda filters and sums, O(n) (Hour 13).  
    **Interviewer’s Intention**: Tests lambda usage.

18. **Question**: What is the difference between `std::queue` and `std::priority_queue`?  
    **Answer**: `queue` is FIFO; `priority_queue` prioritizes elements by value.  
    **Explanation**: `queue` uses deque, `priority_queue` uses heap (Hours 6, 7).  
    **Interviewer’s Intention**: Tests container differences.

19. **Question**: Write a program to check for duplicates in a `std::vector` using `std::unordered_set`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <unordered_set>
    bool hasDuplicates(std::vector<int>& v) {
        std::unordered_set<int> s;
        for (int x : v) {
            if (!s.insert(x).second) return true;
        }
        return false;
    }
    int main() {
        std::vector<int> v = {1, 2, 2};
        std::cout << (hasDuplicates(v) ? "Has duplicates" : "No duplicates") << std::endl;  // Output: Has duplicates
        return 0;
    }
    ```
    **Explanation**: `insert` returns false if duplicate (Hours 11, 13).  
    **Interviewer’s Intention**: Tests hash-based deduplication.

20. **Question**: What iterator type does `std::map` provide?  
    **Answer**: Bidirectional iterator.  
    **Explanation**: Supports forward/backward traversal (Hour 14).  
    **Interviewer’s Intention**: Tests iterator knowledge.

21. **Question**: Write a program to print keys of a `std::map` using `std::for_each`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <map>
    #include <algorithm>
    int main() {
        std::map<std::string, int> m = {{"a", 1}, {"b", 2}};
        std::for_each(m.begin(), m.end(), [](const auto& p) { std::cout << p.first << " "; });
        std::cout << std::endl;  // Output: a b
        return 0;
    }
    ```
    **Explanation**: `for_each` processes key-value pairs (Hours 9, 13).  
    **Interviewer’s Intention**: Tests map iteration.

22. **Question**: How does `std::vector::reserve` affect performance?  
    **Answer**: Preallocates capacity, reducing reallocations.  
    **Explanation**: Avoids O(n) copies during `push_back` (Hour 1).  
    **Interviewer’s Intention**: Tests vector optimization.

23. **Question**: Write a program to find the length of the longest substring with distinct characters in a `std::string`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <string>
    #include <unordered_set>
    int main() {
        std::string s = "abcabcbb";
        std::unordered_set<char> seen;
        int max_len = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (seen.count(s[i])) seen.erase(s[start++]);
            seen.insert(s[i]);
            max_len = std::max(max_len, i - start + 1);
        }
        std::cout << max_len << std::endl;  // Output: 3
        return 0;
    }
    ```
    **Explanation**: Sliding window with `unordered_set` (Hours 4, 11).  
    **Interviewer’s Intention**: Tests string and hash usage.

24. **Question**: What is the purpose of `std::back_inserter`?  
    **Answer**: Appends elements to a container using `push_back`.  
    **Explanation**: Works with vectors, deques, etc. (Hour 14).  
    **Interviewer’s Intention**: Tests iterator adaptors.

25. **Question**: Write a program to reverse a `std::vector` using `std::reverse` and iterators.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {1, 2, 3};
        std::reverse(v.begin(), v.end());
        for (int x : v) std::cout << x << " ";  // Output: 3 2 1
        return 0;
    }
    ```
    **Explanation**: `reverse` swaps elements in range (Hours 1, 12).  
    **Interviewer’s Intention**: Tests vector and algorithm usage.