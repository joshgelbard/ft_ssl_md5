#include "util.h"
#include <unistd.h>

void	xprint(char *s)
{
	size_t len;

	len = xstrlen(s);
	write(STDOUT_FILENO, s, len);
}

void	xprinterr(char *s)
{
	size_t	len;

	len = xstrlen(s);
	write(STDERR_FILENO, s, len);
}

void	xputs(char *s)
{
	xprint(s);
	xprint("\n");
}

void	xputserr(char *s)
{
	xprinterr(s);
	xprinterr("\n");
}
