
#include "setup.h"
#include "foldcreation.h"
#include "mainbuffs.h"

#define vertex_list_count (sizeof(vertex_list)/sizeof(vertex_list[0]))

static DVLB_s* vshader_dvlb;
static shaderProgram_s program;
int uLoc_projection,uLoc_modelview,uform_selectset,uform_light;
C3D_Mtx MV;
C3D_Mtx P;
C3D_BufInfo buttonInfo,sliderInfo,limitInfo,backInfo;
static void* BUTTON_DATA;
static void* SLIDER_DATA;
static void* LIMIT_DATA;
static void* TABLEBACK_DATA;
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
	C3D_BindProgram(&program);

	uLoc_projection = shaderInstanceGetUniformLocation(program.vertexShader, "P");
	uLoc_modelview = shaderInstanceGetUniformLocation(program.vertexShader, "MV");
	uform_selectset = shaderInstanceGetUniformLocation(program.vertexShader, "S");
	uform_light= shaderInstanceGetUniformLocation(program.vertexShader, "L");
	
	C3D_AttrInfo* attrInfo = C3D_GetAttrInfo();
	AttrInfo_Init(attrInfo);
	AttrInfo_AddLoader(attrInfo, 0, GPU_FLOAT, 3); 
	AttrInfo_AddLoader(attrInfo, 1, GPU_FLOAT, 3); 

	Mtx_OrthoTilt(&P, -160.0, 160.0, -120.0, 120.0, 0.0, 1.0, true);
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_projection, &P);
	printf("hello");

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


	//table  vbo

}

void sceneExit()
{
	//freeing buffer
	linearFree(BUTTON_DATA);
	linearFree(SLIDER_DATA);
	//freeing shader
	shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);
}