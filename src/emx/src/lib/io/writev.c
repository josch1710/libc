/* writev.c (emx+gcc) -- Copyright (c) 1995 by Eberhard Mattes */

#include "libc-alias.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <io.h>
#include <alloca.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/uio.h>

int _STD(writev) (int handle, const struct iovec *iov, int iovcnt)
{
/** @todo make syscall for this as we wanna let tcpip handle this it's own way. */
  int i, n;
  size_t total, len;
  char *buf, *mp, *p;

  if (iovcnt <= 0 || iovcnt > 16)
    {
      errno = EINVAL;
      return -1;
    }

  total = 0;
  for (i = 0; i < iovcnt; ++i)
    {
      if (iov[i].iov_len < 0)
        {
          errno = EINVAL;
          return -1;
        }
      total += iov[i].iov_len;
    }

  mp = NULL;
  if (total <= 0x1000)
    buf = alloca (total);
  else
    buf = mp = malloc (total);
  if (buf == NULL)
    {
      errno = EINVAL;
      return -1;
    }

  p = buf;
  for (i = 0; i < iovcnt; ++i)
    {
      len = iov[i].iov_len;
      memcpy (p, iov[i].iov_base, len);
      p += len;
    }

  n = write (handle, buf, total);
  if (mp != NULL)
    free (mp);
  return n;
}
