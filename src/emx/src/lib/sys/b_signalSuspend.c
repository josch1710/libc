/* $Id: b_signalSuspend.c 2254 2005-07-17 12:25:44Z bird $ */
/** @file
 *
 * LIBC SYS Backend - suspend till next signal.
 *
 * Copyright (c) 2004 knut st. osmundsen <bird-srcspam@anduin.net>
 *
 *
 * This file is part of InnoTek LIBC.
 *
 * InnoTek LIBC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * InnoTek LIBC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with InnoTek LIBC; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */


/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#include "libc-alias.h"
#include <signal.h>
#include <errno.h>
#include <InnoTekLIBC/thread.h>
#include <InnoTekLIBC/backend.h>
#define __LIBC_LOG_GROUP __LIBC_LOG_GRP_BACK_SIGNAL
#include <InnoTekLIBC/logstrict.h>
#include "b_signal.h"


/**
 * Suspends the current thread till a signal have been handled.
 *
 * @returns Negative error code (errno) on failure. (always fails)
 * @param   pSigSet     Temporary signal mask for the thread.
 */
int         __libc_Back_signalSuspend(const sigset_t *pSigSet)
{
    LIBCLOG_ENTER("pSigSet=%p {%08lx%08lx}\n",
                  (void *)pSigSet, pSigSet ? pSigSet->__bitmap[1] : 0, pSigSet ? pSigSet->__bitmap[0] : 0);
    __LIBC_PTHREAD              pThrd = __libc_threadCurrent();
    sigset_t                    SigSet = *pSigSet;
    __LIBC_THREAD_SIGSUSPEND    SigSuspend = {0};

    /*
     * Gain exclusive access to the signal stuff.
     */
    int rc =__libc_back_signalSemRequest();
    if (rc)
        LIBCLOG_ERROR_RETURN_INT(rc);

    /*
     * Change the signal mask.
     */
    pThrd->SigSetBlockedOld     = pThrd->SigSetBlocked;
    pThrd->fSigSetBlockedOld    = 1;
    pThrd->SigSetBlocked        = SigSet;
    SigSuspend.fDone            = 0;
    pThrd->u.pSigSuspend        = &SigSuspend;
    pThrd->enmStatus            = enmLIBCThreadStatus_sigsuspend;

    /** @todo The specs say no rescheduling of signals in sigsuspend()... I'm not sure if that's a great idea. */

    /*
     * Perform signal wait and return.
     */
    rc = __libc_back_signalWait(pThrd, &SigSuspend.fDone, NULL);
    __libc_back_signalSemRelease();
    if (rc == -EINTR)
        LIBCLOG_RETURN_INT(rc);
    LIBCLOG_ERROR_RETURN_INT(rc);
}


