
### Homework Solutions
1.  
```cpp
#include <iostream>
int main() {
    int age = 30;
    double salary = 50000.50;
    char grade = 'A';
    std::cout << "I am " << age << " years old, earn " << salary << ", and my grade is " << grade << "." << std::endl;
    return 0;
}
```

2.  
```cpp
#include <iostream>
int main() {
    int a, b;
    std::cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    std::cout << a << " " << b << std::endl;
    return 0;
}
```

3.  
```cpp
#include <iostream>
#include <iomanip>  // For setprecision
int main() {
    double radius, pi = 3.14159;
    std::cin >> radius;
    double area = pi * radius * radius;
    std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    return 0;
}
```

4.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string first, last;
    std::cin >> first >> last;
    std::cout << first[0] << "." << last[0] << "." << std::endl;
    return 0;
}
```

5.  
```cpp
#include <iostream>
int main() {
    float a, b;
    std::cin >> a >> b;
    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Diff: " << a - b << std::endl;
    std::cout << "Prod: " << a * b << std::endl;
    std::cout << "Quot: " << a / b << std::endl;
    // Modulus not for float, skip or cast
    return 0;
}
```

6.  
```cpp
#include <iostream>
int main() {
    int num;
    std::cin >> num;
    std::cout << (num % 2 == 0 ? "Even" : "Odd") << std::endl;
    return 0;
}
```

7.  
```cpp
#include <iostream>
int main() {
    double c;
    std::cin >> c;
    double f = c * 9 / 5 + 32;
    std::cout << f << std::endl;
    return 0;
}
```

8.  
```cpp
#include <iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int max = (a > b ? (a > c ? a : c) : (b > c ? b : c));
    std::cout << max << std::endl;
    return 0;
}
```

9.  
```cpp
#include <iostream>
int main() {
    int age;
    double height;
    std::cin >> age >> height;
    std::cout << (age >= 18 && height >= 5.5 ? "Eligible" : "Not Eligible") << std::endl;
    return 0;
}
```

10.  
```cpp
#include <iostream>
int main() {
    double p, r, t;
    std::cin >> p >> r >> t;
    double i = p * r * t / 100;
    std::cout << i << std::endl;
    return 0;
}
```

11.  
```cpp
#include <iostream>
int main() {
    char ch;
    std::cin >> ch;
    bool isVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    std::cout << (isVowel ? "Vowel" : "Consonant") << std::endl;
    return 0;
}
```

12.  
```cpp
#include <iostream>
int main() {
    int x = 10;
    std::cout << x << std::endl;
    x += 5; std::cout << x << std::endl;
    x *= 2; std::cout << x << std::endl;
    x -= 10; std::cout << x << std::endl;
    x /= 5; std::cout << x << std::endl;
    return 0;
}
```

13.  
```cpp
#include <iostream>
int main() {
    double w, h;
    std::cin >> w >> h;
    double bmi = w / (h * h);
    std::string cat = (bmi < 18.5 ? "Underweight" : (bmi < 25 ? "Normal" : "Overweight"));
    std::cout << bmi << " " << cat << std::endl;
    return 0;
}
```

14.  
```cpp
#include <iostream>
#include <string>
int main() {
    std::string pass;
    std::cin >> pass;
    std::cout << (pass.length() >= 8 ? "Valid" : "Invalid") << std::endl;
    return 0;
}
```

15.  
```cpp
#include <iostream>
#include <iomanip>
int main() {
    int sec;
    std::cin >> sec;
    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    int s = sec % 60;
    std::cout << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ":" << std::setw(2) << s << std::endl;
    return 0;
}
