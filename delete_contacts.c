#include "contact.h"

void delete_contact(AddressBook *addressbook)
{
    int index;
    char choice;

    // Loop to allow the user to delete multiple contacts
    do
    {
        index = select_contact(addressbook);
        if(index == -1)
            return;

        printf("\nSelected Contact\n");
        display_contact(addressbook, index);

        printf("\nDo You Want To Delete This Contact ? (Y/N) : ");
        scanf(" %c", &choice);

        // If the user confirms deletion, shift the contacts in the array to remove the selected contact
        if(choice == 'Y' || choice == 'y'){
            for(int i = index; i < addressbook->contact_count - 1; i++)
                addressbook->contact_details[i] = addressbook->contact_details[i + 1];
            
            addressbook->contact_count--;
            printf("\nContact Deleted Successfully\n");
        }
        // If the user cancels deletion, display a cancellation message
        else
            printf("\nDeletion Cancelled\n");

        // Ask the user if they want to delete another contact
        do
        {
            printf("\nDo You Want To Delete Another Contact ? (Y/N) : ");
            scanf(" %c", &choice);

            if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                printf("Invalid Choice\n");

        } while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    } while(choice == 'Y' || choice == 'y');
}