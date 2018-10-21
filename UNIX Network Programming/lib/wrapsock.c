/*
 * socket wrapper functions.
 * These could all go into separate files, so only the ones needed cause
 * the corresponding function to be added to the executable. If sockets
 * are a library (SVR4) this might make a differencr (?), but if sockets
 * are in the kernel (BSD) it doesn't matter.
 *
 *warning: passing arg 2 of `bind' discards `const' from pointer target type
 */

#include "unp.h"

int Accpet(int fd, struct sockaddr *sa, socklen_t * salenptr)
{
	int n;

again:
	if ( (n = accpet(fd, sa, salenptr)) < 0) {
#ifdef EPROTO
		if (errno == EPROTO || errno == ECONNABORTED)
#else
		if (errno == ECONNABORTED)
#endif
			goto again;
		else
			err_sys("accpet error");
	}
 	return(n);
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		err_sys("bind error");
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		err_sys("connect error");
}
