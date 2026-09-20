#include "contact.h"

// Function to save the contacts from the address book to a file
void save_contacts(AddressBook *addressbook)
{
    FILE *fp;

    // Open the file in write mode
    fp = fopen("contacts.txt", "w");

    // If the file cannot be opened, display an error message and return
    if(fp == NULL){
        printf("Unable to Open File\n");
        return;
    }

    // Write the total number of contacts to the file as the first line
    fprintf(fp,"#%d\n",addressbook->contact_count);

    // Write the contact details to the file
    for(int i = 0; i < addressbook->contact_count; i++){
        fprintf(fp,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,
                addressbook->contact_details[i].Mail_ID);
    }

    // Close the file after writing
    fclose(fp);

    printf("\nContacts Saved Successfully\n");
}

// Function to load contacts from the file into the address book
void load_contacts(AddressBook *addressbook)
{
    FILE *fp;

    fp = fopen("contacts.txt", "r");

    // Check whether the file is present or not
    if(fp == NULL){
        printf("File Not Found\n");
        return;
    }

    int total_contacts;

    // Printing the total number of contacts with #
    fscanf(fp, "#%d\n", &total_contacts);

    // Showing message that no data is available in the address book
    if(total_contacts == 0){
        printf("No Data Available In The Address Book\n");
        fclose(fp);
        return;
    }

    addressbook->contact_count = 0;

    // To scanf contacts from the file
    for(int i = 0; i < total_contacts; i++)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressbook->contact_details[i].Name,
            addressbook->contact_details[i].Mobile_number,
            addressbook->contact_details[i].Mail_ID);

        addressbook->contact_count++;
    }

    // Close the file after writing
    fclose(fp);

}