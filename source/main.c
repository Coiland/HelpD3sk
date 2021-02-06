/*
--------Author: Insteadof2--------
*/
#include "headers.h"
#include "foldcreation.h"

#define CLEAR_COLOR 0x68B0D8FF

#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

// typedef struct vertex
// { 
// 	float x; 
// 	float y; 
// 	float z; 
// } vertex;
typedef struct { float position[3]; } vertex;
static const vertex vertex_list[] =
{
	
	// { {80.0f, 40.0f, -400.0f} },
	// { {280.0f, 40.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
		
	// { {280.0f, 140.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
	// { {280.0f, 40.0f, -400.0f} },

	{ {60.0f, 160.0f, 200.0f} },
	{ {260.0f, 160.0f, 200.0f} },
	{ {60.0f, 210.0f, 200.0f }},
		
	{ {260.0f, 210.0f, 200.0f} },
	{ {60.0f, 210.0f, 200.0f }},
	{ {260.0f, 160.0f, 200.0f} },
};

#define vertex_list_count (sizeof(vertex_list)/sizeof(vertex_list[0]))

static DVLB_s* vshader_dvlb;
static shaderProgram_s program;
static int uLoc_projection,uLoc_modelview;
static C3D_Mtx MV;
static C3D_Mtx P;

static void* BUFFER_DATA;
void createFolders()
{
	addfolderhead("first");
	addfolderhead("second");
}
void setupBuffs()
{
	vshader_dvlb = DVLB_ParseFile((u32*)vshader_shbin, vshader_shbin_size);
	shaderProgramInit(&program);
	shaderProgramSetVsh(&program, &vshader_dvlb->DVLE[0]);
	C3D_BindProgram(&program);

	uLoc_projection = shaderInstanceGetUniformLocation(program.vertexShader, "P");
	uLoc_modelview = shaderInstanceGetUniformLocation(program.vertexShader, "MV");
	
	C3D_AttrInfo* attrInfo = C3D_GetAttrInfo();
	AttrInfo_Init(attrInfo);
	AttrInfo_AddLoader(attrInfo, 0, GPU_FLOAT, 3); // v0=position
	// AttrInfo_AddFixed(attrInfo, 1); // v1=color

	// C3D_FixedAttribSet(1, 1.0, 1.0, 1.0, 1.0);
	// Mtx_OrthoTilt(&P, 0.0, 320.0, 0.0, 240.0, 0.0, 1.0, true);
	Mtx_PerspTilt(&P, C3D_AngleFromDegrees(80.0f), 320/240, 0.01f, 1000.0f,  true);
	// Mtx_Persp(&P, C3D_AngleFromDegrees(80.0f), 320/240, 0.01f, 1000.0f,  true);
	BUFFER_DATA = linearAlloc(sizeof(vertex_list));
	memcpy(BUFFER_DATA , vertex_list, sizeof(vertex_list));

	C3D_BufInfo* bufInfo = C3D_GetBufInfo();
	BufInfo_Init(bufInfo);
	BufInfo_Add(bufInfo, BUFFER_DATA , sizeof(vertex), 1, 0x0);

}
void display(s16 i)
{
	// static s16 c ;
	// c+=i;
	printf("\x1b[4;0H%03d", i);
	
	//Mtx_Translate(&MV,-160.0f,-120.0f+i,0.0f,true);
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_projection, &P);
	
	headfolders* temp = kinghead;
	if (temp==NULL)
	{
		return;
	}
	u8 y=0;
	while(temp!=NULL)
	{

		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-160.0f,-120.0f-y*70.0+i,0.0f,true);
		C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
		C3D_DrawArrays(GPU_TRIANGLES, 0, 6);
		temp=temp->next;
		y++;
	}
	
}
void sceneExit()
{
	//freeing buffer
	linearFree(BUFFER_DATA);
	//freeing shader
	shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);
}
int main(int argc, char* argv[])
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	
	touchPosition screen; 
	u16 ytemp=0;
	u16 first=0;
	u16 hold=0;
	u8 i=0;

	consoleInit(GFX_TOP, NULL);
	C3D_RenderTarget* bottom = C3D_RenderTargetCreate(240, 320, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
	C3D_RenderTargetSetOutput(bottom, GFX_BOTTOM, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);
	
	
	setupBuffs();
	createFolders();
	while (aptMainLoop())
	{
		
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmen
		
			//reads the current touch position 
		hidTouchRead(&screen);
		if(i==0 && screen.py!=0)
		{
			first=screen.py + hold;
			i=1;
		}
		ytemp=-screen.py+first;
		if(screen.py==0 )
		{
			ytemp=hold;
			i=0;
		}
	
		printf("\x1b[2;0H%03d; %03d", screen.px, screen.py);
		printf("\x1b[3;0H%03d", ytemp);
		
			
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C3D_RenderTargetClear(bottom,C3D_CLEAR_ALL,C3D_CLEAR_COLOR,0);
		C3D_FrameDrawOn(bottom);
		
		display(ytemp);
		hold=ytemp;
		C3D_FrameEnd(0);
		
	}

	sceneExit();
	C3D_Fini();
	gfxExit();
	return 0;
}
