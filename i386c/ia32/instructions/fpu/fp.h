/*
 * Copyright (c) 2003 NONAKA Kimihiro
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef	IA32_CPU_INSTRUCTION_FPU_FP_H__
#define	IA32_CPU_INSTRUCTION_FPU_FP_H__

#ifdef __cplusplus
extern "C" {
#endif

void fpu_initialize(void);

void FPU_FWAIT(void);

#if defined(USE_FPU)
void DB2_FPU_FINIT(void);
void DB2_FPU_FXSAVERSTOR(void);
void DB2_ESC0(void);
void DB2_ESC1(void);
void DB2_ESC2(void);
void DB2_ESC3(void);
void DB2_ESC4(void);
void DB2_ESC5(void);
void DB2_ESC6(void);
void DB2_ESC7(void);
#endif

void NOFPU_FPU_FINIT(void);
void NOFPU_FPU_FXSAVERSTOR(void);
void NOFPU_ESC0(void);
void NOFPU_ESC1(void);
void NOFPU_ESC2(void);
void NOFPU_ESC3(void);
void NOFPU_ESC4(void);
void NOFPU_ESC5(void);
void NOFPU_ESC6(void);
void NOFPU_ESC7(void);

#ifdef __cplusplus
}
#endif

#endif	/* IA32_CPU_INSTRUCTION_FPU_FP_H__ */
