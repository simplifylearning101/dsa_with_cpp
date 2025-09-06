# Hard Interview Questions for Hours 1–14: C++ STL Containers and Algorithms

Below are 10 challenging interview questions covering Hours 1–14. These questions test advanced understanding of STL containers, algorithms, and iterators, suitable for experienced candidates.

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
       for