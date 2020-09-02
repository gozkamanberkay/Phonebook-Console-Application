// ----------------------------------------------------------------------------
// nodes.c
//
// Created 20/07/2020 by Berkay GOZKAMAN.
// Last Editing 10/08/2020.
//
// ----------------------------------------------------------------------------
#include "node.h"

// ----------------------------------------------------------------------------
/*
 * Returns the created node.
 *
 * @paraContact holds data that will append to the node.
 *
 * @return newNode the created node.
 */
struct node* nodes_getNewNode (contact paraContact)
{   
	struct node* newNode;

	newNode = (struct node*) malloc(sizeof(struct node));  
	newNode->dataContact = paraContact;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

// ----------------------------------------------------------------------------
/*
 * Returns true if the provided reference is null otherwise returns false.
 *
 * @param paraNode a reference to be checked against NULL.
 *
 * @return true if the provided reference is null otherwise returns false.		   
 */
bool nodes_isNull (struct node* paraNode) 
{    
	return paraNode == NULL;
}

// ----------------------------------------------------------------------------
/*
 * Returns true if the previous of provided reference is not null otherwise returns false.
 *
 * @param paraNode source node to check.
 *
 * @return true if the previous of provided reference is not null otherwise returns false.
 */
bool nodes_hasPrev (struct node* paraNode)
{    
	return paraNode->prev != NULL;
}

// ----------------------------------------------------------------------------
/*
 * Returns true if the next of provided reference is not null otherwise returns false.
 *
 * @param paraNode source node to check.
 *
 * @return true if the next of provided reference is not null otherwise returns false.
 */
bool nodes_hasNext (struct node* paraNode)
{    
	return paraNode->next != NULL;
}

// ----------------------------------------------------------------------------
/*
 * Returns the end node of the linked list.
 *
 * @param paraNode a reference of node of the linked list.
 *
 * @return the end node of the linked list.
 */
struct node* nodes_getLastNode (struct node* paraNode)
{   
	while (nodes_hasNext(paraNode))
	{
		paraNode = paraNode->next;
	}

	return paraNode;
}

// ----------------------------------------------------------------------------
/*
 * Returns the node that has provided content of the linked list.
 *
 * @param paraRootReference a reference of root of the linked list,
 *		  paraContact a reference of contact to be compared to get the node of the linked list.
 *
 * @return the node that has provided content of the linked list if there exist otherwise returns null.
 */
struct node* nodes_getNodeUsingContact (struct node* paraRootReference, contact paraContact)
{
	while (!nodes_isNull(paraRootReference))
	{
		if (!strcmp((paraRootReference)->dataContact.contactName, paraContact.contactName) && 
		    !strcmp((paraRootReference)->dataContact.contactSurname, paraContact.contactSurname) && 
		    !strcmp((paraRootReference)->dataContact.contactPhoneNumb, paraContact.contactPhoneNumb))
		{
			return paraRootReference;
		}

		paraRootReference = paraRootReference->next;
	}

	return NULL;
}

// ----------------------------------------------------------------------------
/*
 * Appends provided node to the head of the linked list.
 *
 * @param paraRootReference a reference(pointer to pointer) of root of the linked list,
 *		  paraNodeToAppend a reference of the node to append to the linked list.
 */
void nodes_insertNodeToHead (struct node** paraRootReference, struct node* paraNodeToAppend)
{
	if (nodes_isNull(*paraRootReference))
	{
		(*paraRootReference) = paraNodeToAppend;
	}
	else
	{ // If the root of the linked list is not null, in other words the linked list is not empty.
		paraNodeToAppend->next = (*paraRootReference);
		(*paraRootReference)->prev = paraNodeToAppend;
		(*paraRootReference) = paraNodeToAppend;
	}
}

// ----------------------------------------------------------------------------
/*
 * Appends the node to after the provided node of the linked list.
 *
 * @param paraNodeProvided a reference of the node before the appended node to the linked list,
 * 		  paraNodeToAppend a reference of the node to append to the linked list.
 */
void nodes_insertNodeToProvidedNode (struct node* paraNodeProvided, struct node* paraNodeToAppend)
{
	paraNodeToAppend->prev = paraNodeProvided;
	paraNodeToAppend->next = paraNodeProvided->next;

	if (paraNodeProvided->next != NULL)
	{
		(paraNodeProvided->next)->prev = paraNodeToAppend;
	}

	paraNodeProvided->next = paraNodeToAppend;
}

// ----------------------------------------------------------------------------
/*
 * Appends provided node to the end of the linked list.
 *
 * @param paraRootReference a reference(pointer to pointer) root of the linked list,
 *		  paraNodeToAppend a reference of the node to append to the linked list.
 */
void nodes_insertNodeToEnd (struct node** paraRootReference, struct node* paraNodeToAppend)
{
	struct node* tempNode;

	if (nodes_isNull(*paraRootReference))
	{
		(*paraRootReference) = paraNodeToAppend;
	}
	else
	{ // If the root of the linked list is not null, in other words the linked list is not empty.
		tempNode = nodes_getLastNode(*paraRootReference);

		tempNode->next = paraNodeToAppend;
		paraNodeToAppend->prev = tempNode;
	} 
}

// ----------------------------------------------------------------------------
/*
 * Deletes the node of the linked list.
 *
 * @param paraRootReference a reference(pointer to pointer) root of the linked list,
 *		  paraNodeToDelete provided node to delete to the linked list.
 */
void nodes_deleteNode (struct node** paraRootReference, struct node* paraNodeToDelete)
{	
	struct node* newLastNode;
	struct node* prevNode;
	struct node* nextNode;

	if (nodes_isNull(*paraRootReference))
	{ // If the root of the linked list is null, in other words the linked list is empty.
		return;
	}
	else if (!nodes_hasPrev(*paraRootReference) && !nodes_hasNext(*paraRootReference))
	{ // If the node to be deleted is the only single node of the linked list.
		(*paraRootReference) = NULL;
	}
	else if (paraNodeToDelete->prev == NULL)
	{ // If the node to be deleted is the first node of the linked list.
		(*paraRootReference) = (*paraRootReference)->next;
		(*paraRootReference)->prev = NULL;
	} 
	else if (paraNodeToDelete->next == NULL)
	{ // If the node to be deleted is the last node of the linked list.
		newLastNode = paraNodeToDelete->prev;
		newLastNode->next = NULL;
	} 
	else
	{ // If the node to be deleted is an intermediate node of the linked list.
		prevNode = paraNodeToDelete->prev;
		prevNode->next = paraNodeToDelete->next;

		nextNode = paraNodeToDelete->next;
		nextNode->prev = paraNodeToDelete->prev;
	}

	free(paraNodeToDelete);
} // End of nodes_deleteNode Function.

// ----------------------------------------------------------------------------
/*
 * Prints the content of just the provided reference node to the screen.
 *
 * @param paraNode a reference of node to be printed on the screen.
 */
void nodes_printNode (struct node* paraNode)
{
	printf("[%s %s]\t[%s]\n", paraNode->dataContact.contactName, paraNode->dataContact.contactSurname, paraNode->dataContact.contactPhoneNumb);
}

// ----------------------------------------------------------------------------
/*
 * Inserts the contact by alphabetical order to the linked list.
 *
 * @param paraRootReference a reference(pointer to pointer) root of the linked list,
 *		  paraContactToDelete a reference contact to append from the linked list.
 */
void nodes_insertContactToLinkedList (struct node** paraRootReference, contact paraContactToAppend)
{
	struct node* createdNode; 
	struct node* tempNode;
	int controlValue;

	createdNode = nodes_getNewNode(paraContactToAppend);

	if (nodes_isNull(*paraRootReference))
	{ // If the root of the linked list is null, in other words the linked list is empty.
		nodes_insertNodeToHead(paraRootReference, createdNode);
	}
	else
	{ // The linked list has has element/elements.
		tempNode = (*paraRootReference);

		while (!nodes_isNull(tempNode))
		{
			controlValue = strcmp(tempNode->dataContact.contactName, createdNode->dataContact.contactName); // str_1 < str_2 ? -1 : +1

			if (!nodes_hasPrev(tempNode) && controlValue > 0)
			{ // If to append before the first node of the linked list.
				nodes_insertNodeToHead(paraRootReference, createdNode);
				return;		
			}
			else if (!nodes_hasNext(tempNode) && !(controlValue > 0))
			{ // If to append after the last node of the linked list.
				nodes_insertNodeToEnd(paraRootReference, createdNode);
				return;
			}	
			else
			{ // If to append the intermediate node of the linked list.
				if (controlValue > 0)
				{ // If to append after the intermediate node of the linked list.
					nodes_insertNodeToProvidedNode(tempNode->prev, createdNode);
					return;
				}
				else if (controlValue == 0)
				{ // If to append before the intermediate node of the linked list.
					nodes_insertNodeToProvidedNode(tempNode, createdNode);
					return;
				}
			}

			tempNode = tempNode->next;
		}
	}
} // End of nodes_insertContactToNode Function.

// ----------------------------------------------------------------------------
/*
 * Deletes the contact from the linked list.
 *
 * @param paraRootReference a reference(pointer to pointer) root of the linked list,
 *		  paraContactToDelete a reference contact to delete from the linked list.
 */
void nodes_deleteContactFromLinkedList (struct node** paraRootReference, contact paraContactToDelete)
{
	struct node* tempNode;

	tempNode = nodes_getNodeUsingContact(*paraRootReference, paraContactToDelete);
	
	if (tempNode != NULL)
	{	
		nodes_deleteNode(paraRootReference, tempNode);
	}
	else
	{
		printf("[_ERROR_]: The given contact was not found.\n");	
	}
}

// ----------------------------------------------------------------------------
/*
 * Prints the contents of linked list starting from the given node to the screen.
 *
 * @param paraNode a reference of node of linked list to be printed on the screen.
 */
void nodes_printLinkedList (struct node* paraNode)
{
	if (nodes_isNull(paraNode))
	{
		printf("[_NOTIFICATION_]: The linked list is empty.\n");	
	}
	else
	{
		while (!nodes_isNull(paraNode))
		{
			nodes_printNode(paraNode);
			paraNode = paraNode->next;
		}
	}
}
