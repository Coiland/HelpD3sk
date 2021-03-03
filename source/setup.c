
#include "setup.h"
#include "foldcreation.h"
#include "mainbuffs.h"
#include "topbuffs.h"
#include "textbuffs.h"

#define vertex_list_count (sizeof(vertex_list)/sizeof(vertex_list[0]))

static DVLB_s* vshader_dvlb;
shaderProgram_s program;
int uLoc_projection,uLoc_modelview,uform_selectset,uform_light;
C3D_Mtx MV;
C3D_Mtx P;
C3D_BufInfo buttonInfo,sliderInfo,limitInfo,backInfo,canvasInfo;
C3D_AttrInfo attrInfo;

static void* BUTTON_DATA;
static void* SLIDER_DATA;
static void* LIMIT_DATA;
static void* TABLEBACK_DATA;
static void* CANVAS_DATA;

C2D_TextBuf dynamicBuf;
C2D_Text *dynamicText_p;

void createFolders()
{
	
	//dont put anything in focus initially
	addfolderhead("first");
	
	addfolderhead("second");
	addfolderhead("third");
	
	addfolderhead("fourth");
	addfolderhead("fifth");
	addfolderhead("six");
	addfolderhead("seven");
	//focus=kinghead->next;
	addfolder("sup","mombo","second");
	addfolder("hey","mom","second");
	addfolder("hey","mom","second");
	addfolder("hey","mom","second");
	addfolder("hey","mom","second");
	addfolder("hey","mom","second");
	addfolder("hey","mom","second");
	addfolder("hey","mom","third");

}
void setupBuffs()
{
	vshader_dvlb = DVLB_ParseFile((u32*)vshader_shbin, vshader_shbin_size);
	shaderProgramInit(&program);
	shaderProgramSetVsh(&program, &vshader_dvlb->DVLE[0]);


	uLoc_projection = shaderInstanceGetUniformLocation(program.vertexShader, "P");
	uLoc_modelview = shaderInstanceGetUniformLocation(program.vertexShader, "MV");
	uform_selectset = shaderInstanceGetUniformLocation(program.vertexShader, "S");
	uform_light= shaderInstanceGetUniformLocation(program.vertexShader, "L");
	
	
	AttrInfo_Init(&attrInfo);
	AttrInfo_AddLoader(&attrInfo, 0, GPU_FLOAT, 3); 
	AttrInfo_AddLoader(&attrInfo, 1, GPU_FLOAT, 3); 

	//printf("hello");

	SLIDER_DATA = linearAlloc(bslider_size);
	memcpy(SLIDER_DATA , sliderref, bslider_size);
	BufInfo_Init(&sliderInfo);
	BufInfo_Add(&sliderInfo, SLIDER_DATA , sizeof(vertex), 2, 0x10);

	LIMIT_DATA = linearAlloc(bslider_size);
	memcpy(LIMIT_DATA , sliderlimitsref, bslider_size);
	BufInfo_Init(&limitInfo);
	BufInfo_Add(&limitInfo, LIMIT_DATA , sizeof(vertex), 2, 0x10);

	BUTTON_DATA = linearAlloc(button_size);
	memcpy(BUTTON_DATA , mainbuttref, button_size);
	BufInfo_Init(&buttonInfo);
	BufInfo_Add(&buttonInfo, BUTTON_DATA , sizeof(vertex), 2, 0x10);

	TABLEBACK_DATA = linearAlloc(tableback_size);
	memcpy(TABLEBACK_DATA , tableback, tableback_size);
	BufInfo_Init(&backInfo);
	BufInfo_Add(&backInfo, TABLEBACK_DATA , sizeof(vertex), 2, 0x10);

	CANVAS_DATA = linearAlloc(canvas_size);
	memcpy(CANVAS_DATA, canvas_p, canvas_size);
	BufInfo_Init(&canvasInfo);
	BufInfo_Add(&canvasInfo, CANVAS_DATA , sizeof(vertex), 2, 0x10);

	dynamicBuf = C2D_TextBufNew(4096);
	dynamicText_p=(C2D_Text*)malloc(maincount);
	for(u8 i =0; i<maincount; i++)
	{
		 C2D_TextParse(&dynamicText_p[i], dynamicBuf, &(mainTitles[i][0]));
   		 C2D_TextOptimize(&dynamicText_p[i]);
	}
}

void sceneExit()
{
	//freeing buffer
	linearFree(BUTTON_DATA);
	linearFree(SLIDER_DATA);
	linearFree(LIMIT_DATA);
	linearFree(TABLEBACK_DATA);
	//freeing shader
	shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);
}