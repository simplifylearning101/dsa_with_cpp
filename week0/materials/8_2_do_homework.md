# C++ Refresher for DSA Cohort: Hour 8 - Homework

Practice these 20 problems to reinforce inheritance, polymorphism, function overloading, and operator overloading. These problems are more complex to prepare for advanced DSA and coding interviews.

1. **Problem**: Create a base class `Shape` and derived class `Triangle` with area calculation.  
   **Outcome**: Print triangle area.  
   **Example**: Base 3, Height 4 → 6

2. **Problem**: Write a class `Employee` and derived class `Manager` with a bonus attribute.  
   **Outcome**: Print manager details with bonus.  
   **Example**: Name "Alice", Salary 5000, Bonus 1000 → Alice, 5000, 1000

3. **Problem**: Create a function `printArea` overloaded for `Circle` and `Rectangle`.  
   **Outcome**: Print areas.  
   **Example**: Circle radius 2, Rectangle 3x4 → 12.5664, 12

4. **Problem**: Overload `+` operator for a `Vector` class (x, y coordinates).  
   **Outcome**: Print sum of vectors.  
   **Example**: (1, 2) + (3, 4) → (4, 6)

5. **Problem**: Implement a base class `Animal` and derived classes `Dog` and `Cat` with virtual `speak`.  
   **Outcome**: Print animal sounds polymorphically.  
   **Example**: Dog "Rex", Cat "Whiskers" → Rex barks, Whiskers meows

6. **Problem**: Create a class `Matrix` with overloaded `==` operator to compare 2x2 matrices.  
   **Outcome**: Print if equal.  
   **Example**: [[1, 2], [3, 4]] == [[1, 2], [3, 4]] → Yes

7. **Problem**: Write a base class `Vehicle` and derived class `Bike` with overridden `describe`.  
   **Outcome**: Print bike details.  
   **Example**: Brand "Yamaha", Wheels 2 → Yamaha, 2 wheels

8. **Problem**: Overload `multiply` function for scalar and vector multiplication of a `Point`.  
   **Outcome**: Print result.  
   **Example**: Point (2, 3) * 2 → (4, 6)

9. **Problem**: Create an abstract base class `Drawable` and derived `Square` with virtual `draw`.  
   **Outcome**: Print square drawing simulation.  
   **Example**: Side 4 → Square drawn with side 4

10. **Problem**: Implement multiple inheritance for a `FlyingCar` from `Car` and `Airplane`.  
    **Outcome**: Print combined features.  
    **Example**: Brand "Future", Speed 200 → Future, 200 mph

11. **Problem**: Overload `<<` operator for a `Time` class (hours, minutes).  
    **Outcome**: Print time in format.  
    **Example**: 14, 30 → 14:30

12. **Problem**: Create a base class `Person` and derived `Student` with overridden `introduce`.  
    **Outcome**: Print student details.  
    **Example**: Name "Bob", ID 101 → Bob, Student ID: 101

13. **Problem**: Write a function `scale` overloaded for `int` and `double` scaling of a `Box`.  
    **Outcome**: Print scaled dimensions.  
    **Example**: Box (2, 3, 4) scaled by 2 → (4, 6, 8)

14. **Problem**: Overload `*` operator for matrix-vector multiplication in a `Matrix` class.  
    **Outcome**: Print result vector.  
    **Example**: [[1, 2], [3, 4]] * [1, 1] → [3, 7]

15. **Problem**: Create a base class `Container` and derived `Stack` with virtual `push`.  
    **Outcome**: Print stack after push.  
    **Example**: Push 1, 2 → [1, 2]

16. **Problem**: Implement hierarchical inheritance with `Shape`, `Circle`, and `Square`.  
    **Outcome**: Print areas polymorphically.  
    **Example**: Circle radius 3, Square side 4 → 28.2743, 16

17. **Problem**: Overload `+=` operator for a `Counter` class.  
    **Outcome**: Print counter after increment.  
    **Example**: Counter 5 += 3 → 8

18. **Problem**: Create a base class `Media` and derived `Book` and `Movie` with virtual `play`.  
    **Outcome**: Print media-specific actions.  
    **Example**: Book "1984", Movie "Inception" → Read 1984, Watch Inception

19. **Problem**: Overload `>` operator for a `Fraction` class.  
    **Outcome**: Print if one fraction is larger.  
    **Example**: 3/4 > 1/2 → Yes

20. **Problem**: Implement a `TreeNode` class with inheritance for `BinaryNode` and virtual traversal.  
    **Outcome**: Print inorder traversal.  
    **Example**: Node values 1, 2, 3 → 2, 1, 3