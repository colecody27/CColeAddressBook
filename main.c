//
//  main.c
//  CColeAddressBook
//
//  Created by Cody Wade Cole on 11/30/20.
//

#include <stdio.h>
#include "contact.h"

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    //Create ContactList and set first Contact equal to null.
    ContactList list1;
    list1.fPtr = NULL;
    printf("%s\n", "Ready");
    //Variables
    char action, inLineInfo[1020], fieldName[25], field[255], fileName[300];
    int index;
    scanf(" %c", &action);
    //Enter loop
    while(action != 'q'){
        switch(action){
            case 'a':
                scanf(" %d %s", &index, inLineInfo);
                insert(&list1, index, inLineInfo);
                break;
            case 'd':
                scanf(" %d", &index);
                delete(&list1, index);//*Might not catch low values* Ex: -1.
                break;
            case 'g':
                scanf(" %d", &index);
                getContact(&list1, index);
                break;
            case 'f':
                scanf(" %d %s", &index, fieldName);
                getField(&list1, index, fieldName);
                break;
            case 'n':
                getCount(&list1);
                break;
            case '1':
                scanf(" %s", fileName);
                loadFile(fileName, &list1);
                break;
            case 's':
                scanf(" %s", fileName);
                saveFile(fileName, &list1);
                break;
            case 'e':
                scanf(" %d %s %s", &index, fieldName, field);
                editContact(&list1, index, fieldName, field);
                break;
        }
        //Receive next action
        scanf(" %c", &action);
    }
    printf("%s\n", "Complete");
    return 0;
    
}
