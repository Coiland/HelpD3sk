/*
--------Author: Insteadof2--------
*/

#ifndef UPDATESTATE_H
#define UPDATESTATE_H
#include "headers.h"
#include "foldcreation.h"
void updateState(u32,touchPosition);
void sliderout(s16);
extern folders *subselect;
extern headfolders *headselect;
extern folders *subfocus;
extern headfolders *mainfocus;
extern float subtranslate,maxtranslate;

#endif