/*
** Copyright 2002, Manuel J. Petit. All rights reserved.
** Distributed under the terms of the NewOS License.
*/

#include <string.h>
#include <sys/syscalls.h>
#include "rld_priv.h"



char const * const names[]=
{
	"I'm too sexy!",
	"BEWARE OF THE DUCK!",
	"B_DONT_DO_THAT",
	"I need a girlfriend!",
	"assert(C++--!=C)",
	"5038 RIP Nov. 2001",
	"1.e4 e5 2.Nf3 Nc6 3.Bb5",
	"Press any key..."
};
#define RLD_SCRATCH_SIZE 65536



static region_id  rld_region;
static char      *rld_base;
static char      *rld_ptr;

void
rldheap_init(void)
{
	rld_region= sys_vm_create_anonymous_region(
		(char*)names[sys_get_current_proc_id()%(sizeof(names)/sizeof(names[0]))],
		(void**)&rld_base,
		REGION_ADDR_ANY_ADDRESS,
		RLD_SCRATCH_SIZE,
		REGION_WIRING_LAZY,
		LOCK_RW
	);

	rld_ptr= rld_base;
}

void *
rldalloc(size_t s)
{
	void *retval;

	s= (s+15)&~15;

	retval= rld_ptr;
	rld_ptr+= s;

	return retval;
}

void
rldfree(void *p)
{
	(void)(p);
}
