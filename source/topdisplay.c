#include "updatestate.h"
#include "topdisplay.h"
#include "topbuffs.h"
#include "mainbuffs.h"
#include "setup.h"
C2D_TextBuf dynamicsBuf;
C2D_Text dynamicsText[2];
C2D_Text* dynamicsthing;

// C3D_BufInfo testInfo;
// static void* TEST_DATA;

const vertex randotriangle[] =
{
	//-------------slider limits------------------------
	{{23.0f,209.0f,0.5f},{0.5f,0.67f,0.85f}},
	{{17.0f,209.0f,0.5f},{0.5f,0.67f,0.85f}},
	{{23.0f,29.0f,0.5f},{0.5f,0.67f,0.85f}},

};
int i =0;
const char text[][30]= {"hello","goodbye"};
const char* rando_p=text;

void topSetup()
{
    dynamicsBuf = C2D_TextBufNew(4096);
    dynamicsthing=(C2D_Text*)malloc(10*sizeof(char));
    
    C2D_TextParse(&dynamicsthing[0],dynamicsBuf,&(text[1][0]));
    C2D_TextParse(&dynamicsthing[1], dynamicsBuf, &(text[0][0]));
    C2D_TextOptimize(&dynamicsthing[0]);
    C2D_TextOptimize(&dynamicsthing[1]);


    // TEST_DATA = linearAlloc(sizeof(randotriangle));
	// memcpy(TEST_DATA , randotriangle, sizeof(randotriangle));
	// BufInfo_Init(&testInfo);
	// BufInfo_Add(&testInfo, TEST_DATA , sizeof(vertex), 2, 0x10);
}

void topscreenrender()
{
    
    setBuffs(&canvasInfo,&attrInfo,1);
	Mtx_Identity(&MV);
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
	C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
    C3D_DrawArrays(GPU_TRIANGLES, 0, 6);

    
   
    if (subfocus!=NULL)
    {

    }
    else if (mainfocus!=NULL)
    {

    }
    else
    {   
        C2D_Prepare();
        C2D_TextBufClear(dynamicsBuf);
        //if (i>2)
        //{
        C2D_DrawText(&dynamicsthing[1], C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 180,50.0f, 0.5f, 1.75f, 1.75f, C2D_Color32f(0.667f,0.0f,0.667f,1.0f));
       // }
        //else
       // {
           C2D_DrawText(&dynamicsthing[0], C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 180,100.0f, 0.5f, 1.75f, 1.75f, C2D_Color32f(0.667f,0.0f,0.667f,1.0f));
        //}
       
         C2D_Flush();
    }
   
    i++;
}	