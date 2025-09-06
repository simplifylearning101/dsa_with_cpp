# Very Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 10 very challenging interview questions covering Hours 1–14. These questions test deep mastery of STL containers, algorithms, iterators, and their interactions, suitable for advanced candidates.

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
   **Answer**: Uses separate chaining (linked lists or buckets) or open addressing in some implementations.  
   **Explanation**: Collisions resolved by storing multiple elements per hash slot, O(1) average lookup (Hour 9).  
   **Interviewer’s Intention**: Tests hash table internals.

3. **Question**: Write a program to find all pairs in a `std::vector` summing to a target using `std::unordered_set` and `std::for_each`.  
   **Answer**:  
   ```cpp
   #include <iostream>
   #include <vector>
   #include <unordered_set>
   #include <algorithm>
   std::vector<std::pair<int, int>> findPairs(std::vector<int>& nums, int target) {
       std