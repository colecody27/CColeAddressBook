//
//  contact.c
//  CColeAddressBook
//
//  Created by Cody Wade Cole on 11/30/20.
//

#include "contact.h"

void insert(ContactList *pList, int index, char value[1020]){
    Contact * pNew = malloc(sizeof(Contact));
    if(pNew){
        strncpy(pNew->inLineInfo, value, 1020);
        //inLineInfo was being altered. To avoid this a copy was created.
        char cpy[1020];
        strcpy(cpy, pNew->inLineInfo);
        //Split string into desired fields.
        char * key = strtok(cpy, ",");
        int cutCount = 0;
        while(key!=NULL){
            switch(cutCount){
                case 0:
                    strcpy(pNew->lastName, key);
                    cutCount++;
                    break;
                case 1:
                    strcpy(pNew->firstName, key);
                    cutCount++;
                    break;
                case 2:
                    strcpy(pNew->email, key);
                    cutCount++;
                    break;
                case 3:
                    strcpy(pNew->phoneNumber, key);
                    cutCount++;
                    break;
            }
            key = strtok(NULL, ",");
        }
    }

    //List is not empty.
    if(pList->fPtr != NULL){
        Contact * pCur = pList->fPtr;
        //Inserting at front
        if(index == 0){
            pList->fPtr = pNew;
            pNew->next = pCur;
            pList->size++;
        }
        else{
        //Search for index at middle or end.
         for(int i = 0; i < index-1; i++){
          //Returns node previous to insertion point.
          pCur = pCur->next;
          }
        
        //Index is at end
        if(pCur->next == NULL)
            pCur->next = pNew;
        else{
        //Index is in middle
        pNew->next = pCur->next;
        pCur->next = pNew;
         }
            pList->size++;
      }
    }else{
        pList->fPtr = pNew;
        pList->size = 1;
    }
}

void delete(ContactList *pList, int index){
    Contact *pCur = pList->fPtr;
    if(index < pList->size){
        //Deleting first node
        if(index == 0){
            pList->fPtr = pList->fPtr->next;
            free(pCur);
        }else{
            for(int i = 0; i < index-1; i++){
                pCur = pCur->next;
            }
            Contact * cur = pCur->next;
            //Deleting last node
            if(cur->next == NULL){
                free(cur);
                cur->next = NULL;
            }else{
            //Deleting middle node
                pCur->next = cur->next;
                free(cur);
            }
        }
        pList->size--;
    }
}

void getContact(ContactList *pList, int index){
    Contact *pCur = pList->fPtr;
    if(index < pList->size){
        for(int i = 0; i < index; i++){
            pCur = pCur->next;
        }
        printf("%s\n", pCur->inLineInfo);
    }else
        printf("%s\n", "This index is not available");
}

void getField(ContactList *pList, int index, char value[255]){
    Contact *pCur = pList->fPtr;
    //Find contact
    if(index < pList->size){
        for(int i = 0; i < index; i++){
            pCur = pCur->next;
        }
    //Print specified field.
        if(strcmp(value, "firstName")==0){
            printf("%s\n", pCur->firstName);
        }else if(strcmp(value, "lastName")==0){
            printf("%s\n", pCur->lastName);
        }else if(strcmp(value, "email")==0){
            printf("%s\n", pCur->email);
        }else if(strcmp(value, "phoneNumber")==0){
            printf("%s\n", pCur->phoneNumber);
        }else
            printf("%s\n", "Field was not found");
  }else
      printf("%s\n", "This index is not available");
}

void getCount(ContactList *pList){
    printf("%d\n", pList->size);
}

void loadFile(char fileName[255], ContactList *pList){
    //Read the file.
    FILE * ptr;
    ptr = fopen(fileName, "r");
    if(!ptr){
        printf("%s\n", "Could not find file.");
        exit(1);
    }
    char info[1020];
    //lineCount is used to skip the first line.
    int lineCount = 0;
    //Read each line
    while(fgets(info, 1020, ptr)){
        if(lineCount > 0){
        //Insert each line.(Index will be required)
        insert(pList, pList->size, info);
        }
        lineCount++;
    }
    fclose(ptr);
}

void saveFile(char fileName[255], ContactList *pList){
    FILE * ptr;
    ptr = fopen(fileName, "w+");
    if(!ptr){
        printf("%s\n", "Error in writing to file.");
        exit(1);
    }
    Contact * pCur = pList->fPtr;
    for(int i = 0; i < pList->size; i++){
       fputs(pCur->inLineInfo, ptr);
       pCur = pCur->next;
    }
   fclose(ptr);
}

void editContact(ContactList *pList, int index, char value[255], char replacement[255]){
   Contact *pCur = pList->fPtr;
   if(index < pList->size){
      for(int i = 0; i < index; i++){
         pCur = pCur->next;
      }//Replace desired field.
      if(strcmp(value, "firstName")==0){
         strncpy(pCur->firstName,replacement,255);
      }else if(strcmp(value, "lastName")==0){
         strcpy(pCur->lastName,replacement);
      }else if(strcmp(value, "email")==0){
         strcpy(pCur->email,replacement);
      }else if(strcmp(value, "phoneNumber")==0){
         strcpy(pCur->phoneNumber,replacement);
      }else{
          printf("%s\n", "Field was not found");
         exit(1);
      }
      //Change inLineInfo to equal altered field.
      strcpy(pCur->inLineInfo, pCur->lastName);
      strcat(pCur->inLineInfo, ",");
      strcat(pCur->inLineInfo, pCur->firstName);
      strcat(pCur->inLineInfo, ",");
      strcat(pCur->inLineInfo, pCur->email);
      strcat(pCur->inLineInfo, ",");
      strcat(pCur->inLineInfo, pCur->phoneNumber);
   }else
      printf("%s\n", "This index is not available");
}
