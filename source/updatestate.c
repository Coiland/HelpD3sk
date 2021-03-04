#include "updatestate.h"
#include "setup.h"
#include "subfolder.h"
#include "mainfolder.h"
#include "foldcreation.h"
static void tapFocus(float,float);
static void display(s16);
static s16 ytemp=0;
static s16 first=0;
static s16 hold=0;
static u16 penx=0;
static u16 peny=0;
static u16 tapx=0;
static u16 tapy=0;
static u8 i=0;
static u8 holdcount=0;
headfolders *mainfocus=NULL;
folders *subfocus=NULL;
headfolders *headselect=NULL;
float maxtranslate =0;
float subtranslate =0;

void updateState(u32 keys, touchPosition screen)
{
	
	if(keys & KEY_B)
		{
		mainfocus=NULL;
		subfocus=NULL;
		headselect=NULL;
		ytemp=0;
		}
	else
	{

		if(i==0 && (screen.py!=0||screen.px!=0))
		{
			first=screen.py + hold;
			i=1;
			holdcount++;
			tapx=screen.px;
			tapy=screen.py;
		}
		else if (i==1 && ((abs(screen.py-tapy))<5)&& ((abs(screen.px-tapx))<5))
		{
			holdcount++;
		}
		else if (screen.py!=0 || screen.px!=0)
		{
			holdcount=0;
		}
		ytemp=-screen.py+first;

		if(screen.py==0 && screen.px==0)
		{
			ytemp=hold;
			if(i==1)
			{
				if(holdcount<20 && holdcount>0)
				{
					tapFocus(penx,peny);
				}
			}
			holdcount =0;
			i=0;
		}

		penx=screen.px;
		peny=screen.py;
		
		if((-120.0+ytemp+236)<116)
		{
			ytemp=0;
		}
		else if (headselect!=NULL)
		{
			if((-120.0-((headselect->count)-1)*55.0+236)<-71)
			{
				subtranslate=-187 + ((headselect->count)-1)*55.0;

				if((-120.0+ytemp-((headselect->count)-1)*55.0+236)>-71)
				{
					ytemp= subtranslate;
				}
			}
			else
			{
				ytemp=0;
			}
		}
		else if (headselect==NULL)
		{
			
			if((-120.0-(maincount-1)*55.0+236)<-71)
			{
				maxtranslate =-187 + (maincount-1)*55.0;
				//printf("this is man count %d",maincount);
				if((-120.0+ytemp-(maincount-1)*55.0+236)>-71)
				{
					ytemp= maxtranslate;
				}
			}
			else
			{
				ytemp=0;
			}
		}
		
		
		//printf("this is : %d", ytemp);
	}
		hold=ytemp;
        display(ytemp);

}

		



static void tapFocus(float x, float y)
{
	int i =4;
	//printf("\x1b[40;0H%03f; %03f", x, y);
	x=-160+(((x-5)*320)/314) ;
	y=120-(((y-5)*240)/234) ;
	if(headselect!=NULL)
	{
		folders *temp = mainfocus->head;
		while(temp!=NULL)
		{
			if(i==4)
			{
				
			}
			
			if((x>= temp->x )&& (x<=(temp->x+270)))
			{
				if ((y<= temp->y )&& (y>=(temp->y-45)))
				{
				
					subfocus=temp;
					
					
					//printf("\x1b[14;0H Focus name is %s", subfocus->name);
					return;
				}
				
			}
			temp=temp->next;
			i++;
			//i+=2;
		}

	}
	else if(kinghead!=NULL)
	{
		
		headfolders *temp = kinghead;
		while(temp!=NULL)
		{
			//printf("\x1b[%d;0H%f:%f",i,temp->x,temp->y);
			if((x>= temp->x )&& (x<=(temp->x+270)))
			{
				if ((y<= temp->y )&& (y>=(temp->y-45)))
				{
					if(temp==mainfocus)
					{
						headselect=mainfocus;
						ytemp=0;
					}
					else
					{
						mainfocus=temp;
					}
					
					//printf("\x1b[14;0H Focus name is %s", mainfocus->name);
					return;
				}
				
			}
			temp=temp->next;
			//i+=2;
		}
	}
}

static void display(s16 i)
{

	if(headselect!=NULL)
	{
		C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_light, 0.0f, 0.5f,  0.0f, 1.0f);
		subDisplay(mainfocus,i);
	}
	else
	{
		C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_light, 0.2f, 0.0f,  0.9f, 1.0f);
		mainDisplay(i);
	}
   
}

void sliderout(s16 i)
{
	float t;
	if(maxtranslate==0)
	{
		t=0;
	}
	else
	{
		t=i/(maxtranslate);
	}
	setBuffs(&sliderInfo,&attrInfo,1);
	Mtx_Identity(&MV);
	Mtx_Translate(&MV,-160.0f,-120.0f -t*150.0f,0.0f,true);
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
	C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_selectset, 0.0f, 0.0f,  0.0f, 0.0f);
	C3D_DrawArrays(GPU_TRIANGLES, 0, 12);
	
	setBuffs(&limitInfo,&attrInfo,1);
	Mtx_Identity(&MV);
	Mtx_Translate(&MV,-160.0f,-120.0f ,0.0f,true);
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelview, &MV);
	C3D_DrawArrays(GPU_TRIANGLES, 0, 12);	
}
void setBuffs(C3D_BufInfo* vbo,C3D_AttrInfo* attributes, u8 projflag)
{
	C3D_BindProgram(&program);
	C3D_SetAttrInfo(attributes);
	C3D_SetBufInfo(vbo);
	if (projflag)
	{
		Mtx_OrthoTilt(&P, -160.0, 160.0, -120.0, 120.0, 0.0, 1.0, true);
	}
	else
	{

	}
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_projection, &P);
	C3D_TexEnv* env = C3D_GetTexEnv(0);
	C3D_TexEnvInit(env);
	C3D_TexEnvSrc(env, C3D_Both, GPU_PRIMARY_COLOR, 0, 0);
	C3D_TexEnvFunc(env, C3D_Both, GPU_REPLACE);
}
