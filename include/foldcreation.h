
/*
--------Author: Insteadof2--------
*/
#ifndef FOLDCREATION_H
#define FOLDCREATION_H
#include "headers.h"
typedef struct headfolders headfolders;
typedef struct folders folders;
struct headfolders
{
    char* name; 
    float x,y;
    headfolders* next;
    headfolders* prev;
    folders* tail;
    folders* head;
    u8 count;
};
 struct folders
{
	float x,y;
	folders* next;
    folders* prev; 
	char* text; 
	char* name; 
};
extern headfolders* kinghead; 
extern headfolders* kingtail;
void addfolderhead(char* );
void addfolder(char* text,char * name, char* headname);
extern u8 maincount;
#endif