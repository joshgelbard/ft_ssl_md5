#include "util.h"
#include <unistd.h>

void	xprint(char *s)
{
	size_t len;

	len = xstrlen(s);
	write(1, s, len);
}

