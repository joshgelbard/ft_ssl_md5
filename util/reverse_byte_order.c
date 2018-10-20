#include "reverse_byte_order.h"
#include <string.h>

void reverse_byte_order(void *p, size_t len)
{
	unsigned char tmp;
	unsigned char *pp;
	size_t i;

	pp = (unsigned char *)p;
	i = 0;
	while (i < len / 2)
	{
		tmp = pp[i];
		pp[i] = pp[len - i - 1];
		pp[len - i - 1] = tmp;
		i++;
	}
}

