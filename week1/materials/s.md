```cpp
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

class PhonebookManager {
private:
    std::map<std::string, std::string> contacts; // Name -> Phone number

public:
    // Add a contact
    void addContact(const std::string& name, const std::string& phone) {
        if (contacts.find(name) != contacts.end()) {
            std::cout << "Contact '" << name << "' already exists.\n";
        } else {
            contacts[name] = phone;
            std::cout << "Added contact: " << name << ", " << phone << "\n";
        }
    }

    // Delete a contact by name
    void deleteContact(const std::string& name) {
        if (contacts.erase(name)) {
            std::cout << "Deleted contact: " << name << "\n";
        } else {
            std::cout << "Contact '" << name << "' not found.\n";
        }
    }

    // Update a contact's phone number
    void updateContact(const std::string& name, const std::string& phone) {
        if (contacts.find(name) != contacts.end()) {
            contacts[name] = phone;
            std::cout << "Updated contact: " << name << ", " << phone << "\n";
        } else {
            std::cout << "Contact '" << name << "' not found.\n";
        }
    }

    // Search contacts by partial name match
    std::vector<std::string> searchContact(const std::string& query) {
        std::vector<std::string> results;
        std::string queryLower = query;
        std::transform(queryLower.begin(), queryLower.end(), queryLower.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        std::for_each(contacts.begin(), contacts.end(), [&](const auto& pair) {
            std::string nameLower = pair.first;
            std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (nameLower.find(queryLower) != std::string::npos) {
                results.push_back(pair.first + ": " + pair.second);
            }
        });
        return results;
    }

    // List all contacts
    void listContacts() {
        if (contacts.empty()) {
            std::cout << "Phonebook is empty.\n";
            return;
        }
        std::cout << "All contacts:\n";
        std::for_each(contacts.begin(), contacts.end(),
                      [](const auto& pair) {
                          std::cout << pair.first << ": " << pair.second << "\n";
                      });
    }
};

int main() {
    PhonebookManager phonebook;
    std::string command, name, phone;

    while (true) {
        std::cout << "\nPhonebook Manager\n";
        std::cout << "1. Add contact\n2. Delete contact\n3. Update contact\n";
        std::cout << "4. Search contact\n5. List all contacts\n6. Exit\n";
        std::cout << "Enter command (1-6): ";
        std::cin >> command;

        if (command == "6") break;

        if (command == "1") {
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phone);
            phonebook.addContact(name, phone);
        }
        else if (command == "2") {
            std::cout << "Enter name to delete: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            phonebook.deleteContact(name);
        }
        else if (command == "3") {
            std::cout << "Enter name to update: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter new phone number: ";
            std::getline(std::cin, phone);
            phonebook.updateContact(name, phone);
        }
        else if (command == "4") {
            std::cout << "Enter name to search: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            auto results = phonebook.searchContact(name);
            if (results.empty()) {
                std::cout << "No contacts found.\n";
            } else {
                std::cout << "Search results:\n";
                for (const auto& result : results) {
                    std::cout << result << "\n";
                }
            }
        }
        else if (command == "5") {
            phonebook.listContacts();
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }
    return 0;
}
```