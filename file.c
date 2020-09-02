// ----------------------------------------------------------------------------
// file.c
//
// Created 02/08/2020 by Berkay GOZKAMAN.
// Last Editing 06/08/2020.
//
// ----------------------------------------------------------------------------
#include "file.h"

// ----------------------------------------------------------------------------
/*
 * Saves the contacts from the linked list to the file.
 *
 * @param paraRootReference a reference of root of the linked list,
 *		  fpWrite a reference of file to be written.
 */
void file_saveContactsFromLinkedListToFile (struct node* paraRootReference, FILE *fpWrite) 
{
	char *tempName, *tempSurname, *tempPhoneNumb;

	if (paraRootReference == NULL)
	{
		printf("[_ERROR_]: Contacts not saved, the given linked list is empty.\n");	
	}
	else
	{
		while (paraRootReference != NULL)
		{
			tempName = paraRootReference->dataContact.contactName;
			tempSurname = paraRootReference->dataContact.contactSurname;
			tempPhoneNumb = paraRootReference->dataContact.contactPhoneNumb;

			fprintf(fpWrite, "%s %s %s\n", tempName, tempSurname, tempPhoneNumb);

			paraRootReference = paraRootReference->next;
		}
		printf("[_NOTIFICATION_]: Contacts saved to \"contacts.txt\".\n");
	}
}

// ----------------------------------------------------------------------------
/*
 * Loads the contacts from file to the linked list.
 *
 * @param fpRead a reference of file to be read,
 *		  paraRootReference a reference(pointer to pointer) of root of the linked list.
 */
void file_loadContactsFromFileToLinkedList (FILE *fpRead, struct node** paraRootReference)
{
	char *tempName, *tempSurname, *tempPhoneNumb;
	contact tempContact;

	if (fpRead == NULL)
	{
		printf("[_ERROR_]: The given file not found to load.\n");
	}
	else if (*paraRootReference != NULL)
	{
		printf("[_ERROR_]: Contacts not loaded, the given linked list not empty.\n");
	}
	else
	{
		while (!feof(fpRead))
		{
			tempName = malloc(14);       // 13 + \0
			tempSurname = malloc(14);    // 13 + \0
    			tempPhoneNumb = malloc(14);  // 13 + \0
			
			fscanf(fpRead, "%s %s %s\n", tempName, tempSurname, tempPhoneNumb);

			tempContact.contactName = tempName;
    			tempContact.contactSurname = tempSurname;
    			tempContact.contactPhoneNumb = tempPhoneNumb;

    			nodes_insertContactToLinkedList(paraRootReference, tempContact);
		}
		printf("[_NOTIFICATION_]: Contacts loaded from \"contacts.txt\".\n");
	}
}
