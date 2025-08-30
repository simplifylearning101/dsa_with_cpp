#include <iostream>  // For input/output operations
#include <string>    // For string handling

// Base class for a person
class Person {
protected:
    std::string name;  // Name of the person
    int id;            // Unique ID
public:
    Person(std::string n, int i) : name(n), id(i) {
        std::cout << "Person " << id << " created\n";
    }
    virtual ~Person() {
        std::cout << "Person " << id << " destroyed\n";
    }
    virtual void display() const {
        std::cout << "Name: " << name << ", ID: " << id << "\n";
    }
    int getId() const { return id; }
};

// Derived class for a student
class Student : public Person {
private:
    int* grades;       // Dynamic array of grades
    int count;         // Number of grades
    int capacity;      // Capacity of grades array
public:
    // Constructor
    Student(std::string n, int i, int cap = 10) 
        : Person(n, i), count(0), capacity(cap) {
        grades = new int[capacity];
        std::cout << "Student " << id << " created\n";
    }
    
    // Destructor
    ~Student() {
        delete[] grades;
        std::cout << "Student " << id << " destroyed\n";
    }
    
    // Add a single grade (overloaded)
    void addGrade(int grade) {
        if (grade < 0 || grade > 100) {
            std::cout << "Invalid grade\n";
            return;
        }
        if (count >= capacity) {
            std::cout << "Grade array full\n";
            return;
        }
        grades[count++] = grade;
        std::cout << "Grade added\n";
    }
    
    // Add multiple grades (overloaded)
    void addGrade(int* newGrades, int size) {
        for (int i = 0; i < size && count < capacity; i++) {
            if (newGrades[i] >= 0 && newGrades[i] <= 100) {
                grades[count++] = newGrades[i];
            }
        }
        std::cout << "Grades added\n";
    }
    
    // Overload + to combine grades
    Student operator+(const Student& other) const {
        Student result(name + "_combined", id + other.id, capacity + other.capacity);
        result.addGrade(grades, count);
        result.addGrade(other.grades, other.count);
        return result;
    }
    
    // Recursive function to find highest grade
    int highestGrade(int index) const {
        if (index == count - 1) return grades[index];
        return std::max(grades[index], highestGrade(index + 1));
    }
    
    // Compute average grade
    double average() const {
        if (count == 0) return 0.0;
        double sum = 0;
        for (int i = 0; i < count; i++) sum += grades[i];
        return sum / count;
    }
    
    // Override display
    void display() const override {
        Person::display();
        std::cout << "Grades: ";
        for (int i = 0; i < count; i++) std::cout << grades[i] << " ";
        std::cout << "\nAverage: " << average();
        if (count > 0) std::cout << ", Highest: " << highestGrade(0);
        std::cout << "\n";
    }
};

// Menu-driven interface
void menu(Student** students, int& count, int capacity) {
    while (true) {
        std::cout << "\n1. Add Student\n2. Add Grade\n3. Combine Students\n"
                  << "4. Display All\n5. Exit\nOption: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        
        if (choice == 5) break;
        
        if (choice == 1) {
            if (count >= capacity) {
                std::cout << "Student array full\n";
                continue;
            }
            std::string name;
            int id;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter ID: ";
            std::cin >> id;
            students[count++] = new Student(name, id);
        }
        else if (choice == 2) {
            int id, grade;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter grade: ";
            std::cin >> grade;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == id) {
                    students[i]->addGrade(grade);
                    break;
                }
            }
        }
        else if (choice == 3) {
            int id1, id2;
            std::cout << "Enter two student IDs: ";
            std::cin >> id1 >> id2;
            Student *s1 = nullptr, *s2 = nullptr;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == id1) s1 = students[i];
                if (students[i]->getId() == id2) s2 = students[i];
            }
            if (s1 && s2 && count < capacity) {
                students[count++] = new Student(*s1 + *s2);
                std::cout << "Students combined\n";
            }
            else {
                std::cout << "Invalid IDs or array full\n";
            }
        }
        else if (choice == 4) {
            for (int i = 0; i < count; i++) students[i]->display();
        }
        else {
            std::cout << "Invalid option\n";
        }
    }
}

int main() {
    const int capacity = 50;
    Student* students[capacity];
    int count = 0;
    menu(students, count, capacity);
    for (int i = 0; i < count; i++) delete students[i];
    return 0;
}