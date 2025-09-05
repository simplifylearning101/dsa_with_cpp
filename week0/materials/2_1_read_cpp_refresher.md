# C++ Refresher for DSA Cohort: Hour 2

This is the second hour of a 5-6 hour C++ refresher designed for students preparing for a 10-week Data Structures and Algorithms (DSA) cohort. 

In this session, we will cover control structures: conditional statements (`if`, `else if`, `else`), switch statements, and loops (`for`, `while`, `do-while`). These are like decision-making and repetitive tasks in real life.

## Hour 2: Topics Covered
We will revise the following concepts:  
1. Conditional Statements (`if`, `else if`, `else`)  
2. Switch Statements  
3. For Loops  
4. While and Do-While Loops  

### Concept 1: Conditional Statements (`if`, `else if`, `else`)
Conditional statements are like deciding what to wear based on the weather. If it's raining, take an umbrella; else if it's sunny, wear sunglasses; otherwise, just a jacket. 

In C++, `if` checks a condition (true/false), and executes code if true. `else if` and `else` handle alternative cases. Use curly braces `{}` for clarity, especially in interviews, to avoid errors.

**Example Program: Grade Calculator**
```cpp
#include <iostream>

int main() {
    int score;  // Variable to store exam score
    std::cout << "Enter your score (0-100): ";  // Prompt user
    std::cin >> score;  // Read score
    
    // Conditional statements to assign grade
    if (score >= 90) {  // Check if score is 90 or above
        std::cout << "Grade: A" << std::endl;
    }
    else if (score >= 80) {  // Check if score is 80-89
        std::cout << "Grade: B" << std::endl;
    }
    else if (score >= 70) {  // Check if score is 70-79
        std::cout << "Grade: C" << std::endl;
    }
    else if (score >= 60) {  // Check if score is 60-69
        std::cout << "Grade: D" << std::endl;
    }
    else {  // If score is below 60
        std::cout << "Grade: F" << std::endl;
    }
    
    return 0;  // End program
}
```
**Expected Outcome** (assuming input of 85):  
```
Enter your score (0-100): 85
Grade: B
```
This is like a teacher assigning grades based on a marking rubric.

### Concept 2: Switch Statements
A switch statement is like a menu at a fast-food restaurant: you pick an option (e.g., burger, pizza), and get a specific response. It’s an alternative to multiple `else if` statements for discrete values. Use `break` to exit each case, and `default` for unmatched cases. Useful in interviews for clean code when handling fixed options.

**Example Program: Day of the Week**
```cpp
#include <iostream>

int main() {
    int day;  // Variable for day number (1-7)
    std::cout << "Enter day number (1-7): ";  // Prompt user
    std::cin >> day;  // Read input
    
    // Switch to map day number to name
    switch (day) {
        case 1:  // If day is 1
            std::cout << "Monday" << std::endl;
            break;  // Exit switch
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:  // If no case matches
            std::cout << "Invalid day!" << std::endl;
            break;
    }
    
    return 0;  // End program
}
```
**Expected Outcome** (assuming input of 3):  
```
Enter day number (1-7): 3
Wednesday
```
This is like selecting a day from a calendar app.

### Concept 3: For Loops
A `for` loop is like packing a fixed number of boxes for moving: you know how many to pack, and you repeat the process. It’s ideal when the number of iterations is known. Syntax: `for (initialization; condition; update)`. Common in DSA for iterating over arrays or ranges.

**Example Program: Print Numbers 1 to 10**
```cpp
#include <iostream>

int main() {
    // Loop from 1 to 10
    for (int i = 1; i <= 10; i++) {  // Initialize i=1; continue while i<=10; increment i
        std::cout << i << " ";  // Print number with space
    }
    std::cout << std::endl;  // Newline after loop
    
    return 0;  // End program
}
```
**Expected Outcome**:  
```
1 2 3 4 5 6 7 8 9 10
```
This is like counting items on a checklist.


### Concept 4: While and Do-While Loops
A `while` loop is like washing dishes until the sink is empty: check the condition first, then act. A `do-while` loop is similar but ensures at least one iteration (e.g., try washing at least one dish before checking). Use `while` when the number of iterations is unknown, and `do-while` when you need at least one run. In interviews, choose the right loop to avoid infinite loops.

**Example Program: Sum of Numbers Until Zero**
```cpp
#include <iostream>

int main() {
    int num;  // Variable for user input
    int sum = 0;  // Variable to store sum
    
    // Do-while to ensure at least one input
    do {
        std::cout << "Enter a number (0 to stop): ";  // Prompt
        std::cin >> num;  // Read number
        sum += num;  // Add to sum
    } while (num != 0);  // Continue until 0 is entered
    
    std::cout << "Sum: " << sum << std::endl;  // Print total
    
    return 0;  // End program
}
```
**Expected Outcome** (assuming inputs 5, 3, 0):  
```
Enter a number (0 to stop): 5
Enter a number (0 to stop): 3
Enter a number (0 to stop): 0
Sum: 8
```

### Points to Remember for Interview Preparation
- Use curly braces `{}` for all control structures to avoid bugs like dangling `else` in interviews.  
- Be cautious with `switch`: forgetting `break` causes fall-through, a common interview trick question.  
- For loops are critical for array-based DSA problems; practice iterating forward and backward.  
- Avoid infinite loops in `while`/`do-while` by ensuring the condition will eventually be false.  
- In interviews, explain your choice of control structure (e.g., `for` vs `while` based on iteration count).  
- Handle edge cases (e.g., negative inputs, zero, or invalid data) to make code robust.  
- Use meaningful variable names (e.g., `score` instead of `x`) for readability in whiteboard coding.  
- Know how to nest conditionals and loops for complex problems (e.g., matrix traversal).  
- Practice debugging control flow errors (e.g., off-by-one in loops) as they’re common in interviews.  
- Combine these with Hour 1 concepts (e.g., use variables in loops) for a strong foundation.

