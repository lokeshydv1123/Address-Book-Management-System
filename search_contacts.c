#include "contact.h"

void search_contacts(AddressBook *addressbook)
{
    int option;
    char choice;

    // Loop to allow the user to search for multiple contacts
    do
    {
        printf("\nSearch Contact Menu\n");
        printf("1. Search by Name\n");
        printf("2. Search by Mobile Number\n");
        printf("3. Search by Email ID\n");
        printf("4. Exit\n");

        printf("\nEnter the option : ");
        scanf("%d", &option);

        // Switch statement to handle the user's choice for searching contacts
        switch(option)
        {
            case 1:
                search_by_name(addressbook);
                break;

            case 2:
                search_by_mobile(addressbook);
                break;

            case 3:
                search_by_email(addressbook);
                break;

            case 4:
                return;

            default:
                printf("Invalid Option\n");
        }

        // Prompt the user to search for another contact or exit the search menu
        do{
            printf("\nDo You Want To Search Another Contact ? (Y/N) : ");
            scanf(" %c", &choice);
            if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                printf("Invalid Choice\n");
        } while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    } while(choice == 'Y' || choice == 'y');
}

// Function to search contacts by name
void search_by_name(AddressBook *addressbook)
{
    char name[50];
    int found = 0;

    printf("Enter the Name : ");
    scanf(" %[^\n]", name);

    printf("\nMatching Contacts\n");

    // Loop through the contacts in the address book to find matches based on the search criteria
    for(int i = 0; i < addressbook->contact_count; i++){
        if(strstr(addressbook->contact_details[i].Name, name) != NULL){
            display_contact(addressbook, i);
            found = 1;
        }
    }

    // If no contacts match the search criteria, inform the user
    if(!found)
        printf("\nContact Not Found\n");
}

// Function to search contacts by mobile number
void search_by_mobile(AddressBook *addressbook)
{
    char mobile[11];
    int found = 0;

    printf("Enter the Mobile Number : ");
    scanf("%s", mobile);

    printf("\nMatching Contacts\n");

    // Loop through the contacts in the address book to find matches based on the search criteria
    for(int i = 0; i < addressbook->contact_count; i++){
        if(strstr(addressbook->contact_details[i].Mobile_number, mobile) != NULL){
            display_contact(addressbook, i);
            found = 1;
        }
    }

    // If no contacts match the search criteria, inform the user
    if(!found)
        printf("\nContact Not Found\n");
}

// Function to search contacts by email ID
void search_by_email(AddressBook *addressbook)
{
    char email[20];
    int found = 0;

    printf("Enter Email ID : ");
    scanf("%s", email);

    printf("\nMatching Contacts\n");

    // Loop through the contacts in the address book to find matches based on the search criteria
    for(int i = 0; i < addressbook->contact_count; i++){
        if(strstr(addressbook->contact_details[i].Mail_ID, email) != NULL){
            display_contact(addressbook, i);
            found = 1;
        }
    }

    // If no contacts match the search criteria, inform the user
    if(!found)
        printf("\nContact Not Found\n");
}

// Function to display a contact's details
void display_contact(AddressBook *addressbook, int index)
{
    printf("\n----------------------------------\n");
    printf("Name          : %s\n", addressbook->contact_details[index].Name);
    printf("Mobile Number : %s\n", addressbook->contact_details[index].Mobile_number);
    printf("Email ID      : %s\n", addressbook->contact_details[index].Mail_ID);
    printf("----------------------------------\n");
}
