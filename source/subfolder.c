#include "subfolder.h"
#include "setup.h"
#include "updatestate.h"
void subDisplay(folders* top,s16 i)
{
	
	printf("\x1b[14;10H Focus text is  %d", i);
		
	folders* temp = top;
	if (temp==NULL)
	{
		return;
	}
	u8 y=0;
	while(temp!=NULL)
	{
		setBuffs(&buttonInfo,&attrInfo,1);
		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-150.0f,-120.0f-y*55.0+i,0.0f,true);
		if(temp==subfocus)
		{
			C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 1.0f, 1.0f,  1.0f, 1.0f);
		}
		else
		{
			C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
			//printf("You are here 	good	");

		}
		C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
	
		C3D_DrawArrays(GPU_TRIANGLES, 0, 54);
		//x and y from upper left 
		temp->x= -120;
		temp->y= -120.0f-y*50.0+i+236;
		temp=temp->next;
		y++;
	}

	sliderout(i);
}