#include "subfolder.h"
#include "setup.h"
#include "updatestate.h"
void subDisplay(headfolders* headtofolder,s16 i)
{
	float c2dleftmost;
	float c2dtopmost;
	//printf("\x1b[14;10H Focus text is  %d", i);
	C2D_Text *subName_p=(C2D_Text*)malloc(4096);
	folders* temp = headtofolder->head;
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
		temp->y= -120.0f-y*55.0+i+236;
		
		c2dleftmost=(temp->x + 160.0f)*(400.0f/320.0f);
		c2dtopmost=240.0f-(temp->y + 120.0f);
    
        C2D_TextParse(&(subName_p[y]),subnameBuf,temp->name);
        C2D_TextOptimize(&(subName_p[y]));
    
		C2D_Prepare();
        C2D_TextBufClear(subnameBuf);
        C2D_DrawText(&(subName_p[y]), C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter | C2D_WordWrap,c2dleftmost+(buttonwidth/2)*400.0f/320.0f,c2dtopmost+buttonheight/2 + 10.0f, 0.2f, 1.2f, 1.1f, C2D_Color32f(0.0f,0.0f,0.0f,1.0f),200.0f);
        C2D_Flush();
		y++;
		temp=temp->next;
	}

	sliderout(i);
}