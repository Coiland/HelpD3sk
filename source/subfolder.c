#include "subfolder.h"
#include "setup.h"
#include "updatestate.h"
void subDisplay(folders* top,s16 i)
{
	folders* temp = top;
	if (temp==NULL)
	{
		return;
	}
	u8 y=0;
	while(temp!=NULL)
	{
		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-150.0f,-120.0f-y*55.0+i,0.0f,true);
		if(temp==subselect)
		{
			printf("\x1b[14;0H Focus text is  %s", temp->text);
		}
		C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
		C3D_DrawArrays(GPU_TRIANGLES, 0, 54);
		//x and y from upper left 
		temp->x= -120;
		temp->y= -120.0f-y*60.0+i+236;
		temp=temp->next;
		y++;
	}

}