#ifdef WIN32
#include	<windows.h>
#endif

#include	<stdio.h>
#include	<stddef.h>
#include	<stdint.h>
#include	<setjmp.h>
#include	<SDL.h>

#define	SLZAURUS
#define	BYTESEX_LITTLE
#define	OSLANG_EUC
#define	OSLINEBREAK_CRLF


#ifndef __GNUC__
typedef	signed int			SINT;
typedef	signed char			SINT8;
typedef	unsigned char		UINT8;
typedef	signed short		SINT16;
typedef	unsigned short		UINT16;
typedef	signed int			SINT32;
typedef	unsigned int		UINT32;
#else
#include	<stdlib.h>
typedef	signed int			SINT;
typedef	unsigned int			UINT;
typedef	signed char			SINT8;
typedef	unsigned char		UINT8;
typedef	signed short		SINT16;
typedef	unsigned short		UINT16;
typedef	signed int			SINT32;
typedef	signed long long	SINT64;
typedef	unsigned long long	UINT64;
#endif

#define	BRESULT				UINT
#define	OEMCHAR				char
#define	OEMTEXT(string)		string
#define	OEMSPRINTF			sprintf
#define	OEMSTRLEN			strlen

#define SIZE_VGA
#if !defined(SIZE_VGA)
#define	RGB16		UINT32
#define	SIZE_QVGA
#endif


#include	"common.h"
#include	"milstr.h"
#include	"_memory.h"
#include	"rect.h"
#include	"lstarray.h"
#include	"trace.h"


#define	GETTICK()			SDL_GetTicks()
#define	__ASSERT(s)
#define	SPRINTF				sprintf
#define	STRLEN				strlen

#define	VERMOUTH_LIB
// #define	SOUND_CRITICAL

#define	SUPPORT_EUC

#define	SUPPORT_16BPP
#define	MEMOPTIMIZE		2

#define	SOUNDRESERVE	100

#define SUPPORT_NORMALDISP
#define	SUPPORT_CRT15KHZ
#define	SUPPORT_HOSTDRV
#define	SUPPORT_SWSEEKSND
#define	SUPPORT_SASI
#define	SUPPORT_SCSI
#define RESOURCE_US  1

#if defined(CPUCORE_IA32)
#define IA32_PAGING_EACHSIZE
#define IA32_REBOOT_ON_PANIC
#endif

#if defined(SUPPORT_PC9821)
#define	SUPPORT_CRT31KHZ
#define	SUPPORT_PC9801_119
#endif

#define	SCREEN_BPP		16

#define	sigjmp_buf				jmp_buf
#ifndef	sigsetjmp
#define	sigsetjmp(env, mask)	setjmp(env)
#endif
#ifndef	siglongjmp
#define	siglongjmp(env, val)	longjmp(env, val)
#endif

#ifndef WIN32
#define	FASTCALL
#endif
#define	CPUCALL
#define	MEMCALL
#define	DMACCALL
#define	IOOUTCALL
#define	IOINPCALL
#define	SOUNDCALL
#define	VRAMCALL
#define	SCRNCALL
#define	VERMOUTHCL

#define	msgbox(title, msg)
