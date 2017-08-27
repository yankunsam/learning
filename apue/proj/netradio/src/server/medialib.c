#include <stdio.h>

#include "medialib.h"

struct mlib_chn_context_st
{
	chnid_t chnid;
	char *desc;
	mytbf *tbf;
	glob_t globres;
	int cur;
	int fd;
	off_t offset;

	.....
};








