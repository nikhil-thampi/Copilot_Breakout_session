class Contact:
    def __init__(self, name, address, email, phone_number):
        self.name = name
        self.address = address
        self.email = email
        self.phone_number = phone_number


phonebook = []


def add_contact(name, address, email, phone_number):
    phonebook.append(Contact(name, address, email, phone_number))


def update_contact(name, new_name, new_address, new_email, new_phone_number):
    for contact in phonebook:
        if contact.name == name:
            contact.name = new_name
            contact.address = new_address
            contact.email = new_email
            contact.phone_number = new_phone_number
            return
    print("Contact not found")


def remove_contact(name):
    global phonebook
    phonebook = [contact for contact in phonebook if contact.name != name]


def search_contact(name):
    for contact in phonebook:
        if contact.name == name:
            print(
                f"Name: {contact.name}, Address: {contact.address}, Email: {contact.email}, Phone Number: {contact.phone_number}"
            )
            return
    print("Contact not found")


def main():
    add_contact("John Doe", "123 Main St", "johndoe@example.com", "123-456-7890")
    add_contact("Jane Doe", "456 Elm St", "janedoe@example.com", "098-765-4321")

    search_contact("John Doe")
    update_contact(
        "John Doe", "John Doe", "456 Main St", "johndoe@example.com", "123-456-7890"
    )
    search_contact("John Doe")


if __name__ == "__main__":
    main()
