# C++ Refresher for DSA Cohort: Hour 3 - Homework Solutions

Solutions to the 15 homework problems for Hour 3, covering functions, scope, and arrays.

1. **Problem**: Write a function to check if a number is even.  
```cpp
#include <iostream>
bool isEven(int num) {  // Function to check if number is even
    return num % 2 == 0;  // Return true if divisible by 2
}
int main() {
    int num;
    std::cin >> num;
    std::cout << (isEven(num) ? "true" : "false") << std::endl;
    return 0;
}
```

2. **Problem**: Create a function to calculate the cube of a number.  
```cpp
#include <iostream>
int cube(int num) {  // Function to compute cube
    return num * num * num;  // Return num^3
}
int main() {
    int num;
    std::cin >> num;
    std::cout << cube(num) << std::endl;
    return 0;
}
```

3. **Problem**: Write a program with a function to find the maximum of two numbers.  
```cpp
#include <iostream>
int max(int a, int b) {  // Function to find maximum
    return a > b ? a : b;  // Return larger number
}
int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << max(a, b) << std::endl;
    return 0;
}
```

4. **Problem**: Create a program to demonstrate local and global variable scope with same name.  
```cpp
#include <iostream>
int x = 10;  // Global variable
int main() {
    int x = 20;  // Local variable shadows global
    std::cout << "Local: " << x << ", Global: " << ::x << std::endl;  // :: accesses global
    return 0;
}
```

5. **Problem**: Write a function to compute the area of a rectangle given length and width.  
```cpp
#include <iostream>
double rectangleArea(double length, double width) {  // Function for area
    return length * width;  // Return area
}
int main() {
    double l, w;
    std::cin >> l >> w;
    std::cout << rectangleArea(l, w) << std::endl;
    return 0;
}
```

6. **Problem**: Create an array to store 5 user-input numbers and print them using a function.  
```cpp
#include <iostream>
void printArray(int arr[], int size) {  // Function to print array
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    printArray(arr, 5);
    return 0;
}
```

7. **Problem**: Write a function to find the minimum element in an array of 5 integers.  
```cpp
#include <iostream>
int findMin(int arr[], int size) {  // Function to find minimum
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    std::cout << findMin(arr, 5) << std::endl;
    return 0;
}
```

8. **Problem**: Create a program to reverse an array of 5 elements using a function.  
```cpp
#include <iostream>
void reverseArray(int arr[], int size) {  // Function to reverse array
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

9. **Problem**: Write a function to count occurrences of a number in an array.  
```cpp
#include <iostream>
int countOccurrences(int arr[], int size, int target) {  // Function to count occurrences
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) count++;
    }
    return count;
}
int main() {
    int arr[5], target;
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    std::cin >> target;
    std::cout << countOccurrences(arr, 5, target) << std::endl;
    return 0;
}
```

10. **Problem**: Create a program with a function to check if an array is sorted in ascending order.  
```cpp
#include <iostream>
bool isSorted(int arr[], int size) {  // Function to check if sorted
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    std::cout << (isSorted(arr, 5) ? "true" : "false") << std::endl;
    return 0;
}
```

11. **Problem**: Write a program to demonstrate block scope with nested blocks.  
```cpp
#include <iostream>
int main() {
    int x = 100;  // Outer scope
    {
        int x = 50;  // Inner scope
        std::cout << "Inner: " << x << std::endl;
    }
    std::cout << "Outer: " << x << std::endl;
    return 0;
}
```

12. **Problem**: Create a function to calculate average of an array of 5 doubles.  
```cpp
#include <iostream>
double arrayAverage(double arr[], int size) {  // Function to compute average
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}
int main() {
    double arr[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    std::cout << arrayAverage(arr, 5) << std::endl;
    return 0;
}
```

13. **Problem**: Write a program to swap two elements in an array using a function.  
```cpp
#include <iostream>
void swapElements(int arr[], int i, int j) {  // Function to swap elements
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main() {
    int arr[5];
    int i, j;
    for (int k = 0; k < 5; k++) {
        std::cin >> arr[k];
    }
    std::cin >> i >> j;
    swapElements(arr, i, j);
    for (int k = 0; k < 5; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

14. **Problem**: Create a function to check if a number is positive using local scope.  
```cpp
#include <iostream>
bool isPositive(int num) {  // Function with local scope
    int local = num;  // Local variable
    return local > 0;
}
int main() {
    int num;
    std::cin >> num;
    std::cout << (isPositive(num) ? "true" : "false") << std::endl;
    return 0;
}
```

15. **Problem**: Write a program to find the second largest element in an array using a function.  
```cpp
#include <iostream>
int secondLargest(int arr[], int size) {  // Function to find second largest
    int max = arr[0], second = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            second = max;
            max = arr[i];
        } else if (arr[i] > second && arr[i] != max) {
            second = arr[i];
        }
    }
    return second;
}
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    std::cout << secondLargest(arr, 5) << std::endl;
    return 0;
}
```