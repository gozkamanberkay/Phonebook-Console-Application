// ----------------------------------------------------------------------------
// menu.c
//
// Created 02/08/2020 by Berkay GOZKAMAN.
// Last Editing 02/08/2020.
//
// ----------------------------------------------------------------------------
#include "menu.h"

// ----------------------------------------------------------------------------
void menu_showSelectionList (void)
{
	printf(" ---------------------------------\n");
	printf("|  PRESS [ W ] or [ S ] to MOVE   |\n");
	printf("|   -> [1]...LIST The Contacts    |\n");
	printf("|      [2]...ADD The Contact      |\n");
	printf("|      [3]...DELETE The Contact   |\n");
	printf("|      [4]...SAVE to The File     |\n");
	printf("|      [5]...LOAD from The File   |\n");
	printf("|      [6]...EXIT                 |\n");
	printf("|  PRESS [ ENTER ] to SELECT      |\n");
	printf(" ---------------------------------\n");
}

// ----------------------------------------------------------------------------
void menu_showSelectionAdd (void)
{
	printf(" ---------------------------------\n");
	printf("|  PRESS [ W ] or [ S ] to MOVE   |\n");
	printf("|      [1]...LIST The Contacts    |\n");
	printf("|   -> [2]...ADD The Contact      |\n");
	printf("|      [3]...DELETE The Contact   |\n");
	printf("|      [4]...SAVE to The File     |\n");
	printf("|      [5]...LOAD from The File   |\n");
	printf("|      [6]...EXIT                 |\n");
	printf("|  PRESS [ ENTER ] to SELECT      |\n");
	printf(" ---------------------------------\n");
}

// ----------------------------------------------------------------------------
void menu_showSelectionDelete (void)
{
	printf(" ---------------------------------\n");
	printf("|  PRESS [ W ] or [ S ] to MOVE   |\n");
	printf("|      [1]...LIST The Contacts    |\n");
	printf("|      [2]...ADD The Contact      |\n");
	printf("|   -> [3]...DELETE The Contact   |\n");
	printf("|      [4]...SAVE to The File     |\n");
	printf("|      [5]...LOAD from The File   |\n");
	printf("|      [6]...EXIT                 |\n");
	printf("|  PRESS [ ENTER ] to SELECT      |\n");
	printf(" ---------------------------------\n");
}

// ----------------------------------------------------------------------------
void menu_showSelectionSave (void)
{
	printf(" ---------------------------------\n");
	printf("|  PRESS [ W ] or [ S ] to MOVE   |\n");
	printf("|      [1]...LIST The Contacts    |\n");
	printf("|      [2]...ADD The Contact      |\n");
	printf("|      [3]...DELETE The Contact   |\n");
	printf("|   -> [4]...SAVE to The File     |\n");
	printf("|      [5]...LOAD from The File   |\n");
	printf("|      [6]...EXIT                 |\n");
	printf("|  PRESS [ ENTER ] to SELECT      |\n");
	printf(" ---------------------------------\n");
}

// ----------------------------------------------------------------------------
void menu_showSelectionLoad (void)
{
	printf(" ---------------------------------\n");
	printf("|  PRESS [ W ] or [ S ] to MOVE   |\n");
	printf("|      [1]...LIST The Contacts    |\n");
	printf("|      [2]...ADD The Contact      |\n");
	printf("|      [3]...DELETE The Contact   |\n");
	printf("|      [4]...SAVE to The File     |\n");
	printf("|   -> [5]...LOAD from The File   |\n");
	printf("|      [6]...EXIT                 |\n");
	printf("|  PRESS [ ENTER ] to SELECT      |\n");
	printf(" ---------------------------------\n");
}

// ----------------------------------------------------------------------------
void menu_showSelectionExit (void)
{
	printf(" ---------------------------------\n");
	printf("|  PRESS [ W ] or [ S ] to MOVE   |\n");
	printf("|      [1]...LIST The Contacts    |\n");
	printf("|      [2]...ADD The Contact      |\n");
	printf("|      [3]...DELETE The Contact   |\n");
	printf("|      [4]...SAVE to The File     |\n");
	printf("|      [5]...LOAD from The File   |\n");
	printf("|   -> [6]...EXIT                 |\n");
	printf("|  PRESS [ ENTER ] to SELECT      |\n");
	printf(" ---------------------------------\n");
}

// ----------------------------------------------------------------------------
void menu_getMenuScreen (int paraMenuSelection)
{	
	system("clear"); // To clear the terminal screen.

	switch (paraMenuSelection)
	{
		case 1:
			menu_showSelectionList();
			break;

		case 2:
			menu_showSelectionAdd();
			break;

		case 3:
			menu_showSelectionDelete();
			break;

		case 4:
			menu_showSelectionSave();
			break;

		case 5:
			menu_showSelectionLoad();
			break;
			
		case 6:
			menu_showSelectionExit();
			break;

		default:
			printf("[_ERROR_]: Enter a valid number to get a menu screen.\n\n");	
			break;		
	}
}
