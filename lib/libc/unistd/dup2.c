/*
** Copyright 2001, Manuel J. Petit. All rights reserved.
** Distributed under the terms of the NewOS License.
*/

#include <unistd.h>
#include <errno.h>
#include <sys/syscalls.h>


int
dup2(int ofd, int nfd)
{
	int retval;

	retval= _kern_dup2(ofd, nfd);

	if(retval< 0) {
		errno = retval;
	}

	return retval;
}
