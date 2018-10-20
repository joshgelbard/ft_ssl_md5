#include  "memprint.h"
#include <string.h>
#include <stdio.h>

// fixme: replace s?printf with homemade version and remove stdio.h
void mem2string(void *p, size_t len, char *s)
{
	size_t i;
	unsigned char *pp;

	pp = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		sprintf(s + i * 2, "%02x", pp[i]);
		i++;
	}
}

void memprint(void *p, size_t len)
{
	unsigned char *pp;
	size_t i;

	pp = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		printf("%02x", pp[i]);
		i++;
	}
}

