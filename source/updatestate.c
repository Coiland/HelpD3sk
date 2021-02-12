#include "updatestate.h"
#include "setup.h"
#include "subfolder.h"
#include "mainfolder.h"
static void tapFocus(float,float);
static void display(s16);
static u16 ytemp=0;
static u16 first=0;
static u16 hold=0;
static u16 penx=0;
static u16 peny=0;
static u8 i=0;
static u8 holdcount=0;
static u8 tapflag=0;
static headfolders *mainfocus=NULL;
static folders *subfocus=NULL;
headfolders *headselect=NULL;
folders *subselect=NULL;

void updateState(u32 keys, touchPosition screen)
{
	if(keys & KEY_B)
	{
		mainfocus=NULL;
		subfocus=NULL;
		headselect=NULL;
		subselect=NULL;
	}
	else
	{
    	if(i==0&& (screen.py!=0||screen.px!=0))
		{
			first=screen.py + hold;
			i=1;
			holdcount++;
		}
		else if (i==1 && (abs(screen.py-peny)<6)&& (abs(screen.px-penx)<6))
		{
			holdcount++;
		}
		ytemp=-screen.py+first;
		// && screen.py==0 && screen.px==0
		if(screen.py==0 && screen.px==0)
		{
			ytemp=hold;
			if(i==1)
			{
				if(holdcount<20)
				{
					tapflag=1;
				}
			holdcount =0;
			}
			i=0;
		}

		if(tapflag==1)
		{
			tapFocus(penx,peny);
			tapflag=0;
		}
        hold=ytemp;
		penx=screen.px;
		peny=screen.py;
        display(ytemp);
	}

		
}


static void tapFocus(float x, float y)
{
	int i =4;
	printf("\x1b[40;0H%03f; %03f", x, y);
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
					if (temp==subfocus)
					{
						subselect=subfocus;
					}
					else
					{
						subfocus=temp;
					}
					
					printf("\x1b[14;0H Focus name is %s", subfocus->name);
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
					}
					else
					{
						mainfocus=temp;
					}
					
					printf("\x1b[14;0H Focus name is %s", mainfocus->name);
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

	
	//Mtx_Translate(&MV,-160.0f,-120.0f+i,0.0f,true);
	//Mtx_PerspTilt(&P, C3D_AngleFromDegrees(atan2(240,0.1)*360/M_PI), 320/240, 0.1f, 1000.0f,  true);
	
	C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_projection, &P);

	if(headselect!=NULL)
	{
		subDisplay(mainfocus->head,i);
	}
	else
	{
		mainDisplay(i);
	}
   
}