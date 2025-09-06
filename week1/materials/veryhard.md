# Very Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 25 very challenging interview questions covering Hours 1–14. These questions test deep mastery of STL containers, algorithms, iterators, and their interactions, suitable for advanced candidates.

1. **Question**: Write a program to implement a sliding window maximum using `std::deque` and STL algorithms.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <deque>
   #include <algorithm>
   std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
       std::deque<int> dq;
       std::vector<int> result;
       for (int i = 0; i < nums.size(); ++i) {
           while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
           while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
           dq.push_back(i);
           if (i >= k - 1) result.push_back(nums[dq.front()]);
       }
       return result;
   }
   int main() {
       std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
       int k = 3;
       auto result = maxSlidingWindow(nums, k);
       for (int x : result) std::cout << x << " ";  // Output: 3 3 5 5 6 7
       return 0;
   }
   ```
   **Explanation**: `deque` maintains indices of potential max elements (Hours 3, 12).  
   **Interviewer’s Intention**: Tests advanced deque usage and algorithmic thinking.

2. **Question**: How does `std::unordered_map` handle hash collisions?  
   **Answer**: Uses separate chaining (linked lists or buckets) or open addressing.  
   **Explanation**: Resolves collisions with O(1) average lookup (Hour 9).  
   **Interviewer’s Intention**: Tests hash table internals.

3. **Question**: Write a program to find all pairs in a `std::vector` summing to a target using `std::unordered_set` and `std::for_each`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <unordered_set>
   #include <algorithm>
   std::vector<std::pair<int, int>> findPairs(std::vector<int>& nums, int target) {
       std::unordered_set<int> seen;
       std::vector<std::pair<int, int>> result;
       std::for_each(nums.begin(), nums.end(), [&](int x) {
           if (seen.count(target - x)) result.emplace_back(x, target - x);
           seen.insert(x);
       });
       return result;
   }
   int main() {
       std::vector<int> nums = {2, 7, 11, 15};
       int target = 9;
       auto pairs = findPairs(nums, target);
       for (const auto& p : pairs) std::cout << p.first << "," << p.second << " ";  // Output: 7,2
       return 0;
   }
   ```
   **Explanation**: `unordered_set` enables O(1) lookups (Hours 9, 13).  
   **Interviewer’s Intention**: Tests hash-based algorithms.

4. **Question**: Explain the role of `iterator_traits` in STL algorithms.  
   **Answer**: Provides type information (e.g., iterator category, value type) for generic algorithms.  
   **Explanation**: Allows algorithms to adapt to iterator capabilities (Hour 14).  
   **Interviewer’s Intention**: Tests advanced iterator knowledge.

5. **Question**: Write a program to implement a custom functor for `std::priority_queue` to sort pairs by second element.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <queue>
   #include <vector>
   struct Compare {
       bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
           return a.second > b.second;  // Min-heap on second
       }
   };
   int main() {
       std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
       pq.emplace(1, 3); pq.emplace(2, 1); pq.emplace(3, 2);
       while (!pq.empty()) {
           std::cout << pq.top().first << "," << pq.top().second << " ";  // Output: 2,1 3,2 1,3
           pq.pop();
       }
       return 0;
   }
   ```
   **Explanation**: Functor customizes heap order (Hours 7, 13).  
   **Interviewer’s Intention**: Tests custom comparators.

6. **Question**: Write a program to remove elements from a `std::vector` less than a threshold using `std::remove_if` and iterators.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   int main() {
       std::vector<int> v = {1, 5, 3, 7, 2};
       int threshold = 4;
       auto new_end = std::remove_if(v.begin(), v.end(), [threshold](int x) { return x < threshold; });
       v.erase(new_end, v.end());
       for (int x : v) std::cout << x << " ";  // Output: 5 7
       return 0;
   }
   ```
   **Explanation**: `remove_if` shifts elements, `erase` resizes (Hours 1, 13).  
   **Interviewer’s Intention**: Tests iterator and algorithm interaction.

7. **Question**: How does `std::multiset` handle duplicate elements compared to `std::set`?  
   **Answer**: `multiset` allows duplicates, `set` ensures uniqueness; both sorted.  
   **Explanation**: Both use balanced trees (Hour 10).  
   **Interviewer’s Intention**: Tests container nuances.

8. **Question**: Write a program to merge two sorted `std::multiset`s using `std::merge` and `inserter`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <set>
   #include <algorithm>
   #include <iterator>
   int main() {
       std::multiset<int> ms1 = {1, 2, 2}, ms2 = {2, 3, 3};
       std::multiset<int> result;
       std::merge(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), std::inserter(result, result.begin()));
       for (int x : result) std::cout << x << " ";  // Output: 1 2 2 2 3 3
       return 0;
   }
   ```
   **Explanation**: `merge` preserves duplicates, `inserter` adds to `multiset` (Hours 10, 14).  
   **Interviewer’s Intention**: Tests handling duplicates with adaptors.

9. **Question**: What are the iterator requirements for `std::transform`?  
   **Answer**: Input iterators for source, output iterator for destination.  
   **Explanation**: Ensures container compatibility (Hours 13, 14).  
   **Interviewer’s Intention**: Tests algorithm-iterator compatibility.

10. **Question**: Write a program to implement a stack using two `std::queue`s.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <queue>
    class MyStack {
        std::queue<int> q1, q2;
    public:
        void push(int x) {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            std::swap(q1, q2);
        }
        int pop() {
            int x = q1.front();
            q1.pop();
            return x;
        }
        int top() { return q1.front(); }
        bool empty() { return q1.empty(); }
    };
    int main() {
        MyStack s;
        s.push(1); s.push(2);
        std::cout << s.pop() << std::endl;  // Output: 2
        return 0;
    }
    ```
    **Explanation**: Simulates LIFO using FIFO queues (Hour 6).  
    **Interviewer’s Intention**: Tests creative container usage.

11. **Question**: Write a program to find the k-th smallest element in a `std::vector` using `std::nth_element`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {3, 1, 4, 2};
        int k = 2;
        std::nth_element(v.begin(), v.begin() + k - 1, v.end());
        std::cout << v[k - 1] << std::endl;  // Output: 2
        return 0;
    }
    ```
    **Explanation**: `nth_element` partially sorts, O(n) (Hour 12).  
    **Interviewer’s Intention**: Tests advanced sorting algorithms.

12. **Question**: How does `std::unordered_set` ensure uniqueness?  
   **Answer**: Uses hash table to reject duplicate keys.  
   **Explanation**: O(1) average insertion/check (Hour 11).  
   **Interviewer’s Intention**: Tests hash table mechanics.

13. **Question**: Write a program to implement a queue using two `std::stack`s.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <stack>
    class MyQueue {
        std::stack<int> s1, s2;
    public:
        void push(int x) { s1.push(x); }
        int pop() {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
        int front() { /* Similar logic to pop */ return s2.top(); }
        bool empty() { return s1.empty() && s2.empty(); }
    };
    int main() {
        MyQueue q;
        q.push(1); q.push(2);
        std::cout << q.pop() << std::endl;  // Output: 1
        return 0;
    }
    ```
    **Explanation**: Simulates FIFO using LIFO stacks (Hour 5).  
    **Interviewer’s Intention**: Tests creative container usage.

14. **Question**: What is the space complexity of `std::vector::push_back`?  
   **Answer**: O(1) amortized, O(n) worst case for reallocation.  
   **Explanation**: Doubling capacity minimizes reallocations (Hour 1).  
   **Interviewer’s Intention**: Tests vector memory management.

15. **Question**: Write a program to find the median of a `std::vector` using `std::nth_element`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    double findMedian(std::vector<int>& v) {
        int n = v.size();
        std::nth_element(v.begin(), v.begin() + n/2, v.end());
        if (n % 2) return v[n/2];
        std::nth_element(v.begin(), v.begin() + n/2 - 1, v.end());
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    }
    int main() {
        std::vector<int> v = {1, 3, 2, 4};
        std::cout << findMedian(v) << std::endl;  // Output: 2.5
        return 0;
    }
    ```
    **Explanation**: `nth_element` finds middle elements, O(n) (Hour 12).  
    **Interviewer’s Intention**: Tests statistical algorithms.

16. **Question**: How does `std::map` maintain sorted order?  
   **Answer**: Uses a balanced binary search tree (e.g., red-black tree).  
   **Explanation**: Ensures O(log n) operations (Hour 9).  
   **Interviewer’s Intention**: Tests map internals.

17. **Question**: Write a program to count frequency of elements in a `std::vector` using `std::unordered_map`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <unordered_map>
    int main() {
        std::vector<int> v = {1, 2, 2, 3};
        std::unordered_map<int, int> freq;
        for (int x : v) freq[x]++;
        for (const auto& p : freq) std::cout << p.first << ":" << p.second << " ";  // Output: 1:1 2:2 3:1
        return 0;
    }
    ```
    **Explanation**: `unordered_map` tracks counts, O(n) (Hour 9).  
    **Interviewer’s Intention**: Tests hash-based counting.

18. **Question**: What is the difference between `std::for_each` and `std::transform`?  
   **Answer**: `for_each` applies function for side effects; `transform` stores results.  
   **Explanation**: `transform` requires output iterator (Hour 13).  
   **Interviewer’s Intention**: Tests algorithm roles.

19. **Question**: Write a program to find the longest common prefix in a `std::vector` of `std::string`s.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        std::string prefix = strs[0];
        for (const auto& s : strs) {
            while (s.find(prefix) != 0) prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
        return prefix;
    }
    int main() {
        std::vector<std::string> strs = {"flower", "flow", "flight"};
        std::cout << longestCommonPrefix(strs) << std::endl;  // Output: fl
        return 0;
    }
    ```
    **Explanation**: Uses string operations (Hour 4).  
    **Interviewer’s Intention**: Tests string processing.

20. **Question**: What iterator type does `std::unordered_set` provide?  
    **Answer**: Forward iterator.  
    **Explanation**: Supports single-direction traversal (Hour 14).  
    **Interviewer’s Intention**: Tests iterator knowledge.

21. **Question**: Write a program to rotate a `std::vector` by k positions using `std::rotate`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    int main() {
        std::vector<int> v = {1, 2, 3, 4, 5};
        int k = 2;
        std::rotate(v.begin(), v.begin() + k % v.size(), v.end());
        for (int x : v) std::cout << x << " ";  // Output: 3 4 5 1 2
        return 0;
    }
    ```
    **Explanation**: `rotate` shifts elements, O(n) (Hour 12).  
    **Interviewer’s Intention**: Tests advanced algorithms.

22. **Question**: How does `std::priority_queue` handle duplicate priorities?  
    **Answer**: Stores all elements, orders by comparator.  
    **Explanation**: Heap allows duplicates (Hour 7).  
    **Interviewer’s Intention**: Tests priority queue behavior.

23. **Question**: Write a program to check if two `std::string`s are anagrams using `std::unordered_map`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <string>
    #include <unordered_map>
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        std::unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (char c : t) if (--freq[c] < 0) return false;
        return true;
    }
    int main() {
        std::string s = "rat", t = "tar";
        std::cout << (isAnagram(s, t) ? "Anagram" : "Not anagram") << std::endl;  // Output: Anagram
        return 0;
    }
    ```
    **Explanation**: `unordered_map` counts character frequencies (Hours 4, 9).  
    **Interviewer’s Intention**: Tests string and hash usage.

24. **Question**: What is the purpose of `std::inserter`?  
    **Answer**: Inserts elements at a specific iterator position.  
    **Explanation**: Works with associative containers (Hour 14).  
    **Interviewer’s Intention**: Tests iterator adaptors.

25. **Question**: Write a program to find the top k frequent elements in a `std::vector` using `std::priority_queue`.  
    **Answer**:  
    ```cpp
    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <queue>
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        for (const auto& p : freq) {
            pq.emplace(p.second, p.first);
            if (pq.size() > k) pq.pop();
        }
        std::vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    int main() {
        std::vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        auto result = topKFrequent(nums, k);
        for (int x : result) std::cout << x << " ";  // Output: 1 2
        return 0;
    }
    ```
    **Explanation**: `unordered_map` counts frequencies, `priority_queue` selects top k (Hours 7, 9).  
    **Interviewer’s Intention**: Tests complex container and algorithm combination.