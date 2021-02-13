#include "subfolder.h"
#include "setup.h"
#include "updatestate.h"
void subDisplay(folders* top,s16 i)
{
	
	u8 topflag=0;
	u8 bottomflag=0;

	printf("\x1b[14;10H Focus text is  %d", i);
		
	folders* temp = top;
	if (temp==NULL)
	{
		return;
	}
	// if((-120.0+i+236)<116)
	// {
	// 	topflag=1;
	// }
	u8 y=0;
	while(temp!=NULL)
	{
		// if (topflag==1)
		// {
		// 	i=0;
		// }
		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-150.0f,-120.0f-y*55.0+i,0.0f,true);
		// if(temp==subselect)
		// {
		// 	printf("\x1b[14;0H Focus text is  %s", temp->text);
		// }
		if(temp==subfocus)
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
		C3D_DrawArrays(GPU_TRIANGLES, 0, 54);
		//x and y from upper left 
		temp->x= -120;
		temp->y= -120.0f-y*50.0+i+236;
		temp=temp->next;
		y++;
	}

}