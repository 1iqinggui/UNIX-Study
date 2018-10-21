/* include unph */
/* Our own header. Tabs are set for 4 spaces, not 8 */

#ifndef __unp_h
#define __unp_h

#include <sys/socket.h>	/* basic socket definitions */

#include	<errno.h>
#include 	<fcntl.h>	/* for nonblocking */
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

/* Miscellaneous constants */
#define MAXLINE 	4096	/* max text line length */
#define BUFFSIZE	8192	/* buffer size for reads and writes */

/* Following shortens all the typecasts of pointer arguments: */
#define SA struct sockaddr

/* prototypes for our socket wrapper functions: see {Sec errors} */
int 	Accpet(int, SA *, socklen_t *);
void 	Bind(int, const SA *, socklen_t);
void 	Connect(int, const SA *, socklen_t);
#endif
