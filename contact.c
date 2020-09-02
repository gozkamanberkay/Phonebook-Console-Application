// ----------------------------------------------------------------------------
// contact.c
//
// Created 20/07/2020 by Berkay GOZKAMAN.
// Last Editing 10/08/2020.
//
// ----------------------------------------------------------------------------
#include "contact.h"

// ----------------------------------------------------------------------------
/*
 * Returns contact that is created after gets input from the user.
 *
 * @return tempContact type of struct contact that are created. 
 */
contact contact_getInputToCreateContactFromUser (void)
{
    contact tempContact;
    char *tempString, *tempName, *tempSurname, *tempPhoneNumb;

    tempString = malloc(42);     // 13 + ' ' + 13 + ' ' + 13 + \0
    tempName = malloc(14);       // 13 + \0
    tempSurname = malloc(14);    // 13 + \0
    tempPhoneNumb = malloc(14);  // 13 + \0

    printf("Enter Contact Name Surname Phone-Number: ");
    fgets(tempString, 42, stdin); // Gets from the buffer to put into the string.
    sscanf(tempString, "%s %s %s", tempName, tempSurname, tempPhoneNumb); // Splits the string and assigments the temp values.
    free(tempString);

    tempContact.contactName = tempName;
    tempContact.contactSurname = tempSurname;
    tempContact.contactPhoneNumb = tempPhoneNumb;

    return tempContact;
}
