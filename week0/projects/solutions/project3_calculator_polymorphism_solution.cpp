#include <iostream>  // For input/output operations
#include <string>    // For string handling
#include <vector>    // For operation history

// Abstract base class for numbers
class Number {
protected:
    std::string type;  // Type identifier
public:
    Number(std::string t) : type(t) {}
    virtual Number* add(const Number* other) const = 0;  // Pure virtual add
    virtual Number* multiply(const Number* other) const = 0;  // Pure virtual multiply
    virtual void display() const = 0;  // Pure virtual display
    virtual ~Number() {}
    std::string getType() const { return type; }
};

// Integer class
class Integer : public Number {
private:
    int value;
public:
    Integer(int v) : Number("Integer"), value(v) {}
    Number* add(const Number* other) const override {
        if (other->getType() == "Integer") {
            return new Integer(value + dynamic_cast<const Integer*>(other)->value);
        }
        return nullptr;
    }
    Number* multiply(const Number* other) const override {
        if (other->getType() == "Integer") {
            return new Integer(value * dynamic_cast<const Integer*>(other)->value);
        }
        return nullptr;
    }
    void display() const override {
        std::cout << value;
    }
    int getValue() const { return value; }
};

// Decimal class
class Decimal : public Number {
private:
    double value;
public:
    Decimal(double v) : Number("Decimal"), value(v) {}
    Number* add(const Number* other) const override {
        if (other->getType() == "Decimal") {
            return new Decimal(value + dynamic_cast<const Decimal*>(other)->value);
        }
        return nullptr;
    }
    Number* multiply(const Number* other) const override {
        if (other->getType() == "Decimal") {
            return new Decimal(value * dynamic_cast<const Decimal*>(other)->value);
        }
        return nullptr;
    }
    void display() const override {
        std::cout << value;
    }
};

// Complex number class
class Complex : public Number {
private:
    double real, imag;
public:
    Complex(double r, double i) : Number("Complex"), real(r), imag(i) {}
    Number* add(const Number* other) const override {
        if (other->getType() == "Complex") {
            auto c = dynamic_cast<const Complex*>(other);
            return new Complex(real + c->real, imag + c->imag);
        }
        return nullptr;
    }
    Number* multiply(const Number* other) const override {
        if (other->getType() == "Complex") {
            auto c = dynamic_cast<const Complex*>(other);
            return new Complex(real * c->real - imag * c->imag, real * c->imag + imag * c->real);
        }
        return nullptr;
    }
    void display() const override {
        std::cout << real << " + " << imag << "i";
    }
};

// Recursive factorial for integers
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Calculator class to manage operations
class Calculator {
private:
    std::vector<Number*> history;  // Dynamic history storage
public:
    Calculator() {}
    ~Calculator() {
        for (auto h : history) delete h;
    }
    
    // Overloaded parseInput for different types
    Number* parseInput(int value) { return new Integer(value); }
    Number* parseInput(double value) { return new Decimal(value); }
    Number* parseInput(double real, double imag) { return new Complex(real, imag); }
    
    void performOperation(Number* a, Number* b, char op) {
        Number* result = nullptr;
        if (op == '+') result = a->add(b);
        else if (op == '*') result = a->multiply(b);
        if (result) {
            std::cout << "Result: ";
            result->display();
            std::cout << "\n";
            history.push_back(result);
        } else {
            std::cout << "Incompatible types\n";
        }
    }
    
    void displayHistory() const {
        if (history.empty()) {
            std::cout << "No operations performed\n";
            return;
        }
        for (size_t i = 0; i < history.size(); i++) {
            std::cout << "Operation " << i + 1 << ": ";
            history[i]->display();
            std::cout << "\n";
        }
    }
};

// Menu-driven interface
void menu(Calculator& calc) {
    while (true) {
        std::cout << "\n1. Integer Operation\n2. Decimal Operation\n3. Complex Operation\n"
                  << "4. Factorial (Integer)\n5. Display History\n6. Exit\nOption: ";
        int choice;
        std::cin >> choice;
        
        if (choice == 6) break;
        
        if (choice == 1) {
            int a, b;
            char op;
            std::cout << "Enter two integers and operator (+ or *): ";
            std::cin >> a >> b >> op;
            Number* n1 = calc.parseInput(a);
            Number* n2 = calc.parseInput(b);
            calc.performOperation(n1, n2, op);
            delete n1; delete n2;
        }
        else if (choice == 2) {
            double a, b;
            char op;
            std::cout << "Enter two decimals and operator (+ or *): ";
            std::cin >> a >> b >> op;
            Number* n1 = calc.parseInput(a);
            Number* n2 = calc.parseInput(b);
            calc.performOperation(n1, n2, op);
            delete n1; delete n2;
        }
        else if (choice == 3) {
            double r1, i1, r2, i2;
            char op;
            std::cout << "Enter two complex numbers (real imag real imag) and operator (+ or *): ";
            std::cin >> r1 >> i1 >> r2 >> i2 >> op;
            Number* n1 = calc.parseInput(r1, i1);
            Number* n2 = calc.parseInput(r2, i2);
            calc.performOperation(n1, n2, op);
            delete n1; delete n2;
        }
        else if (choice == 4) {
            int n;
            std::cout << "Enter integer for factorial: ";
            std::cin >> n;
            if (n >= 0) std::cout << "Factorial: " << factorial(n) << "\n";
            else std::cout << "Invalid input\n";
        }
        else if (choice == 5) {
            calc.displayHistory();
        }
        else {
            std::cout << "Invalid option\n";
        }
    }
}

int main() {
    Calculator calc;
    menu(calc);
    return 0;
}