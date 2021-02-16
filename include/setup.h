#ifndef SETUP_H
#define SETUP_H

#include "headers.h"
void setupBuffs();
void createFolders();
void sceneExit();
extern int uLoc_projection,uLoc_modelview,uform_selectset,uform_light;
extern C3D_Mtx MV;
extern C3D_Mtx P;
extern C3D_BufInfo bufInfo,tableInfo,limitInfo;
#endif