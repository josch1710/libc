/* mou18.c */

#define INCL_MOU
#include <os2.h>

USHORT _THUNK_FUNCTION (Mou16RemovePtr) ();

USHORT MouRemovePtr (PNOPTRRECT pmourtRect, HMOU hmou)
{
  return ((USHORT)
          (_THUNK_PROLOG (4+2);
           _THUNK_FLAT (pmourtRect);
           _THUNK_SHORT (hmou);
           _THUNK_CALL (Mou16RemovePtr)));
}
