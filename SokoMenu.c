#include <intuition/intuition.h>
#include <clib/exec_protos.h>

#include "SokoMenu.h"

BOOL wybierzKolor(struct Window *w, struct menuSokobana *menu);
BOOL wybierzSterowanie(struct Window *w, struct menuSokobana *menu);

struct menuSokobana obsluzMenu(struct Window *w)
{
	char napisstartowy8[]="PRESS: J <JOYSTICK> or K <KEYBOARD>";
	struct menuSokobana menu;
	
	if (!wybierzKolor(w, &menu))
		return(menu);
		
	narysujDrugieMenu(w->RPort);
		
	if (!wybierzSterowanie(w, &menu))
		return(menu);

	return(menu);
}
	
BOOL wybierzKolor(struct Window *w, struct menuSokobana *menu)
{
	BOOL wyjscie=FALSE, wybrano = FALSE;
	WORD kolor=KOLOR_CGA;
	struct IntuiMessage *msg;

	while (!wyjscie && !wybrano)
	{
		WaitPort(w->UserPort);
		while (msg=(struct IntuiMessage *)GetMsg(w->UserPort))
		{
			if (msg->Class==IDCMP_RAWKEY)
			{
				if (msg->Code==KEY_C)
				{
					kolor=KOLOR_CGA;
					wybrano = TRUE;
				}
				else if (msg->Code==KEY_A)
				{
					kolor=KOLOR_AMIGA;					
					wybrano = TRUE;
				}
				else if (msg->Code==KEY_T)
				{
					kolor=KOLOR_TANDY;								
					wybrano = TRUE;
				}
				else if (msg->Code==KEY_ESC)
				{
					wyjscie=TRUE;
				}
			}
			ReplyMsg((struct Message *)msg);
		}
	}
	menu->kolor=kolor;
	menu->wyjscie=wyjscie;	
	return(!wyjscie);
}

BOOL wybierzSterowanie(struct Window *w, struct menuSokobana *menu)
{
	BOOL wyjscie=FALSE, wybrano = FALSE;
	WORD ster = STER_JOYSTICK;
	struct IntuiMessage *msg;

	while (!wyjscie && !wybrano)
	{
		WaitPort(w->UserPort);
		while (msg=(struct IntuiMessage *)GetMsg(w->UserPort))
		{
			if (msg->Class==IDCMP_RAWKEY)
			{
				if (msg->Code==KEY_J)
				{
					ster=STER_JOYSTICK;
					wybrano = TRUE;
				}
				else if (msg->Code==KEY_K)
				{
					ster = STER_KLAWIATURA;					
					wybrano = TRUE;
				}
				else if (msg->Code==KEY_ESC)
				{
					wyjscie=TRUE;
				}
			}
			ReplyMsg((struct Message *)msg);
		}
	}
	menu->sterowanie=ster;
	menu->wyjscie=wyjscie;	
	return(!wyjscie);}