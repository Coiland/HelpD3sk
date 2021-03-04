#include "mainfolder.h"
#include  "setup.h"
#include "updatestate.h"

void mainDisplay(s16 i)
{
    headfolders *temp = kinghead;
	u8 y=0;
	float c2dleftmost;
	float c2dtopmost;
	while(temp!=NULL)
	{
		setBuffs(&buttonInfo,&attrInfo,1);
		Mtx_Identity(&MV);
		Mtx_Translate(&MV,-150.0f,-120.0f-y*55.0+i,0.0f,true);
	
		if(temp==mainfocus)
		{
			C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 1.0f, 1.0f,  1.0f, 1.0f);
		}
		else
		{
			C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
		}

		C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
		C3D_DrawArrays(GPU_TRIANGLES, 0, 84);

		setBuffs(&backInfo,&attrInfo,1);
		C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
		C3D_DrawArrays(GPU_TRIANGLES, 0, 30);
	
		temp->x= -120;
		temp->y= -120.0f-y*55.0+i+236;
		//convert coordinates for c2d usage 
		c2dleftmost=(temp->x + 160.0f)*(400.0f/320.0f);
		c2dtopmost=240.0f-(temp->y + 120.0f);
		C2D_Prepare();
        C2D_TextBufClear(mainnameBuf);
        C2D_DrawText(&(mainName_p[y]), C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter | C2D_WordWrap,c2dleftmost+(buttonwidth/2)*400.0f/320.0f,c2dtopmost+buttonheight/2 + 10.0f, 0.2f, 1.2f, 1.1f, C2D_Color32f(0.0f,0.0f,0.0f,1.0f),200.0f);
        C2D_Flush();

		temp=temp->next;
		y++;
	}
	//puy into its own function
	sliderout(i);
}