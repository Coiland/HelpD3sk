/*
--------Author: Insteadof2--------
*/
#ifndef FOLDCREATION_H
#define FOLDCREATION_H
typedef struct headfolders headfolders;
typedef struct folders folders;
struct headfolders
{
    char* name; 
    float x,y;
    headfolders* next;
    folders* tail;
    folders* head;
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
#endif