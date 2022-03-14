#include <exec/types.h>

#define KEY_ESC 0x45
#define KEY_A 0x20
#define KEY_T 0x14
#define KEY_C 0x33
#define KEY_R 0x13
#define KEY_H 0x25
#define KEY_K 0x27
#define KEY_J 0x26

struct menuSokobana
{
	WORD kolor, sterowanie;
	BOOL wyjscie;
};
enum
{
	KOLOR_CGA,
	KOLOR_TANDY,
	KOLOR_AMIGA
};

enum
{
	STER_JOYSTICK,
	STER_KLAWIATURA
};
struct menuSokobana obsluzMenu(struct Window *w);
void narysujMenu(struct RastPort *rp);
void narysujDrugieMenu(struct RastPort *rp);