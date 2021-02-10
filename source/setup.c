
#include "setup.h"
#include "foldcreation.h"
#define CLEAR_COLOR 0x68B0D8FF

typedef struct { float position[3]; } vertex;
static const vertex vertex_list[] =
{
	
	// { {80.0f, 40.0f, -400.0f} },
	// { {280.0f, 40.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
		
	// { {280.0f, 140.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
	// { {280.0f, 40.0f, -400.0f} },

	{ {60.0f, 186.0f, 0.1f} },
	{ {260.0f, 186.0f, 0.1f} },	
	{ {60.0f, 236.0f,  0.1f }},
		
	{ {260.0f, 236.0f, 0.1f} },
	{ {60.0f, 236.0f, 0.1f }},
	{ {260.0f, 186.0f, 0.1f} },
};

#define vertex_list_count (sizeof(vertex_list)/sizeof(vertex_list[0]))

static DVLB_s* vshader_dvlb;
static shaderProgram_s program;
int uLoc_projection,uLoc_modelview;
C3D_Mtx MV;
C3D_Mtx P;

static void* BUFFER_DATA;
void createFolders()
{
	//dont put anything in focus initially
	addfolderhead("first");
	
	addfolderhead("second");
	//focus=kinghead->next;
	addfolder("sup","mombo","second");
	addfolder("hey","mom","second");
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
	AttrInfo_AddLoader(attrInfo, 0, GPU_FLOAT, 3); 
	BUFFER_DATA = linearAlloc(sizeof(vertex_list));
	memcpy(BUFFER_DATA , vertex_list, sizeof(vertex_list));

	C3D_BufInfo* bufInfo = C3D_GetBufInfo();
	BufInfo_Init(bufInfo);
	BufInfo_Add(bufInfo, BUFFER_DATA , sizeof(vertex), 1, 0x0);

}

void sceneExit()
{
	//freeing buffer
	linearFree(BUFFER_DATA);
	//freeing shader
	shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);
}