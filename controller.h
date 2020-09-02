// ----------------------------------------------------------------------------
// controller.h
//
// ----------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H

// ----------------------------------------------------------------------------
#include <stdbool.h>

// ----------------------------------------------------------------------------
bool controller_isPressedUp(int paraPressedButton);
bool controller_isPressedDown(int paraPressedButton);
bool controller_isPressedEnter(int paraPressedButton);
void controller_pressAnyButtonToBack(void);
int controller_getInputFromUserToSelectMenuOperation(void);
int controller_getCheckOverflowOfMenuBoundary(int paraLowerNumericalLimitOfMenuOptions, int paraUpperNumericalLimitOfMenuOptions, int paraCurrentMenuSelection);

// ----------------------------------------------------------------------------
#endif
