# C++ Refresher for DSA Cohort: Hour 4 - Homework Solutions

Solutions to the 15 homework problems for Hour 4, covering pointers, references, and strings.

1. **Problem**: Write a program to use a pointer to double a number.  
```cpp
#include <iostream>
int main() {
    int num = 5;  // Variable to double
    int* ptr = &num;  // Pointer to num
    std::cout << "Original: " << num << std::endl;
    *ptr *= 2;  // Double via pointer
    std::cout << "Doubled: " << num << std::endl;
    return 0;
}
```

2. **Problem**: Create a function to increment a number using a pointer.  
```cpp
#include <iostream>
void increment(int* ptr) {  // Function to increment via pointer
    (*ptr)++;  // Increment value at address
}
int main() {
    int num;
    std::cin >> num;
    increment(&num);
    std::cout << num << std::endl;
    return 0;
}
```

3. **Problem**: Write a program to swap two numbers using pointers.  
```cpp
#include <iostream>
void swap(int* a, int* b) {  // Function to swap via pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x, y;
    std::cin >> x >> y;
    swap(&x, &y);
    std::cout << x << ", " << y << std::endl;
    return 0;
}
```

4. **Problem**: Create a function to check if a string is empty using a reference.  
```cpp
#include <iostream>
#include <string>
bool isEmpty(std::string& str) {  // Function with reference
    return str.empty();  // Use empty() method
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << (isEmpty(str) ? "true" : "false") << std::endl;
    return 0;
}
```

5. **Problem**: Write a program to concatenate two strings using `std::string`.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    std::cout << s1 + s2 << std::endl;
    return 0;
}
```

6. **Problem**: Create a function to reverse a string using references.  
```cpp
#include <iostream>
#include <string>
void reverseString(std::string& str) {  // Function with reference
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    reverseString(str);
    std::cout << str << std::endl;
    return 0;
}
```

7. **Problem**: Write a program to access array elements using a pointer.  
```cpp
#include <iostream>
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> arr[i];
    }
    int* ptr = arr;  // Pointer to array
    for (int i = 0; i < 3; i++) {
        std::cout << *(ptr + i) << " ";  // Access via pointer arithmetic
    }
    std::cout << std::endl;
    return 0;
}
```

8. **Problem**: Create a function to find the length of a string without using `length()`.  
```cpp
#include <iostream>
#include <string>
int stringLength(std::string& str) {  // Function with reference
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << stringLength(str) << std::endl;
    return 0;
}
```

9. **Problem**: Write a program to use a pointer to find the maximum in an array.  
```cpp
#include <iostream>
int findMax(int* arr, int size) {  // Function with pointer
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) max = *(arr + i);
    }
    return max;
}
int main() {
    int arr[4];
    for (int i = 0; i < 4; i++) {
        std::cin >> arr[i];
    }
    std::cout << findMax(arr, 4) << std::endl;
    return 0;
}
```

10. **Problem**: Create a function to count vowels in a string using references.  
```cpp
#include <iostream>
#include <string>
int countVowels(std::string& str) {  // Function with reference
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') count++;
    }
    return count;
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << countVowels(str) << std::endl;
    return 0;
}
```

11. **Problem**: Write a program to compare two strings for equality.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    std::cout << (s1 == s2 ? "Equal" : "Not Equal") << std::endl;
    return 0;
}
```

12. **Problem**: Create a function to swap two array elements using pointers.  
```cpp
#include <iostream>
void swapElements(int* arr, int i, int j) {  // Function with pointer
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
}
int main() {
    int arr[4];
    int i, j;
    for (int k = 0; k < 4; k++) {
        std::cin >> arr[k];
    }
    std::cin >> i >> j;
    swapElements(arr, i, j);
    for (int k = 0; k < 4; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

13. **Problem**: Write a program to check if a pointer is null before dereferencing.  
```cpp
#include <iostream>
int main() {
    int* ptr = nullptr;  // Null pointer
    if (ptr != nullptr) {
        std::cout << *ptr << std::endl;
    } else {
        std::cout << "Null pointer" << std::endl;
    }
    return 0;
}
```

14. **Problem**: Create a function to convert a string to uppercase using references.  
```cpp
#include <iostream>
#include <string>
void toUpper(std::string& str) {  // Function with reference
    for (char& c : str) {
        if (c >= 'a' && c <= 'z') c -= 32;  // Convert to uppercase
    }
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    toUpper(str);
    std::cout << str << std::endl;
    return 0;
}
```

15. **Problem**: Write a program to find the first occurrence of a character in a string using a pointer.  
```cpp
#include <iostream>
#include <string>
int findChar(std::string& str, char c) {  // Function with reference
    const char* ptr = str.c_str();  // Pointer to string
    for (int i = 0; ptr[i] != '\0'; i++) {
        if (ptr[i] == c) return i;
    }
    return -1;
}
int main() {
    std::string str;
    char c;
    std::getline(std::cin, str);
    std::cin >> c;
    std::cout << findChar(str, c) << std::endl;
    return 0;
}
```