//
//  contact.h
//  CColeAddressBook
//
//  Created by Cody Wade Cole on 11/30/20.
//

#ifndef contact_h
#define contact_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Create Contact class that will act as a node in the list.
typedef struct contact {
    char inLineInfo[1020];
    char firstName[255];
    char lastName[255];
    char email[255];
    char phoneNumber[255];
    int index;
    struct contact *next;
}Contact;
//Create Contact list with a pointer to first node and a count of nodes.
typedef struct contactList{
    Contact * fPtr;
    int size;
}ContactList;

/*Insert a node with data value in a sorted order using the index.
 *Index: Position to insert.
 *pList: A pointer to the list which contains the first Contact.
 *value: The value to be inserted into list.
 */
void insert(ContactList *pList, int index, char value[255]);

/*Delete a node by index.
 *pList: A pointer to the list which contains the first Contact.
 *index: Index value to be deleted.
 */
void delete(ContactList *pList, int index);

/*Return a Contact at given index.
 *pList: A pointer to the list which contains the first Contact.
 *index: Location of node.
 */
void getContact(ContactList *pList, int index);

/*Return field of desired contact at given index.
 *pList: A pointer to the list which contains the first Contact.
 *index: Index value to be deleted.
 *Value: First name, last name, email, or phone number.
 */
void getField(ContactList *pList, int index, char value[255]);

/*Return count of list.
 *pList: A pointer to the list which contains the first Contact.
 */
void getCount(ContactList *pList);

/*Load a preformatted file into a list.
 *String filename -- Directory of file.
 *pList: A pointer to the list which contains the first Contact.
 */
void loadFile(char fileName[255], ContactList *pList);

/*Print list to a file. If existing, overwrite.
 *String filename -- Directory of file.
 *pList: A pointer to the list which contains the first Contact.
 */
void saveFile(char fileName[255], ContactList *pList);

/*Edit a Contacts field at a given index.
 *pList: A pointer to the list which contains the first Contact.
 *Index: Index of Contact to be edited.
 *Value: Name of field to be edited
 *Replacement:New value.
 */
void editContact(ContactList *pList, int index, char value[255], char replacement[255]);

/*Sort contacts in ascending order based on fields.
 *pList: A pointer to the list which contains the first Contact.
 */
void sortContacts(ContactList *pList);

#endif /* contact_h */


