#include <iostream>  // For input/output operations
#include <string>    // For string handling

// Base class for perishable items
class Perishable {
protected:
    int expirationDays;  // Days until expiration
public:
    Perishable(int days) : expirationDays(days) {}
    virtual void display() const {
        std::cout << "Expires in " << expirationDays << " days";
    }
    virtual ~Perishable() {}
};

// Base class for electronic items
class Electronic {
protected:
    int warrantyMonths;  // Warranty period in months
public:
    Electronic(int months) : warrantyMonths(months) {}
    virtual void display() const {
        std::cout << "Warranty: " << warrantyMonths << " months";
    }
    virtual ~Electronic() {}
};

// Derived class with multiple inheritance
class Item : public Perishable, public Electronic {
private:
    std::string name;  // Item name
    int id;            // Unique ID
    double price;      // Price
public:
    Item(std::string n, int i, double p, int days, int months) 
        : Perishable(days), Electronic(months), name(n), id(i), price(p) {
        std::cout << "Item " << id << " created\n";
    }
    ~Item() {
        std::cout << "Item " << id << " destroyed\n";
    }
    
    // Override display to show all details
    void display() const override {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", ";
        Perishable::display();
        std::cout << ", ";
        Electronic::display();
        std::cout << "\n";
    }
    
    // Overload == for comparison by ID
    bool operator==(const Item& other) const {
        return id == other.id;
    }
    
    int getId() const { return id; }
    double getPrice() const { return price; }
};

// Inventory class to manage items
class Inventory {
private:
    Item** items;      // Dynamic array of item pointers
    int capacity;      // Total capacity
    int count;         // Current number of items
public:
    Inventory(int cap = 50) : capacity(cap), count(0) {
        items = new Item*[capacity];
        for (int i = 0; i < capacity; i++) items[i] = nullptr;
    }
    ~Inventory() {
        for (int i = 0; i < count; i++) delete items[i];
        delete[] items;
    }
    
    // Add single item (overloaded)
    void addItem(std::string name, int id, double price, int days, int months) {
        if (count >= capacity) {
            std::cout << "Inventory full\n";
            return;
        }
        items[count++] = new Item(name, id, price, days, months);
    }
    
    // Add multiple items (overloaded)
    void addItem(std::string* names, int* ids, double* prices, int* days, int* months, int size) {
        for (int i = 0; i < size && count < capacity; i++) {
            items[count++] = new Item(names[i], ids[i], prices[i], days[i], months[i]);
        }
    }
    
    // Remove item by ID
    void removeItem(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getId() == id) {
                delete items[i];
                items[i] = items[count - 1];
                items[count - 1] = nullptr;
                count--;
                std::cout << "Item removed\n";
                return;
            }
        }
        std::cout << "Item not found\n";
    }
    
    // Compare two items by ID
    void compare(int id1, int id2) const {
        Item *i1 = nullptr, *i2 = nullptr;
        for (int i = 0; i < count; i++) {
            if (items[i]->getId() == id1) i1 = items[i];
            if (items[i]->getId() == id2) i2 = items[i];
        }
        if (i1 && i2) {
            std::cout << (*i1 == *i2 ? "Items are equal" : "Items are not equal") << "\n";
        } else {
            std::cout << "One or both items not found\n";
        }
    }
    
    // Recursive total value calculation
    double totalValue(int index) const {
        if (index >= count) return 0;
        return items[index]->getPrice() + totalValue(index + 1);
    }
    
    void displayAll() const {
        if (count == 0) {
            std::cout << "Inventory empty\n";
            return;
        }
        for (int i = 0; i < count; i++) items[i]->display();
    }
};

// Menu-driven interface
void menu(Inventory& inv) {
    while (true) {
        std::cout << "\n1. Add Item\n2. Remove Item\n3. Compare Items\n"
                  << "4. Display All\n5. Total Value\n6. Exit\nOption: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        
        if (choice == 6) break;
        
        if (choice == 1) {
            std::string name;
            int id, days, months;
            double price;
            std::cout << "Enter name, ID, price, expiration days, warranty months: ";
            std::getline(std::cin, name);
            std::cin >> id >> price >> days >> months;
            inv.addItem(name, id, price, days, months);
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;
            inv.removeItem(id);
        }
        else if (choice == 3) {
            int id1, id2;
            std::cout << "Enter two IDs: ";
            std::cin >> id1 >> id2;
            inv.compare(id1, id2);
        }
        else if (choice == 4) {
            inv.displayAll();
        }
        else if (choice == 5) {
            std::cout << "Total Value: $" << inv.totalValue(0) << "\n";
        }
        else {
            std::cout << "Invalid option\n";
        }
    }
}

int main() {
    Inventory inv;
    menu(inv);
    return 0;
}