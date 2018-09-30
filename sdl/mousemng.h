enum {
	uPD8255A_LEFTBIT	= 0x80,
	uPD8255A_RIGHTBIT	= 0x20
};

enum {
	MOUSEPROC_SYSTEM		= 0,
	MOUSEPROC_WINUI,
	MOUSEPROC_BG
};

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	SINT16	x;
	SINT16	y;
	UINT8	btn;
	UINT	flag;
#if !defined(__LIBRETRO__)
	UINT8	showcount;
#endif	/* __LIBRETRO__ */
} MOUSEMNG;

extern MOUSEMNG	mousemng;

void mousemng_initialize(void);
UINT8 mousemng_getstat(SINT16 *x, SINT16 *y, int clear);
void mousemng_sync(int mpx,int mpy);
void mousemng_enable(UINT proc);
void mousemng_disable(UINT proc);
void mousemng_toggle(UINT proc);
void mousemng_hidecursor();
void mousemng_showcursor();
void mousemng_onmove(SDL_MouseMotionEvent *motion);
void mousemng_buttonevent(SDL_MouseButtonEvent *button);
int ismouse_captured(void);

#ifdef __cplusplus
}
#endif

