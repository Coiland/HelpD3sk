/*
--------Author: Insteadof2--------
*/

#include "setup.h"
#include "updatestate.h"
u8 fov =80;


#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
	GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

int main(int argc, char* argv[])
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	
	touchPosition screen; 



	consoleInit(GFX_TOP, NULL);
	C3D_RenderTarget* bottom = C3D_RenderTargetCreate(240, 320, GPU_RB_RGBA8, GPU_RB_DEPTH24_STENCIL8);
	C3D_RenderTargetSetOutput(bottom, GFX_BOTTOM, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);

	
	setupBuffs();
	createFolders();
	int z =0;
	while (aptMainLoop())
	{
		
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; 
		// else if(kDown& KEY_A)
		// {
		// 	fov++;
		// }
		hidTouchRead(&screen);

		printf("\x1b[20;10H%03d; %03d", screen.px, screen.py);

		//printf("\x1b[3;0H%03d", ytemp);
		
		
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C3D_RenderTargetClear(bottom,C3D_CLEAR_ALL,C3D_CLEAR_COLOR,0);
		C3D_FrameDrawOn(bottom);
		updateState(kDown,screen);
		C3D_FrameEnd(0);
	}

	sceneExit();
	C3D_Fini();
	gfxExit();
	return 0;
}
