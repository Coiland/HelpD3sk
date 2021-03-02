#include "updatestate.h"
#include "topdisplay.h"
#include "textbuffs.h"
#include "mainbuffs.h"
#include "setup.h"
C2D_TextBuf dynamicBuf;
C2D_Text dynamicText[2];

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

void topSetup()
{
    dynamicBuf = C2D_TextBufNew(4096);
  
   C2D_TextParse(&dynamicText[0], dynamicBuf, "hello");
    C2D_TextParse(&dynamicText[1], dynamicBuf, "hello55554");
    C2D_TextOptimize(&dynamicText[0]);
    C2D_TextOptimize(&dynamicText[1]);


    // TEST_DATA = linearAlloc(sizeof(randotriangle));
	// memcpy(TEST_DATA , randotriangle, sizeof(randotriangle));
	// BufInfo_Init(&testInfo);
	// BufInfo_Add(&testInfo, TEST_DATA , sizeof(vertex), 2, 0x10);
}

void topscreenrender()
{
    
   

    
   
    if (subfocus!=NULL)
    {

    }
    else if (mainfocus!=NULL)
    {

    }
    else
    {   
        
        //  C3D_BindProgram(&program);
        // C3D_SetAttrInfo(&attrInfo);
        // C3D_SetBufInfo(&testInfo);
        // C3D_DrawArrays(GPU_TRIANGLES, 0, 3);
        C2D_Prepare();
        C2D_TextBufClear(dynamicBuf);
        if (i>2)
        {
           C2D_DrawText(&dynamicText[1], C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 180,100.0f, 0.5f, 1.75f, 1.75f, C2D_Color32f(0.667f,0.0f,0.667f,1.0f));
        }
        else
        {
            C2D_DrawText(&dynamicText[0], C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 180,100.0f, 0.5f, 1.75f, 1.75f, C2D_Color32f(0.667f,0.0f,0.667f,1.0f));
        }
       
         C2D_Flush();
	   
    }
   
    i++;
}	