#include "util.h"
#include <stdlib.h>

void	*zalloc(size_t len)
{
	void	*b;
	size_t	i;

	i = 0;
	b = malloc(len);
	while (i < len)
	{
		((unsigned char *)b)[i] = 0;
		i++;
	}
	return (b);
}

