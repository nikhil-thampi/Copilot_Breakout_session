#include <iostream>
#include <vector>
#include <algorithm>

struct Contact {
    std::string name;
    std::string address;
    std::string email;
    std::string phoneNumber;
};

std::vector<Contact> phonebook;

void addContact(const std::string& name, const std::string& address, const std::string& email, const std::string& phoneNumber) {
    phonebook.push_back({name, address, email, phoneNumber});
}

void updateContact(const std::string& name, const std::string& newName, const std::string& newAddress, const std::string& newEmail, const std::string& newPhoneNumber) {
    auto it = std::find_if(phonebook.begin(), phonebook.end(),
        [&name](const Contact& c) { return c.name == name; });

    if (it != phonebook.end()) {
        it->name = newName;
        it->address = newAddress;
        it->email = newEmail;
        it->phoneNumber = newPhoneNumber;
    } else {
        std::cout << "Contact not found" << std::endl;
    }
}

void removeContact(const std::string& name) {
    phonebook.erase(std::remove_if(phonebook.begin(), phonebook.end(),
        [&name](const Contact& c) { return c.name == name; }), phonebook.end());
}

void searchContact(const std::string& name) {
    auto it = std::find_if(phonebook.begin(), phonebook.end(),
        [&name](const Contact& c) { return c.name == name; });

    if (it != phonebook.end()) {
        std::cout << "Name: " << it->name << ", Address: " << it->address << ", Email: " << it->email << ", Phone Number: " << it->phoneNumber << std::endl;
    } else {
        std::cout << "Contact not found" << std::endl;
    }
}

int main() {
    addContact("John Doe", "123 Main St", "johndoe@example.com", "123-456-7890");
    addContact("Jane Doe", "456 Elm St", "janedoe@example.com", "098-765-4321");

    searchContact("John Doe");
    updateContact("John Doe", "John Doe", "456 Main St", "johndoe@example.com", "123-456-7890");
    searchContact("John Doe");

    return 0;
}
