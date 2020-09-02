// ----------------------------------------------------------------------------
// file.h
//
// ----------------------------------------------------------------------------
#ifndef FILE_H
#define FILE_H

// ----------------------------------------------------------------------------
#include <stdio.h>
#include "node.h"
#include "contact.h"

// ----------------------------------------------------------------------------
void file_saveContactsFromLinkedListToFile(struct node* paraRootReference, FILE *fpWrite);

// ----------------------------------------------------------------------------
void file_loadContactsFromFileToLinkedList (FILE *fpRead, struct node** paraRootReference);

// ----------------------------------------------------------------------------
#endif
