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
void addfolder(char* text,char * name, char* headname) 
 {
    headfolders *temp=kinghead;
    while(strcmp(headname,temp->name)!=0)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            return;
        }  
        
    }
   
    folders* new=(folders*)malloc(sizeof(folders));
    if(new==NULL)
    {
        printf("Invalid heap allocation while creating head folder");
        return;
    }
    if (temp->head==NULL)
    {
        temp->head=new;
    }
    else
    {
        new->prev = temp->tail;  
        temp->tail=new;
    }
   
    new->name=name;
    // printf("\x1b[14;0H Focus name is %s", new->name);
    new->next=NULL;
    new->text=text;
     
    
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
 
