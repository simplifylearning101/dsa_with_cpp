# C++ Refresher for DSA Cohort: Hour 5 - Homework Solutions

Solutions to the 15 homework problems for Hour 5, covering dynamic memory allocation, structures, and recursion.

1. **Problem**: Write a program to allocate a dynamic integer and assign it a value, then print it.  
```cpp
#include <iostream>
int main() {
    int* ptr = new int;  // Allocate single integer
    *ptr = 42;  // Assign value
    std::cout << *ptr << std::endl;  // Print value
    delete ptr;  // Free memory
    ptr = nullptr;  // Avoid dangling pointer
    return 0;
}
```

2. **Problem**: Create a function to dynamically allocate an array and initialize it with zeros.  
```cpp
#include <iostream>
void initArray(int* arr, int size) {  // Function to initialize array
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}
int main() {
    int size;
    std::cin >> size;
    int* arr = new int[size];  // Allocate array
    initArray(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;  // Free memory
    arr = nullptr;
    return 0;
}
```

3. **Problem**: Write a program to define a structure for a book (title, author, year) and print its details.  
```cpp
#include <iostream>
#include <string>
struct Book {
    std::string title;
    std::string author;
    int year;
};
int main() {
    Book b;
    std::cin >> b.title >> b.author >> b.year;
    std::cout << b.title << ", " << b.author << ", " << b.year << std::endl;
    return 0;
}
```

4. **Problem**: Create a recursive function to compute the nth Fibonacci number.  
```cpp
#include <iostream>
unsigned long long fibonacci(int n) {  // Recursive function
    if (n <= 1) return n;  // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}
int main() {
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;
    return 0;
}
```

5. **Problem**: Write a program to dynamically allocate an array of doubles and compute their sum.  
```cpp
#include <iostream>
int main() {
    int size = 3;
    double* arr = new double[size];  // Allocate array
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    std::cout << sum << std::endl;
    delete[] arr;
    arr = nullptr;
    return 0;
}
```

6. **Problem**: Create a structure for a point (x, y) and compute distance from origin using a function.  
```cpp
#include <iostream>
#include <cmath>
struct Point {
    double x, y;
};
double distance(Point p) {  // Function to compute distance
    return std::sqrt(p.x * p.x + p.y * p.y);
}
int main() {
    Point p;
    std::cin >> p.x >> p.y;
    std::cout << distance(p) << std::endl;
    return 0;
}
```

7. **Problem**: Write a recursive function to compute power (base, exponent).  
```cpp
#include <iostream>
unsigned long long power(int base, int exp) {  // Recursive function
    if (exp == 0) return 1;  // Base case
    return base * power(base, exp - 1);  // Recursive case
}
int main() {
    int base, exp;
    std::cin >> base >> exp;
    std::cout << power(base, exp) << std::endl;
    return 0;
}
```

8. **Problem**: Create a program to allocate an array of structures (name, score) and print them.  
```cpp
#include <iostream>
#include <string>
struct Student {
    std::string name;
    int score;
};
int main() {
    int size = 2;
    Student* students = new Student[size];  // Allocate array of structures
    for (int i = 0; i < size; i++) {
        std::cin >> students[i].name >> students[i].score;
    }
    for (int i = 0; i < size; i++) {
        std::cout << students[i].name << ": " << students[i].score << std::endl;
    }
    delete[] students;
    students = nullptr;
    return 0;
}
```

9. **Problem**: Write a recursive function to reverse a string.  
```cpp
#include <iostream>
#include <string>
std::string reverseString(std::string str, int i) {  // Recursive function
    if (i >= str.length() / 2) return str;  // Base case
    char temp = str[i];
    str[i] = str[str.length() - 1 - i];
    str[str.length() - 1 - i] = temp;
    return reverseString(str, i + 1);  // Recursive call
}
int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << reverseString(str, 0) << std::endl;
    return 0;
}
```

10. **Problem**: Create a program to dynamically allocate a 2D array (2x3) and initialize with sequential numbers.  
```cpp
#include <iostream>
int main() {
    int rows = 2, cols = 3;
    int** arr = new int*[rows];  // Allocate array of pointers
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // Allocate each row
    }
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value++;  // Initialize with 1, 2, 3...
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];  // Free each row
    }
    delete[] arr;  // Free array of pointers
    arr = nullptr;
    return 0;
}
```

11. **Problem**: Write a structure for a rectangle (length, width) and a function to compute area.  
```cpp
#include <iostream>
struct Rectangle {
    double length, width;
};
double area(Rectangle r) {  // Function to compute area
    return r.length * r.width;
}
int main() {
    Rectangle r;
    std::cin >> r.length >> r.width;
    std::cout << area(r) << std::endl;
    return 0;
}
```

12. **Problem**: Create a recursive function to compute sum of digits in a number.  
```cpp
#include <iostream>
int sumDigits(int n) {  // Recursive function
    if (n == 0) return 0;  // Base case
    return (n % 10) + sumDigits(n / 10);  // Recursive case
}
int main() {
    int n;
    std::cin >> n;
    std::cout << sumDigits(n) << std::endl;
    return 0;
}
```

13. **Problem**: Write a program to allocate dynamic memory for a string and concatenate another string.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string* str = new std::string;  // Allocate string
    std::string temp;
    std::getline(std::cin, *str);
    std::getline(std::cin, temp);
    *str += temp;  // Concatenate
    std::cout << *str << std::endl;
    delete str;  // Free memory
    str = nullptr;
    return 0;
}
```

14. **Problem**: Create a recursive function to check if a number is a palindrome.  
```cpp
#include <iostream>
bool isPalindrome(int n, int original, int reversed = 0) {  // Recursive function
    if (n == 0) return reversed == original;  // Base case
    return isPalindrome(n / 10, original, reversed * 10 + n % 10);  // Recursive case
}
int main() {
    int n;
    std::cin >> n;
    std::cout << (isPalindrome(n, n) ? "true" : "false") << std::endl;
    return 0;
}
```

15. **Problem**: Write a program using a structure for employee (name, id, salary) and sort by salary.  
```cpp
#include <iostream>
#include <string>
struct Employee {
    std::string name;
    int id;
    double salary;
};
int main() {
    int size = 2;
    Employee* emp = new Employee[size];  // Allocate array
    for (int i = 0; i < size; i++) {
        std::cin >> emp[i].name >> emp[i].id >> emp[i].salary;
    }
    // Simple bubble sort by salary
    for (int i = 0; i < size - 1; i++) {
        if (emp[i].salary < emp[i + 1].salary) {
            Employee temp = emp[i];
            emp[i] = emp[i + 1];
            emp[i + 1] = temp;
        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << emp[i].name << ": " << emp[i].salary << std::endl;
    }
    delete[] emp;
    emp = nullptr;
    return 0;
}
```