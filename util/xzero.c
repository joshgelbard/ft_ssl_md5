#include "util.h"

void	xzero(void *p, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
}
