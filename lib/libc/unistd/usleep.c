/* 
** Copyright 2001, Manuel J. Petit. All rights reserved.
** Distributed under the terms of the NewOS License.
*/

#include <unistd.h>
#include <sys/syscalls.h>


int
usleep(unsigned useconds)
{
	return _kern_snooze((bigtime_t)(useconds));
}
