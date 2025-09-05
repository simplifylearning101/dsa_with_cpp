### Homework Solutions
1.  
```cpp
#include <iostream>
int main() {
    int num;
    std::cin >> num;
    if (num > 0) std::cout << "Positive" << std::endl;
    else if (num < 0) std::cout << "Negative" << std::endl;
    else std::cout << "Zero" << std::endl;
    return 0;
}
```

2.  
```cpp
#include <iostream>
int main() {
    int year;
    std::cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        std::cout << "Leap" << std::endl;
    else
        std::cout << "Not Leap" << std::endl;
    return 0;
}
```

3.  
```cpp
#include <iostream>
int main() {
    int age;
    std::cin >> age;
    if (age < 13) std::cout << "Child" << std::endl;
    else if (age <= 19) std::cout << "Teen" << std::endl;
    else if (age <= 59) std::cout << "Adult" << std::endl;
    else std::cout << "Senior" << std::endl;
    return 0;
}
```

4.  
```cpp
#include <iostream>
int main() {
    char grade;
    std::cin >> grade;
    switch (grade) {
        case 'A': std::cout << 4 << std::endl; break;
        case 'B': std::cout << 3 << std::endl; break;
        case 'C': std::cout << 2 << std::endl; break;
        case 'D': std::cout << 1 << std::endl; break;
        case 'F': std::cout << 0 << std::endl; break;
        default: std::cout << "Invalid" << std::endl;
    }
    return 0;
}
```

5.  
```cpp
#include <iostream>
int main() {
    for (int i = 2; i <= 20; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

6.  
```cpp
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    std::cout << fact << std::endl;
    return 0;
}
```

7.  
```cpp
#include <iostream>
int main() {
    int num;
    std::cin >> num;
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}
```

8.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string pass;
    do {
        std::cin >> pass;
    } while (pass != "secret");
    std::cout << "Access Granted" << std::endl;
    return 0;
}
```

9.  
```cpp
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= 10; i++) {
        std::cout << n * i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

10.  
```cpp
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    bool isPrime = true;
    if (n <= 1) isPrime = false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) isPrime = false;
    }
    std::cout << (isPrime ? "Prime" : "Not Prime") << std::endl;
    return 0;
}
```

11.  
```cpp
#include <iostream>
int main() {
    int num, rev = 0;
    std::cin >> num;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    std::cout << rev << std::endl;
    return 0;
}
```

12.  
```cpp
#include <iostream>
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}
```

13.  
```cpp
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}
```

14.  
```cpp
#include <iostream>
int main() {
    int balance = 1000, amount;
    std::cin >> amount;
    if (amount % 100 == 0 && amount <= balance)
        std::cout << "Success" << std::endl;
    else
        std::cout << "Invalid amount or insufficient balance" << std::endl;
    return 0;
}
```

15.  
```cpp
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        std::cout << a << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
    std::cout << std::endl;
    return 0;
}
```
