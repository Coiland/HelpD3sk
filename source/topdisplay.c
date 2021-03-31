#include <stdarg.h>
#include "updatestate.h"
#include "topdisplay.h"
#include "topbuffs.h"
#include "mainbuffs.h"
#include "setup.h"

#define VERTEX_SIZE (sizeof(vertex))
#define ANIMATION_RATE (0.02f)

static char default_text[]=
{
    "Use analog stick or touchpad to scroll"
};
typedef struct threevec
{
    float x;
    float y;
    float z;
} threevec;
static void topSetMV(threevec *, threevec *, threevec *, threevec *, u16);
static void topDraw(float);
static void drawCanvas();
static void drawtext(u32 textsize, char *, float);

C2D_TextBuf dynamicsBuf;

static threevec startscale = {1.0f, 1.0f, 1.0f};
static threevec firstrans = {0.0f, 115.0f, 0.0f};
static threevec sectrans = {195.0f, 0.0f, 0.0f};
static threevec scaley = {1.0f, 1.667f, 1.0f};
static threevec tabletrans = {0.0f, 30.0f, 170.0f};

void topSetup()
{
    dynamicsBuf = C2D_TextBufNew(4096);
}

void topscreenrender()
{
    static float i = 0;
   
    drawCanvas();
    if (subfocus != NULL)
    {
    }
    else if (mainfocus != NULL)
    {
        topDraw(i);
        drawtext(sizeof(default_text)/sizeof(char), default_text, i);
        
    }
    else
    {
        topDraw(i);
        drawtext(sizeof(default_text)/sizeof(char), default_text, i);
        
        
    }
    i += ANIMATION_RATE;
}

void topSetMV(threevec *scale, threevec *angle, threevec *axis, threevec *translate, u16 numvertices)
{
    Mtx_Identity(&MV);
    if (axis->z)
    {
        Mtx_RotateZ(&MV, angle->z, false);
    }
    if (axis->y)
    {
        Mtx_RotateY(&MV, angle->y, false);
    }
    if (axis->x)
    {
        Mtx_RotateX(&MV, angle->x, false);
    }

    Mtx_Scale(&MV, scale->x, scale->y, scale->z);
    Mtx_Translate(&MV, translate->x, translate->y, translate->z, false);
    C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
    C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f, 0.0f, 0.0f);
    C3D_DrawArrays(GPU_TRIANGLES, 0, numvertices);
}
void topDraw(float i)
{
    threevec angle = {0.0f, 0.0f, 0.0f};
    threevec axis = {0.0f, 0.0f, 0.0f};
    angle.z = 0.0f;
    axis.z = 0.0f;
    angle.x = C3D_AngleFromDegrees(-30.0f);
    axis.x = 1.0f;
    angle.y = i;
    axis.y = 1.0f;
    setBuffs(&legsInfo, &attrInfo, 0, 0);
    topSetMV(&startscale, &angle, &axis, &tabletrans, helplegs_size / VERTEX_SIZE);
    setBuffs(&tableInfo, &attrInfo, 0, 1);
    topSetMV(&startscale, &angle, &axis, &tabletrans, maintable_size / VERTEX_SIZE);
}
static void drawtext(u32 textsize, char text[], float i)
{
    C2D_Text *HelpD3sk = (C2D_Text *)malloc(8+5);
    C2D_Text *hint_text = (C2D_Text *)malloc(textsize+5);
    if(HelpD3sk==NULL || hint_text ==NULL)
    {
        return;
    }
    C2D_TextParse(HelpD3sk, dynamicsBuf, "HelpD3sk");
    C2D_TextOptimize(HelpD3sk);
    C2D_Prepare();
    C2D_TextBufClear(dynamicsBuf);
    C2D_DrawText(HelpD3sk, C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter, 200.0f, 60.0f + 10 * sin(i), 0.5f, 1.75f, 1.75f, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
    C2D_Flush();
    free(HelpD3sk);
    C2D_TextParse(hint_text, dynamicsBuf, text);
    C2D_TextOptimize(hint_text);
    C2D_Prepare();
    C2D_TextBufClear(dynamicsBuf);
    C2D_DrawText(hint_text, C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter | C2D_WordWrap , 200.0f, 222, 0.5f, 0.60f, 0.60f, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f),380.0f);
    C2D_Flush();
    free(hint_text);
}
static void drawCanvas()
{
    threevec angle = {0.0f, 0.0f, 0.0f};
    threevec axis = {0.0f, 0.0f, 0.0f};
    setBuffs(&canvasInfo, &attrInfo, 0, 0);
    sectrans.x *= -1;
    topSetMV(&startscale, &angle, &axis, &sectrans, canvas_size / VERTEX_SIZE);
    sectrans.x *= -1;
    topSetMV(&startscale, &angle, &axis, &sectrans, canvas_size / VERTEX_SIZE);
    angle.z = M_PI / 2;
    axis.z = 1.0f;
    firstrans.y *= -1;
    topSetMV(&scaley, &angle, &axis, &firstrans, canvas_size / VERTEX_SIZE);
    firstrans.y *= -1;
    topSetMV(&scaley, &angle, &axis, &firstrans, canvas_size / VERTEX_SIZE);
}