
#include "setup.h"
#include "foldcreation.h"
#define CLEAR_COLOR 0x68B0D8FF

//typedef struct { float position[3]; } vertex;
typedef struct { float position[3]; } vertex;
static const vertex vertex_list[] =
{
	
	// { {80.0f, 40.0f, -400.0f} },
	// { {280.0f, 40.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
		
	// { {280.0f, 140.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
	// { {280.0f, 40.0f, -400.0f} },
	//--------------main rectangle two triangles--------------
	{ {35.0f, 191.0f, 0.1f} },
	{ {295.0f, 191.0f, 0.1f} },	
	{ {35.0f, 236.0f,  0.1f }},
		
	{ {295.0f, 236.0f, 0.1f} },
	{ {35.0f, 236.0f, 0.1f }},
	{ {295.0f, 191.0f, 0.1f} },
	//-----------------right side rectangle two triangels-------------

	{ {300.0f, 196.0f,0.1f} }, 
	{ {300.0f, 231.0f,0.1f} },
	{ {295.0f,  231.0f,0.1f} },

	{ {295.0f, 231.0f,0.1f} },
	{ {295.0f, 196.0f,0.1f} }, 
	{ {300.0f, 196.0f,0.1f} }, 
	



	

	
	// //-----------------left side rectangle two triangels-------------
	{ {30.0f, 196.0f,0.1f} }, 
	{ {35.0f, 196.0f,0.1f} }, 
	{ {35.0f, 231.0f,0.1f} },
	
	

	{ {30.0f, 196.0f,0.1f} }, 
	{ {35.0f, 231.0f,0.1f} },
	{ {30.0f, 231.0f,0.1f} },
	

	
	

	

	// //-------------------right bottom corner 3 triangles----------------
	{ {295.0f, 191.0f,0.1f} },
	{ {297.088f, 192.206f,0.1f} },
	{ {295.0f, 196.0f,0.1f} }, 

	{ {297.088f, 192.206f,0.1f} },
	{ {298.793f, 193.911f,0.1f} },
	{ {295.0f, 196.0f,0.1f} }, 

	{ {298.793f, 193.911f,0.1f} },
	{ {300.0f, 196.0f,0.1f} },
	{ {295.0f, 196.0f,0.1f} }, 

	// //right top curve 
	{ {295.0f, 231.0f,0.1f} },
	{ {297.088f, 234.794f,0.1f} },
	{ {295.0f, 236.0f,0.1f} },
	
	{ {295.0f, 231.0f,0.1f} },
	{ {298.793f, 233.089f,0.1f} },
	{ {297.088f, 234.794f,0.1f} },
	
	

	{ {298.793f, 233.089f,0.1f} },
	{ {295.0f, 231.0f,0.1f} },
	{ {300.0f, 231.0f,0.1f} },
	

	// //left bottom

	{ {31.207f, 193.911f,0.1f} },
	{ {35.0f, 196.0f,0.1f} }, 
	{ {30.0f, 196.0f,0.1f} },

	{ {35.0f, 196.0f,0.1f} }, 
	{ {31.207f, 193.911f,0.1f} },
	{ {32.912f, 192.206f,0.1f} },
	
	{ {35.0f, 196.0f,0.1f} }, 
	{ {32.912f, 192.206f,0.1f} },
	{ {35.0f, 191.0f,0.1f} },



	


	
	
	// //left top 
	{ {35.0f, 236.0f,0.1f} },
	{ {32.912f, 234.794f,0.1f} },
	{ {35.0f, 231.0f,0.1f} },

	{ {32.912f, 234.794f,0.1f} },
	{ {31.207f, 233.089f,0.1f} },
	{ {35.0f, 231.0f,0.1f} },


	{ {31.207f, 233.089f,0.1f} },
	{ {30.0f, 231.0f,0.1f} },
	{ {35.0f, 231.0f,0.1f} },
	
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
	Mtx_OrthoTilt(&P, -160.0, 160.0, -120.0, 120.0, 0.0, 1.0, true);
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