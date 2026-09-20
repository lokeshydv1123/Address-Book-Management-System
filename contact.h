#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Structures for the Fields
typedef struct Contact_data
{
    char Name[50];
    char Mobile_number[11];
    char Mail_ID[50];

} Contacts;

// Structures foe the Contact deatils
typedef struct AddressBook_Data
{
    // Array of structures for the Fields sturucture
    Contacts contact_details[100];
    // To keep the track no of contact count
    int contact_count;
} AddressBook;

/* Function declarations */

void create_contact(AddressBook *);
void list_contacts(AddressBook *);
void search_contacts(AddressBook *);
void edit_contact(AddressBook *);
void delete_contact(AddressBook *);
void save_contacts(AddressBook *);
int validate_name(AddressBook *, char []);
int validate_mobile(AddressBook *, char []);
int validate_email(AddressBook *, char []);
void search_by_name(AddressBook *);
void search_by_mobile(AddressBook *);
void search_by_email(AddressBook *);
void display_contact(AddressBook *, int);
void save_contacts(AddressBook *);
void load_contacts(AddressBook *);
int select_contact(AddressBook *addressbook);
void to_lower(char str[]);


#endif
// CONTACT_H
// CONTACT_H