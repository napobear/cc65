/*****************************************************************************/
/*                                                                           */
/*                              aim65.h                                      */
/*                                                                           */
/*            Rockwell AIM-65 system-specific definitions                    */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2024      Roberto Lavarone                                            */
/* EMail:        napobear@gmail.com                                          */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

#ifndef _AIM65_H
#define _AIM65_H

/* Check for errors */
#if !defined(__AIM65__)
#error This module may only be used when compiling for the AIM-65!
#endif

/*****************************************************************************/
/*                                   Data                                    */
/*****************************************************************************/

/*****************************************************************************/
/*                                 Hardware                                  */
/*****************************************************************************/

#include <_6522.h>
#define VIA1 (*(struct __6522*)0xA000) // User 6522
#define VIA2 (*(struct __6522*)0xA800) // System 6522

/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/

int __fastcall__ loadt(unsigned char);
/* Read from tape */

int __fastcall__ dumpt(unsigned char, const void*, const void*);
/* Write to tape */

/* End of aim65.h */
#endif
