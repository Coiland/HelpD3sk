
#include "setup.h"
#include "foldcreation.h"
#define CLEAR_COLOR 0x68B0D8FF

//typedef struct { float position[3]; } vertex;
typedef struct { 
	float position[3];
	float colour[3];
 } vertex;
static const vertex vertex_list[] =
{
	
	// { {80.0f, 40.0f, -400.0f} },
	// { {280.0f, 40.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
		
	// { {280.0f, 140.0f, -400.0f} },
	// { {80.0f, 140.0f, -400.0f }},
	// { {280.0f, 40.0f, -400.0f} },
//--------------main rectangle two triangles--------------
	{ {35.0f, 191.0f, 0.1f},{0.9f,0.0f,0.1f} },
	{ {295.0f, 191.0f, 0.1f},{0.7f,0.0f,0.1f}}, 
	{ {35.0f, 236.0f, 0.1f },{0.9f,0.0f,1.0f}},
	{ {295.0f, 236.0f, 0.1f},{0.7f,0.0f,1.0f} },
	{ {35.0f, 236.0f, 0.1f },{0.9f,0.0f,1.0f}},
	{ {295.0f, 191.0f, 0.1f},{0.7f,0.0f,0.1f} },
	//-----------------right side rectangle two triangels-------------

	{ {300.0f, 196.0f,0.1f} ,{0.6f,0.0f,0.2f}}, 
	{ {300.0f, 231.0f,0.1f} ,{0.6f,0.0f,0.9f}},
	{ {295.0f, 231.0f,0.1f} ,{0.7f,0.0f,0.9f}},

	{ {295.0f, 231.0f,0.1f},{0.7f,0.0f,0.9f} },
	{ {295.0f, 196.0f,0.1f},{0.7f,0.0f,0.2f} }, 
	{ {300.0f, 196.0f,0.1f},{0.6f,0.0f,0.2f} }, 



	// //-----------------left side rectangle two triangels-------------
	{ {30.0f, 196.0f,0.1f},{1.0f,0.0f,0.2f} }, 
	{ {35.0f, 196.0f,0.1f},{0.9f,0.0f,0.2} }, 
	{ {35.0f, 231.0f,0.1f},{0.9f,0.0f,0.9f} },

	{ {30.0f, 196.0f,0.1f},{1.0f,0.0f,0.2f} }, 
	{ {35.0f, 231.0f,0.1f},{0.9f,0.0f,0.9f} },
	{ {30.0f, 231.0f,0.1f}, {1.0f,0.0f,0.9f}},



	// //-------------------right bottom corner 3 triangles----------------
	{ {295.0f, 191.0f,0.1f}, {0.7f,0.0f,0.1f}},
	{ {297.088f, 192.206f,0.1f},{0.675f,0.0f,0.125f} },
	{ {295.0f, 196.0f,0.1f} , {0.7f,0.0f,0.2f}}, 

	{ {297.088f, 192.206f,0.1f},{0.675f,0.0f,0.125f} },
	{ {298.793f, 193.911f,0.1f} ,{0.65f,0.0f,0.15f}},
	{ {295.0f, 196.0f,0.1f}, {0.7f,0.0f,0.2f} }, 

	{ {298.793f, 193.911f,0.1f},{0.65f,0.0f,0.15f} },
	{ {300.0f, 196.0f,0.1f},{0.6f,0.0f,0.2f} },
	{ {295.0f, 196.0f,0.1f} ,{0.7f,0.0f,0.2f}}, 

	// //right top curve 
	{ {295.0f, 231.0f,0.1f}, {0.7f,0.0f,0.9f} },
	{ {297.088f, 234.794f,0.1f} ,{0.675f,0.0f,0.975f}},
	{ {295.0f, 236.0f,0.1f},{0.7f,0.0f,1.0f} },
	{ {295.0f, 231.0f,0.1f},{0.7f,0.0f,0.9f} },
	{ {298.793f, 233.089f,0.1f},{0.65f,0.0f,0.95f} },
	{ {297.088f, 234.794f,0.1f},{0.675f,0.0f,0.975f} },

	{ {298.793f, 233.089f,0.1f},{0.65f,0.0f,0.95f} },
	{ {295.0f, 231.0f,0.1f} , {0.7f,0.0f,0.9f}},
	{ {300.0f, 231.0f,0.1f}, {0.6f,0.0f,0.9f} },

	// //left bottom

	{ {31.207f, 193.911f,0.1f},{0.975f,0.0f,0.15f}},
	{ {35.0f, 196.0f,0.1f} ,{0.9f,0.0f,0.2f}}, 
	{ {30.0f, 196.0f,0.1f} ,{1.0f,0.0f,0.2f}},

	{ {35.0f, 196.0f,0.1f} ,{0.9f,0.0f,0.2f}}, 
	{ {31.207f, 193.911f,0.1f},{0.975f,0.0f,0.15f} },
	{ {32.912f, 192.206f,0.1f},{0.95f,0.0f,0.125f} },
	{ {35.0f, 196.0f,0.1f},{0.9f,0.0f,0.2f} }, 
	{ {32.912f, 192.206f,0.1f},{0.95f,0.0f,0.125f} },
	{ {35.0f, 191.0f,0.1f},{0.9f,0.0f,0.1f} },



	// //left top 
	{ {35.0f, 236.0f,0.1f},{0.9f,0.0f,1.0f}},
	{ {32.912f, 234.794f,0.1f},{0.95f,0.0f,0.975f} },
	{ {35.0f, 231.0f,0.1f},{0.9f,0.0f,0.9f}},

	{ {32.912f, 234.794f,0.1f},{0.95f,0.0f,0.975f} },
	{ {31.207f, 233.089f,0.1f},{0.975f,0.0f,0.95f} },
	{ {35.0f, 231.0f,0.1f} ,{0.9f,0.0f,0.9f}},

	{ {31.207f, 233.089f,0.1f},{0.975f,0.0f,0.95f} },
	{ {30.0f, 231.0f,0.1f},{1.0f,0.0f,0.9f} },
	{ {35.0f, 231.0f,0.1f},{0.9f,0.0f,0.9f} },

	{ {40.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {80.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {40.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},

	{ {40.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {80.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {80.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},
	


	//left bottom
	{ {53.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {48.0f,221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {48.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},

	{ {48.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {53.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {53.0f,  221.0f,0.05f},{0.0f,0.0f,0.0f}},
	

	//right bottom
	{ {72.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {72.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {67.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},

	
	{ {67.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {67.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},
	{ {72.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
	

};
static const vertex table_list[] =
{
	//top 2
// 	{ {35.0f, 191.0f, 0.1f},{0.9f,0.0f,0.1f} },
// { {295.0f, 191.0f, 0.1f},{0.7f,0.0f,0.1f}}, 
// { {35.0f, 236.0f, 0.1f },{0.9f,0.0f,1.0f}},
// { {295.0f, 236.0f, 0.1f},{0.7f,0.0f,1.0f} },
// { {35.0f, 236.0f, 0.1f },{0.9f,0.0f,1.0f}},
// { {295.0f, 191.0f, 0.1f},{0.7f,0.0f,0.1f} },
	// { {40.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {80.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {40.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},

	// { {40.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {80.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {80.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},
	


	// //left bottom
	// { {53.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {48.0f,221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {48.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},

	// { {48.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {53.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {53.0f,  221.0f,0.05f},{0.0f,0.0f,0.0f}},
	

	// //right bottom
	// { {72.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {72.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {67.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},

	
	// { {67.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {67.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},
	// { {72.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},


	{ {10.0f, 224.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {10.0f,194.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {17.5f, 194.0f,0.05f},{0.2f,0.0f,0.8f}},

	{ {17.5f,  224.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {10.0f,224.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {17.5f, 194.0f,0.05f},{0.2f,0.0f,0.8f}},
	

	//right bottom
	
	{ {10.0f,224.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {17.5f,  224.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {13.75f, 234.0f,0.05f},{0.2f,0.0f,0.8f}},

	
	{ {13.75f, 184.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {17.5f, 194.0f,0.05f},{0.2f,0.0f,0.8f}},
	{ {10.0f,194.0f,0.05f},{0.2f,0.0f,0.8f}},
	
	
	
};
// static const vertex scroller[] =
// {
// 	//top 2
// // 	{ {35.0f, 191.0f, 0.1f},{0.9f,0.0f,0.1f} },
// // { {295.0f, 191.0f, 0.1f},{0.7f,0.0f,0.1f}}, 
// // { {35.0f, 236.0f, 0.1f },{0.9f,0.0f,1.0f}},
// // { {295.0f, 236.0f, 0.1f},{0.7f,0.0f,1.0f} },
// // { {35.0f, 236.0f, 0.1f },{0.9f,0.0f,1.0f}},
// // { {295.0f, 191.0f, 0.1f},{0.7f,0.0f,0.1f} },
// 	{ {40.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {80.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {40.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},

// 	{ {40.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {80.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {80.0f, 226.0f,0.05f},{0.0f,0.0f,0.0f}},
	


// 	//left bottom
// 	{ {53.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {48.0f,221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {48.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},

// 	{ {48.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {53.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {53.0f,  221.0f,0.05f},{0.0f,0.0f,0.0f}},
	

// 	//right bottom
// 	{ {72.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {72.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {67.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},

	
// 	{ {67.0f, 221.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {67.0f, 201.0f,0.05f},{0.0f,0.0f,0.0f}},
// 	{ {72.0f,  201.0f,0.05f},{0.0f,0.0f,0.0f}},
	
	
	
// };

// static const C3D_Mtx light[] =
// {
// 	{0.5f,0.5f,0.5f,1.0f}
// };
#define vertex_list_count (sizeof(vertex_list)/sizeof(vertex_list[0]))

static DVLB_s* vshader_dvlb;
static shaderProgram_s program;
int uLoc_projection,uLoc_modelview,uform_selectset,uform_light;
C3D_Mtx MV;
C3D_Mtx P;
C3D_BufInfo bufInfo,tableInfo;
static void* BUFFER_DATA;
static void* TABLE_DATA;
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


	C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_light, 0.5f, 0.5f,  0.5f, 1.0f);

	TABLE_DATA = linearAlloc(sizeof(table_list));
	memcpy(TABLE_DATA , table_list, sizeof(table_list));

	BufInfo_Init(&tableInfo);
	BufInfo_Add(&tableInfo, TABLE_DATA , sizeof(vertex), 2, 0x10);

	BUFFER_DATA = linearAlloc(sizeof(vertex_list));
	memcpy(BUFFER_DATA , vertex_list, sizeof(vertex_list));

	BufInfo_Init(&bufInfo);
	BufInfo_Add(&bufInfo, BUFFER_DATA , sizeof(vertex), 2, 0x10);

	//table  vbo

}

void sceneExit()
{
	//freeing buffer
	linearFree(BUFFER_DATA);
	linearFree(TABLE_DATA);
	//freeing shader
	shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);
}