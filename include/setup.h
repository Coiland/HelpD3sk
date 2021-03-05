/*
--------Author: Insteadof2--------
*/

#ifndef SETUP_H
#define SETUP_H

#include "headers.h"
void setupBuffs();
void createFolders();
void sceneExit();

extern int uLoc_projection,uLoc_modelview,uform_selectset,uform_light;
extern C3D_Mtx MV,P;
extern shaderProgram_s program;
extern C3D_BufInfo buttonInfo,sliderInfo,limitInfo,backInfo,canvasInfo;
extern C3D_AttrInfo attrInfo;
extern C2D_TextBuf nameBuf;/*,subnameBuf;*/
//extern C2D_Text *mainName_p,*subName_p;
extern u16 buttonwidth,buttonheight;
#endif