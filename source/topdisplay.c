#include "updatestate.h"
#include "topdisplay.h"
#include "textbuffs.h"
#include "mainbuffs.h"
C2D_TextBuf dynamicBuf;
C2D_Text dynamicText[4];

// C3D_BufInfo testInfo;
// static void* TEST_DATA;

// const vertex randotriangle[] =
// {
// 	//-------------slider limits------------------------
// 	{{23.0f,209.0f,0.5f},{0.5f,0.67f,0.85f}},
// 	{{17.0f,209.0f,0.5f},{0.5f,0.67f,0.85f}},
// 	{{23.0f,29.0f,0.5f},{0.5f,0.67f,0.85f}},

// };

void topSetup()
{
    dynamicBuf = C2D_TextBufNew(4096);
    // C2D_TextParse(&dynamicText, dynamicBuf, "hello");
    	// C2D_TextOptimize(&dynamicText);
        	// Create two text buffers: one for static text, and another one for
	// dynamic text - the latter will be cleared at each frame.
	//g_staticBuf  = C2D_TextBufNew(4096); // support up to 4096 glyphs in the buffer
    //dynamicBuf = C2D_TextBufNew(4096);
    // TEST_DATA = linearAlloc(sizeof(randotriangle));
	// memcpy(TEST_DATA , randotriangle, sizeof(randotriangle));
	// BufInfo_Init(&testInfo);
	// BufInfo_Add(&testInfo, TEST_DATA , sizeof(vertex), 2, 0x10);
}

void topscreenrender()
{
    //C2D_TextBufClear(dynamicBuf);
     char buf[160];
    C2D_Text dynText;
    snprintf(buf, sizeof(buf), "Current text size: %f (Use  to change)",5);
    C2D_TextParse(&dynText, dynamicBuf, buf);
    C2D_TextOptimize(&dynText);
    C2D_DrawText(&dynText,C2D_AlignCenter, 200.0f, 220.0f, 0.5f, 0.5f, 0.5f);
    // C3D_SetBufInfo(&testInfo);
	// C3D_DrawArrays(GPU_TRIANGLES, 0, 3);
    if (subfocus!=NULL)
    {

    }
    else if (mainfocus!=NULL)
    {

    }
    else
    {
    
       
        //C2D_DrawText(&dynamicText, C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 180, 250.0f, 0.5f, 1.75f, 1.75f, C2D_Color32f(0.667f,0.0f,0.667f,1.0f));
        //C2D_DrawText(&dynamicText[0], C2D_AtBaseline | C2D_WithColor, 16.0f, 210.0f, 0.5f, 0.5f, 0.75f, C2D_Color32f(1.0f,0.0f,0.0f,1.0f));
        //C2D_DrawText(&dynamicText[0], 0, 8.0f, 8.0f, 0.5f, 0.5f, 0.5f)
        
    }
}	