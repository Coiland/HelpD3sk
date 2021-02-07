/*
--------Author: Insteadof2--------
*/

#include "headers.h"
#include "foldcreation.h"

headfolders* kinghead=NULL; 
headfolders* kingtail=NULL;

/*!
 * @param       name     Name to be displayed on the button
 * @param       text     Text explaining the button to be 
 *                       displayed on the top of the screen
 * @param       king    Name of the head you want  the button
 *                      to be connected to. Pass NULL if you want to create a new head
 * @result              A pointer to new button 
*/

 //looks for folder with that name and deletes it 
 void deletefolder(char* headname, char* name )
 { 

 }

 //
 void createheadgraphic(headfolders* new, headfolders* prev)
 {

 }
 void creategraphic(folders* new, folders* prev)
 {

 }
 int addfolder(char* text,char * name, char* headname) 
 {
        folders* temp=(folders*)malloc(sizeof(folders));
        if(temp==NULL)
        {
            printf("Invalid heap allocation in addfolder");
            return 0;

        }
      
        temp->next=NULL;
    return 1;
 }

 void addfolderhead(char* name)
 {
    headfolders* new=(headfolders*)malloc(sizeof(folders));
    //headfolders* temp;
    if(new==NULL)
    {
        printf("Invalid heap allocation while creating head folder");
        return;
    }
    if (kinghead==NULL)
    {
        kinghead=new;
    }
    else
    {
        kingtail->next = new; 
        
    }
    //temp = tail; 
    new->name=name;
    new->next=NULL;
    new->head=NULL;
    new->tail=NULL;
    kingtail=new;
 }
 
