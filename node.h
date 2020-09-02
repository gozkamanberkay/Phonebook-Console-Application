// ----------------------------------------------------------------------------
// nodes.h
//
// ----------------------------------------------------------------------------
#ifndef NODE_H
#define NODE_H

// ----------------------------------------------------------------------------
#include <string.h>
#include <stdlib.h>
#include "contact.h"
#include <stdbool.h>

// ----------------------------------------------------------------------------
struct node {
	contact dataContact;
	struct node *prev;
	struct node *next;
};

// ----------------------------------------------------------------------------
void nodes_insertContactToLinkedList (struct node** paraRootReference, contact paraContact);

// ----------------------------------------------------------------------------
void nodes_deleteContactFromLinkedList (struct node** paraRootReference, contact paraContact);

// ----------------------------------------------------------------------------
void nodes_printLinkedList (struct node* paraRootNode);

// ----------------------------------------------------------------------------
#endif
