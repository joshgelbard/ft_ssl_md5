#include "util.h"
#include <unistd.h>

void	xputs(char *s)
{
	size_t len;

	len = xstrlen(s);
	write(1, s, len);
	write(1, "\n", 1);
}

