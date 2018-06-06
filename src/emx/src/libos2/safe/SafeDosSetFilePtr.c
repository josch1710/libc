/* $Id: SafeDosSetFilePtr.c 828 2003-10-10 23:38:11Z bird $ */
/** @file
 *
 * SafeDosSetFilePtr()
 *
 * Copyright (c) 2003 knut st. osmundsen <bird-srcspam@anduin.net>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with This program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#define INCL_BASE
#include <os2.h>


ULONG APIENTRY SafeDosSetFilePtr(HFILE hFile, LONG lOffset, ULONG ulOrigin, PULONG pulPos);
ULONG APIENTRY SafeDosSetFilePtr(HFILE hFile, LONG lOffset, ULONG ulOrigin, PULONG pulPos)
{
    ULONG rc, ul1;
    PULONG pul1 = NULL;

    if (pulPos)
    {
        ul1 = *pulPos;
        pul1 = &ul1;
    }

    rc = DosSetFilePtr(hFile, lOffset, ulOrigin, pul1);

    if (pulPos)
        *pulPos = ul1;

    return rc;
}

