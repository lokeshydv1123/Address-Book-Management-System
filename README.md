# Address Book

A command-line Address Book application developed in C for managing contact information.

The application supports creating, displaying, searching, updating, deleting, validating, and persistently storing contacts using structures and file handling.

## Features

* Create new contacts
* Display all contacts
* Search contacts
* Update existing contacts
* Delete contacts
* Input validation
* Persistent contact storage using files
* Partial contact search using substring matching
* Menu-driven command-line interface
* Modular C implementation

## Contact Information

Each contact contains:

* Name
* Mobile number
* Email address

A `struct` is used to group these related fields into a single contact record.

## Data Structure

The project uses an array of structures to maintain contacts in memory.

The basic design consists of two structures:

```c
typedef struct
{
    char name[50];
    char mobile[20];
    char email[80];
} Contacts;
```

The `AddressBook` structure maintains the collection of contacts and the current contact count.

This approach keeps related contact information together and makes operations such as search, update, and deletion easier to manage.

## Operations

### Create Contact

The application accepts the contact details from the user, validates the input, and stores the new contact in the Address Book.

### Display Contacts

Displays all contacts currently stored in the Address Book.

### Search Contact

The application allows users to search for contacts using contact information.

Partial matching is supported using `strstr()`, allowing multiple matching contacts to be displayed.

If multiple contacts match the search, the user can select the required contact using its index for further operations.

### Update Contact

The user can select an existing contact and modify its information.

The updated information is validated before being stored.

### Delete Contact

The selected contact is removed from the Address Book.

When an element is deleted from the array, the subsequent elements are shifted one position to maintain a continuous collection.

### Save Contacts

Contact information is stored in a file so that the data is preserved after the program exits.

The application can load existing contact information and save updated data back to the file.

## Input Validation

The project validates the contact information before accepting it.

### Name Validation

The name is checked to ensure that invalid characters are not accepted.

### Mobile Number Validation

The mobile number is validated for the required format and length.

### Email Validation

The email address is checked for the expected email format and invalid characters.

Validation prevents incorrect data from being stored in the Address Book.

## File Handling

File handling is used to provide persistent storage.

The program reads stored contacts when required and writes updated contact information back to the file.

This allows contact data to remain available even after the program terminates.

## Project Flow

```text
Start
  ↓
Initialize Address Book
  ↓
Load Existing Contacts
  ↓
Display Menu
  ↓
User Selects Operation
  ↓
Validate Input
  ↓
Create / Display / Search / Update / Delete
  ↓
Save Updated Contacts
  ↓
Exit
```

## Project Structure

```text
Address-Book/
│
├── main.c
├── contact.h
├── contact.c
└── README.md
```

> The exact source file names may vary depending on the final project organization.

### File Description

| File        | Description                                      |
| ----------- | ------------------------------------------------ |
| `main.c`    | Contains the main program flow and menu handling |
| `contact.h` | Contains structures and function declarations    |
| `contact.c` | Contains contact management operations           |
| `README.md` | Project documentation                            |

## Concepts Used

* C Programming
* Structures
* Arrays of Structures
* Pointers
* Strings
* String Functions
* File Handling
* File I/O
* Input Validation
* Modular Programming
* Searching
* Array Manipulation

## Time Complexity

For an Address Book containing `n` contacts:

| Operation | Complexity |
| --------- | ---------: |
| Display   |       O(n) |
| Search    |       O(n) |
| Create    |       O(1) |
| Update    |       O(n) |
| Delete    |       O(n) |
| Save      |       O(n) |

Search requires checking the stored contacts, while deletion may require shifting subsequent elements in the array.

## Key Learning Outcomes

This project provided practical experience with:

* Designing structures for real-world data
* Managing collections using arrays of structures
* Working with strings and string functions
* Implementing CRUD operations
* Validating user input
* Reading and writing files
* Handling pointers and memory concepts
* Building a modular C application
* Managing edge cases in user input and contact operations

## Limitations

The current implementation uses a fixed-size array to store contacts.

For a larger-scale application, the storage mechanism could be improved using dynamic memory allocation or a linked-list based data structure.

## Future Improvements

Possible improvements include:

* Dynamic memory allocation
* Linked-list based contact storage
* Sorting contacts
* Multiple search filters
* Better file corruption handling
* Password protection
* Import/export functionality
* Database based persistent storage

## Author

**Lokesh Yadav**

B.Tech Computer Science and Engineering

## License

This project is intended for educational and learning purposes.
