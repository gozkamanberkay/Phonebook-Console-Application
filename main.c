// ----------------------------------------------------------------------------
// main.c
//
// Basic PhoneBook App in C Programming.
// Created 20/07/2020 by Berkay GOZKAMAN.
//
// ----------------------------------------------------------------------------
#include "contact.h"
#include "node.h"
#include "menu.h"
#include "file.h"
#include "controller.h"

// ----------------------------------------------------------------------------
int main ()
{
	struct node* headNode;
	FILE *fpContactTxt;	
	int pressedButtonNumericalValue;
	int currentSelectionOfMenu = 1; // default menu selection to display.
	int lowerNumericalLimitOfMenuOptions = 1;
	int upperNumericalLimitOfMenuOptions = 6;
	contact appendedContact;
	contact deletedContact;

	while (1)
	{
		menu_getMenuScreen(currentSelectionOfMenu);
		pressedButtonNumericalValue = controller_getInputFromUserToSelectMenuOperation();

		if (controller_isPressedDown(pressedButtonNumericalValue))
		{
			currentSelectionOfMenu += 1;
		}
		else if (controller_isPressedUp(pressedButtonNumericalValue))
		{
			currentSelectionOfMenu -= 1;
		}
		else if (controller_isPressedEnter(pressedButtonNumericalValue))
		{
			system("clear");

			switch (currentSelectionOfMenu)
			{
				case 1:					
					nodes_printLinkedList(headNode);
					break;

				case 2:
					appendedContact = contact_getInputToCreateContactFromUser();
					nodes_insertContactToLinkedList(&headNode, appendedContact);
					break;

				case 3:
					deletedContact = contact_getInputToCreateContactFromUser();
					nodes_deleteContactFromLinkedList(&headNode, deletedContact);
					break;

				case 4:
					fpContactTxt = fopen("contacts.txt", "w+");
					file_saveContactsFromLinkedListToFile(headNode, fpContactTxt);
					fclose(fpContactTxt);
					break;

				case 5:
					fpContactTxt = fopen("contacts.txt", "r");
					file_loadContactsFromFileToLinkedList (fpContactTxt, &headNode);
					fclose(fpContactTxt);						
					break;

				case 6:
					exit(EXIT_SUCCESS);
			}

			controller_pressAnyButtonToBack();
		}

		currentSelectionOfMenu = controller_getCheckOverflowOfMenuBoundary(lowerNumericalLimitOfMenuOptions, upperNumericalLimitOfMenuOptions, currentSelectionOfMenu);
	} // End of while. 	

	return 0;
} // End of main function.
