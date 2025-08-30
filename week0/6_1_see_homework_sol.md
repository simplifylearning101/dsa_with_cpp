# C++ Refresher for DSA Cohort: Hour 6 - Homework Solutions

Solutions to the 15 homework problems for Hour 6, covering advanced pointers, strings, and recursion.

1. **Problem**: Write a program to use pointer arithmetic to sum an array.  
```cpp
#include <iostream>
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> arr[i];
    }
    int* ptr = arr;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += *(ptr + i);  // Sum using pointer arithmetic
    }
    std::cout << sum << std::endl;
    return 0;
}
```

2. **Problem**: Create a function pointer to call a function that doubles a number.  
```cpp
#include <iostream>
int doubleNum(int x) { return x * 2; }  // Function to double
int main() {
    int (*funcPtr)(int) = doubleNum;  // Function pointer
    int num;
    std::cin >> num;
    std::cout << funcPtr(num) << std::endl;  // Call via pointer
    return 0;
}
```

3. **Problem**: Write a program using a double pointer to modify an array element.  
```cpp
#include <iostream>
void updateElement(int** ptr, int index, int value) {  // Double pointer to modify
    (*ptr)[index] = value;  // Update array element
}
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> arr[i];
    }
    int* ptr = arr;
    int** doublePtr = &ptr;
    updateElement(doublePtr, 1, 10);
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

4. **Problem**: Create a function to reverse a C-style string in-place.  
```cpp
#include <iostream>
#include <cstring>
void reverse(char* str) {  // Function to reverse
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + len - 1 - i);
        *(str + len - 1 - i) = temp;
    }
}
int main() {
    char str[100];
    std::cin.getline(str, 100);
    reverse(str);
    std::cout << str << std::endl;
    return 0;
}
```

5. **Problem**: Write a program to count words in a C-style string using pointers.  
```cpp
#include <iostream>
#include <cstring>
int countWords(char* str) {  // Function to count words
    int count = 0;
    bool inWord = false;
    while (*str) {
        if (*str == ' ') inWord = false;
        else if (!inWord) {
            inWord = true;
            count++;
        }
        str++;
    }
    return count;
}
int main() {
    char str[100];
    std::cin.getline(str, 100);
    std::cout << countWords(str) << std::endl;
    return 0;
}
```

6. **Problem**: Create a recursive function to compute sum of array elements.  
```cpp
#include <iostream>
int arraySum(int* arr, int size, int index = 0) {  // Recursive function
    if (index >= size) return 0;  // Base case
    return arr[index] + arraySum(arr, size, index + 1);  // Recursive case
}
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> arr[i];
    }
    std::cout << arraySum(arr, 3) << std::endl;
    return 0;
}
```

7. **Problem**: Write a program to use a function pointer to compute square or cube based on user choice.  
```cpp
#include <iostream>
int square(int x) { return x * x; }
int cube(int x) { return x * x * x; }
int main() {
    int num, choice;
    std::cin >> num >> choice;
    int (*funcPtr)(int) = (choice == 1) ? square : cube;  // Select function
    std::cout << funcPtr(num) << std::endl;
    return 0;
}
```

8. **Problem**: Create a recursive function to find maximum in an array.  
```cpp
#include <iostream>
int findMax(int* arr, int size, int index = 0) {  // Recursive function
    if (index == size - 1) return arr[index];  // Base case
    int restMax = findMax(arr, size, index + 1);  // Recursive call
    return arr[index] > restMax ? arr[index] : restMax;
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

9. **Problem**: Write a program to check if two C-style strings are equal using pointers.  
```cpp
#include <iostream>
#include <cstring>
bool areEqual(char* s1, char* s2) {  // Function to compare strings
    while (*s1 && *s2) {
        if (*s1 != *s2) return false;
        s1++;
        s2++;
    }
    return *s1 == *s2;  // Check if both end
}
int main() {
    char s1[100], s2[100];
    std::cin.getline(s1, 100);
    std::cin.getline(s2, 100);
    std::cout << (areEqual(s1, s2) ? "Equal" : "Not Equal") << std::endl;
    return 0;
}
```

10. **Problem**: Create a recursive function to generate all subsets of a string.  
```cpp
#include <iostream>
#include <string>
void subsets(std::string str, std::string curr, int index) {  // Recursive function
    if (index == str.length()) {  // Base case
        std::cout << curr << std::endl;
        return;
    }
    subsets(str, curr, index + 1);  // Exclude current char
    subsets(str, curr + str[index], index + 1);  // Include current char
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    subsets(str, "", 0);
    return 0;
}
```

11. **Problem**: Write a program using a double pointer to allocate and initialize a dynamic array.  
```cpp
#include <iostream>
void initArray(int** arr, int size) {  // Function with double pointer
    *arr = new int[size];  // Allocate array
    for (int i = 0; i < size; i++) {
        (*arr)[i] = i + 1;  // Initialize with 1, 2, 3...
    }
}
int main() {
    int size = 3;
    int* arr;
    initArray(&arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    arr = nullptr;
    return 0;
}
```

12. **Problem**: Create a function to find substring in a C-style string using pointers.  
```cpp
#include <iostream>
#include <cstring>
int findSubstring(char* str, char* sub) {  // Function to find substring
    int len1 = strlen(str), len2 = strlen(sub);
    for (int i = 0; i <= len1 - len2; i++) {
        bool found = true;
        for (int j = 0; j < len2; j++) {
            if (*(str + i + j) != *(sub + j)) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}
int main() {
    char str[100], sub[100];
    std::cin.getline(str, 100);
    std::cin.getline(sub, 100);
    std::cout << findSubstring(str, sub) << std::endl;
    return 0;
}
```

13. **Problem**: Write a recursive function to compute binary representation of a number.  
```cpp
#include <iostream>
void toBinary(int n) {  // Recursive function
    if (n == 0) return;  // Base case
    toBinary(n / 2);  // Recursive call
    std::cout << n % 2;  // Print remainder
}
int main() {
    int n;
    std::cin >> n;
    if (n == 0) std::cout << 0;
    else toBinary(n);
    std::cout << std::endl;
    return 0;
}
```

14. **Problem**: Create a program to use pointer arithmetic to reverse an array in-place.  
```cpp
#include <iostream>
void reverseArray(int* arr, int size) {  // Function to reverse
    for (int i = 0; i < size / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }
}
int main() {
    int arr[4];
    for (int i = 0; i < 4; i++) {
        std::cin >> arr[i];
    }
    reverseArray(arr, 4);
    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

15. **Problem**: Write a recursive function to solve Tower of Hanoi for 3 disks.  
```cpp
#include <iostream>
void towerOfHanoi(int n, char src, char aux, char dest) {  // Recursive function
    if (n == 1) {  // Base case
        std::cout << "Move disk 1 from " << src << " to " << dest << std::endl;
        return;
    }
    towerOfHanoi(n - 1, src, dest, aux);  // Move n-1 to auxiliary
    std::cout << "Move disk " << n << " from " << src << " to " << dest << std::endl;
    towerOfHanoi(n - 1, aux, src, dest);  // Move n-1 to destination
}
int main() {
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}
```