/* Copyright (C) 1995-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include "namespace.h"
#include <sys/cdefs.h>

#include <wchar.h>
#include <string.h>
#include <stdlib.h>


/* Duplicate s, returning an identical malloc'd string.	 */
wchar_t *
_STD(wcsdup)(const wchar_t *s)
{
  size_t len = (wcslen (s) + 1) * sizeof (wchar_t);
  void *new = malloc (len);

  if (new == NULL)
    return NULL;

  return (wchar_t *) memcpy (new, (void *) s, len);
}
