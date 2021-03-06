#include <stdarg.h>
#include "updatestate.h"
#include "topdisplay.h"
#include "topbuffs.h"
#include "mainbuffs.h"
#include "setup.h"
typedef struct threevec 
{
    float x;
    float y;
    float z;
}threevec;
static void topSetMV(threevec* ,float ,threevec* );
static void topDraw();
static void drawtext(u32 textsize,char* );

C2D_TextBuf dynamicsBuf;


static threevec startscale={1.0f,1.0f,1.0f};
static threevec firstrans={0.0f,115.0f,0.0f};
static threevec sectrans={155.0f,0.0f,0.0f};
static threevec scaley={1.0f,1.333f,1.0f};



void topSetup()
{
    dynamicsBuf = C2D_TextBufNew(4096);
   
}

void topscreenrender()
{
    topDraw();
    
    if (subfocus!=NULL)
    {
        
    }
    else if (mainfocus!=NULL)
    {

    }
    else
    {   
      drawtext(50,NULL);
    }
}	

void topSetMV(threevec* scale,float angle,threevec* translate)
{
    Mtx_Identity(&MV);
    Mtx_RotateZ(&MV, angle, false);
    Mtx_Scale(&MV,scale->x, scale->y, scale->z);
    Mtx_Translate(&MV,translate->x,translate->y,0.0f,false);
    C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
	C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
    C3D_DrawArrays(GPU_TRIANGLES, 0, 6);
}
void topDraw()
{
    setBuffs(&canvasInfo,&attrInfo,1);
    sectrans.x*=-1;
    topSetMV(&startscale,0,&sectrans);
    sectrans.x*=-1;
    topSetMV(&startscale,0.0f,&sectrans);
    firstrans.y*=-1;
    topSetMV(&scaley,M_PI/2,&firstrans);
    firstrans.y*=-1;
    topSetMV(&scaley,M_PI/2,&firstrans);
}
static void drawtext(u32 textsize,char* text)
{
    C2D_Text* HelpD3sk=(C2D_Text*)malloc(textsize);
    
    C2D_TextParse(HelpD3sk,dynamicsBuf,"HelpD3sk");
    C2D_TextOptimize(HelpD3sk);
    C2D_Prepare();
    C2D_TextBufClear(dynamicsBuf);
    C2D_DrawText(HelpD3sk, C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 180,50.0f, 0.5f, 1.75f, 1.75f, C2D_Color32f(0.667f,0.0f,0.667f,1.0f));
    C2D_Flush();
    
    free(HelpD3sk);
}