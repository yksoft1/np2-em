/**
 * @file	compiler.h
 * @brief	include file for standard system include files,
 *			or project specific include files that are used frequently,
 *			but are changed infrequently
 */

#pragma once

#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#include <SDL.h>

#ifdef WIN32
#include <windows.h>
#endif

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#define	BYTESEX_LITTLE
#define	OSLANG_UTF8
#define	OSLINEBREAK_CRLF
#define RESOURCE_US

typedef	signed int			SINT;
typedef	unsigned int		UINT;
typedef	signed char			SINT8;
typedef	unsigned char		UINT8;
typedef	signed short		SINT16;
typedef	unsigned short		UINT16;
typedef	signed int			SINT32;
typedef	unsigned int		UINT32;
typedef signed long long	SINT64;
typedef unsigned long long	UINT64;

#define	sigjmp_buf				jmp_buf
#ifndef	sigsetjmp
#define	sigsetjmp(env, mask)	setjmp(env)
#endif
#ifndef	siglongjmp
#define	siglongjmp(env, val)	longjmp(env, val)
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

#if !defined(OBJC_BOOL_DEFINED) && !defined (WIN32)
typedef	unsigned char	BOOL;
#endif

#ifndef	TRUE
#define	TRUE	1
#endif

#ifndef	FALSE
#define	FALSE	0
#endif

#ifndef	MAX_PATH
#define	MAX_PATH	256
#endif

#ifndef __cplusplus
#ifndef	max
#define	max(a,b)	(((a) > (b)) ? (a) : (b))
#endif
#ifndef	min
#define	min(a,b)	(((a) < (b)) ? (a) : (b))
#endif
#endif	/* __cplusplus */

#ifndef	ZeroMemory
#define	ZeroMemory(d,n)		memset((d), 0, (n))
#endif
#ifndef	CopyMemory
#define	CopyMemory(d,s,n)	memcpy((d), (s), (n))
#endif
#ifndef	FillMemory
#define	FillMemory(a, b, c)	memset((a), (c), (b))
#endif

#include "common.h"
#include "milstr.h"
#include "_memory.h"
#include "rect.h"
#include "lstarray.h"
#include "trace.h"


#define	GETTICK()			SDL_GetTicks()
#define	__ASSERT(s)
#define	SPRINTF				sprintf
#define	STRLEN				strlen

#define	VERMOUTH_LIB
//#define	SOUND_CRITICAL

#define	SUPPORT_UTF8

#define	SUPPORT_16BPP
#define	SCREEN_BPP		16

#define	MEMOPTIMIZE		2
enum {
	RGB24_B	= 0,
	RGB24_G	= 1,
	RGB24_R	= 2
};

//#define SOUND_CRITICAL
#define	SOUNDRESERVE	100

#define SUPPORT_NORMALDISP
#define	SUPPORT_CRT15KHZ
#define	SUPPORT_HOSTDRV
#define	SUPPORT_SWSEEKSND
#define	SUPPORT_SASI
#define	SUPPORT_SCSI

#if defined(CPUCORE_IA32)
#define IA32_PAGING_EACHSIZE
#define IA32_REBOOT_ON_PANIC
#endif

#if defined(SUPPORT_PC9821)
#define	SUPPORT_CRT31KHZ
#define	SUPPORT_PC9801_119
#endif

#define SUPPORT_ARC
#define SUPPORT_ZLIB

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

#define EMSCRIPTEN_DIR "/emulator/np2/"