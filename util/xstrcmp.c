#include "util.h"

int		xstrcmp(char *s, char *t)
{
	while (*s && *t && *s == *t)
	{
		s++;
		t++;
	}
	return ((unsigned char)s[0] - (unsigned char)t[0]);
}
