#include "contact.h"

void create_contact(AddressBook *addressbook)
{
    char name[20];
    char mobile[11];
    char email[20];
    char choice;

    // Loop to create multiple contacts
    do
    {
        printf("\n----- CREATE CONTACT -----\n");

        // Enter NAME
        while(1)
        {
            printf("Enter Name : ");
            scanf(" %[^\n]", name);

            if(validate_name(addressbook, name))
                break;
        }

        // Enter MOBILE NUMBER
        while(1)
        {
            printf("Enter Mobile Number : ");
            scanf("%s", mobile);

            if(validate_mobile(addressbook, mobile))
                break;
        }

        // Enter EMAIL
        while(1)
        {
            printf("Enter Email ID : ");
            scanf("%s", email);

            if(validate_email(addressbook, email))
                break;
        }

        // Store the contact details in the address book
        strcpy(addressbook->contact_details[addressbook->contact_count].Name, name);
        strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number, mobile);
        strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID, email);

        // Increment the contact count after adding a new contact
        addressbook->contact_count++;

        printf("\nContact Created Successfully\n");

        // Ask the user if they want to create another contact
        do
        {
            printf("\nDo you want to create another contact? (Y/N): ");
            scanf(" %c", &choice);

            if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                printf("Invalid Choice\n");

        } while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    } while(choice == 'Y' || choice == 'y');
}

// Function to validate the name input for creating a contact
int validate_name(AddressBook *addressbook, char name[])
{
    int i;

    // Check if the name is empty
    if(strlen(name) == 0){
        printf("Enter valid Name, can't be NULL\n");
        return 0;
    }

    for(i = 0; name[i] != '\0'; i++){  // Only alphabets and spaces are allowed in the name
        if(!(isalpha(name[i]) || name[i] == ' ')){
            printf("Enter valid Name, only alphabets\n");
            return 0;
        }
    }

    return 1;
}

// Function to validate the mobile number input for creating a contact
int validate_mobile(AddressBook *addressbook, char mobile[])
{
    int i;

    // Check if the mobile number is empty
    if(strlen(mobile) != 10){
        printf("Enter valid Mobile Number of 10 digits\n");
        return 0;
    }

    // Check if the mobile number contains only digits
    for(i = 0; mobile[i] != '\0'; i++){
        if(!isdigit(mobile[i])){
            printf("Enter valid Mobile Number, only digits should be there\n");
            return 0;
        }
    }

    // Check for duplicate mobile numbers in the address book
    for(i = 0; i < addressbook->contact_count; i++){
        if(strcmp(addressbook->contact_details[i].Mobile_number,mobile) == 0){
            printf("Enter valid Mobile Number, duplicate is not allowed\n");
            return 0;
        }
    }

    return 1;
}

// Function to validate the email input for creating a contact
int validate_email(AddressBook *addressbook, char email[])
{
    int i;
    int at_count = 0;

    // Pointers to track the positions of '@' and '.com' in the email for validation
    char *at_ptr;
    char *com_ptr;

    // Check if the email is empty
    if(strlen(email) == 0){
        printf("Email cannot be empty\n");
        return 0;
    }

    // Check for the presence of '@' and validate the characters in the email
    for(i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@')
            at_count++;

        if(email[i] == ' '){
            printf("Space is not allowed\n");
            return 0;
        }

        // Only lowercase letters, digits, '@' and '.' are allowed in the email
        if(!(email[i] >= 'a' && email[i] <= 'z') && !(email[i] >= '0' && email[i] <= '9') && email[i] != '@' && email[i] != '.'){
            printf("Only lowercase letters, digits, '@' and '.' are allowed\n");
            return 0;
        }
    }

    // Check if there is exactly one '@' in the email
    if(at_count != 1){
        printf("Email should contain exactly one '@'\n");
        return 0;
    }


    // Validate the positions of '@' and '.com' in the email
    at_ptr = strchr(email, '@');

    if(at_ptr == email){
        printf("Characters before '@' are required\n");
        return 0;
    }

    com_ptr = strstr(email, ".com");

    // Check if '.com' is present in the email and validate its position
    if(com_ptr == NULL){
        printf("'.com' is missing\n");
        return 0;
    }

    // Check if character is present between '@' and '.com'
    if(com_ptr == at_ptr + 1){
        printf("Characters between '@' and '.com' are required\n");
        return 0;
    }

    // Check if '.com' appears only at the end of the email
    if(strcmp(com_ptr, ".com") != 0){
        printf("'.com' should appear only at the end\n");
        return 0;
    }

    // Check for duplicate email IDs in the address book
    for(i = 0; i < addressbook->contact_count; i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID,email) == 0){
            printf("Duplicate Email ID is not allowed\n");
            return 0;
        }
    }

    return 1;
}