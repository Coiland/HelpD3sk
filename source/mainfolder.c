#include "mainfolder.h"
#include  "setup.h"
#include "updatestate.h"

void mainDisplay(s16 i)
{
    headfolders *temp = kinghead;
	u8 y=0;
	while(temp!=NULL)
	{

		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-150.0f,-120.0f-y*55.0+i,0.0f,true);
		if(temp==mainfocus)
		{
			//C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.7f, 0.7f,  0.7f, 1.0f);
			C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.7f,  0.0f, 0.0f);
			//printf("You are here");

		}
		else
		{
			C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
			//printf("You are here 	good	");

		}

		
		C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
		C3D_SetBufInfo(&bufInfo);
		C3D_DrawArrays(GPU_TRIANGLES, 0, 72);
	
		//x and y from upper left 
		temp->x= -120;
		temp->y= -120.0f-y*55.0+i+236;
		temp=temp->next;
		y++;
	}

	float t;
	if(maxtranslate==0)
	{
		t=0;
	}
	else
	{
		t=i/(maxtranslate);
	}
	Mtx_Identity(&MV);
	Mtx_Translate(&MV,-160.0f,-120.0 -t*180.0f,0.0f,true);
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
	C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
	C3D_SetBufInfo(&tableInfo);
	C3D_DrawArrays(GPU_TRIANGLES, 0, 12);
}