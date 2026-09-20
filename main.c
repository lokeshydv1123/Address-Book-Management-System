/*
Name : Lokesh Yadav
Date : 16/06/2024
Project Name: Address Book 
Description : This project is a simple address book application that allows users to manage their contacts.
It provides functionalities to add, search, edit, delete, and display contacts. 
1. Create Contacts : In this file we can create a new contact by providing the valid name, valid mobile number, and valid email ID. The contact is then added to the address book.
2. Search Contacts : In this file we can search for a contact by providing the name, mobile number, or email ID. The matching contacts are displayed to the user.
3. Edit Contacts : In this file we can edit the details of an existing contact. The user can choose to edit the name, mobile number, email ID, or all fields of the contact.
4. Delete Contacts : In this file we can delete a contact from the address book by providing the name, mobile number, or email ID. The contact is removed from the address book.
5. Display Contacts : In this file we can display all the contacts stored in the address book. The contacts are displayed in a tabular format with their details.
6. Save Contacts : In this file we can save the contacts to a file for persistent storage. The contacts are saved in a structured format that can be loaded later.
*/

#include "contact.h"

int main()
{
    int option;

    AddressBook addressbook;

    addressbook.contact_count = 0;

    /* Load contacts from file at startup */

    load_contacts(&addressbook);

    // Main loop to display the menu and handle user input
    while(1)
    {
        printf("\n=================================\n");
        printf("         ADDRESS BOOK\n");
        printf("=================================\n");

        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Save Contacts\n");
        printf("7. Save & Exit\n");
        printf("8. Exit\n");

        printf("\nEnter the option : ");
        scanf("%d", &option);

        // Handle the user's choice
        switch(option)
        {
            case 1:
                create_contact(&addressbook); // calling the function to create a new contact
                break;
            case 2:
                search_contacts(&addressbook); // calling the function to search for a contact
                break;
            case 3:
                edit_contact(&addressbook); // calling the function to edit a contact
                break;
            case 4:
                delete_contact(&addressbook); // calling the function to delete a contact
                break;
            case 5:
                list_contacts(&addressbook); // calling the function to display all contacts
                break;

            case 6: // calling the function to save contacts to a file
                save_contacts(&addressbook);
                break;
            
            case 7:
                save_contacts(&addressbook); // calling the function to save contacts to a file

                // Simulate a loading effect while saving contacts
                printf("\nSaving Contacts");

                for(int i = 0; i < 5; i++){
                    printf(".");
                    fflush(stdout);
                }

                printf("\n");

                // Simulate an exiting effect while exiting the program
                for(int i = 0; i <= 100; i += 20){
                    printf("\rExiting... %d%%", i);
                    fflush(stdout);
                }
                printf("\n");
                return 0;
            
            case 8: // Simulate an exiting effect while exiting the program
                for(int i = 0; i <= 100; i += 20){
                    printf("\rProgram Terminated, Exiting... %d%%", i);
                    fflush(stdout);
                }
                printf("\n");
                return 0;
            
            default: //Handle invalid option input
                printf("\nInvalid Option\n");
        }
    }

    return 0;
}