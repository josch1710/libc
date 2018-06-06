/* $FreeBSD: src/sys/sys/sem.h,v 1.27 2003/06/02 17:23:37 schweikh Exp $ */
/*	$NetBSD: sem.h,v 1.5 1994/06/29 06:45:15 cgd Exp $	*/

/*
 * SVID compatible sem.h file
 *
 * Author:  Daniel Boulet
 */

/** @file
 * FreeBSD 5.3
 * @changed     bird: no padding in semid_ds. seminfo and semexit are static in our 'kernel'.
 * @changed     bird: added time_t, size_t and pid_t as per POSIX.
 */

#ifndef _SYS_SEM_H_
#define _SYS_SEM_H_

#include <sys/ipc.h>
#include <sys/_types.h>

#if !defined(_TIME_T_DECLARED) && !defined(_TIME_T) /* bird: EMX */
typedef	__time_t	time_t;
#define	_TIME_T_DECLARED
#define _TIME_T                         /* bird: EMX */
#endif

#include <sys/_types.h>
#if !defined(_SIZE_T_DECLARED) && !defined(_SIZE_T) /* bird: emx */
typedef	__size_t	size_t;
#define	_SIZE_T_DECLARED
#define _SIZE_T                         /* bird: emx */
#endif

#if !defined(_PID_T_DECLARED) && !defined(_PID_T) /* bird:emx */
typedef	__pid_t		pid_t;		/* process id */
#define	_PID_T_DECLARED
#define _PID_T                          /* bird: emx */
#endif


struct sem;

struct semid_ds {
	struct ipc_perm	sem_perm;	/* operation permission struct */
	struct sem	*sem_base;	/* pointer to first semaphore in set */
	unsigned short	sem_nsems;	/* number of sems in set */
	time_t		sem_otime;	/* last operation time */
#ifndef __EMX__ /* space is precious */
	long		sem_pad1;	/* SVABI/386 says I need this here */
#endif
	time_t		sem_ctime;	/* last change time */
    					/* Times measured in secs since */
    					/* 00:00:00 GMT, Jan. 1, 1970 */
#ifndef __EMX__ /* space is precious */
	long		sem_pad2;	/* SVABI/386 says I need this here */
	long		sem_pad3[4];	/* SVABI/386 says I need this here */
#endif
};

/*
 * semop's sops parameter structure
 */
struct sembuf {
	unsigned short	sem_num;	/* semaphore # */
	short		sem_op;		/* semaphore operation */
	short		sem_flg;	/* operation flags */
};
#define SEM_UNDO	010000

/*
 * semctl's arg parameter structure
 */
union semun {
	int		val;		/* value for SETVAL */
	struct		semid_ds *buf;	/* buffer for IPC_STAT & IPC_SET */
	unsigned short	*array;		/* array for GETALL & SETALL */
};

/*
 * commands for semctl
 */
#define GETNCNT	3	/* Return the value of semncnt {READ} */
#define GETPID	4	/* Return the value of sempid {READ} */
#define GETVAL	5	/* Return the value of semval {READ} */
#define GETALL	6	/* Return semvals into arg.array {READ} */
#define GETZCNT	7	/* Return the value of semzcnt {READ} */
#define SETVAL	8	/* Set the value of semval to arg.val {ALTER} */
#define SETALL	9	/* Set semvals from arg.array {ALTER} */
#define SEM_STAT 10	/* Like IPC_STAT but treats semid as sema-index */
#define SEM_INFO 11	/* Like IPC_INFO but treats semid as sema-index */

/*
 * Permissions
 */
#define SEM_A		IPC_W	/* alter permission */
#define SEM_R		IPC_R	/* read permission */

#ifdef _KERNEL

/*
 * semaphore info struct
 */
struct seminfo {
	int	semmap,		/* # of entries in semaphore map */
		semmni,		/* # of semaphore identifiers */
		semmns,		/* # of semaphores in system */
		semmnu,		/* # of undo structures in system */
		semmsl,		/* max # of semaphores per id */
		semopm,		/* max # of operations per semop call */
		semume,		/* max # of undo entries per process */
		semusz,		/* size in bytes of undo structure */
		semvmx,		/* semaphore maximum value */
		semaem;		/* adjust on exit max value */
};
#ifndef __EMX__
extern struct seminfo	seminfo;
#endif

/* internal "mode" bits */
#define	SEM_ALLOC	01000	/* semaphore is allocated */
#define	SEM_DEST	02000	/* semaphore will be destroyed on last detach */

#ifndef __EMX__
/*
 * Process sem_undo vectors at proc exit.
 */
void	semexit(struct proc *p);
#endif /* !__EMX__ */
#endif /* _KERNEL */

#ifndef _KERNEL
#include <sys/cdefs.h>
#include <sys/_types.h>

#ifndef _SIZE_T_DECLARED
typedef __size_t        size_t;
#define _SIZE_T_DECLARED
#endif

#ifndef _PID_T_DECLARED
typedef __pid_t         pid_t;
#define _PID_T_DECLARED
#endif

__BEGIN_DECLS
#ifndef __EMX__
int semsys(int, ...);
#endif
int semctl(int, int, int, ...);
int semget(key_t, int, int);
int semop(int, struct sembuf *, size_t);
__END_DECLS
#endif /* !_KERNEL */

#endif /* !_SYS_SEM_H_ */
