#include	"compiler.h"
#include	"mousemng.h"

MOUSEMNG	mousemng;
int captured=0;
#define MOUSESPEEDUP(a) (SINT16)(((SINT32)(a)*20)/10)

UINT8 mousemng_getstat(SINT16 *x, SINT16 *y, int clear) {
	*x = mousemng.x;
	*y = mousemng.y;
	if (clear) {
		mousemng.x = 0;
		mousemng.y = 0;
	}
	return(mousemng.btn);
}

static void mousecapture(BOOL capture) {
	captured = capture;
	if(captured)
	{
		//SDL_CaptureMouse(TRUE);
		mousemng_hidecursor();
	}	
	else
	{
		mousemng_showcursor();
		//SDL_CaptureMouse(FALSE);
	}
}

int ismouse_captured(void){
	return captured;
}

void mousemng_initialize(void) {

	ZeroMemory(&mousemng, sizeof(mousemng));
	mousemng.btn = uPD8255A_LEFTBIT | uPD8255A_RIGHTBIT;
	mousemng.flag = (1 << MOUSEPROC_SYSTEM);
}

void mousemng_sync(int pmx,int pmy) {

		mousemng.x += pmx;
		mousemng.y += pmy;
}

void mousemng_buttonevent(SDL_MouseButtonEvent *button) {
	UINT8 bit;
/*	if(!captured)
	{
		if (button->button == SDL_BUTTON_LEFT && button->type == SDL_MOUSEBUTTONUP)
			mousemng_enable(MOUSEPROC_SYSTEM);
	}*/
	if(captured) {
		switch (button->button) {
		case SDL_BUTTON_LEFT:
			bit = uPD8255A_LEFTBIT;
			break;
		case SDL_BUTTON_RIGHT:
			bit = uPD8255A_RIGHTBIT;
			break;
		default:
			return;
		}
		if (button->type == SDL_MOUSEBUTTONDOWN)
			mousemng.btn &= ~bit;
		else
			mousemng.btn |= bit;
	}
}

void mousemng_enable(UINT proc) {

	UINT	bit;

	bit = 1 << proc;
	if (mousemng.flag & bit) {
		mousemng.flag &= ~bit;
		if (!mousemng.flag) {
			mousecapture(TRUE);
		}
	}
}

void mousemng_disable(UINT proc) {

	if (!mousemng.flag) {
		mousecapture(FALSE);
	}
	mousemng.flag |= (1 << proc);
}

void mousemng_toggle(UINT proc) {

	if (!mousemng.flag) {
		mousecapture(FALSE);
	}
	mousemng.flag ^= (1 << proc);
	if (!mousemng.flag) {
		mousecapture(TRUE);
	}
}

void mousemng_hidecursor() {
	if(captured) {
	//	SDL_ShowCursor(SDL_DISABLE);
	//	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_ShowCursor(0);
	SDL_WM_GrabInput(1);
	}
}

void mousemng_showcursor() {
	// SDL_ShowCursor(SDL_ENABLE);
	// SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_ShowCursor(1);
	SDL_WM_GrabInput(0);
}

void mousemng_onmove(SDL_MouseMotionEvent *motion) {
	if(captured) {
		mousemng.x += MOUSESPEEDUP(motion->xrel);
		mousemng.y += MOUSESPEEDUP(motion->yrel);
	}
}