#include "mainfolder.h"
#include  "setup.h"
void mainDisplay(s16 i)
{
    headfolders *temp = kinghead;
	u8 y=0;
	while(temp!=NULL)
	{

		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-160.0f,-120.0f-y*70.0+i,0.0f,true);
		// if(temp==focus)
		// {
			// printf("\x1b[12;0H Focus name is %s", temp->name);
		// }
		C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
		C3D_DrawArrays(GPU_TRIANGLES, 0, 6);
		//x and y from upper left 
		temp->x= -100;
		temp->y= -120.0f-y*70.0+i+236;
		temp=temp->next;
		y++;
	}
	
}