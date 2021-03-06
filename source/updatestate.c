#include "updatestate.h"
#include "setup.h"
#include "subfolder.h"
#include "mainfolder.h"
#include "foldcreation.h"
static s16 tapFocus(float,float,s16);
static void display(s16);
static s16 checkBounds(s16);
//hold these values throughout 
static s16 first=0;	//printf("\x1b[14;10H Focus text is  %d", i);
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

void updateState(u32 keys, touchPosition screen)	//printf("\x1b[14;10H Focus text is  %d", i);
{
	
	s16 ytemp=0;
	if(keys & KEY_B)
		{
		mainfocus=NULL;
		subfocus=NULL;
		headselect=NULL;
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
					//check if the tap was in bounds, if its a second tap we go into subfolders and reset scroll
					ytemp=tapFocus(penx,peny,ytemp);
				}
			}
			holdcount =0;
			i=0;
		}
		//hold for next iteration
		penx=screen.px;
		peny=screen.py;
	
		//check bounds while scrolling will just return og value if no hits
		ytemp=checkBounds(ytemp);
	}
		hold=ytemp;
        display(ytemp);

}

		
static s16 tapFocus(float x, float y,s16 ytemp)
{
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
					return ytemp;
				}
				
			}
			temp=temp->next;
		}

	}
	else if(kinghead!=NULL)
	{
		
		headfolders *temp = kinghead;
		while(temp!=NULL)
		{
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
					return ytemp;
				}
			}
			temp=temp->next;
		}
	}
	return 0;
}

static void display(s16 i)
{

	if(headselect!=NULL)
	{
		C3D_FVUnifSet(GPU_VERTEX_SHADER, uform_light, 0.0f, 0.5f,  0.0f, 1.0f);
		subDisplay(i);
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

void textSet(float x, float y, char* name)
{
		C2D_Text *Name_p=(C2D_Text*)malloc(100);
		if(Name_p==NULL)
		{
			return;
		}
		float left=(x + 160.0f)*(400.0f/320.0f);
		float top=240.0f-(y + 120.0f);
        C2D_TextParse(Name_p,nameBuf,name);
        C2D_TextOptimize(Name_p);
    
		C2D_Prepare();
        C2D_TextBufClear(nameBuf);
        C2D_DrawText(Name_p, C2D_AtBaseline | C2D_WithColor | C2D_AlignCenter | C2D_WordWrap,left+(buttonwidth/2)*400.0f/320.0f,top+buttonheight/2 + 10.0f, 0.2f, 1.2f, 1.1f, C2D_Color32f(0.0f,0.0f,0.0f,1.0f),200.0f);
        C2D_Flush();
		free(Name_p);
}

static s16 checkBounds(s16 ytemp)
{
	
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
		return ytemp;
}