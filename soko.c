#include <stdio.h>
#include <string.h>
#include <intuition/intuition.h>
#include "sokomenu.h"
#include <clib/intuition_protos.h>
#include <clib/graphics_protos.h>
#include <clib/exec_protos.h>





int main()
{
	struct TextAttr ta={"topaz.font",8,FS_NORMAL,FPF_ROMFONT};
	struct Screen *s;

	if (s=OpenScreenTags(NULL,
		SA_Quiet,	TRUE,
		SA_Depth,	4,
		SA_ShowTitle,	FALSE,
		SA_Font,	&ta,
		TAG_DONE))
	{
		struct ViewPort *vp=&s->ViewPort;
		struct Window *w;

		SetRGB4(vp,0,0,0,0);
		SetRGB4(vp,1,15,15,15);

		if (w=OpenWindowTags(NULL,
			WA_CustomScreen,	s,
			WA_Left,		0,
			WA_Top,			0,
			WA_Width,		s->Width,
			WA_Height,		s->Height,
			WA_Backdrop,		TRUE,
			WA_Borderless,		TRUE,
			WA_Activate,		TRUE,
			WA_IDCMP,		IDCMP_RAWKEY,
			TAG_DONE))
		{
			struct RastPort *rp=w->RPort;
			narysujMenu(rp);
			struct menuSokobana menu=obsluzMenu(w);
			CloseWindow(w);
		}
		CloseScreen(s);
	}

	return(0);
}

void narysujMenu(struct RastPort *rp)
{

	struct TextFont *tf=rp->Font;
	WORD y=tf->tf_Baseline;
	char napisstartowy1[]="Tribute to";
 	char napisstartowy2[]="S-O-K-O-B-A-N";
	char napisstartowy3[]="********* SYSTEM TYPES ***********";
	char napisstartowy4[]="C     IBM - CGA MODE";
	char napisstartowy5[]="T       TANDY MODE";
	char napisstartowy6[]="A     NEW AMIGA MODE";
	char napisstartowy7[]="ENTER YOUR SYSTEM:";
	Move (rp,100,y);
	SetAPen(rp,1);
	Text(rp,napisstartowy1,strlen(napisstartowy1));

	Move (rp,85,100);
	Text(rp,napisstartowy2,strlen(napisstartowy2));
	
	Move (rp,25,120);
	Text(rp,napisstartowy3,strlen(napisstartowy3));

	Move (rp,75,140);
	Text(rp,napisstartowy4,strlen(napisstartowy4));

	Move (rp,75,160);
	Text(rp,napisstartowy5,strlen(napisstartowy5));

	Move (rp,75,180);
	Text(rp,napisstartowy6,strlen(napisstartowy6));

	Move (rp,25,200);
	Text(rp,napisstartowy7,strlen(napisstartowy7));
};

void narysujDrugieMenu (struct Rastport *rp)
{
	char napisstartowy8[]="PRESS: J <JOYSTICK> or K <KEYBOARD>";
	Move (rp,25,220);
	Text (rp,napisstartowy8,strlen(napisstartowy8));
}