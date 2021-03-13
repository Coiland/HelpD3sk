/*
--------Author: Insteadof2--------
*/

#include "foldcreation.h"
#include "headers.h"
#include "setup.h"

headfolders *kinghead = NULL;
headfolders *kingtail = NULL;
u8 maincount = 0;

/*!
 * @param       name     Name to be displayed on the button
 * @param       text     Text explaining the button to be 
 *                       displayed on the top of the screen
 * @param       king    Name of the head you want  the button
 *                      to be connected to. Pass NULL if you want to create a new head
 * @result              A pointer to new button 
*/
void addfolder(char *text, char *name, char *headname)
{
    headfolders *temp = kinghead;
    while (strcmp(headname, temp->name) != 0)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            return;
        }
    }
    (temp->count)++;

    folders *new = (folders *)malloc(sizeof(folders));
    if (new == NULL)
    {
        return;
    }
    if (temp->head == NULL)
    {
        temp->head = new;
    }
    else
    {
        temp->tail->next = new;
    }
    new->prev = temp->tail;
    temp->tail = new;
    new->name = name;
    new->next = NULL;
    new->text = text;
}

void addfolderhead(char *name)
{
    headfolders *new = (headfolders *)malloc(sizeof(headfolders));

    if (new == NULL)
    {
        return;
    }
    if (kinghead == NULL)
    {
        kinghead = new;
    }
    else
    {
        kingtail->next = new;
    }
    new->prev = kingtail;
    new->name = name;
    new->next = NULL;
    new->head = NULL;
    new->tail = NULL;
    kingtail = new;
    maincount++;
}
