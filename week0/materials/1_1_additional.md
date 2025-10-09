# Primitive Data Types in C++
Below is a clear and concise table summarizing the **primitive data types** in C++, their **significance**, **variants**, and the **data they can hold**.

## Table of Primitive Data Types in C++

| **Data Type** | **Significance** | **Variants** | **Data It Can Hold** | **Typical Size (Bytes)** |
|---------------|------------------|--------------|-----------------------|--------------------------|
| **int**       | Represents whole numbers, used for general-purpose integer arithmetic (e.g., counters, indices). | `short`, `int`, `long`, `long long` | Integer values (e.g., -5, 0, 42). Range depends on variant (e.g., `int` typically -2,147,483,648 to 2,147,483,647 on 32-bit systems). | `short`: 2<br>`int`: 4<br>`long`: 4 or 8<br>`long long`: 8 |
| **float**     | Represents single-precision floating-point numbers, used for approximate real numbers (e.g., scientific calculations). | `float` | Decimal numbers with moderate precision (e.g., 3.14, -0.001). Approx. 7 decimal digits. | 4 |
| **double**    | Represents double-precision floating-point numbers, used for higher precision in calculations (e.g., financial or scientific data). | `double`, `long double` | Decimal numbers with higher precision (e.g., 3.14159265359). `double`: ~15 decimal digits; `long double`: varies (often 10-12 bytes). | `double`: 8<br>`long double`: 10-16 |
| **char**      | Represents single characters or small integers, used for text processing or ASCII/Unicode storage. | `char`, `signed char`, `unsigned char` | Single characters (e.g., 'A', '@') or small integers (0 to 255 for `unsigned char`, -128 to 127 for `signed char`). | 1 |
| **bool**      | Represents logical values, used for conditional logic (e.g., loops, if-statements). | None | `true` or `false`. | 1 |
| **void**      | Indicates no value or type, used for functions that return nothing or generic pointers. | None | No data (used in function signatures like `void func()` or pointers like `void*`). | N/A |

## Notes on the Table

- **Sizes**: The size of data types (e.g., `int`, `long`) can vary depending on the system (32-bit vs. 64-bit) and compiler. The table lists typical sizes for modern systems (e.g., using GCC/Clang on 64-bit platforms). Use `sizeof(type)` in C++ to check the size on your system.
- **Variants**:
  - For integers (`int`): `short`, `long`, and `long long` modify the range and size. You can also add `signed` (default) or `unsigned` to allow only non-negative values (e.g., `unsigned int` holds 0 to 4,294,967,295).
  - For `char`: `signed char` and `unsigned char` explicitly define the sign, while plain `char` may be signed or unsigned depending on the compiler.
  - For `double`: `long double` offers extended precision but is platform-dependent.
- **Significance**: Each type is optimized for specific use cases. For example, use `int` for loop counters, `double` for precise calculations, `char` for text, and `bool` for flags.
- **Data Range**: The range depends on the size. For example, a 4-byte `int` has a range of approximately ±2 billion. Use `<limits>` (e.g., `std::numeric_limits<int>::max()`) to check exact ranges programmatically.
- **void**: Not a data-holding type but included as a primitive type for completeness, often used in function declarations or pointers.
---


### Additional Reading - What happens when you compile your C / C++ program.

The compilation process in C++ transforms human-readable source code into an executable program that a computer can run. 

This process typically involves four main stages: **preprocessing**, **compilation**, **assembly**, and **linking**. These stages are often handled by a compiler toolchain like GCC (GNU Compiler Collection) or Clang, which orchestrates them automatically when you run a command like `g++ main.cpp -o output`.

The process starts with your C++ source files (e.g., `.cpp`) and may include header files (`.h`). If there are multiple source files, each is processed independently through the first three stages, producing object files, which are then combined in the linking stage. Note that errors can occur at any stage (e.g., syntax errors during compilation), halting the process with diagnostic messages.

[main.cpp] --> [Preprocessor](Cleans & Expands) --> [main.i](Expanded Code) --> [Compiler](Translates) --> [main.s](Assembly Code) --> [Assembler](Converts) --> [main.o](Object File) --> [Linker](Combines) --> [main.exe](Executable)
                      

### 1. Preprocessing
This is the first stage, handled by the preprocessor (e.g., `cpp` in GCC). It prepares the source code by resolving directives and macros before actual compilation.

**Input**: Your C++ source code (main.cpp), e.g., a file with #include <iostream> and your program logic.
**What Happens**: The preprocessor acts like an editor who:

- Replaces #include with the contents of header files (e.g., adds iostream code).
- Expands macros (e.g., #define PI 3.14 becomes 3.14 everywhere).
- Removes comments and handles directives like #ifdef.

**Output**: A single, expanded text file (main.i) with all headers included and macros resolved.

e.g. 
```text
main.cpp:                       main.i:
#include <iostream>            [Contents of iostream]
#define MAX 100                int main() {
int main() {                     std::cout << 100;
  std::cout << MAX;            }
}
```

### Compilation: Translating to a Printer’s Language

Input: The preprocessed file (main.i).
What Happens: The compiler reads the expanded code and translates it into assembly language (a low-level code closer to what the computer understands). It:

Checks for errors (e.g., missing semicolons).
Converts C++ constructs (loops, functions) into instructions for the CPU.


Output: An assembly file (main.s) with CPU-specific instructions like mov or add.

e.g.
```text
main.s:
mov rax, 1         ; Example assembly instructions
call _ZSt4cout     ; Calls to output "100"
```

### 3. Assembly: Converting to Machine Code

Input: The assembly file (main.s).
What Happens: The assembler converts the assembly instructions into binary machine code that the computer’s CPU can directly execute. It:

Turns text instructions into 0s and 1s.
Prepares data like variables for memory.


Output: An object file (main.o), a binary file with machine code but not yet runnable.
e.g.
```text
main.o:
[Binary: 01001010 11001100 ...]
```

### 4. Linking: Binding the Book

Input: One or more object files (main.o, others if you have multiple .cpp files) and libraries.
What Happens: The linker combines all pieces:

Connects your code to library functions (e.g., std::cout from libstdc++).
Resolves references (e.g., where is cout defined?).
Arranges the code in memory so it can run.


Output: A final executable file (main.exe or a.out), ready to run on your computer.
e.g. 
```text
main.exe:
[Runnable program: Run it with ./main.exe]
```

### Key Points

***Errors***: If there’s a mistake (e.g., typo in code), the process stops at the stage where the error is found, showing a message (e.g., “missing semicolon”).
***Tools***: A compiler like g++ automates all steps with one command: g++ main.cpp -o main.
***Multiple Files***: If your program has multiple .cpp files, each goes through steps 1–3, then all .o files are linked in step 4.

