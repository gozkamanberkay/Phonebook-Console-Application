// ----------------------------------------------------------------------------
// nodes.c
//
// Created 06/08/2020 by Berkay GOZKAMAN.
// Last Editing 10/08/2020.
//
// ----------------------------------------------------------------------------
#include "controller.h"
#include "conio.h"

// ----------------------------------------------------------------------------
/*
 * Checks that 119 represented w in ASCII equals the provided reference.
 *
 * @param paraPressedButton a reference to be checked.
 *
 * @return true if the provided reference equals 119 otherwise returns false.        
 */
bool controller_isPressedUp (int paraPressedButton)
{
    return 119 == paraPressedButton; // ASCII: [ w ] = 119;
}

// ----------------------------------------------------------------------------
/*
 * Checks that 115 represented s in ASCII equals the provided reference.
 *
 * @param paraPressedButton a reference to be checked.
 *
 * @return true if the provided reference equals 115 otherwise returns false.        
 */
bool controller_isPressedDown (int paraPressedButton)
{
    return 115 == paraPressedButton; // ASCII: [ s ] = 115;
}

// ----------------------------------------------------------------------------
/*
 * Checks that 10 represented ENTER in ASCII equals the provided reference.
 *
 * @param paraPressedButton a reference to be checked.
 *
 * @return true if the provided reference equals 10 otherwise returns false.        
 */
bool controller_isPressedEnter (int paraPressedButton)
{
    return 10 == paraPressedButton; // ASCII: [ ENTER ] = 10;
}

// ----------------------------------------------------------------------------
/*
 * Gets input to validate that go to previous page in the menu.
 */
void controller_pressAnyButtonToBack (void)
{
    printf("\nPress [ ANY BUTTON ] back to main menu.\n");
    getch();
    fflush(stdin); // To clear the buffer.
}

// ----------------------------------------------------------------------------
/*
 * Returns input that if equals w, s or enter.
 *
 * @return tempPressedButton that equals w, s or enter.
 */
int controller_getInputFromUserToSelectMenuOperation (void)
{
    int tempPressedButton;

    do 
    {
        tempPressedButton = getch();
        fflush(stdin); // To clear the buffer.
    } while (!controller_isPressedDown(tempPressedButton) && !controller_isPressedUp(tempPressedButton) && !controller_isPressedEnter(tempPressedButton));
    
    return tempPressedButton;   
}

// ----------------------------------------------------------------------------
/*
 * Prevents overflow of numerical equivalent of boundary of the menu selections.
 *
 * @param paraLowerNumericalLimitOfMenuOptions a reference that represent number of the first menu selection,
 *        paraUpperNumericalLimitOfMenuOptions a reference that represent number of the last menu selection,
 *        paraCurrentMenuSelection a reference that represent number of the current menu selection.
 *
 * @return numerical equivalent of the menu selections.
 */
int controller_getCheckOverflowOfMenuBoundary (int paraLowerNumericalLimitOfMenuOptions, int paraUpperNumericalLimitOfMenuOptions, int paraCurrentMenuSelection)
{    
    if (paraCurrentMenuSelection == (paraLowerNumericalLimitOfMenuOptions - 1)) 
    {
        return paraUpperNumericalLimitOfMenuOptions;
    }
    else if (paraCurrentMenuSelection == (paraUpperNumericalLimitOfMenuOptions + 1)) 
    {
        return paraLowerNumericalLimitOfMenuOptions;
    }
    else
    {
        return paraCurrentMenuSelection;
    }
}
