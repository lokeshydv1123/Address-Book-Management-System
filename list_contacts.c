#include "contact.h"

void list_contacts(AddressBook *addressbook)
{
    int i;

    // Check if there are any contacts in the address book before attempting to display them
    if(addressbook->contact_count == 0){
        printf("\nNo Contacts Available, Please Add First\n");
        return;
    }

    // Display the header for the contact list
    printf("\n==================================\n");
    printf("          CONTACT LIST\n");
    printf("==================================\n");

    // Loop through the contacts and display their details
    for(i = 0; i < addressbook->contact_count; i++){
        printf("\nContact %d\n", i + 1);
        printf("---------------------------------\n");
        printf("Name          : %s\n",addressbook->contact_details[i].Name);
        printf("Mobile Number : %s\n",addressbook->contact_details[i].Mobile_number);
        printf("Email ID      : %s\n",addressbook->contact_details[i].Mail_ID);
        printf("---------------------------------\n");
    }
}