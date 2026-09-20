#include "contact.h"

void edit_contact(AddressBook *addressbook)
{
    int index;
    int option;

    char new_name[20];
    char new_mobile[11];
    char new_email[20];
    char choice;

    // Loop to allow the user to edit multiple contacts
    do
    {
        // Call the select_contact function to allow the user to search and select a contact to edit
        index = select_contact(addressbook);
        if(index == -1)
            return;

        printf("\nSelected Contact\n");

        // Display the details of the selected contact before editing
        display_contact(addressbook, index);

        printf("\nEdit Menu\n");
        printf("1. Edit Name\n");
        printf("2. Edit Mobile Number\n");
        printf("3. Edit Email ID\n");
        printf("4. Edit All Fields\n");
        printf("5. Exit\n");

        printf("Enter Option : ");
        scanf("%d", &option);

        // Switch statement to handle the user's choice for editing contact details
        switch(option)
        {
            case 1: // Edit Name
                do{
                    printf("Enter New Name : ");
                    scanf(" %[^\n]", new_name);
                } while(!validate_name(addressbook,new_name));
                strcpy(addressbook->contact_details[index].Name,new_name);
                printf("\nName Updated Successfully\n");
                break;

            case 2: // Edit Mobile Number
                do{
                    printf("Enter New Mobile Number : ");
                    scanf("%s", new_mobile);
                } while(!validate_mobile(addressbook,new_mobile));
                strcpy(addressbook->contact_details[index].Mobile_number,new_mobile);
                printf("\nMobile Number Updated Successfully\n");
                break;

            case 3: // Edit Email ID
                do{
                    printf("Enter New Email ID : ");
                    scanf("%s", new_email);
                } while(!validate_email(addressbook,new_email));
                strcpy(addressbook->contact_details[index].Mail_ID,new_email);
                printf("\nEmail ID Updated Successfully\n");
                break;

            case 4: // Edit All Fields
                do{
                    printf("Enter New Name : ");
                    scanf(" %[^\n]", new_name);
                } while(!validate_name(addressbook,new_name));

                do{
                    printf("Enter New Mobile Number : ");
                    scanf("%s", new_mobile);
                }while(!validate_mobile(addressbook,new_mobile));

                do{
                    printf("Enter New Email ID : ");
                    scanf("%s", new_email);
                } while(!validate_email(addressbook,new_email));

                // Update all fields of the selected contact with the new values
                strcpy(addressbook->contact_details[index].Name,new_name);
                strcpy(addressbook->contact_details[index].Mobile_number,new_mobile);
                strcpy(addressbook->contact_details[index].Mail_ID,new_email);
                printf("\nAll Fields Updated Successfully\n");
                break;

            case 5: // Exit the edit menu
                return;

            default: // Handle invalid option input
                printf("\nInvalid Option\n");
        }

        // Ask the user if they want to edit another contact
        do{ 
            printf("\nDo you want to edit another contact? (Y/N): ");
            scanf(" %c", &choice);

            if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                printf("Invalid Choice\n");
          } while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    } while(choice == 'Y' || choice == 'y');
}

// Function to convert a string to lowercase for case-insensitive comparison
void to_lower(char str[])
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

// Function to select a contact based on user input, allowing search by name, mobile number, or email ID
int select_contact(AddressBook *addressbook)
{
    int option;
    int match[100];
    int count = 0;
    int choice;

    // Temporary variables to store user input for searching contacts
    char search[20];
    char temp[20];

    // Display the search menu to the user for selecting a contact based on different criteria
    printf("\nSearch Contact Using\n");
    printf("1. Search By Name\n");
    printf("2. Search By Mobile Number\n");
    printf("3. Search By Email ID\n");
    printf("4. Exit\n");

    printf("Enter Option : ");
    scanf("%d", &option);

    // Switch statement to handle the user's choice for searching contacts
    switch(option)
    {
        case 1: // Search By Name
            printf("Enter Name : ");
            scanf(" %[^\n]", search);
            to_lower(search);

            // Loop through the contacts in the address book to find matches based on the search criteria
            for(int i = 0; i < addressbook->contact_count; i++){
                strcpy(temp,addressbook->contact_details[i].Name);

                to_lower(temp);

                // If a match is found, display the contact details and store the index of the matching contact in the match array
                if(strstr(temp, search) != NULL){
                    printf("\nIndex %d\n", count + 1);
                    display_contact(addressbook, i);
                    match[count] = i;
                    count++;
                }
            }
            break;

        case 2: // Search By Mobile Number
            printf("Enter Mobile Number : ");
            scanf("%s", search);

            // Loop through the contacts in the address book to find matches based on the search criteria
            for(int i = 0; i < addressbook->contact_count; i++){
                if(strstr(addressbook->contact_details[i].Mobile_number,search) != NULL){
                    printf("\nContact %d\n", count + 1);
                    display_contact(addressbook, i);
                    match[count] = i;
                    count++;
                }
            }
            break;

        case 3: // Search By Email ID
            printf("Enter Email ID : ");
            scanf("%s", search);

            // Loop through the contacts in the address book to find matches based on the search criteria
            for(int i = 0; i < addressbook->contact_count; i++){
                if(strstr(addressbook->contact_details[i].Mail_ID,search) != NULL){
                    printf("\nContact %d\n", count + 1);
                    display_contact(addressbook, i);
                    match[count] = i;
                    count++;
                }
            }
            break;

        case 4: // Exit the search menu
            return -1;

        default: // Handle invalid option input
            printf("Invalid Option\n");
            return -1;
    }

    // If no contacts match the search criteria, inform the user and return -1
    if(count == 0){
        printf("\nContact Not Found\n");
        return -1;
    }

    // If only one contact matches the search criteria, return its index directly
    if(count == 1){
        return match[0];
    }

    // If multiple contacts match the search criteria, prompt the user to select one by index number
    printf("\nEnter Index Number : ");
    scanf("%d", &choice);

    // Validate the user's choice for selecting a contact from the search results
    if(choice < 1 || choice > count){
        printf("\nInvalid Contact Number\n");
        return -1;
    }

    // Return the index of the selected contact from the original address book based on the user's choice
    return match[choice - 1];
}